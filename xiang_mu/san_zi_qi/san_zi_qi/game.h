#pragma once
#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COL 3	
//头文件中声明函数

//初始化棋盘
void init_board(char board[ROW][COL], int row, int col);

//打印棋盘
void print_board(char board[ROW][COL], int row, int col);

//玩家下棋
void player_move(char board[ROW][COL], int row, int col);

//电脑下棋
void computer_move(char board[ROW][COL], int row, int col);

//判断输赢
char is_win(char board[ROW][COL], int row, int col);

//判断平局
int is_full(char board[ROW][COL], int row, int col);
