#ifndef snake_h
#define snake_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <assert.h>

//标识地图大小
#define ROW_MAP 10       //地图的行
#define COL_MAP 20       //地图的列
#define SUCCESS_SCORE 10 //通关分数

enum Direction{          //蛇行走的方向
	R,        //右
	L,        //左
	U,        //上
	D         //下
} Direction;

enum State{
	ERROR_SELF,  //咬到自己
	ERROR_WALL,  //撞到墙
	SUCCESS      //通关
} State;

typedef struct Snake{
	size_t x;    //行
	size_t y;    //列
	struct Snake* next;
} Snake, *pSnake;

void StartGame();
void RunGame();
void EndGame();

#endif
