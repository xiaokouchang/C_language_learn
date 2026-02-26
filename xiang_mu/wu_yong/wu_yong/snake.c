#include"snake.h"
int row = 32;
int col = 32;
extern int maxscore = 0;//记录最高得分

//菜单
void menu()
{
	printf("******************************************\n");
	printf("*****       欢迎来到贪吃蛇游戏       *****\n");
	printf("*****        0. 退出游戏             *****\n");
	printf("*****        1. 开始游戏             *****\n");
	printf("******************************************\n");
}


//初始化
void Init()
{
	printf("开始游戏\n");
	//SnakeLoad();
	hideCursor();
	//printf("请输入边界的横坐标和纵坐标(中间用空格隔开):>");
	//scanf("%d %d", &x, &y);
	system("cls");
	//adjust_console_window(x, y);
	Area(row, col);
	InitSnake(row, col, LENGTH);
	PrintSnake(0);
	Food(row, col);
	PrintFood();
	MoveSnake();//蛇移动
}



//输出边界
void Area(int row, int col)
{
	int i = 0;
	int j = 0;
    color(6);
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (i > 0 && i < row - 1 && j > 0 && j < col - 1)
			{
				printf("  "); 
			}
			else
			{
				state[i][j] = WALL;
				printf("■ ");
			}
		}
		printf("\n");
	}
}

void color(int c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); //颜色设置
}

//初始化蛇
void InitSnake(int row,int col,int len)
{
	//随机生成蛇头
	while (1)
	{
		snake.x = rand() % row + 1;
		snake.y = rand() % col + 1;
		if (snake.x >= 1 && snake.x < row && snake.y >= 1 && snake.y < col)
		{
			break;
		}
	}
	//snake.x = snake.x < 1 ? 1 : (snake.x > row ? row : snake.x);
	//snake.y = snake.y < 1 ? 1 : (snake.y > col ? col : snake.y);
	state[snake.x][snake.y] = HEAD;
	snake.len++;
	//生成蛇身
	int i = 0;
	for (i = 1; i < len; i++)
	{
		SnakeBody(i);
	}
}


//添加蛇身
void SnakeBody(int count)
{
	body[count].x = snake.x;//确保整条蛇为水平延伸
	body[count].y = snake.y - count < 1 ? snake.y + count : snake.y - count;
	body[count].x = body[count].x < 1 ? 1 : (body[count].x > row ? row : body[count].x);
	body[count].y = body[count].y < 1 ? 1 : (body[count].y > col ? col : body[count].y);
	state[body[count].x][body[count].y] = BODY;
	snake.len++;
}


//改变蛇身移动方向(呈弯曲状)
//void SnakeDirection()
//{
//	//将状态数组中蛇的位置标记为空
//	//将蛇头置为空
//	//将蛇身置为空
//	int i = 1;
//	int j = 1;
//	for (i = 1; i < snake.len; i++)
//	{
//		state[body[i].x][body[i].y] = EMPTY;
//	}
//	//记录改变之前蛇头的位置
//	int prevx = snake.x;
//	int prevy = snake.y;
//	snake.y--;//改变蛇头移动方向
//	//蛇身包括蛇头之间两两交换
//	for (i = 1; i < snake.len; i++)
//	{
//		int tempx = body[i].x;
//		int tempy = body[i].y;
//		prevx = body[i].x;
//		prevy = body[i].y;
//		body[i].x = tempx;
//		body[i].y = tempy;
//		//更新新的状态数组
//		state[prevx][prevy] = BODY;
//		state[body[i].x][body[i].y] = BODY;
//		if (i == 0)
//		{
//			state[prevx][prevy] = HEAD;//标记新的蛇头位置
//		}
//	}
//
//	//for (i = 1; i < snake.len; i++)
//	//{
//	//	for (j = 1; j < col; j++)
//	//	{
//	//		if (state[i][j] == BODY)
//	//		{
//	//			state[i][j] = EMPTY;
//	//		}
//	//	}
//	//}
//}
//void SnakeDirection(int prevx, int prevy, int newx, int newy)
//{
//	//将状态数组中蛇的位置标记为空
//	//将蛇头置为空
//	state[prevx][prevy] = EMPTY;
//	//将蛇身置为空
//	int i = 1;
//	int j = 1;
//	for (i = 1; i < snake.len; i++)
//	{
//		state[body[i].x][body[i].y] = EMPTY;
//	}
//	//蛇身包括蛇头之间两两交换
//	for (i = 1; i < snake.len; i++)
//	{
//		int tempx = body[i].x;
//		int tempy = body[i].y;
//		body[i].x = prevx;
//		body[i].y = prevy;
//		prevx = tempx;
//		prevy = tempy;
//	}
//	state[newx][newy] = HEAD;
//	for (i = 1; i < snake.len; i++)
//	{
//		state[body[i].x][body[i].y] = BODY;
//	}
//	snake.x = newx;
//	snake.y = newy;
//}
void SnakeDirection(int prevx, int prevy, int newx, int newy)
{
	//将状态数组中蛇的位置标记为空
	//将蛇头置为空
	state[prevx][prevy] = EMPTY;
	//将蛇身置为空
	int i = 1;
	int j = 1;
	for (i = 1; i < snake.len; i++)
	{
		state[body[i].x][body[i].y] = EMPTY;
	}
	//蛇身包括蛇头之间两两交换
	for (i = 1; i < snake.len; i++)
	{
		int tempx = body[i].x;
		int tempy = body[i].y;
		body[i].x = prevx;
		body[i].y = prevy;
		prevx = tempx;
		prevy = tempy;
	}
	state[newx][newy] = HEAD;
	for (i = 1; i < snake.len; i++)
	{
		state[body[i].x][body[i].y] = BODY;
	}
	snake.x = newx;
	snake.y = newy;
}
//创建食物
void Food(int row, int col)
{
	int flag = 1;
	int foodx = 0;
	int foody = 0;
	while (flag)//不断生成食物
	{
		food.x = rand() % (row - 1) + 1;// 0 - 30 1 -29 
		food.y = rand() % (col - 1) + 1;
		//判断是否在边界上或者蛇身上
		if (state[food.x][food.y] == EMPTY)
		{
			food.x = food.x < 1 ? 1 : (food.x > row - 1 ? row - 1 : food.x);
			food.y = food.y < 1 ? 1 : (food.y > row - 1 ? row - 1 : food.y);
			state[food.x][food.y] = FOOD;
			foodx = food.x;
			foody = food.y;
			flag = 0;
		}
	}
}

