#define _CRT_SECURE_NO_WARNINGS 1 

//函数
//在计算机科学中,子程序是一个大型程序中的某部分代码,由一个或多个语句块组成。
//它负责完成某项特定任务,而且相较于其他代码,具备相对的独立性。
//一般会有输入参数并有返回值,提供对过程的封装和细节的隐藏。
//这些代码通常被集成为软件库。
//函数的语法形式
//C语言中的函数就是⼀个完成某项特定的任务的⼀小段代码,这段代码是有特殊的写法和调用方法的。 
//C语言的程序其实是由⽆数个小的函数组合⽽成的
//⼀个⼤的计算任务可以分解成若⼲个较小的函数(对应较小的任务)完成
//同时⼀个函数如果能完成某项特定任务的话,这个函数也是可以复用的
//库函数
//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	char arr1[20] = { 0 };
//	char arr2[] = "Hello world";
//	strcpy(arr1, arr2);//字符串拷贝
//	printf("%s\n", arr1);
//	return 0;
//}


//数组名是地址,不能被赋值
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr[20] = "hello world";
//	memset(arr, 'x', 5);
//	printf("%s\n", arr);
//	return 0;
//}


//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	printf("%.1lf\n", sqrt(16.0));
//	return 0;
//}


//自定义函数
//其实自定义函数和库函数是⼀样的,形式如下：
//ret_type fun_name(形式参数)
//{
//	statement;函数体
//}
//ret_type --- 返回类型 fun_name ---- 函数名
//实际参数就是真实传递给函数的参数
//不会向内存申请空间,不会真实存在的,所以叫形式参数。
//形式参数只有在函数被调用的过程中为了存放实参传递过来的值,才向内存申请空间
//这个过程就是形参的实例化
//形式参数是指函数名后括号中的变量
//形式参数只有在函数被调用的过程中才实例化(分配内存单元)所以叫形式参数。
//形式参数当函数调用完成之后就自动销毁了。因此形式参数只在函数中有效
//形参和实参各⾃是独立的内存空间
//x和y确实得到了a和b的值,但是x和y的地址和a和b的地址是不⼀样的
//形参是实参的⼀份临时拷贝
#include<stdio.h>
int Max(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}
}
int main()
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);
	int max = Max(num1, num2);
	printf("%d\n", max);
	return 0;
}


//#include<stdio.h>
//
//void temp(int* x, int* y)//形参
//{
//	*x = *x + *y;
//	*y = *x - *y;
//	*x = *x - *y;
//}
//int main()
//{
//	int num1,num2;
//	scanf("%d %d", &num1, &num2);
//	printf("交换前:num1 = %d,num2 = %d\n", num1, num2);
//	temp(&num1, &num2);//实参
//	printf("交换后:num1 = %d num2 = %d\n", num1, num2);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	*pa = 20;
//	printf("%d\n", a);
//}


//#include<stdio.h>
//
//int Add(int x, int y)//形参
//{
//	return x + y;
//}
//int main()
//{
//	int num1, num2;
//	scanf("%d %d", &num1, &num2);
//	int a = Add(num1, num2);//函数调用,实参
//	printf("%d\n", a);
//	return 0;
//}


//使用函数求解两个数的最大公因数和最小公倍数之和
//#include<stdio.h>
////求解两个数的最小公倍数
//long long gongbeishu(long long x, long long y)
//{
//	while (y != 0)
//	{
//		int a = 0;
//		a = x % y;
//		x = y;
//		y = a;
//	}
//	return x;
//}
////求解两个数的最大公因数
//int gongyinshu(long long j, long long k, long long l)
//{
//	return (j * k) / l;
//}
//int main()
//{
//	long long num1, num2;
//	scanf("%lld %lld", &num1, &num2);
//	//两个数交换位置
//	if (num1 < num2)
//	{
//		num1 = num1 + num2;
//		num2 = num1 - num2;
//		num1 = num1 - num2;
//	}
//	long long m = gongbeishu(num1, num2);
//	long long n = gongyinshu(num1, num2, m);
//	printf("%lld\n", m + n);
//	return 0;
//}


