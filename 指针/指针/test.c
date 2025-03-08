#define _CRT_SECURE_NO_WARNINGS 1 
//内存 --- 电脑上的存储设备
//程序运行时会加载到内存中,会使用内存空间
//指针是内存中一个最小单元的编号,也就是地址
//指针通常指的是指针变量,是用来存放内存地址的变量
//指针就是地址,口语中说的指针通常指的是指针变量。
//指针变量:用来存放地址的变量(存放在指针中的值都被当成地址处理)
//32位:0b100000000000000000000000000000000 == 4294967296/1024/1024/1024 = 4
//#include<stdio.h>
//int main()
//{
//	int a = 10;//&a取出a的第一个字节的地址(较小的地址)
//	int* pa = &a;//pa --- 指针变量
//	printf("%p\n", &a);
//	printf("%p\n", pa);
//	*pa = 20;
//	printf("%d\n", a);
//	return 0;
//}


//指针类型决定解引用操作时一次访问几个字节
//char* ---- 1 
//int*  ---- 4
//float*---- 4
//#include<stdio.h>
//int main()
//{
//	//int a = 0x11223344;
//	//int* pa = &a;
//	//*pa = 0;
//	int a = 0x11223344;
//	char* pa = &a;//能放下,访问空间大小改变,只能改1个字节
//	*pa = 0;
//	return 0;
//}


//指针类型决定指针的步长(指针+1 --- 跳过几个字节)
//指针的类型决定了指针向前或者向后走一步有多大(距离)
//char* ---- 1 
//int*  ---- 4
//float*---- 4
//#include<stdio.h>
//int main()
//{
//	int a = 0x11223344;
//	int* pa = &a;
//	char* pc = &a;
//	printf("%p\n", pa);
//	printf("%p\n", pa+1);//跳过4个字节
//	printf("%p\n", pc);
//	printf("%p\n", pc+1);//跳过1个字节
//	return 0;
//}


//p+4向高地址走,p-4向低地址走
//#include<stdio.h>
//
//int main()
//{
//	int a = 0x11223344;
//	char* pc = (char*)&a;
//	int i = 0;
//	for (i = 0;i < 4;i++)
//	{
//		*pc = 0;
//		pc++;
//	}
//	printf("%d\n", a);
//	return 0;
//}


//野指针
//指针指向的位置是不可知的(随机的、不正确的、没有明确限制的)
//#include<stdio.h>
//int main()
//{
//	int* p;//未初始化
//	*p = 20;
//	return 0;
//}


//数组越界访问
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0;i <= sz;i++)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//	return 0;
//}


//指针指向的空间释放
//野指针p
//局部变量a已经销毁
//#include<stdio.h>
//int* test()
//{
//	int a = 10;
//	return &a;
//}
//int main()
//{
//	int *p = test();
//	printf("hehe\n");//函数栈帧被破坏
//	printf("%d\n", *p);
//	return 0;
//}


//如何规避野指针
//指针初始化
//小心指针越界
//指针指向空间释放即使置NULL
//避免返回局部变量的地址
//指针使用之前检查有效性
//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	int* p = NULL;//专门初始化指针;
//	if (p != NULL)
//	{
//		*p = 20;
//	}
//	return 0;
//}


//指针+-整数；指针的关系运算
//#include<stdio.h>
//#define N_VALUES 5
//int main()
//{
//	float values[N_VALUES];
//	float* vp;
//	for (vp = &values[0]; vp < &values[N_VALUES];)
//	{
//		*vp++ = 0;
//	}
//	printf("%f\n", vp);
//	return 0;
//}

//#include<stdio.h>
//
//int my_strlen(char* s)
//{
//	char* p = s;
//	while (*p != '\0')
//		p++;
//	return p - s;
//}


//指针-指针
//前提:两个指针要指向同一块空间
//指针-指针的绝对值得到的是两个指针之间的元素个数
//#include<stdio.h>
//int main()
//{
//	char ch[5] = { 0 };
//	int arr[10] = { 0 };
//	printf("%d\n", &arr[0] - &arr[9]);
//	printf("%d\n", &arr[0] - &ch[4]);//代码错误,两个指针要指向同一块空间
//	return 0;
//}


//求字符串的长度
//第1种方法
//#include<stdio.h>
//int main()
//{
//	char arr[] = "abcdef";
//	int len = strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}