//打印蛇
void PrintSnake(int score)
{
	int i = 0;
	color(5);
	MoveMouse(snake.x, snake.y);
	printf("■");
	//输出蛇身
	for (i = 1; i < snake.len; i++)
	{
		color(4);
		MoveMouse(body[i].x, body[i].y);
		printf("■");
	}
	MoveMouse(row, col);
	color(7);
	printf("目前的分数是:%d    最高得分是:%d\n", score, maxscore);
}


//打印食物
void PrintFood()
{
	color(4);
	MoveMouse(food.x, food.y);
	printf("△");
}


//移动光标
void MoveMouse(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE) 
	{
		printf("获取句柄失败！\n");
		return;
	}
	// 步骤2：定义目标坐标（X=10列，Y=5行）
	COORD targetPos;
	targetPos.X = x * 2; // 横坐标（列）
	targetPos.Y = y;  // 纵坐标（行）
	// 步骤3：移动光标到目标位置
	SetConsoleCursorPosition(hConsole, targetPos);
}


//隐藏光标
void hideCursor() 
{
	// 定义光标信息结构体：dwSize是光标占字符单元格的百分比,bVisible是是否可见
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = 1;        // 光标大小(1-100,不影响隐藏效果)
	cursorInfo.bVisible = FALSE;  // FALSE=隐藏,TRUE=显示
	// 获取标准输出句柄,并设置光标信息
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}


//显示光标
void LightCursor()
{
	// 定义光标信息结构体：dwSize是光标占字符单元格的百分比,bVisible是是否可见
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = 1;        // 光标大小(1-100,不影响隐藏效果)
	cursorInfo.bVisible = TRUE;  // FALSE=隐藏,TRUE=显示
	// 获取标准输出句柄,并设置光标信息
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}


//程序结束
void sleep(int time, int score)
{
	Sleep(time);
	color(7);
	system("cls");
	SnakeSave(score);
}


