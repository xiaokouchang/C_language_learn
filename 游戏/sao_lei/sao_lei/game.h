#pragma once

#include<stdio.h>
#include<stdlib.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

//�׵�����
#define EASY_COUNT 10

//ʵ��ɨ����Ϸ�еĺ�������
//��ʼ������
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

//��ӡ����
void DisPlayBoard(char board[ROWS][COLS], int row, int col);

//������
void SetMine(char board[ROWS][COLS], int row, int col);

//�Ų���
void FindMine(char board[ROWS][COLS], char show[ROWS][COLS], int row, int col);
