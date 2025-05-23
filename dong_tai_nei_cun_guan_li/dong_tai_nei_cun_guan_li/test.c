#define _CRT_SECURE_NO_WARNINGS 1 

//#include<stdio.h>
//int main()
//{
//	int arr[10] = 0;
//	return 0;
//}


//malloc
//free
//calloc
//realloc
//栈区     局部变量  函数的形式参数
//堆区     动态内存管理
//静态区   静态变量 全局变量

//malloc
//申请一块内存空间
//void* 没有具体类型的值
//#include <stdio.h>
//#include <stdlib.h>
//#include <errno.h>
//#include <string.h>
//int main()
//{
//	//申请40个字节,用来存放10个整型
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	//存放1~10
//	int i = 0;
//	for (i = 0;i < 10;i++)
//	{
//		*(p + i) = i + 1;
//	}
//	for (i = 0;i < 10;i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	printf("\n");
//	//free释放申请的内存
//	free(p);
//	p = NULL;
//	return 0;
//}


//calloc
//#include <stdio.h>
//#include <stdlib.h>
//#include <errno.h>
//#include <string.h>
//int main()
//{
//	int* p = calloc(10, sizeof(int));
//	if (NULL == p)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	int i = 0;
//	for (i = 0;i < 10;i++)
//	{
//		*(p + i) = i + 1;
//	}
//	for (i = 0;i < 10;i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	printf("\n");
//	free(p);
//	p = NULL;
//	return 0;
//}


//malloc申请的空间没有初始化,直接返回起始地址  ---- 效率高
//calloc申请好空间会把空间初始化为0,然后返回起始地址 ---- 效率低
//realloc
//直接在后面续上新的空间,返回旧的起始地址
//当后面没有足够的空间可以扩容时,realloc会找一块满足空间大小的新的连续空间
//把旧的空间的数据拷贝到新空间前面的位置,如果开辟成功
//并且把旧的空间释放掉,同时返回新的空间的地址
//如果传的是空指针,则相当于malloc
//#include <stdio.h>
//#include <stdlib.h>
//#include <errno.h>
//#include <string.h>
//int main()
//{
//	//int* p = (int*)realloc(NULL, 5 * sizeof(int));//相当于malloc
//	int* p = (int*)malloc(5 * sizeof(int));
//	if (NULL == p)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	int i = 0;
//	//使用
//	for (i = 0;i < 5;i++)
//	{
//		*(p + i) = i;
//	}
//	//不够了,使用realloc添加空间
//	int* ptr = (int*)realloc(p, 15 * sizeof(int));
//	if (NULL == ptr)
//	{
//		//printf("%s\n", strerror(errno));
//		perror("ptr");
//		return 1;
//	}
//	else
//	{
//		p = ptr;
//	}
//	for (i = 5;i < 15;i++)
//	{
//		*(p + i) = i;
//	}
//	for (i = 0;i < 15;i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	printf("\n");
//	//释放空间
//	free(p);
//	p = NULL;
//	return 0;
//}


//对NULL指针的解引用操作
//#include <stdio.h>
//#include <stdlib.h>
//void test()
//{
//	int* p = (int*)malloc(INT_MAX / 4);
//	*p = 20;//如果p的值是NULL，就会有问题
//	free(p);
//}
//int main()
//{
//	test();
//	return 0;
//}


//对动态开辟空间的越界访问
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int* p = (int*)malloc(100);
//	if (NULL == p)
//	{
//		return 1;
//	}
//	int i = 0;
//	for (i = 0;i < 100;i++)
//	{
//		*(p + i) = i + 1;
//	}
//	for (i = 0;i < 100;i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}


//对非动态开辟内存使用free释放
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int a = 10;
//	int* p = &a;
//	free(p);
//	p = NULL;
//	return 0;
//}


//使用free释放一块动态开辟内存的一部分
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int* p = (int*)malloc(100);
//	p++;
//	free(p);//free释放p指针的起始位置
//	return 0;
//}


//对同一块动态内存多次释放
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int* p = (int*)malloc(100);
//	if (p == NULL)
//	{
//		return 1;
//	}
//	free(p);//free释放p指针的起始位置
//	free(p);
//	return 0;
//}


//动态开辟内存忘记释放(内存泄漏)
//函数内部进行了malloc操作,返回了malloc开辟空间的起始地址
//#include <stdio.h>
//#include <stdlib.h>
//int* test()
//{
//	int* p = (int*)malloc(100);
//	if (NULL == p)
//	{
//		return 1;
//	}
//	return p;
//}
//int main()
//{
//	int ptr = test();
//	free(ptr);
//	ptr = NULL;
//}
//

//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	while (1)
//	{
//		int* p =(int*)malloc(1);
//		//free(p);
//	}
//	return 0;
//}


//malloc与free成对出现,但没有执行
//#include <stdio.h>
//#include <stdlib.h>
//void test()
//{
//	int* p = (int*)malloc(100);
//	if (NULL == p)
//	{
//		return;
//	}
//	if (1)
//		return;
//	free(p);
//	p = NULL;
//}
//int main()
//{
//	test();
//	return 0;
//}


//str传给p的时候,p是str的临时拷贝,有自己独立的空间,当Getmemory函数内部申请了空间后
//地址放在p中,str依然是空指针,当Getmemory函数返回后,strcpy拷贝的时候,形参非法访问内存
//在Getmemory函数内部,动态申请了内存,但是没有释放,会内存泄漏
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}


