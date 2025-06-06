#define _CRT_SECURE_NO_WARNINGS 1 
#include "game.h"

void init_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0;i < row;i++)
	{
		int j = 0;
		for (j = 0;j < col;j++)
		{
			board[i][j] = ' ';
		}
	}
}
void print_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0;i < row;i++)
	{
		int j = 0;
		for (j = 0;j < col;j++)
		{
			if (j == col - 1)
			{
				printf(" %c ", board[i][j]);
			}
			else
			{
				printf(" %c |", board[i][j]);
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0;j < col;j++)
			{
				if (j == col - 1)
				{
					printf("---");
				}
				else
				{
					printf("---|");
				}
			}
			printf("\n");
		}
	}
}

void player_move(char board[ROW][COL], int row, int col)
{
	printf("玩家下棋:>\n");
	while (1)
	{
		printf("请输入要下棋的坐标:>");
		int x = 0;
		int y = 0;
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标被占用,请重新输入\n");
			}
		}
		else
		{
			printf("坐标非法\n");
		}
	}
}

//电脑下棋
//随机生成坐标,只要没有被占用,就下棋
void computer_move(char board[ROW][COL], int row, int col) 
{
	printf("电脑下棋:>\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

char is_win(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//判断三行
	for (i = 0;i < row;i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] !=' ')
		{
			return board[i][0];
		}
	}
	//判断三列
	for (i = 0;i < col;i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	//判断对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//平局
	if (is_full(board, row, col))
	{
		return 'Q';
	}
	//继续,没有玩家或者电脑赢,
	return 'C';
}
int is_full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0;i < row;i++)
	{
		int j = 0;
		for (j = 0;j < col;j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}






