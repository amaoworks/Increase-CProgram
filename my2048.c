#include"my_getch.h"
#include"math.h"
#include"time.h"
#define SPACE() printf("    ")
#define RED_NUM(n) printf("\033[;31m%4d",(n))
#define GREEN_NUM(n) printf("\033[;32m%4d",(n))
#define BLUE_NUM(n) printf("\033[;34m%4d",(n))
#define YELLOW_NUM(n) printf("\033[;33m%4d",(n))
#define PURPLE_NUM(n) printf("\033[;35m%4d",(n))
#define DEEPGREEN_NUM(n) printf("\033[;36m%4d",(n))

/*根据不同的number进行不同的宏替换，输出不同颜色的数字*/
void printNum(const int num)
{
    if(num==0)
 SPACE();
    else if(num==1024 || num==32)
 RED_NUM(num);
    else if(num==2 || num==64 )
 BLUE_NUM(num);
    else if(num==4 || num==128)
 GREEN_NUM(num);
    else if(num==8 || num==256)
 YELLOW_NUM(num);
    else if(num==16 || num==512)
 PURPLE_NUM(num);
    else
 DEEPGREEN_NUM(num);
}


enum game_stat{PLAYING,FAILED,EXITED,DONE};
enum cmd{UP,DOWN,LEFT,RIGHT,QUIT,INVALID};

enum cmd direction;
short empty[16];

struct Game
{
    int box[16];
    enum game_stat stat;
    int step;
    unsigned long int point;
}game;
void init_game()
{
    int i;
    for(i=0;i<16;i++)
 game.box[i]=0;
    game.stat=PLAYING;
    game.step=0;
    game.point=0;
}

/*检验游戏是否能否继续*/
void check_fail()
{
    int i,j;
    for(i=0;i<4;i++)
 for(j=0;j<3;j++)
     if(game.box[i*4+j]==game.box[i*4+j+1])
  return;
    for(j=0;j<4;j++)
 for(i=0;i<3;i++)
     if(game.box[i*4+j]==game.box[(i+1)*4+j])
  return;

    game.stat=FAILED;
}

/*2和4出现的概率比为3/1*/
int get2or4()
{
    int x=rand()%4;
    return x>3 ? 4:2;
}

/*接收键盘的键入，方向键由三个char类型字符表示：
上：27 91 65
下：27 91 66
右：27 91 67
左：27 91 68
*/
void inputCmd()
{
    char c=my_getch();
    if(c==27)
    {
 c=my_getch();
 if(c==91)
 {
     c=my_getch();
     if(c==65)
  direction=UP;
     if(c==66)
  direction=DOWN;
     if(c==67)
  direction=RIGHT;
     if(c==68)
  direction=LEFT;
     //printf("%d ",c);
 }
    }
    else if(c=='\n')
 direction=QUIT;
    else
 direction=INVALID;
}

/*检索空位，即为0的值
*/
int findPos()
{
    int i,count=0,pos;
    for(i=0;i<16;i++)
 empty[i]=-1;
    for(i=0;i<16;i++)
    {
 if(game.box[i]==0)
     empty[count++]=i;
    }
    if(count==0)
 return -1;//game over
    pos=empty[rand()%count];
    //printf("pos=%d\n",pos);
    return pos;
}

int merge()//不可以移动时返回-1
{
    int box_4x4[4][4];
    int i,j,deep;
    int has_move=-1,merge_line=0;

    for(i=0;i<4;i++)
 for(j=0;j<4;j++)
     box_4x4[i][j]=game.box[i*4+j];

    if(direction==RIGHT)
    {
 //printf("RIGHT");
        for(i=0;i<4;i++)
        {
        deep=3;
     merge_line=0;
     for(j=3;j>=0;j--)
     {
         if(box_4x4[i][j]!=0)
  {
      box_4x4[i][deep]=box_4x4[i][j];
      if(deep!=j)  box_4x4[i][j]=0;
      if(deep<3 && merge_line==0 && box_4x4[i][deep]==box_4x4[i][deep+1] )
      { game.point+=box_4x4[i][deep+1];  box_4x4[i][deep+1]*=2;
          box_4x4[i][deep]=0;  merge_line=1;  }
      else deep--;
  }
     }
        }
    }
    if(direction==LEFT)
    {
 //printf("LEFT");
        for(i=0;i<4;i++)
        {
        deep=0;
     merge_line=0;
     for(j=0;j<4;j++)
     {
         if(box_4x4[i][j]!=0)
  {
      box_4x4[i][deep]=box_4x4[i][j];
      if(deep!=j)  box_4x4[i][j]=0;
      if(deep>0 && merge_line==0 && box_4x4[i][deep]==box_4x4[i][deep-1] )
      {  game.point+=box_4x4[i][deep-1];  box_4x4[i][deep-1]*=2;
          box_4x4[i][deep]=0;  merge_line=1;  }
      else deep++;
  }
     }
        }
    }
    if(direction==UP)
    {
 //printf("UP");
        for(j=0;j<4;j++)
        {
        deep=0;
     merge_line=0;
     for(i=0;i<4;i++)
     {
         if(box_4x4[i][j]!=0)
  {
      box_4x4[deep][j]=box_4x4[i][j];
      if(deep!=i)  box_4x4[i][j]=0;
      if(deep>0 && merge_line==0 && box_4x4[deep][j]==box_4x4[deep-1][j])
      {  game.point+=box_4x4[deep-1][j];  box_4x4[deep-1][j]*=2; 
          box_4x4[deep][j]=0;  merge_line=1; }
      else deep++;
  }
     }
        }
    }
    if(direction==DOWN)
    {
 //printf("DOWN");
        for(j=0;j<4;j++)
        {
     merge_line=0;
        deep=3;
     for(i=3;i>=0;i--)
     {
         if(box_4x4[i][j]!=0)
  {
      box_4x4[deep][j]=box_4x4[i][j];
      if(deep!=i)  box_4x4[i][j]=0;
      if(deep<3 && merge_line==0 && box_4x4[deep][j]==box_4x4[deep+1][j]) 
      {   game.point+=box_4x4[deep+1][j]; box_4x4[deep+1][j]*=2; 
          box_4x4[deep][j]=0; merge_line=1; }
      else deep--;
  }
     }
        }
    }

    for(i=0;i<4;i++)
 for(j=0;j<4;j++)
     if(game.box[i*4+j]!=box_4x4[i][j])
     {  
  game.box[i*4+j]=box_4x4[i][j]; 
         has_move=1;
  if(game.box[i*4+j]==2048)  game.stat=DONE;
     }
    return has_move;
}

