#pragma once

#include<stdio.h>
#include<stdlib.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

//雷的数量
#define EASY_COUNT 10

//实现扫雷游戏中的函数声明
//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

//打印棋盘
void DisPlayBoard(char board[ROWS][COLS], int row, int col);

//布置雷
void SetMine(char board[ROWS][COLS], int row, int col);

//排查雷
void FindMine(char board[ROWS][COLS], char show[ROWS][COLS], int row, int col);
