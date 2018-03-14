#include "snake.h"

pSnake head = NULL;   //定义蛇头指针
pSnake Food = NULL;   //定义食物指针

int sleeptime = 500;  //间隔时间，用来控制速度
int Score = 0;        //总分
int everyScore = 1;   //每步得分

//定义游戏中用到的符号
const char food = '#';
const char snake = '*';

void Pos(int x, int y){   //控制光标
	COORD pos;            //pos为结构体
	pos.X = x;            //控制列
	pos.Y = y;            //控制行
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);//读取标准输出句柄来控制光标为pos
}

void Face(){
	system("color 0c");
	printf("|---------------------------------------------|");
	printf("|           Welcome to Snake Game!            |");
	printf("|                                             |");
	printf("|           开始游戏请按 Enter 键             |");
	printf("|           退出游戏请按 Esc 键               |");
	printf("|           暂停游戏请按 Space 键             |");
	printf("|           通过上下左右控制方向              |");
	printf("|           通过 F1 键减速 F2 键加速          |");
	printf("|---------------------------------------------|");
}

void Map(){           // 初始化地图
	int i = 0;
	for(i = 0; i<COL_MAP; i+=2)  // 打印上下边框（每个 # 占用两列）
	{
		Pos(i, 0);
		printf("#");
		Pos(i, ROW_MAP-1);
		printf("#");
	}
	for(i = 0; i < ROW_MAP; i++) //打印左右边框
	{
		Pos(0, i);
		printf("#");
		Pos(COL_MAP-2, i);
		printf("#");
	}
}

void PrintSnake(){               //打印蛇
	pSnake cur = head;
	while(cur){
		Pos(cur->y, cur->x);
		printf("%c", snake);
		cur = cur->next;
	}
}

void InitSnake(){                //初始化蛇身
	int initNum = 3;
	int i = 0;
	pSnake cur;
	head = (pSnake)malloc(sizeof(Snake));
	head->x = 5;
	head->y = 10;
	head->next = NULL;

	cur = head;
	for(i = 1; i < initNum; i++){
		pSnake newNode = (pSnake)malloc(sizeof(Snake));
		newNode->x = 5+i;
		newNode->y = 10;
		newNode->next = NULL;
		cur->next = newNode;
		cur = cur->next;
	}

	PrintSnake();
}

void CreateFood(){               //在地图上随机产生一个食物
	pSnake cur = head;
	Food = (pSnake)malloc(sizeof(Snake));
    
    //产生x~y的随机数 k=rand()%(Y-X+1)+X;  
    srand((unsigned)time(NULL));  
    Food->x = rand()%(ROW_MAP-2 - 1 + 1)+1;  
    Food->y = rand()%(COL_MAP-3 - 2 + 1)+2;  
    Food->next = NULL;  
    while(cur)   //检查食物是否与蛇身重合  
    {  
        if(cur->x == Food->x && cur->y == Food->y)  
        {  
            free(Food);  
            Food = NULL;  
            CreateFood();  
            return;  
        }  
        cur = cur->next;  
    }  
    Pos(Food->y, Food->x);  
    printf("%c", food); 
}

void StartGame()  //游戏开始的所有设置  
{  
    Face();  
    system("pause");  
  
    if(GetAsyncKeyState(VK_RETURN))  
    {  
        system("cls");  
        Pos(COL_MAP+5, 1);  
        printf("当前分数/通关分数:");  
        Pos(COL_MAP+20, 1);  
        printf("%d/%d", Score, SUCCESS_SCORE);  
        Pos(COL_MAP+5, 2);  
        printf("当前分每步得分:");  
        Pos(COL_MAP+20, 2);  
        printf("%d", everyScore);  
        Pos(COL_MAP+5, 3);  
        printf("\n");  
        Pos(COL_MAP+5, 4);  
        printf("速度越快 得分越高哦！！\n");  
  
        Map();  
        InitSnake();  
        CreateFood();  
    }  
    else if(GetAsyncKeyState(VK_ESCAPE))  
    {  
        exit(0);  
    }  
}  
  
int IsCrossWall()             //判断是否碰到墙  
{  
    if(head->x <= 0 || head->x >= ROW_MAP-1  
        ||head->y <= 1 || head->y >= COL_MAP-2)  
    {  
        State = ERROR_WALL;  
        return 0;  
    }  
    return 1;  
}  
  
int IsEatSelf(pSnake newHead)  //判断是否咬到自己  
{  
    pSnake cur = head;  
    assert(newHead);  
    while(cur)  
    {  
        if(cur->x == newHead->x && cur->y == newHead->y)  
        {  
            State = ERROR_SELF;  
            return 0;  
        }  
        cur = cur->next;  
    }  
    return 1;  
}  
  
