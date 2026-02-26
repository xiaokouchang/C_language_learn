#include"snake.h"

void game1()
{
	color(7);
	int game = 1;
	int ret = SnakeLoad();
	srand((unsigned int)time(NULL));
	while (1 && game)
	{
		menu();
		printf("请输入你的选项:>");                                                               
		scanf("%d", &game);
		switch (game)
		{
		case 0:
			sleep(0, ret);
			printf("退出游戏\n");
			break;
		case 1:
			Init();
			sleep(1000, ret);
			break;
		default:
			printf("非法输入,请重新输入\n");
			break;
		}
	}
	
}

void game2()
{
	int row = 32;
	int col = 32;
	srand((unsigned int)time(NULL));
	Init();
	hideCursor();
	printf("请输入边界的横坐标和纵坐标(中间用空格隔开):>");
	scanf("%d %d", &row, &col);
	system("cls");
	//adjust_console_window(x, y);
	Area(row, col);
	InitSnake(row, col, LENGTH);
	//PrintSnake(score);
	//sleep(5000);
}
void test1()
{
	printf("请按任意键（按 ESC 键退出）...\n");

	while (1) { // 无限循环
		// 1. 检测是否有按键按下（非阻塞）
		if (_kbhit()) {
			// 2. 读取按下的按键（此时不会阻塞，因为已检测到按键）
			char key = _getch();
			// 3. 处理按键：ESC 键的 ASCII 码是 27
			if (key == 27) {
				printf("\n你按下了 ESC 键，程序退出！\n");
				break; // 退出循环
			}
			else {
				printf("\n你按下了：%c (ASCII 码：%d)\n", key, key);
			}
		}

		// 程序可以同时执行其他逻辑（非阻塞特性）
		printf("."); // 打印占位符，展示程序一直在运行
		Sleep(200);  // 延时 200 毫秒，避免打印太快
	}
}
void test2()
{
	int x = 10, y = 5; // 初始位置
	printf("使用方向键移动（按 Q 退出）\n");

	while (1) 
	{
		// 实时检测按键
		if (_kbhit()) 
		{
			int key = _getch();
			// 方向键是扩展键，_getch() 会先返回 0 或 224，再返回实际键值
			if (key == 0 || key == 224) 
			{
				key = _getch(); // 读取方向键的实际值
				switch (key) {
				case 72: y--; break; // 上
				case 80: y++; break; // 下
				case 75: x--; break; // 左
				case 77: x++; break; // 右
				}
				// 清屏（Windows 控制台命令）
				system("cls");
				// 打印当前位置
				for (int i = 0; i < y; i++) printf("\n");
				for (int i = 0; i < x; i++) printf(" ");
				printf("●\n"); // 打印移动的字符
				printf("当前位置：x=%d, y=%d\n", x, y);
				Sleep(10); // 控制移动速度
			}
			else if (key == 'q' || key == 'Q') 
			{
				printf("程序退出！\n");
				break;
			}
		}
	}
}
int main()
{
	game1();//正式
	//game2();//测试
	//test1();
	//test2();
	return 0;
}