//函数
//求字符串长度是在统计'\0'之前的字符
//#include<stdio.h>
//
//int my_strlen(char* str)
//{
//	int count = 0;
//	while(*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}


//#include<stdio.h>
//
//int my_strlen(char* str)
//{
//	char* start = str;//不能使用int*
//	while (*str != '\0')
//	{
//		str++;
//	}
//	return str - start;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}


//#include<stdio.h>
//#define N_VALUES 5
//int main()
//{
//	float values[N_VALUES];
//	float* vp;
//	for (vp = &values[N_VALUES]; vp > &values[0];)
//	{
//		*--vp = 0;
//	}
//	return 0;
//}


//允许指向数组元素的指针与指向数组最后一个元素后面的那个内存位置的指针比较,
//不允许与指向第一个元素之前的那个内存位置的指针进行比较
//建议指针向后越界
//超出范围,但是没有访问
//#include<stdio.h>
//#define N_VALUES 5
//int main()
//{
//	float values[N_VALUES];
//	float* vp;
//	for (vp = &values[N_VALUES - 1]; vp > &values[0];vp--)
//	{
//		*vp = 0;
//	}
//	return 0;
//}


//指针和数组
//指针和数组是不同的对象,存放地址的,大小4/8字节
//数组是一组相同类型元素的集合
//数组的数组名是数组首元素的地址,地址是可以放在指针变量中的
//可以通过数组访问指针
//arr[i] == *(arr + i) == i[arr] == *(i + arr)
//[]是个操作符,arr和i是[]的操作数,交换律
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	int *p = arr;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0;i < sz;i++)
//	{
//		*p = i + 1;
//		p++;
//	}
//	p = arr;
//	for (i = 0;i < sz;i++)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//	return 0;
//}


//二级指针
//存放一级指针变量的地址
//#include<stdio.h>
//
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	*pa = 20;//找到a
//	printf("%d\n", a);
//	return 0;
//}


//#include<stdio.h>
//
//int main()
//{
//	int a = 10;
//	int* pa = &a;//pa是一级指针变量
//	int** ppa = &pa;//二级指针,第一颗*表示pa的类型是int *,第二颗*表示指针
//	//int*** pppa = &ppa;//ppa是三级指针变量
//	printf("%d\n", *ppa);
//	return 0;
//}


//指针数组是存放指针的数组
//字符数组是存放字符的数组
//#include<stdio.h>
//
//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int d = 40;
//	int e = 50;
//	int i = 0;
//	int* arr1[5] = { &a,&b,&c,&d,&e };//指针数组
//	for (i = 0;i < 5;i++)
//	{
//		printf("%d ", *(arr1[i]));
//	}
//	return 0;
//}


//使用一维数组,模拟二维数组
//#include<stdio.h>
//int main()
//{
//	int arr1[] = { 1,2,3,4 };
//	int arr2[] = { 5,6,7,8 };
//	int arr3[] = { 9,10,11,12 };
//	int* arr[3] = { arr1,arr2,arr3 };
//	int i = 0;
//	for (i = 0;i < 3;i++)
//	{
//		int j = 0;
//		for (j = 0;j < 4;j++)
//		{
//			printf("%d ", arr[i][j]);//+j向后偏移j个元素
//		}
//		printf("\n");
//	}
//	return 0;
//}


//指针就是个变量,用来存放地址,地址唯一标识一块内存空间。
//指针的大小是固定的4/8个字节(32位平台/64位平台)。
//指针是有类型,指针的类型决定了指针的+-整数的步长,指针解引用操作的时候的权限。
//字符指针
//本质是把字符串hello world.首字符的地址放到了p中。
//输出整个字符串
//#include<stdio.h>
//int main()
//{
//	const char* p = "hello world.";
//	printf("%s\n", p);
//	return 0;
//}


//打印第一个字符
//#include<stdio.h>
//int main()
//{
//	const char* p = "hello world.";
//	printf("%c\n", *p);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	char ch = 'w';
//	char* pc = &ch;
//	*pc = 'w';
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	char str1[] = "hello world.";//表示首元素的地址
//	char str2[] = "hello world.";//两个数组的起始位置不相同
//	const char* str3 = "hello world.";//str3和str4的地址相同
//	const char* str4 = "hello world.";
//	//char str3 = "hello world.";
//	//char str4 = "hello world.";
//	if (str1 == str2)
//		printf("str1 and str2 are same\n");
//	else
//		printf("str1 and str2 are not same\n");
//	if (str3 == str4)
//		printf("str3 and str4 are same\n");
//	else
//		printf("str3 and str4 are not same\n");
//	return 0;
//}


