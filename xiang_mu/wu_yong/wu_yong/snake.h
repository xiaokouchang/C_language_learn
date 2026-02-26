#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <Windows.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>

#define ROW 32  //初始化蛇的长度
#define COL 32 //初始化蛇的长度
#define EMPTY 0  //标记空
#define WALL 1  //标记墙
#define HEAD 2  //标记蛇头
#define BODY 3  //标记蛇身
#define FOOD 4  //标记食物
int state[ROW][COL];//坐标位置的状态
enum move
{
	UP = 72,
	DOWN = 80,  
	LEFT = 75,
	RIGHT = 77,
	ESC = 27
};

//#define direction  0//记录蛇每次移动的方向

#define LENGTH 3  //蛇的初始化长度
//#define UP    1  //蛇向上移动
//#define DOWN  2  //蛇向下移动
//#define LEFT  3  //蛇向左移动
//#define RIGHT 4  //蛇向右移动

//蛇头
struct Snake
{
	int len;//记录蛇身长度
	int x;//蛇头横坐标
	int y;//蛇头纵坐标
}snake;

//蛇身
struct Body
{
	int x;//蛇身横坐标
	int y;//蛇身纵坐标
}body[ROW * COL];

//食物
struct Food
{
	int x;//食物横坐标
	int y;//食物纵坐标
}food;

//菜单
void menu();

//初始化
void Init();

//绘制边界
void Area(int row, int col);

//颜色设置
void color(int c);

//初始化蛇
void InitSnake(int row, int col, int len);

//添加蛇身
void SnakeBody(int count);

//打印蛇
void PrintSnake(int score);

//生成食物
void Food(int row, int col);

//打印食物
void PrintFood();

//移动光标
void MoveMouse(int x, int y);

//程序结束
void sleep(int time, int score);

//隐藏光标
void hideCursor();

//显示光标
void LightCursor();

//蛇移动
void MoveSnake();

//蛇吃食物
int SnakeEat();

//改变蛇移动方向
//void SnakeDirection();
void SnakeDirection(int prevx, int prevy, int newx, int newy);

//清理旧蛇
void ClearSnake(int prevx, int prevy);

//蛇是否撞墙或者撞蛇身
int SnakeWall(int newx, int newy);

//蛇头是否撞蛇身
//int SnakeBody();

//从文件中加载最高得分和目前得分

void SnakeSave(int score);

//将最高得分和目前得分保存到文件中
int SnakeLoad();