void drawBox()
{
    int *box=game.box;

    printf("\033[2J");//清屏
    printf("\033[2H");//光标复位
    printf("\033[?25l");//隐藏光标

    printf(" steps: %8d points: %10lu \n",game.step,game.point);
    printf("\033[;30m---------------------------------\n");
    printf("\033[;30m|       |       |       |       |\n");
    //printf("| %4d  | %4d  | %4d  | %4d  |\n",box[0],box[1],box[2],box[3]);
    printf("\033[;30m| ");
    printNum(box[0]);  printf("\033[;30m  | ");
    printNum(box[1]);  printf("\033[;30m  | ");
    printNum(box[2]);  printf("\033[;30m  | ");
    printNum(box[3]);  printf("\033[;30m  |\n");
    printf("\033[;30m|       |       |       |       |\n");
    printf("\033[;30m+-------+-------+-------+-------+\n");
    printf("\033[;30m|       |       |       |       |\n");
    //printf("| %4d  | %4d  | %4d  | %4d  |\n",box[4],box[5],box[6],box[7]);
    printf("\033[;30m| ");
    printNum(box[4]);  printf("\033[;30m  | ");
    printNum(box[5]);  printf("\033[;30m  | ");
    printNum(box[6]);  printf("\033[;30m  | ");
    printNum(box[7]);  printf("\033[;30m  |\n");
    printf("\033[;30m|       |       |       |       |\n");
    printf("\033[;30m+-------+-------+-------+-------+\n");
    printf("\033[;30m|       |       |       |       |\n");
    //printf("| %4d  | %4d  | %4d  | %4d  |\n",box[8],box[9],box[10],box[11]);
    printf("\033[;30m| ");
    printNum(box[8]);  printf("\033[;30m  | ");
    printNum(box[9]);  printf("\033[;30m  | ");
    printNum(box[10]);  printf("\033[;30m  | ");
    printNum(box[11]);  printf("\033[;30m  |\n");
    printf("\033[;30m|       |       |       |       |\n");
    printf("\033[;30m+-------+-------+-------+-------+\n");
    printf("\033[;30m|       |       |       |       |\n");
    //printf("| %4d  | %4d  | %4d  | %4d  |\n",box[12],box[13],box[14],box[15]);
    printf("\033[;30m| ");
    printNum(box[12]);  printf("\033[;30m  | ");
    printNum(box[13]);  printf("\033[;30m  | ");
    printNum(box[14]);  printf("\033[;30m  | ");
    printNum(box[15]);  printf("\033[;30m  |\n");
    printf("\033[;30m|       |       |       |       |\n");
    printf("\033[;30m---------------------------------\n");
    if(game.stat==FAILED)
 printf("   oh,failed! try again.\n");
    else if(game.stat==DONE)
 printf("   yeah,you won! \n");
}

int main(int argc,char** argv)
{
 int pwdlen=10;
 int newPos;
 int has_merge=1;
 init_game();
 srand(time(0));
 fflush(stdin);
 while(1)
 {
        //printf("\033[2J");//清屏
        //printf("\033[2H");//光标复位
     //printf("\033[?25l");//隐藏光标
     newPos=findPos();
     if(newPos==-1)
     {
         check_fail();
  if(game.stat==FAILED)
      break;
     }
     if(has_merge!=-1)
     {
                game.box[newPos]=get2or4();
     }
     drawBox();

     inputCmd(direction);
     if(direction==QUIT)
  break;
     else if(direction==INVALID)
  continue;
     else
     {
  has_merge=merge();
  if(game.stat==DONE) break;
  if(has_merge!=-1)  game.step++;
     }
 }
    drawBox();
    printf("\033[;30m");
}