//
////#include <stdio.h>
////#include <windows.h>
////#include <limits.h>
////
////// 函数声明：调整控制台窗口尺寸以匹配绘制的边界
////void adjust_console_window1(int rows, int cols);
////// 函数声明：输出边界（优化版）
////void Area1(int x, int y);
////
////int main() {
////    // 示例：传入较大的尺寸（比如40行，60列）
////    int rows = 40;
////    int cols = 60;
////
////    // 1. 先调整控制台窗口尺寸
////    adjust_console_window1(rows, cols);
////    // 2. 再绘制边界
////    Area1(rows, cols);
////
////    return 0;
////}
////
////// 核心函数：动态调整控制台窗口尺寸
////void adjust_console_window1(int rows, int cols) {
////    // 获取控制台句柄
////    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
////    if (hConsole == INVALID_HANDLE_VALUE) {
////        printf("获取控制台句柄失败！\n");
////        return;
////    }
////
////    // 计算实际需要的列数：每个边界字符是"■ "（2个字符），所以列数要*2
////    int real_cols = cols * 2;
////    // 限制最大尺寸（避免超出控制台支持的最大值）
////    // 控制台最大列数一般不超过200，最大行数不超过90（可根据系统调整）
////    real_cols = (real_cols > 200) ? 200 : real_cols;
////    rows = (rows > 90) ? 90 : rows;
////
////    // 1. 设置控制台缓冲区尺寸（决定可显示的最大范围）
////    COORD buffer_size;
////    buffer_size.X = real_cols;  // 缓冲区列数
////    buffer_size.Y = rows;       // 缓冲区行数
////    SetConsoleScreenBufferSize(hConsole, buffer_size);
////
////    // 2. 设置控制台窗口可视尺寸（实际看到的区域）
////    SMALL_RECT window_rect;
////    window_rect.Left = 0;
////    window_rect.Top = 0;
////    window_rect.Right = real_cols - 1;  // 列数从0开始，所以-1
////    window_rect.Bottom = rows - 1;      // 行数从0开始，所以-1
////    SetConsoleWindowInfo(hConsole, TRUE, &window_rect);
////}
////
////// 优化版：输出边界（增加参数校验）
////void Area1(int x, int y) {
////    // 参数校验：限制最小/最大尺寸，避免无效值
////    if (x < 3 || y < 3) {  // 至少3行3列才能形成边界
////        printf("边界尺寸不能小于3行3列！\n");
////        return;
////    }
////    // 限制最大尺寸（和窗口调整逻辑一致）
////    x = (x > 90) ? 90 : x;
////    y = (y > 100) ? 100 : y;  // 因为列数*2，所以y最大100（对应200列）
////
////    int i = 0;
////    int j = 0;
////    for (i = 0; i < x; i++) {
////        for (j = 0; j < y; j++) {
////            if (i > 0 && i < x - 1 && j > 0 && j < y - 1) {
////                printf("  ");  // 内部空白（2个空格，和■ 宽度匹配）
////            }
////            else {
////                printf("■ "); // 边界字符（方块+空格，保证对齐）
////            }
////        }
////        printf("\n");  // 换行
////    }
////}
//
//
////#include <stdio.h>
////#include <windows.h>
////
////// 核心函数：将控制台窗口最大化，并适配缓冲区尺寸
////void set_console_maximized() {
////    HWND hWnd = GetConsoleWindow();
////    if (hWnd == NULL) {
////        printf("获取控制台窗口句柄失败！\n");
////        return;
////    }
////
////    // 1. 直接将窗口最大化（核心API）
////    ShowWindow(hWnd, SW_MAXIMIZE);
////
////    // 2. 获取屏幕分辨率（适配最大化后的缓冲区）
////    // 屏幕宽度（像素）
////    int screen_width = GetSystemMetrics(SM_CXSCREEN);
////    // 屏幕高度（像素）
////    int screen_height = GetSystemMetrics(SM_CYSCREEN);
////
////    // 3. 适配DPI缩放，计算控制台缓冲区的行列数
////    HDC hDc = GetDC(hWnd);
////    float dpi_scale = GetDeviceCaps(hDc, LOGPIXELSX) / 96.0f;
////    ReleaseDC(hWnd, hDc);
////
////    // 控制台字符宽度约8像素/个，每个边界字符是"■ "（2个字符）
////    int buffer_cols = (screen_width / dpi_scale) / 2;  // 列数（适配2字符宽度）
////    int buffer_rows = (screen_height / dpi_scale) / 16; // 行数（字符高度约16像素/行）
////
////    // 4. 设置控制台缓冲区尺寸，避免最大化后内容截断
////    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
////    if (hConsole != INVALID_HANDLE_VALUE) {
////        COORD buffer_size;
////        buffer_size.X = (buffer_cols > 0) ? buffer_cols : 100; // 最小100列
////        buffer_size.Y = (buffer_rows > 0) ? buffer_rows : 50;  // 最小50行
////        SetConsoleScreenBufferSize(hConsole, buffer_size);
////    }
////
////    // 5. 禁用窗口还原按钮（避免用户误操作缩小窗口）
////    SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_MINIMIZEBOX);
////}
////
////// 你的边界绘制函数（保持不变，最大化后会自适应显示）
////void Area1(int x, int y) {
////    if (x < 3 || y < 3) {
////        printf("边界尺寸不能小于3行3列！\n");
////        return;
////    }
////    int i = 0, j = 0;
////    for (i = 0; i < x; i++) {
////        for (j = 0; j < y; j++) {
////            if (i > 0 && i < x - 1 && j > 0 && j < y - 1) {
////                printf("  ");
////            }
////            else {
////                printf("■ ");
////            }
////        }
////        printf("\n");
////    }
////}
////
////int main() {
////    // 第一步：将控制台窗口最大化
////    set_console_maximized();
////
////    // 第二步：绘制边界（可根据屏幕大小调整行列数，示例为40行80列）
////    Area1(40, 80);
////
////    return 0;
////}