//传值调用
//函数的形参和实参分别占有不同内存块，对形参的修改不会影响实参。
//传址调用
//传址调用是把函数外部创建变量的内存地址传递给函数参数的一种调用函数的方式。
//这种传参方式可以让函数和函数外边的变量建立起真正的联系
//函数内部可以直接操作函数外部的变量。
//#include<stdio.h>
//int is_leap_year(int x)
//{
//	if ((x % 4 == 0 && x % 100 != 0) || x % 400 == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	int year = 0;
//	for (year = 1000;year <= 2000;year++)
//	{
//		if (is_leap_year(year))
//		{
//			printf("%d ",year);
//		}
//	}
//	return 0;
//}


//使用函数写出100~200之间的素数
//#include<stdio.h>
//#include<math.h>
//int is_prime(int x)
//{
//	int j = 0;
//	for (j = 2;j <= sqrt(x);j++)
//	{
//		if (x % j == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	int i = 0;
//	for (i = 101;i <= 200;i+=2)
//	{
//		if (is_prime(i))
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}


//写一个函数,实现整型有序数组的二分查找
//#include<stdio.h>
//int binary_search(int arr[], int x, int y)//形参名字可以和实参相同
//{
//	int left = 0;
//	int right = y - 1;
//	int flag = 0;
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
//		if (arr[mid] < x)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > x)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			flag = 1;
//			return mid;
//		}
//	}
//	if (flag == 0)
//	{
//		return -1;
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 6;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = binary_search(arr, k, sz);
//	if (ret == -1)
//	{
//		printf("找不到\n");
//	}
//	else
//	{
//		printf("找到了,下标是:%d\n", ret);
//	}
//	return 0;
//}


//写一个函数,每调用一次num增加1
//#include<stdio.h>
//void Add(int* x)
//{
//	//*x = *x + 1;
//	(*x)++;
//}
//int main()
//{
//	int num = 0;
//	Add(&num);
//	printf("%d\n", num);
//	return 0;
//}


//#include<stdio.h>
//int Add(int n)
//{
//	return n + 1;
//}
//int main()
//{
//	int num = 0;
//	int ret = Add(num);
//	printf("%d\n", ret);
//	return 0;
//}


//函数的返回的类型不写是默认返回int类型
//#include<stdio.h>
//
//int test()
//{
//	printf("hehehe\n");
//}
//int main()
//{
//	int ret = test();
//	printf("%d\n", ret);
//	return 0;
//}


//return后边可以是⼀个数值,也可以是⼀个表达式,如果是表达式则先执⾏表达式,返回表达式的结果。
//return后边也可以什么都没有,直接写return;这种写法适合函数返回类型是void的情况。
//return语句执⾏后,函数就彻底返回,后边的代码不再执⾏。
//return返回的值和函数返回类型不⼀致,系统会⾃动将返回的值隐式转换为函数的返回类型。
//如果函数中存在if等分⽀的语句,则要保证每种情况下都有return返回,否则会出现编译错误。
//函数的返回类型如果不写,编译器会默认函数的返回类型是int。
//函数写了返回类型,但是函数中没有使⽤return返回值,那么函数的返回值是未知的。
//#include<stdio.h>
//void print()//没有返回值
//{
//	printf("hehe\n");
//}
//
//int main()
//{
//	print();
//	return 0;
//}


//数组做函数参数
//写一个函数,将数组的内容全部置为-1,并输出
//#include<stdio.h>
//int set_arr(int arr[],int m)
//{
//	int i = 0;
//	for (i = 0;i < m;i++)
//	{
//		arr[i] = -1;
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	set_arr(arr,sz);
//	return 0;
//}


//函数的嵌套调用和链式访问
//嵌套调用
//函数和函数之间可以根据实际的需求进行组合的,也就是互相调用的
//链式访问
//把一个函数的返回值作为另外一个函数的参数。
//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	printf("%d\n", strlen("abcdef"));
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	printf("%d", printf("%d", printf("%d", 43)));
//	return 0;
//}


