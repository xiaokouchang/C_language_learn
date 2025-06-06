#define _CRT_SECURE_NO_WARNINGS 1 

#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisPlayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("----------扫雷----------\n");
	for (i = 0; i <= col; i++)
	{
		if (i == 0)
		{
			printf("  ");
			continue;
		}
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("----------扫雷----------\n");
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		//1.产生随机的坐标1~9
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		//2.在坐标中放置雷
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}


int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return (mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1]
		+ mine[x][y - 1] + mine[x][y + 1] + mine[x + 1][y - 1]
		+ mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0');
}


void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < (row * col - EASY_COUNT))
	{
		printf("请输入要排查的坐标:> ");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')
			{
				printf("该坐标被排查过了\n");
				continue;
			}
			if (mine[x][y] == '1')
			{
				printf("很遗憾,你被炸死了\n");
				DisPlayBoard(mine, ROW, COL);
				break;
			}
			else
			{
				//统计一下坐标
				int n = get_mine_count(mine, x, y);
				show[x][y] = n + '0';
				DisPlayBoard(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("坐标非法,请重新输入\n");
		}
	}
	if (win == (row * col - EASY_COUNT))
	{
		printf("恭喜你,排雷成功\n");
		DisPlayBoard(mine, ROW, COL);
	}
}


//拓展
//1.能够展开一片雷的操作
//该坐标不是雷
//该坐标周围没有雷
//该坐标没有被排查过

//对该坐标周围的8个坐标,做上述的递归操作

//该坐标被置为空白,说明很安全
//2.标记和取消雷
//3.显示剩余雷的个数

//EasyX - C语言的界面库