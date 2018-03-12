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
	printf("-----------------------------------------------")
}