int IsFood(pSnake pos)  //判断该位置是不是食物  
{  
    assert(pos);  
    if(pos->x == Food->x && pos->y == Food->y)  
    {  
        return 1;  
    }  
    return 0;  
}  
  
void SnakeMove()   //蛇移动一次  
{  
    pSnake newHead = NULL;  
    newHead = (pSnake)malloc(sizeof(Snake));  
  
    if(Direction == R)  
    {  
        newHead->x = head->x;  
        newHead->y = head->y+1;  
        newHead->next = head;  
    }  
    else if(Direction == L)  
    {  
        newHead->x = head->x;  
        newHead->y = head->y-1;  
        newHead->next = head;  
    }  
    else if(Direction == U)  
    {  
        newHead->x = head->x-1;  
        newHead->y = head->y;  
        newHead->next = head;  
      
    }  
    else if(Direction == D)  
    {  
        newHead->x = head->x+1;  
        newHead->y = head->y;  
        newHead->next = head;  
    }  
  
    if(IsFood(newHead))  
    {  
        head = newHead;  
        PrintSnake();  
        CreateFood();  
        Score += everyScore;  
        Pos(COL_MAP+20, 1);  
        printf("%d/%d", Score, SUCCESS_SCORE);  
        if(Score >= SUCCESS_SCORE)  
        {  
            State = SUCCESS;  
        }  
    }  
    else   
        {  
            if(IsCrossWall() && IsEatSelf(newHead))  
            {  
                pSnake cur = NULL;  
                head = newHead;  
                cur = head;  
                //删除蛇尾并打印  
                while(cur->next->next != NULL)  
                {  
                    Pos(cur->y, cur->x);  
                    printf("%c", snake);  
                    cur = cur->next;  
                }  
                  
                Pos(cur->y, cur->x);  
                printf("%c", snake);  
                Pos(cur->next->y, cur->next->x);  
                printf(" ");  //打印空格来覆盖频幕上的蛇尾  
                free(cur->next);  
                cur->next = NULL;  
            }  
            else  
            {  
                free(newHead);  
                newHead = NULL;  
            }  
    }  
}  
  
void Pause()  
{  
    while(1)  
    {  
        Sleep(sleeptime);  
        if(GetAsyncKeyState(VK_SPACE))  
        {  
            break;  
        }  
    }  
}  
  
void ControlSnake() //用键盘控制游戏  
{  
    if(GetAsyncKeyState(VK_UP) && Direction!=D)  
    {  
        Direction = U;  
    }  
    else if(GetAsyncKeyState(VK_DOWN) && Direction!=U)  
    {  
        Direction = D;  
    }  
    else if(GetAsyncKeyState(VK_LEFT) && Direction!=R)  
    {  
        Direction = L;  
    }  
    else if(GetAsyncKeyState(VK_RIGHT) && Direction!=L)  
    {  
        Direction = R;  
    }  
    else if(GetAsyncKeyState(VK_F1))  
    {  
        if(sleeptime != 500)  
        {  
            sleeptime = 500;  
            everyScore = 1;  
            Pos(COL_MAP+20, 2);  
            printf("%d", everyScore);  
        }  
    }  
    else if(GetAsyncKeyState(VK_F2))  
    {  
        if(sleeptime != 300)  
        {  
            sleeptime = 300;  
            everyScore = 2;  
            Pos(COL_MAP+20, 2);  
            printf("%d", everyScore);  
        }  
    }  
    else if(GetAsyncKeyState(VK_SPACE))  
    {  
        Pause();  
    }  
    else if(GetAsyncKeyState(VK_ESCAPE))  
    {  
        exit(0);  
    }  
}  
  
void StateGame() //判断游戏失败或成功  
{  
    if(State == ERROR_SELF)  
    {  
        system("cls");  
        printf("很遗憾，蛇咬到自己，游戏失败！\n");  
    }  
    else if(State == ERROR_WALL)  
    {  
        system("cls");  
        printf("很遗憾，蛇碰到墙壁，游戏失败！\n");  
    }  
    else if(State == SUCCESS)  
    {  
        system("cls");  
        printf("恭喜您，已通关！！！\n");  
    }  
      
}  

void RunGame()  
{  
    Direction = R; //蛇初始行走方向为右  
    State = NORMAL;//游戏初始为正常状态  
    while(1)  
    {  
        ControlSnake();  
        SnakeMove();  
        if(State != NORMAL)  
        {  
            StateGame();  
            break;  
        }  
        Sleep(sleeptime);  
    }  
}  
  
void EndGame()  //释放链表并恢复默认值  
{  
    pSnake cur = head;  
    while(cur)  
    {  
        pSnake del = cur;  
        cur = cur->next;  
        free(del);  
        del = NULL;  
    }  
    head = NULL;  
    if(Food != NULL)  
    {  
        free(Food);  
        Food = NULL;  
    }  
    Score = 0;  
    everyScore = 1;  
    sleeptime = 500;  
}  
