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
//	int a = 10;
//	int* pa = &a;
//	//&a取出a的第一个字节的地址(较小的地址)
//	//pa --- 指针变量 --- 用来存放地址的变量
//	printf("a的地址是:%p\n", &a);//使用%p输出a的地址
//	printf("a的地址是:%p\n", pa);
//	printf("修改前a的值是:%d\n", a);
//	*pa = 20;
//	printf("修改后a的值是:%d\n", a);
//	printf("修改后a的地址是:%p\n", pa);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	printf("修改前a的地址是:%p\n", &a);//使用%p输出a的地址
//	printf("修改前a的值是:%d\n", a);
//	a = 20;
//	printf("修改后a的值是:%d\n", a);
//	printf("修改后a的地址是:%p\n", &a);
//	return 0;
//}


//#include <stdio.h>
//int main() 
//{
//    int num = 10;
//    int* pa = &num;//定义一个整型指针pa并指向num,pa的类型是int
//    //pa里存储的是变量num的地址,使用解引用操作符来访问。
//    printf("a = %d\n", *pa);
//    return 0;
//}


//指针类型决定解引用操作时一次访问几个字节,访问权限的大小
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
//int*  ---- 一次访问4个字节,+1跳过4个字节
//float*---- 4
//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	char* pc = (char*)&a;
//	//因为a是整型,在大多数系统中整型占用4个字节的内存空间
//  //而pc是字符型指针,字符型指针每次移动一个字节,
//  //为了能让pc指向a的内存地址,需要将a的地址强制转换为字符型指针
//	printf("%p\n", pa);
//	printf("%p\n", pa + 1);//跳过4个字节
//	printf("%p\n", pc);
//	printf("%p\n", pc + 1);//跳过1个字节
//	return 0;
//}


//p + 4向高地址走,p - 4向低地址走
//#include<stdio.h>
//int main()
//{
//	int a = 0x11223344;
//	char* pc = (char*)&a;
//	int i = 0;
//	for (i = 0;i < 4;i++)
//	{
//		*pc = 0;
//		pc++;//pc向右移动
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


//#include <stdio.h>
//int main() 
//{
//    int* ptr;  // 初始化为 NULL
//    int num = 10;
//    ptr = &num;  // 指向有效的地址
//    printf("%d\n", *ptr);
//    return 0;
//}


//#include <stdio.h>
//int main()
//{
//    int* ptr;//未初始化的指针
//    *ptr = 10;//错误:使用野指针
//    return 0;
//}


//数组越界访问
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;//数组名是数组首元素的地址
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0;i <= sz;i++)//i==sz访问时超出数组下标的范围
//	{
//		printf("%d ", *p);
//		p++;//p向右移动
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	char* p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0;i < sz * 4;i++)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//	return 0;
//}


//#include <stdio.h>
//int main() 
//{
//    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//    int* p = arr + sizeof(arr) / sizeof(arr[0]) - 1; 
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    int i = 0;
//    for (i = 0; i < sz; i++) 
//    {
//        printf("%d ", *p);
//        p--;
//    }
//    printf("\n");
//    return 0;
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
//	int* p = test();
//	printf("hehe\n");//函数栈帧被破坏
//	printf("%d\n", *p);
//	//printf("hehe\n");//函数栈帧被破坏
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	printf("hehe\n");
//	printf("%d\n", *pa);
//}

//#include <stdio.h>
//
//int main() 
//{
//    int* ptr = NULL;//初始化为 NULL
//    int num = 10;
//    ptr = &num;//指向有效的地址
//    printf("%d\n", *ptr);
//    return 0;
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


//指针+-整数;指针的关系运算
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
//	return 0;
//}


//指针-指针
//前提:两个指针要指向同一块空间
//指针-指针的绝对值得到的是两个指针之间的元素个数
//#include<stdio.h>
//int main()
//{
//	char ch[5] = { 0 };
//	int arr[10] = { 0 };
//	printf("%d\n", &arr[9] - &arr[0]);
//	//printf("%d\n", &arr[0] - &ch[4]);//代码错误,两个指针要指向同一块空间
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
//1.计数器
//2.递归
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr[] = "abcdef";
//	int len = strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}


//指针-指针
//#include<stdio.h>
//int* my_strlen(char* s)
//{
//	char* start = s;
//	while (*start != '\0')
//	{
//		start++;
//	}
//	return start - s;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}


//计数器
//#include<stdio.h>
//int my_strlen(char* str)
//{
//	int count = 0;
//	while(*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}


//允许指向数组元素的指针与指向数组最后一个元素后面的那个内存位置的指针比较
//不允许与指向第一个元素之前的那个内存位置的指针进行比较
//建议指针向后越界
//超出范围,但是没有访问
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
//指针和数组是不同的对象
//指针是一种变量,存放地址的,大小4/8字节
//数组是一组相同类型元素的集合,是可以放多个元素的,大小是取决于元素个数和元素类型
//数组的数组名是数组首元素的地址,地址是可以放在指针变量中的
//可以通过数组访问指针
//arr[i] == *(arr + i) == i[arr] == *(i + arr)
//[]是个操作符,arr和i是[]的操作数,交换律
//第一种方法
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	int *p = arr;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//赋值
//	for (i = 0;i < sz;i++)
//	{
//		*p = i + 1;
//		p++;
//	}
//	p = arr;
//	//输出
//	for (i = 0;i < sz;i++)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//	return 0;
//}


//第二种方法
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//赋值
//	for (i = 0;i < sz;i++)
//	{
//		*p++ = i + 1;
//	}
//	p = arr;
//	//输出
//	for (i = 0;i < sz;i++)
//	{
//		printf("%d ", *p++);
//	}
//	return 0;
//}


//第三种方法
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//赋值
//	for (i = 0;i < sz;i++)
//	{
//		*(p + i) = i + 1;//p不发生变化,i变化
//	}
//	//输出
//	for (i = 0;i < sz;i++)
//	{
//		//printf("%d ", *(p + i));
//		//printf("%d ", *(arr + i));
//		//printf("%d ", *(i + arr));
//		printf("%d ", i[arr]);
//	}
//	return 0;
//}


//二级指针
//存放一级指针变量的地址
//#include<stdio.h>
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


//#include<stdio.h>
//void print1(int arr[3][4], int r, int c)
//{
//	int i = 0;
//	for (i = 0;i < r;i++)
//	{
//		int j = 0;
//		for (j = 0;j < c;j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//void print2(int (*p)[4], int r, int c)
//{
//	int i = 0;
//	for (i = 0;i < r;i++)
//	{
//		int j = 0;
//		for (j = 0;j < c;j++)
//		{
//			//printf("%d ", (*p)[j]+i);
//			//printf("%d ", (*(p + i))[j]);
//			printf("%d ", p[i][j]);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][4] = { {1,2,3,4},{2,3,4,5},{3,4,5,6} };
//	//print1(arr, 3, 4);
//	print2(arr, 3, 4);
//	return 0;
//}


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