//函数声明:
//告诉编译器有一个函数叫什么,参数是什么,返回类型是什么。
//但是具体是不是存在,函数声明决定不了。
//函数的声明一般出现在函数的使用之前。要满足先声明后使用。
//函数的声明一般要放在头文件中的。
//函数定义:
//函数的定义是指函数的具体实现，交待函数的功能实现
//#include "Add.h"
//#include<stdio.h>
//int main()
//{
//	int num1 = 0;
//	int num2 = 0;
//	scanf("%d %d", &num1, &num2);
//	int ret = Add(num1, num2);
//	printf("%d\n", ret);
//	return 0;
//}


//变量的声明 --- 名字和类型
//全局变量不初始化默认是0
//#include<stdio.h>
//int g_val;
//
//int main()
//{
//	printf("g_val = %d\n", g_val);
//	return 0;
//}
//
//int g_val = 2022;


//程序调用自身的编程技巧称为递归。
//递归做为一种算法在程序设计语言中广泛应用。 
//一个过程或函数在其定义或说明中有直接或间接调用自身的一种方法。
//它通常把一个大型复杂的问题层层转化为一个与原问题相似的规模较小的问题来求解，
//递归策略
//只需少量的程序就可描述出解题过程所需要的多次重复计算，大大地减少了程序的代码量。
//递归的主要思考方式在于:大事化小
//递归的两个必要条件
//存在限制条件，当满足这个限制条件的时候，递归便不再继续。
//每次递归调用之后越来越接近这个限制条件。
//每一次调用函数,都会为本次函数在内存的栈区上开辟一块内存空间。
//#include<stdio.h>
//
//int main()
//{
//	printf("hehe\n");
//	main();
//	return 0;
//}


//正序输出
//#include<stdio.h>
//void print(unsigned int n)
//{
//	if (n > 9)
//	{
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//int main()
//{
//	unsigned int num = 0;
//	scanf("%d", &num);
//	print(num);
//	return 0;
//}


//编写函数不允许创建临时变量,求字符串的长度
//数组名其实是首元素的地址
//字符指针+1,向后跳1个字符
//#include<stdio.h>
//#include<string.h>
//创建临时变量count
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "apple";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}

//不创建临时变量
//int my_strlen(char* str)
//{
//	if (*str != '\0')
//	{
//		return 1 + my_strlen(1 + str);
//	}
//	else
//	{
//		return 0;
//	}
//}

//int main()
//{
//	char arr[] = "apple";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}


//函数栈帧
//每一次函数调用都会为本次函数调用分配内存空间(内存的栈区)
//为本次函数调用分配的内存空间叫做被称为这次函数调用的栈帧空间
//求n的阶乘(不考虑溢出)
//#include<stdio.h>
//int Fac(int n)
//{
//	if (n <= 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n * Fac(n - 1);
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Fac(n);
//	return 0;
//}


//#include<stdio.h>
//int Fac(int n)
//{
//	int i = 0;
//	int ret = 1;
//	for (i = 1;i <= n;i++)
//	{
//		ret *= i;
//	}
//	return ret;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Fac(n);
//	printf("%d\n", ret);
//	return 0;
//}


//求第n个斐波那契数列
//1 1 2 3 5 8 13 21 34 55
//第一种方法
//#include<stdio.h>
//int count = 0;
//int Fib(int n)
//{
//	if (n == 3)
//	{
//		count++;
//	}
//	if (n <= 2)
//	{
//		return 1;
//	}
//	return Fib(n - 1) + Fib(n - 2);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Fib(n);
//	printf("%d\n", ret);
//	printf("%d\n", count);
//	return 0;
//}


//斐波那契
//第2种方法
//#include<stdio.h>
//int Fib(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 0;
//	int i = 0;
//	while (n > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return b;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Fib(n);
//	printf("%d\n", ret);
//	return 0;
//}


//汉诺塔问题
//青蛙跳台阶问题


//寄存器
//eax ebx ecx edx ebp esp
//ebp esp
//这2个寄存器中存放的是地址,这2个地址是用来维护函数栈帧的
//每一个函数调用,都要在栈区中创建空间。
//#include<stdio.h>
//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 0;
//	c = Add(a, b);
//	printf("%d\n", c);
//	return 0;
//}


