#define _CRT_SECURE_NO_WARNINGS 1 

#include "game.h"
void menu()
{
	printf("**********************************\n");
	printf("**********    1.play     *********\n");
	printf("**********    0.exit     *********\n");
	printf("**********************************\n");
}

void game()
{
	//需要存放布置雷的信息,需要存放排查出的雷的信息 -- 需要2个二维数组
	//排查时,防止坐标越界,要给数组行,列各加2
	char mine[ROWS][COLS] = { 0 };//布置好的雷的信息
	char show[ROWS][COLS] = { 0 };//排查出的雷的信息

	//1.初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//2.打印棋盘
	//DisPlayBoard(mine, ROW, COL);
	DisPlayBoard(show, ROW, COL);

	//3.布置雷
	SetMine(mine, ROW, COL);
	//DisPlayBoard(mine, ROW, COL);

	//4.排查雷
	FindMine(mine, show, ROW, COL);
}
void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{	//打印菜单
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("扫雷游戏\n");
			//实现扫雷游戏的逻辑
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
}
int main()
{
	//实现游戏的主逻辑
	test();
	return 0;
}