//指针数组
//指针数组 --- 存放指针的数组。
//整形指针 --- 存放整型地址的指针
//字符指针 --- 存放字符地址的指针
//&数组名VS数组名
//arr是数组名,数组名表示数组首元素的地址。
//int* arr1[10]; //整形指针的数组
//char* arr2[4]; //一级字符指针的数组
//char** arr3[5];//二级字符指针的数组
//#include<stdio.h>
//int main()
//{
//	char* arr[4] = { "abcdef","qwer","hello","hehe" };
//	int i = 0;
//	for (i = 0;i < 4;i++)
//	{
//		printf("%s ", arr[i]);
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int arr1[5] = { 1,2,3,4,5 };
//	int arr2[5] = { 2,3,4,5,6 };
//	int arr3[5] = { 3,4,5,6,7 };
//	int arr4[5] = { 0,0,0,0,0 };
//	int* arr[4] = { arr1,arr2,arr3,arr4 };//首元素的地址
//	int i = 0;
//	for (i = 0;i < 4;i++)
//	{
//		int j = 0;
//		for (j = 0;j < 4;j++)
//		{
//			//arr[i][j] == *(arr[i]+j)
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}


//指针数组
//int* arr1[10]; //整形指针的数组
//char* arr2[4]; //一级字符指针的数组
//char** arr3[5];//二级字符指针的数组


//数组指针 --- 指针
//int (*pa)[10] = &arr;//数组指针
//int (*pa)[10] = arr; //可以这样写,不合理
//#include<stdio.h>
//int main()
//{
//	char ch = 'w';
//	char* pc = &ch;
//
//	int num = 10;
//	int* pi = &num;
//	
//	int arr[10];
//	int (*pa)[10] = &arr;//数组指针
//	return 0;
//}


//arr是数组名,数组名表示数组首元素的地址
//&arr --- 数组的地址
//数组首元素的地址和数组的地址从值的角度来看是一样的,但是意义不一样
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("%p\n", arr);//int*
//	printf("%p\n", arr + 1);//4
//	
//	printf("%p\n", &arr);//int (*)arr[10]
//	printf("%p\n", &arr + 1);//40
//
//	printf("%p\n", &arr[0]);//int*
//	printf("%p\n", &arr[0] + 1);//4
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0;i < 10;i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	return 0;
//}


//二维数组的数组名是首元素第一行的地址
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int (*p)[10] = &arr;
//	int i = 0;
//	for (i = 0;i < 10;i++)
//	{
//		printf("%d ", (*p)[i]);
//	}
//	return 0;
//}


