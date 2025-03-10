#define _CRT_SECURE_NO_WARNINGS 1 
#include "game.h"

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	for (i = 0;i < rows;i++)
	{
		int j = 0;
		for (j = 0;j < cols;j++)
		{
			board[i][j] = set;
		}
	}
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	//控制列号
	int j = 0;
	printf("--------扫雷--------\n");
	for (j = 0;j <= col;j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1;i <= row;i++)
	{
		printf("%d ", i);
		for (j = 1;j <= col;j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("--------扫雷--------\n");
}
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	//假设布置10个雷
	int count = EASY_COUNT;
	while (count)
	{
		//1. 生成随机下标
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		//2. 布置雷
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}