//蛇移动
//int direction = LEFT;//记录蛇每次移动的方向
//void MoveSnake()
//{
//	while (1)
//	{
//		int prevx = snake.x;
//		int prevy = snake.y;
//		int newx = snake.x;
//		int newy = snake.y;
//		if (_kbhit())
//		{
//			//记录改变之前蛇头的位置
//
//			int key = _getch();
//			if (key == 0 || key == 224)
//			{
//				key = _getch();
//				switch (key)
//				{
//				case UP:
//					if (direction != DOWN)
//					{
//						direction = UP;
//					}
//					break;
//				case DOWN:
//					if (direction != UP)
//					{
//						direction = DOWN;
//					}
//					break;
//				case LEFT:
//					if (direction != RIGHT)
//					{
//						direction = LEFT;
//					}
//					break;
//				case RIGHT:
//					if (direction != LEFT)
//					{
//						direction = RIGHT;
//					}
//					break;
//				}
//			}
//		}
//		switch (direction)
//		{
//		case UP:
//			newy = snake.y - 1;
//			break;
//		case DOWN:
//			newy = snake.y + 1;
//			break;
//		case LEFT:
//			newx = snake.x - 1;
//			break;
//		case RIGHT:
//			newx = snake.x + 1;
//			break;
//		}
//		SnakeDirection(prevx, prevy, newx, newy);//改变蛇身移动方向
//		//判断蛇头是否吃到食物
//		int ret = SnakeEat();
//		if (ret)
//		{
//			Food(row, col);
//		}
//		system("cls");
//		Area(row, col);
//		PrintSnake();
//		PrintFood();
//		//判断蛇头是否撞墙
//		Sleep(100); // 控制移动速度
//	}
//}


//清理旧蛇
void ClearSnake(int prevx, int prevy)
{
	MoveMouse(prevx, prevy);
	printf(" ");
}


int direction = LEFT;//记录蛇每次移动的方向
void MoveSnake()
{
	int score = 0;//记录目前得分
	while (1)
	{
		//Area(row, col);
		int prevx = snake.x;
		int prevy = snake.y;
		int newx = snake.x;
		int newy = snake.y;
		if (_kbhit())
		{
			//记录改变之前蛇头的位置
			int key = _getch();
			if (key == 0 || key == 224)
			{
				key = _getch();
				switch (key)
				{
				case UP:
					if (direction != DOWN)
					{
						direction = UP;
					}
					break;
				case DOWN:
					if (direction != UP)
					{
						direction = DOWN;
					}
					break;
				case LEFT:
					if (direction != RIGHT)
					{
						direction = LEFT;
					}
					break;
				case RIGHT:
					if (direction != LEFT)
					{
						direction = RIGHT;
					}
					break;
				}
			}
			
		}
		switch (direction)
		{
		case UP:
			newy = snake.y - 1;
			break;
		case DOWN:
			newy = snake.y + 1;
			break;
		case LEFT:
			newx = snake.x - 1;
			break;
		case RIGHT:
			newx = snake.x + 1;
			break;
		}
		//判断蛇头是否撞墙
		int ret = SnakeWall(newx, newy);
		if (ret == 1)
		{
			sleep(5000, score);
			printf("很遗憾,游戏失败,蛇头撞墙\n");
			break;
		}
		if (ret == 2)
		{
			sleep(5000, score);
			printf("很遗憾,游戏失败,蛇头撞蛇身\n");
			break;
		}
		//清理旧蛇头
		ClearSnake(prevx, prevy);
		//清理旧蛇身
		int i = 0;
		for (i = 1; i < snake.len; i++)
		{
			ClearSnake(body[i].x, body[i].y);
		}
		SnakeDirection(prevx, prevy, newx, newy);//改变蛇身移动方向
		//判断蛇头是否吃到食物
		int eat = SnakeEat();
		if (eat)
		{
			score++;
			Food(row, col);
		}
		PrintSnake(score);
		PrintFood();
		Sleep(100);
	}
}


int SnakeWall(int newx, int newy)
{
	if(state[newx][newy] == 1)//蛇头撞墙
	{
		return 1;
	}
	else if (state[newx][newy] == 3)//蛇头撞蛇身
	{
		return 2;
	}
	return 0;
}


//蛇吃食物
int SnakeEat()
{
	int ret = 0;
	if (snake.x == food.x && snake.y == food.y)
	{
		SnakeBody(snake.len);//蛇的长度增加1
		food.x = food.y = EMPTY;//食物的位置置为空
		ret = 1;
	}
	return ret;
}


//将最高得分和目前得分保存到文件中
void SnakeSave(int score)
{
	SnakeLoad();
	if (score > maxscore)
	{
		maxscore = score;
	}
	FILE* pf = fopen("snake.txt", "w");
	if (pf == NULL)
	{
		perror("SnakeSave");
		return;
	}
	fprintf(pf, "贪吃蛇的最高得分是: %d\n", maxscore);
	fclose(pf);
	pf = NULL;
	printf("保存文件成功\n");
}


//从文件中加载最高得分
int SnakeLoad()
{
	FILE* pf = fopen("snake.txt", "r");
	if (pf == NULL)
	{
		perror("SnakeLoad");
		return;
	}
	int score = 0;
	fscanf(pf, "贪吃蛇的最高得分是: %d", &score);
	maxscore = score;
	fclose(pf);
	pf = NULL;
	return maxscore;
}