#include<stdio.h>
void print1(int arr[3][4], int r, int c)
{
	int i = 0;
	for (i = 0;i < r;i++)
	{
		int j = 0;
		for (j = 0;j < c;j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
void print2(int (*p)[4], int r, int c)
{
	int i = 0;
	for (i = 0;i < r;i++)
	{
		int j = 0;
		for (j = 0;j < c;j++)
		{
			//printf("%d ", (*p)[j]+i);
			//printf("%d ", (*(p + i))[j]);
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int arr[3][4] = { {1,2,3,4},{2,3,4,5},{3,4,5,6} };
	//print1(arr, 3, 4);
	print2(arr, 3, 4);
	return 0;
}


//*p = arr = *&arr
//#include<stdio.h>
//int main()
//{
//	int arr[10];
//	int* p = &arr;
//	return 0;
//}


//int arr[5];                //数组 
//int* parr1[10];			 //指针数组,数组10个元素,每个元素是int*类型的
//int (*parr2)[10];		 
//数组指针,该指针指向一个数组,数组是10个元素,每个元素是int类型的
//int (*parr3[10])[5];
//parr3是数组,数组有10个元素,数组的每个元素的类型是:int(*)[5]的数组指针类型


//#include <stdio.h>
//void test(int arr[])
//{
//}
//void test(int arr[10])
//{
//}
//void test(int* arr)
//{
//}
//void test2(int* arr[20])
//{
//}
//void test2(int** arr)
//{
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int* arr2[20] = { 0 };
//	test(arr);
//	test2(arr2);
//}


//void test(int arr[3][5])
//{
//}
//void test(int arr[][])
//{
//}
//void test(int arr[][5])
//{
//}
//总结：二维数组传参，函数形参的设计只能省略第一个[]的数字。
//因为对一个二维数组，可以不知道有多少行，但是必须知道一行多少元素。
//这样才方便运算。
//void test(int (*arr)[5])
//{
//}
//int main()
//{
//	int arr[3][5] = { 0 };
//	test(arr);
//}


//一级指针传参
//#include <stdio.h>
//void print(int* p, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", *(p + i));
//	}
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9 };
//	int* p = &arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//一级指针p，传给函数
//	print(p, sz);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9 };
//	int* p = &arr;
//	int* a = arr;
//	//函数形参为int* 实参可以写成test(arr);test(&a);和test(p);
//	return 0;
//}


//#include <stdio.h>
//void test(int** ptr)
//{
//	printf("num = %d\n", **ptr);
//}
//int main()
//{
//	int n = 10;
//	int* p = &n;
//	int** pp = &p;
//	test(pp);
//	test(&p);
//	return 0;
//}


//void test(char** p)
//{
//}
//int main()
//{
//	char c = 'b';
//	char* pc = &c;
//	char** ppc = &pc;
//	char* arr[10];
//	/*test(&pc);
//	test(ppc);*/
//	test(arr);//Ok?
//	return 0;
//}


//函数指针 --- 指向函数的指针
//#include<stdio.h>
//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int arr[10];
//	int (*p)[10] = arr;
//	//printf("%p\n", &Add);
//	int (*pf)(int, int) = &Add;
//	//int (*pf)(int, int) = Add;//两种写法都一样
//	int ret = (*pf)(2, 3);//可以写成int ret = pf(2, 3);
//	printf("%d\n", ret);
//	return 0;
//}


//*arr = *(arr+0) = arr[0]
//#include<stdio.h>
//
//int main()
//{
//	int arr[3][3] = { 1 };
//	int p = **arr;
//	printf("%d\n", p);
//	return 0;
//}


//(类型) --- 强制类型转换
//#include<stdio.h>
//int main()
//{
//	(*(void (*)())0)();//将0强制转化成函数指针
//	//该代码是一次函数调用
//	//调用0地址处的一个函数
//	//首先代码中将0强制类型转换为void(*)()的函数指针
//	//然后去调用0地址处的函数
//	void (*signal(int, void(*)(int)))(int);
//	//该代码是一次函数的声明
//	//名字叫signal
//	//signal函数的参数有两个,第一个是int类型,第二个是函数指针类型
//	//该函数指针能够指向的那个函数的参数是int
//	//返回类型是void
//	//signal函数的返回类型是一个函数指针
//	//该函数指针能够指向的那个函数的参数是int,返回类型是void
//	typedef void(*pf_t)(int);
//	pf_t signal(int, pf_t);//简写
//	return 0;
//}


//#define _CRT_SECURE_NO_WARNINGS 1 
//#include <stdio.h>
//#include <Windows.h>
//#include <stdlib.h>
//#include <time.h>
//#include <conio.h>
//
//#define ROW 22 //游戏区行数
//#define COL 42 //游戏区列数
//
//#define KONG 0 //标记空（什么也没有）
//#define WALL 1 //标记墙
//#define FOOD 2 //标记食物
//#define HEAD 3 //标记蛇头
//#define BODY 4 //标记蛇身
//
//#define UP 72 //方向键：上
//#define DOWN 80 //方向键：下
//#define LEFT 75 //方向键：左
//#define RIGHT 77 //方向键：右
//#define SPACE 32 //暂停
//#define ESC 27 //退出
//
////蛇头
//struct Snake
//{
//	int len; //记录蛇身长度
//	int x; //蛇头横坐标
//	int y; //蛇头纵坐标
//}snake;
//
////蛇身
//struct Body
//{
//	int x; //蛇身横坐标
//	int y; //蛇身纵坐标
//}body[ROW * COL]; //开辟足以存储蛇身的结构体数组
//
//int face[ROW][COL]; //标记游戏区各个位置的状态
//
////隐藏光标
//void HideCursor();
////光标跳转
//void CursorJump(int x, int y);
////初始化界面
//void InitInterface();
////颜色设置
//void color(int c);
////从文件读取最高分
//void ReadGrade();
////更新最高分到文件
//void WriteGrade();
////初始化蛇
//void InitSnake();
////随机生成食物
//void RandFood();
////判断得分与结束
//void JudgeFunc(int x, int y);
////打印蛇与覆盖蛇
//void DrawSnake(int flag);
////移动蛇
//void MoveSnake(int x, int y);
////执行按键
//void run(int x, int y);
////游戏主体逻辑函数
//void Game();
//
//int max, grade; //全局变量
//int main()
//{
//#pragma warning (disable:4996) //消除警告
//	max = 0, grade = 0; //初始化变量
//	system("title 贪吃蛇"); //设置cmd窗口的名字
//	system("mode con cols=84 lines=23"); //设置cmd窗口的大小
//	HideCursor(); //隐藏光标
//	ReadGrade(); //从文件读取最高分到max变量
//	InitInterface(); //初始化界面
//	InitSnake(); //初始化蛇
//	srand((unsigned int)time(NULL)); //设置随机数生成起点
//	RandFood(); //随机生成食物
//	DrawSnake(1); //打印蛇
//	Game(); //开始游戏
//	return 0;
//}
//
////隐藏光标
//void HideCursor()
//{
//	CONSOLE_CURSOR_INFO curInfo; //定义光标信息的结构体变量
//	curInfo.dwSize = 1; //如果没赋值的话，光标隐藏无效
//	curInfo.bVisible = FALSE; //将光标设置为不可见
//	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //获取控制台句柄
//	SetConsoleCursorInfo(handle, &curInfo); //设置光标信息
//}
////光标跳转
//void CursorJump(int x, int y)
//{
//	COORD pos; //定义光标位置的结构体变量
//	pos.X = x; //横坐标
//	pos.Y = y; //纵坐标
//	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //获取控制台句柄
//	SetConsoleCursorPosition(handle, pos); //设置光标位置
//}
////初始化界面
//void InitInterface()
//{
//	color(6); //颜色设置为土黄色
//	for (int i = 0; i < ROW; i++)
//	{
//		for (int j = 0; j < COL; j++)
//		{
//			if (j == 0 || j == COL - 1)
//			{
//				face[i][j] = WALL; //标记该位置为墙
//				CursorJump(2 * j, i);
//				printf("■");
//			}
//			else if (i == 0 || i == ROW - 1)
//			{
//				face[i][j] = WALL; //标记该位置为墙
//				CursorJump(2 * j, i);
//				printf("■");
//			}
//			else
//			{
//				face[i][j] = KONG; //标记该位置为空
//			}
//		}
//	}
//	color(7); //颜色设置为白色
//	CursorJump(0, ROW);
//	printf("当前得分:%d", grade);
//	CursorJump(COL, ROW);
//	printf("历史最高得分:%d", max);
//}
////颜色设置
//void color(int c)
//{
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); //颜色设置
//	//注：SetConsoleTextAttribute是一个API（应用程序编程接口）
//}
////从文件读取最高分
//void ReadGrade()
//{
//	FILE* pf = fopen("贪吃蛇最高得分记录.txt", "r"); //以只读的方式打开文件
//	if (pf == NULL) //打开文件失败
//	{
//		pf = fopen("贪吃蛇最高得分记录.txt", "w"); //以只写的方式打开文件
//		fwrite(&max, sizeof(int), 1, pf); //将max写入文件（此时max为0），即将最高得分初始化为0
//	}
//	fseek(pf, 0, SEEK_SET); //使文件指针pf指向文件开头
//	fread(&max, sizeof(int), 1, pf); //读取文件当中的最高得分到max当中
//	fclose(pf); //关闭文件
//	pf = NULL; //文件指针及时置空
//}
////更新最高分到文件
//void WriteGrade()
//{
//	FILE* pf = fopen("贪吃蛇最高得分记录.txt", "w"); //以只写的方式打开文件
//	if (pf == NULL) //打开文件失败
//	{
//		printf("保存最高得分记录失败\n");
//		exit(0);
//	}
//	fwrite(&grade, sizeof(int), 1, pf); //将本局游戏得分写入文件当中
//	fclose(pf); //关闭文件
//	pf = NULL; //文件指针及时置空
//}
////初始化蛇
//void InitSnake()
//{
//	snake.len = 2; //蛇的身体长度初始化为2
//	snake.x = COL / 2; //蛇头位置的横坐标
//	snake.y = ROW / 2; //蛇头位置的纵坐标
//	//蛇身坐标的初始化
//	body[0].x = COL / 2 - 1;
//	body[0].y = ROW / 2;
//	body[1].x = COL / 2 - 2;
//	body[1].y = ROW / 2;
//	//将蛇头和蛇身位置进行标记
//	face[snake.y][snake.x] = HEAD;
//	face[body[0].y][body[0].x] = BODY;
//	face[body[1].y][body[1].x] = BODY;
//}
////随机生成食物
//void RandFood()
//{
//	int i, j;
//	do
//	{
//		//随机生成食物的横纵坐标
//		i = rand() % ROW;
//		j = rand() % COL;
//	} while (face[i][j] != KONG); //确保生成食物的位置为空，若不为空则重新生成
//	face[i][j] = FOOD; //将食物位置进行标记
//	color(12); //颜色设置为红色
//	CursorJump(2 * j, i); //光标跳转到生成的随机位置处
//	printf("●"); //打印食物
//}
////判断得分与结束
//void JudgeFunc(int x, int y)
//{
//	//若蛇头即将到达的位置是食物，则得分
//	if (face[snake.y + y][snake.x + x] == FOOD)
//	{
//		snake.len++; //蛇身加长
//		grade += 10; //更新当前得分
//		color(7); //颜色设置为白色
//		CursorJump(0, ROW);
//		printf("当前得分:%d", grade); //重新打印当前得分
//		RandFood(); //重新随机生成食物
//	}
//	//若蛇头即将到达的位置是墙或者蛇身，则游戏结束
//	else if (face[snake.y + y][snake.x + x] == WALL || face[snake.y + y][snake.x + x] == BODY)
//	{
//		Sleep(1000); //留给玩家反应时间
//		system("cls"); //清空屏幕
//		color(7); //颜色设置为白色
//		CursorJump(2 * (COL / 3), ROW / 2 - 3);
//		if (grade > max)
//		{
//			printf("恭喜你打破最高记录，最高记录更新为%d", grade);
//			WriteGrade();
//		}
//		else if (grade == max)
//		{
//			printf("与最高记录持平，加油再创佳绩", grade);
//		}
//		else
//		{
//			printf("请继续加油，当前与最高记录相差%d", max - grade);
//		}
//		CursorJump(2 * (COL / 3), ROW / 2);
//		printf("GAME OVER");
//		while (1) //询问玩家是否再来一局
//		{
//			char ch;
//			CursorJump(2 * (COL / 3), ROW / 2 + 3);
//			printf("再来一局?(y/n):");
//			scanf("%c", &ch);
//			if (ch == 'y' || ch == 'Y')
//			{
//				system("cls");
//				main();
//			}
//			else if (ch == 'n' || ch == 'N')
//			{
//				CursorJump(2 * (COL / 3), ROW / 2 + 5);
//				exit(0);
//			}
//			else
//			{
//				CursorJump(2 * (COL / 3), ROW / 2 + 5);
//				printf("选择错误，请再次选择");
//			}
//		}
//	}
//}
////打印蛇与覆盖蛇
//void DrawSnake(int flag)
//{
//	if (flag == 1) //打印蛇
//	{
//		color(10); //颜色设置为绿色
//		CursorJump(2 * snake.x, snake.y);
//		printf("■"); //打印蛇头
//		for (int i = 0; i < snake.len; i++)
//		{
//			CursorJump(2 * body[i].x, body[i].y);
//			printf("□"); //打印蛇身
//		}
//	}
//	else //覆盖蛇
//	{
//		if (body[snake.len - 1].x != 0) //防止len++后将(0, 0)位置的墙覆盖
//		{
//			//将蛇尾覆盖为空格即可
//			CursorJump(2 * body[snake.len - 1].x, body[snake.len - 1].y);
//			printf("  ");
//		}
//	}
//}
////移动蛇
//void MoveSnake(int x, int y)
//{
//	DrawSnake(0); //先覆盖当前所显示的蛇
//	face[body[snake.len - 1].y][body[snake.len - 1].x] = KONG; //蛇移动后蛇尾重新标记为空
//	face[snake.y][snake.x] = BODY; //蛇移动后蛇头的位置变为蛇身
//	//蛇移动后各个蛇身位置坐标需要更新
//	for (int i = snake.len - 1; i > 0; i--)
//	{
//		body[i].x = body[i - 1].x;
//		body[i].y = body[i - 1].y;
//	}
//	//蛇移动后蛇头位置信息变为第0个蛇身的位置信息
//	body[0].x = snake.x;
//	body[0].y = snake.y;
//	//蛇头的位置更改
//	snake.x = snake.x + x;
//	snake.y = snake.y + y;
//	DrawSnake(1); //打印移动后的蛇
//}
////执行按键
//void run(int x, int y)
//{
//	int t = 0;
//	while (1)
//	{
//		if (t == 0)
//			t = 3000; //这里t越小，蛇移动速度越快（可以根据次设置游戏难度）
//		while (--t)
//		{
//			if (kbhit() != 0) //若键盘被敲击，则退出循环
//				break;
//		}
//		if (t == 0) //键盘未被敲击
//		{
//			JudgeFunc(x, y); //判断到达该位置后，是否得分与游戏结束
//			MoveSnake(x, y); //移动蛇
//		}
//		else //键盘被敲击
//		{
//			break; //返回Game函数读取键值
//		}
//	}
//}
////游戏主体逻辑函数
//void Game()
//{
//	int n = RIGHT; //开始游戏时，默认向后移动
//	int tmp = 0; //记录蛇的移动方向
//	goto first; //第一次进入循环先向默认方向前进
//	while (1)
//	{
//		n = getch(); //读取键值
//		//在执行前，需要对所读取的按键进行调整
//		switch (n)
//		{
//		case UP:
//		case DOWN: //如果敲击的是“上”或“下”
//			if (tmp != LEFT && tmp != RIGHT) //并且上一次蛇的移动方向不是“左”或“右”
//			{
//				n = tmp; //那么下一次蛇的移动方向设置为上一次蛇的移动方向
//			}
//			break;
//		case LEFT:
//		case RIGHT: //如果敲击的是“左”或“右”
//			if (tmp != UP && tmp != DOWN) //并且上一次蛇的移动方向不是“上”或“下”
//			{
//				n = tmp; //那么下一次蛇的移动方向设置为上一次蛇的移动方向
//			}
//		case SPACE:
//		case ESC:
//		case 'r':
//		case 'R':
//			break; //这四个无需调整
//		default:
//			n = tmp; //其他键无效，默认为上一次蛇移动的方向
//			break;
//		}
//	first: //第一次进入循环先向默认方向前进
//		switch (n)
//		{
//		case UP: //方向键：上
//			run(0, -1); //向上移动（横坐标偏移为0，纵坐标偏移为-1）
//			tmp = UP; //记录当前蛇的移动方向
//			break;
//		case DOWN: //方向键：下
//			run(0, 1); //向下移动（横坐标偏移为0，纵坐标偏移为1）
//			tmp = DOWN; //记录当前蛇的移动方向
//			break;
//		case LEFT: //方向键：左
//			run(-1, 0); //向左移动（横坐标偏移为-1，纵坐标偏移为0）
//			tmp = LEFT; //记录当前蛇的移动方向
//			break;
//		case RIGHT: //方向键：右
//			run(1, 0); //向右移动（横坐标偏移为1，纵坐标偏移为0）
//			tmp = RIGHT; //记录当前蛇的移动方向
//			break;
//		case SPACE: //暂停
//			system("pause>nul"); //暂停后按任意键继续
//			break;
//		case ESC: //退出
//			system("cls"); //清空屏幕
//			color(7); //颜色设置为白色
//			CursorJump(COL - 8, ROW / 2);
//			printf("  游戏结束  ");
//			CursorJump(COL - 8, ROW / 2 + 2);
//			exit(0);
//		case 'r':
//		case 'R': //重新开始
//			system("cls"); //清空屏幕
//			main(); //重新执行主函数
//		}
//	}
//}