//修改
//方法1
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//char* GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory(str);
//	strcpy(str, "hello world");
//	printf("%s\n", str);
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}


//方法2
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//void GetMemory(char** p)
//{
//	*p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}


//printf
//#include<stdio.h>
//int main()
//{
//	//printf("hehe\n");
//	char* p = "hehe";
//	printf(p);
//	printf("\n");
//	printf("%c\n", *p);
//	return 0;
//}


//非法访问内存
//返回栈空间地址的问题
//#include <stdio.h>
//char* GetMemory(void)
//{
//	char p[] = "hello world";
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}


//修改
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//char* GetMemory(void)
//{
//	char* p = (char*)malloc(strlen("hello world") + 1);
//	if (p != NULL)
//	{
//		strcpy(p, "hello world");
//		return p;
//	}
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//	free(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}


//#include <stdio.h>
//int* test()
//{
//	int a = 10;
//	return &a;
//}
//int main()
//{
//	int* p = test();
//	printf("hehe\n");
//	printf("%d\n", *p);
//}


//#include <stdio.h>
//#include <stdlib.h>
//int* test()
//{
//	int* a = (int*)malloc(40);
//	if (a != NULL)
//	{
//		*a = 10;
//		return a;
//	}
//}
//int main()
//{
//	int* p = test();
//	printf("hehe\n");
//	printf("%d\n", *p);
//	free(p);
//	return 0;
//}


//内存泄漏
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}


//修改
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//}
//int main()
//{
//	Test();
//	return 0;
//}


//修改
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);
//	str = NULL;
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//}
//int main()
//{
//	Test();
//	return 0;
//}


//C/C++程序内存分配的几个区域:
//栈区:在执行函数时,函数内局部变量的存储单元都可以在栈上创建,
//函数执行结束时这些存储单元自动被释放。
//栈内存分配运算内置于处理器的指令集中,效率很高,但是分配的内存容量有限。 
//栈区主要存放运行函数而分配的局部变量、函数参数、返回数据、返回地址等。
//
//堆区:一般由程序员分配释放,若程序员不释放,程序结束时可能由OS回收,分配方式类似于链表。
//
//数据段(静态区):存放全局变量、静态数据。程序结束后由系统释放。
//
//代码段:存放函数体(类成员函数和全局函数)的二进制代码。
//实际上普通的局部变量是在栈区分配空间的,栈区的特点是在上面创建的变量出了作用域就销毁。
//但是被static修饰的变量存放在数据段(静态区),数据段的特点是在上面创建的变量,
//直到程序结束才销毁,所以生命周期变长。


//柔性数组
//结构中的柔性数组成员前面必须至少一个其他成员
//sizeof 返回的这种结构大小不包括柔性数组的内存
//包含柔性数组成员的结构用malloc()函数进行内存的动态分配
//并且分配的内存应该大于结构的大小,以适应柔性数组的预期大小
//方法1
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//struct S
//{
//	int n;
//	char arr[];//或者char arr[0];数组大小是未知的
//};
//int main()
//{
//	printf("%zd\n", sizeof(struct S));
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 10 * sizeof(char));//数组大小可调整
//	ps->n = 100;
//	int i = 0;
//	for (i = 0;i < 10;i++)
//	{
//		ps->arr[i] = 'q' + i;
//	}
//	for (i = 0;i < 10;i++)
//	{
//		printf("%c ", ps->arr[i]);
//	}
//	printf("\n");
//	//增容
//	struct S* ptr = (struct S*)realloc(ps, 10 * sizeof(char));
//	if (ptr != NULL)
//	{
//		ps = ptr;
//	}
//	else
//	{
//		perror("ptr");
//		return 1;
//	}
//	free(ps);
//	ps = NULL;
//	return 0;
//}


//方法2
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//struct S
//{
//	int n;
//	char* arr;
//};
//int main()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S));
//	if (ps == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//	ps->n = 100;
//	ps->arr = (char*)malloc(sizeof(char) * 10);
//	if (ps->arr == NULL)
//	{
//		perror("malloc->arr");
//		return 1;
//	}
//	int i = 0;
//	for (i = 0;i < 10;i++)
//	{
//		ps->arr[i] = 'q' + i;
//	}
//	for (i = 0;i < 10;i++)
//	{
//		printf("%c ", ps->arr[i]);
//	}
//	printf("\n");
//	char* ptr = (char*)realloc(ps->arr, 10 * sizeof(char));
//	if (ptr != NULL)
//	{
//		ps->arr = ptr;
//	}
//	else
//	{
//		perror("realloc->ptr");
//		return 1;
//	}
//	free(ps->arr);
//	ps->arr = NULL;
//	free(ps);
//	ps = NULL;
//	return 0;
//}


//上述代码1和代码2可以完成同样的功能,但是方法1的实现有两个好处:
//方便内存释放
//如果我们的代码是在一个给别人用的函数中,你在里面做了二次内存分配,并把整个结构体返回给用户。
//用户调用free可以释放结构体,但是用户并不知道这个结构体内的成员也需要free,
//所以你不能指望用户来发现这个事。所以,如果我们把结构体的内存以及其成员要的内存一次性分配好了,
//并返回给用户一个结构体指针,用户做一次free就可以把所有的内存也给释放掉
//有利于访问速度
//连续的内存有益于提高访问速度,也有益于减少内存碎片

