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


//指针的关系运算
//#include <stdio.h>
//int main() 
//{
//    int arr[5] = { 1, 2, 3, 4, 5 };
//    int* ptr1 = &arr[0];
//    int* ptr2 = &arr[2];
//    //比较两个指针的大小
//    if (ptr1 < ptr2) 
//    {
//        printf("ptr1指向的元素在ptr2指向的元素之前\n");
//    }
//    else 
//    {
//        printf("ptr1指向的元素在ptr2指向的元素之后\n");
//    }
//    // 检查指针是否相等
//    if (ptr1 == ptr2) 
//    {
//        printf("ptr1和ptr2指向同一个元素\n");
//    }
//    else 
//    {
//        printf("ptr1和ptr2指向不同的元素\n");
//    }
//    //检查指针是否为空
//    if (ptr1 != NULL) 
//    {
//        printf("ptr1不是空指针\n");
//    }
//    return 0;
//}


//#include <stdio.h>
//
//int main() 
//{
//    int arr[5] = { 10, 20, 30, 40, 50 };
//    int* ptr = &arr[0]; //指针ptr指向数组的第一个元素
//    printf("指针初始指向的值:   %d,地址:%p\n", *ptr, (void*)ptr);
//    ptr++;//指针向前移动一个位置,指向数组的第二个元素
//    printf("指针移动后指向的值: %d,地址:%p\n", *ptr, (void*)ptr);
//    return 0;
//}


//#include <stdio.h>
//int main() 
//{
//    int arr[5] = { 10, 20, 30, 40, 50 };
//    int* ptr = arr; //指针ptr指向数组的第一个元素
//    //输出ptr初始指向的值
//    printf("初始时,ptr指向的值:%d\n",*ptr);
//    //指针ptr加2
//    ptr = ptr + 2;
//    // 输出ptr加2后指向的值
//    printf("ptr加2后,指向的值:%d\n", *ptr);
//    return 0;
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


//#include <stdio.h>
//
//int main() 
//{
//    int arr[5] = { 10, 20, 30, 40, 50 };
//    int* ptr = &arr[4]; //指针ptr指向数组的第5个元素
//    printf("指针初始指向的值:   %d,地址:%p\n", *ptr, (void*)ptr);
//    ptr--;//指针向前移动一个位置,指向数组的第4个元素
//    printf("指针移动后指向的值: %d,地址:%p\n", *ptr, (void*)ptr);
//    return 0;
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


//#include <stdio.h>
//int main() 
//{
//    int arr[5] = { 1, 2, 3, 4, 5 };
//    int* ptr = arr;
//    //指向数组最后一个元素后面的那个内存位置
//    int* end = arr + 5;
//    while (ptr < end) 
//    {
//        printf("%d ", *ptr);
//        ptr++;
//    }
//    printf("\n");
//    return 0;
//}


//#include <stdio.h>
//int main() 
//{
//    int arr[5] = { 1, 2, 3, 4, 5 };
//    int* ptr = arr;
//    //错误示例:指向第一个元素之前的那个内存位置
//    int* before_start = arr - 1;
//    //下面这行代码会产生未定义行为
//    if (ptr > before_start) 
//    { 
//        printf("错误的比较\n");
//    }
//    return 0;
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
//	printf("%p\n", ppa);
//	printf("%p\n", *ppa);
//	printf("%d\n", **ppa);
//	return 0;
//}


//#include<stdio.h>
//
//int main()
//{
//	int a = 10;
//	int* pa = &a;//pa是一级指针变量
//	int** ppa = &pa;//二级指针,第一颗*表示pa的类型是int *,第二颗*表示指针
//	printf("%p\n", ppa);
//	printf("%p\n", *ppa);
//	printf("%d\n", **ppa);
//	return 0;
//}


//指针数组是存放指针的数组
//#include<stdio.h>
//int main()
//{
//	int* ptr_array[5];
//	return 0;
//}


//逐个元素初始化
//#include <stdio.h>
//int main() 
//{
//    int a = 10, b = 20, c = 30;
//    int* ptr_array[3];
//    ptr_array[0] = &a;
//    ptr_array[1] = &b;
//    ptr_array[2] = &c;
//    return 0;
//}


//整体初始化
//#include <stdio.h>
//int main() 
//{
//    int a = 10, b = 20, c = 30;
//    int* ptr_array[3] = { &a, &b, &c };
//    return 0;
//}


//字符数组是存放字符的数组
//#include<stdio.h>
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
//	printf("\n");
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
//			//printf("%d ", arr[i][j]);//+j向后偏移j个元素
//			printf("%2d ", *(arr[i] + j));//+j向后偏移j个元素
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
//	//hello world是常量字符串
//	char* p = "hello world";//p里放的hello world\0中首字符的地址
//	printf("%s\n", p);
//	printf("%c\n", *p);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	//hello world是常量字符串
//	const char* p = "hello world";//p里放的hello world\0中首字符的地址
//	char* pa = &p;
//	*pa = 'a';
//	printf("%c\n", *pa);
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


//两个数组的起始位置不相同
//数组名表示数组首元素的地址
//这里str3和str4指向的是一个同一个常量字符串。
//C/C++会把常量字符串存储到单独的一个内存区域
//当几个指针指向同一个字符串的时候,他们实际会指向同一块内存。
//但是用相同的常量字符串去初始化不同的数组的时候就会开辟出不同的内存块。
//所以str1和str2不同,str3和str4不同。
//#include <stdio.h>
//int main()
//{
//	char str1[] = "hello world.";
//	char str2[] = "hello world.";
//	const char* str3 = "hello world.";
//	const char* str4 = "hello world.";
//	char str5 = "hello world.";
//	char str6 = "hello world.";
//	if (str1 == str2)
//		printf("str1 and str2 are same\n");
//	else
//		printf("str1 and str2 are not same\n");
//	if (str3 == str4)
//		printf("str3 and str4 are same\n");
//	else
//		printf("str3 and str4 are not same\n");
//	if (str5 == str6)
//		printf("str5 and str6 are same\n");
//	else
//		printf("str5 and str6 are not same\n");
//	return 0;
//}


//指针数组
//指针数组 --- 存放指针的数组。
//整形指针 --- 存放整型地址的指针 --- 指向整型的指针
//字符指针 --- 存放字符地址的指针 --- 指向字符的指针
//&数组名VS数组名
//arr是数组名,数组名表示数组首元素的地址。
//int* arr1[10]; //整形指针的数组
//char* arr2[4]; //一级字符指针的数组
//char** arr3[5];//二级字符指针的数组
//#include<stdio.h>
//int main()
//{
//	const char* arr[4] = { "abcdef","qwer","hello","hehe" };
//	char** pa = arr;
//	int i = 0;
//	for (i = 0;i < 4;i++)
//	{
//		printf("%s ", arr[i]);
//	}
//	printf("\n");
//	for (i = 0;i < 4;i++)
//	{
//		printf("%c ", *pa[i]);
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
//	int** pa = arr;
//	for (i = 0;i < 4;i++)
//	{
//		int j = 0;
//		for (j = 0;j < 5;j++)
//		{
//			//arr[i][j] == *(arr[i]+j)
//			printf("%d ", pa[i][j]);
//			//printf("%d ", *(pa[i] + j));
//		}
//		printf("\n");
//	}
//	//通过arr输出arr2的元素
//	//for (i = 0;i < 5;i++)
//	//{
//	//	printf("%d ", *(pa[1] + i));
//	//}
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
//	printf("%p\n", &arr[0]);//int*
//	printf("%p\n", &arr[0] + 1);//4
//	printf("%p\n", &arr);//int (*)[10]
//	printf("%p\n", &arr + 1);//40
//	return 0;
//}


//#include<stdio.h>
//
//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int (*ptr1)[5] = &a;
//	printf("%d,%d", *(a), *(a + 4));
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int* ptr = (int*)(&a + 1);
//	//&a是数组的地址, (&a + 1)表示取得是数组最后一个元素的地址
//	printf("%d,%d", *(a + 1), *(ptr - 1));
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


//#include <stdio.h>

// 函数使用数组指针接收一维数组
//void print(int (*arr)[5], int size) 
//{
//    for (int i = 0; i < size; i++)
//    {
//        printf("%d ", (*arr)[i]);
//    }
//    printf("\n");
//}
//int main() 
//{
//    int arr[5] = { 1, 2, 3, 4, 5 };
//    print(&arr, 5);
//    return 0;
//}


//二维数组的首元素是第一行
//二维数组的数组名表示首元素的地址是第一行的地址
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
//			printf("%d ", *(p[i] + j));
//			//printf("%d ", (*(p + i))[j]);
//			//printf("%d ", p[i][j]);
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
//	int (*p)[10] = &arr;
//	return 0;
//}


//int arr[5];                //整型数组,数组是5个元素 
//int* parr1[10];			 //指针数组,数组10个元素,每个元素是int*类型的
//int (*parr2)[10];		 
//数组指针,该指针指向一个数组,数组是10个元素,每个元素是int类型的
//int (*parr3[10])[5];
//parr3是数组,数组有10个元素,数组的每个元素的类型是:int(*)[5]的数组指针类型


//#include <stdio.h>
//void test1(int arr[])
//{
//}
//void test2(int arr[10])
//{
//}
//void test3(int* arr)
//{
//}
//void test4(int* arr[20])
//{
//}
//void test5(int** arr)
//{
//}
//int main()
//{
//	int arr[10] = { 0 };
//	test1(arr);
//	test2(arr);
//	test3(arr);
//	test4(arr);
//	test5(arr);
//	return 0;
//}


//#include <stdio.h>
//void test1(int arr[])
//{
//}
//void test2(int arr[10])
//{
//}
//void test3(int* arr)
//{
//}
//void test4(int* arr[20])
//{
//}
//void test5(int** arr)
//{
//}
//int main()
//{
//    int arr[10] = { 0 };
//    int* arr2[20]; // 定义一个包含20个int*类型元素的数组
//    int** arr3 = &arr2[0]; // 定义一个指向int*类型的指针
//    test1(arr);
//    test2(arr);
//    test3(arr);
//    test4(arr2);
//    test5(arr3);
//    return 0;
//}


//#include <stdio.h>
//void test1(int* arr[20])
//{
//}
//void test2(int** arr)
//{
//}
//int main()
//{
//	int* arr2[20] = { 0 };
//	test1(arr2);
//	test2(arr2);
//	return 0;
//}


//总结：二维数组传参，函数形参的设计只能省略第一个[]的数字。
//因为对一个二维数组,可以不知道有多少行,但是必须知道一列多少元素。
//这样才方便运算。
//#include<stdio.h>
//void test1(int arr[3][5])
//{
//}
//void test2(int arr[][])//error
//{
//}
//void test3(int arr[][5])
//{
//}
//void test4(int* arr)//error
//{
//}
//void test5(int* arr[5])//error,存放指针的数组,和数组无关
//{
//}
//void test6(int (*arr)[5])//ok
//{
//}
//void test7(int** arr)//error
//{
//}
//int main()
//{
//	int arr[3][5] = { 0 };
//	test1(arr);
//	test2(arr);
//	test3(arr);
//	test4(arr);
//	test5(arr);
//	test6(arr);
//	test7(arr);
//	return 0;
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
//	//一级指针p,传给函数
//	print(p, sz);
//	return 0;
//}


//一级指针传参
//函数形参为int*实参可以写成test(arr);test(&a);和test(p);
//#include<stdio.h>
//void test(int* p)
//{
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9 };
//	int a = 10;
//	int* p = &a;
//	test(&a);
//	test(arr);
//	test(p);
//	return 0;
//}


//二级指针传参
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
//	int* arr[10] = { 0 };
//	test(pp);
//	test(arr);
//	test(&p);
//	return 0;
//}


//#include<stdio.h>
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
//	int (*pf)(int, int) = &Add;//pf存放函数地址的指针变量
//	//&函数名和函数名都是函数的地址
//	//int (*pf)(int, int) = Add;//两种写法都一样
//	int ret = (*pf)(2, 3);//可以写成int ret = pf(2, 3);
//	printf("%d\n", ret);
//	return 0;
//}


//#include<stdio.h>
//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int arr[10];
//	int (*p)[10] = arr;
//	printf("%p\n", &Add);
//	printf("%p\n", Add);
//	//int (*pf)(int, int) = &Add;
//  //pf存放函数地址的指针变量
//	////&函数名和函数名都是函数的地址
//	////int (*pf)(int, int) = Add;//两种写法都一样
//	//int ret = (*pf)(2, 3);//可以写成int ret = pf(2, 3);
//	//printf("%d\n", ret);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	const char* c = "hello world";
//	//scanf("%s", &c);
//	printf("%s\n", c);
//	return 0;
//}


//*arr = *(arr+0) = arr[0]
//**arr = *(arr[0]+0) = arr[0][0]
//#include<stdio.h>
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
//	void (*signal ( int, void(*)(int) ) )(int);
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


//#include<stdio.h>
//#define uint unsigned int 
////typedef unsigned int uint;
//int main()
//{
//	uint num = 10;
//	printf("%d\n", num);
//	return 0;
//}


//#include<stdio.h>
//int my_strlen(const char* str)
//{
//	return 0;
//}
//int main()
//{
//	char* ch[5];
//	int arr[10] = { 0 };
//	int (*pa)[10] = &arr;//pa是数组指针
//	int (*pf)(const char*)= &my_strlen;//pf是函数指针
//	//pfA是数组指针--- 函数指针数组
//	int (*pfA[5])(const char*) = { &my_strlen };
//	return 0;
//}


//#include <stdio.h>
//int add(int a, int b) 
//{
//    return a + b;
//}
//int sub(int a, int b) 
//{
//    return a - b;
//}
//int mul(int a, int b) 
//{
//    return a * b;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int main() 
//{
//    //声明一个函数指针数组
//    int (*arr[4])(int, int) = { add, sub, mul, Div };
//    //通过函数指针数组调用函数
//    int result1 = arr[0](3, 4);
//    int result2 = arr[1](3, 4);
//    int result3 = arr[2](3, 4);
//    int result4 = arr[3](3, 4);
//    printf("3 + 4 = %d\n", result1);
//    printf("3 - 4 = %d\n", result2);
//    printf("3 * 4 = %d\n", result3);
//    printf("3 / 4 = %d\n", result4);
//    return 0;
//}


//写一个计算器实现整数的加减乘除
//#include<stdio.h>
//void menu()
//{
//	printf("****************************\n");
//	printf("****** 1.add   2.sub *******\n");
//	printf("****** 3.mul   4.div *******\n");
//	printf("****** 0.exit        *******\n");
//	printf("****************************\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("请输入两个操作数:>");
//			scanf("%d %d", &x, &y);
//			ret = Add(x, y);
//			printf("%d\n", ret);
//			break;
//		case 2:
//			printf("请输入两个操作数:>");
//			scanf("%d %d", &x, &y);
//			ret = Sub(x, y);
//			printf("%d\n", ret);
//			break;
//		case 3:
//			printf("请输入两个操作数:>");
//			scanf("%d %d", &x, &y);
//			ret = Mul(x, y);
//			printf("%d\n", ret);
//			break;
//		case 4:
//			printf("请输入两个操作数:>");
//			scanf("%d %d", &x, &y);
//			ret = Div(x, y);
//			printf("%d\n", ret);
//			break;
//		case 0:
//			printf("退出计算器\n");
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}


//使用函数指针数组
//#include<stdio.h>
//void menu()
//{
//	printf("****************************\n");
//	printf("****** 1.Add   2.Sub *******\n");
//	printf("****** 3.Mul   4.Div *******\n");
//	printf("****** 0.exit        *******\n");
//	printf("****************************\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//int (*pf[5])(int, int) = { NULL,Add,Sub,Mul,Div };
//
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		if (input == 0)
//		{
//			printf("退出计算器\n");
//			break;
//		}
//		else if (input >= 1 && input <= 4)
//		{
//			printf("请输入两个操作数:>");
//			scanf("%d %d", &x, &y);
//			ret = pf[input](x, y);
//			printf("%d\n", ret);
//		}
//		else
//		{
//			printf("选择错误\n");
//		}
//	} while (input);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int arr[10];
//	int (*pA)[10] = &arr;
//	//函数指针数组
//	int (*pf[5])(int, int);
//	//ppf是指向函数指针数组的指针,5表示ppf指向的数组pf有5个元素
//  //+1跳过整个数组
//	int (*(*ppf)[5])(int, int) = &pf;
//	return 0;
//}


//回调函数
//#include<stdio.h>
//void menu()
//{
//	printf("****************************\n");
//	printf("****** 1.add   2.sub *******\n");
//	printf("****** 3.mul   4.div *******\n");
//	printf("****** 0.exit        *******\n");
//	printf("****************************\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//void calc(int (*pf)(int, int))
//{
//	int ret = 0;
//	int x = 0;
//	int y = 0;
//	printf("请输入两个操作数:>");
//	scanf("%d %d", &x, &y);
//	ret = pf(x, y);
//	printf("%d\n", ret);
//}
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			calc(Add);
//			break;
//		case 2:
//			calc(Sub);
//			break;
//		case 3:
//			calc(Mul);
//			break;
//		case 4:
//			calc(Div);
//			break;
//		case 0:
//			printf("退出计算器\n");
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}


//#include<stdio.h>
//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0;i < sz - 1;i++)
//	{
//		int j = 0;
//		for (j = 0;j < sz - 1 - i;j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz);
//	int i = 0;
//	for (i = 0;i < sz;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	float f = 5.5f;
//	int* p = &a;
//	void* pp = &f;
//	//pp = &a;
//	printf("%f\n", *(float*)pp);
//	return 0;
//}


//void qsort(void* base,//排序数组的起始地址
//	size_t num,//元素个数
//	size_t width, //一个元素的大小
//	int(*cmp)(const void* elem1, const void* elem2));//两个元素的比较函数
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0;i < sz - 1;i++)
//	{
//		int j = 0;
//		for (j = 0;j < sz - 1 - i;j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//}
//int cmp_int(const void* e1, const void* e2)
//{
//	//return *(int*)e1 - *(int*)e2;//升序
//	//return *(int*)e2 - *(int*)e1;//降序
//}
////使用qsort对数组进行排序、升序
//void test1()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//bubble_sort(arr, sz);
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);//cmp_int不需要传参
//	int i = 0;
//	for (i = 0;i < sz;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
////排序结构体
//struct Stu
//{
//	char name[20];
//	int age;
//};
//int cmp_stu_by_age(const void* e1, const void* e2)
//{
//	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
//}
//int cmp_stu_by_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct Stu*)e1)->name,((struct Stu*)e2)->name);
//}
//void test2()
//{
//	struct Stu s[3] = { { "zhangsan",20 },{"lisi",50},{"wangwu",33} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	//qsort(s, 3, sizeof(s[0]), cmp_stu_by_age);
//	qsort(s, 3, sizeof(s[0]), cmp_stu_by_name);
//}
//int main()
//{
//	test1();
//	test2();
//	return 0;
//}


//#include<stdio.h>
//void sort(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0;i < sz - 1;i++)
//	{
//		int j = 0;
//		for (j = 0;j < sz - 1 - i;j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 4,3,2,7,5,8,6,1,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	sort(arr, sz);
//	int i = 0;
//	for (i = 0;i < sz;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct lettle
{
    char c;
    int index;
}lettle;
int compare(const void* a, const void* b)
{
    return ((lettle*)a)->c - ((lettle*)b)->c;
}
int lengthOfLongestSubstring(char* s) {
    lettle* let = (lettle*)malloc(strlen(s) * sizeof(lettle));
    int i = 0;
    for (i = 0; i < strlen(s); i++)
    {
        let[i].index = i;
        let[i].c = s[i];
    }
    int left = 0;
    int right = 1;
    //qsort(let, strlen(s), sizeof(lettle), compare);
    for (i = 0; i < strlen(s); i++)
    {
        printf("%c ", let[i].c);
    }
    printf("\n");
    int count = 1;
    int j = 0;
    while (right < strlen(s))
    {
        char num1 = let[left].c;
        char num2 = let[right].c;
        int* ret = (int*)malloc(strlen(s) * sizeof(int));
        if (ret == NULL)
        {
            return;
        }
        ret[j] = (int)(let[left].c);
        int flag = 0;
        for (int k = 0; k < j; k++)
        {
            if (ret[j] == ret[k])
            {
                flag = 1;
                break;
            }
        }
        if (flag != 1)
        {
            left++;
            let[left].c = let[right].c;
            count++;
        }
        else
        {
            right++;
        }
    }
    for (i = 0; i < strlen(s); i++)
    {
        printf("%c ", let[i].c);
    }
    printf("\n");
    return count;
}
int main()
{
    char s[7] = {'p','w','w','k','e','w','\0'};
    int ret = lengthOfLongestSubstring(s);
    printf("%d\n", ret);
    return 0;
}


//设计qsort函数
//#include<stdio.h>
//#include<string.h>
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;//升序
//	//return *(int*)e2 - *(int*)e1;//降序
//}
//void Swap(char* buf1, char* buf2, int width)
//{
//	int i = 0;
//	for (i = 0;i < width;i++)
//	{
//		char temp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = temp;
//		buf1++;
//		buf2++;
//	}
//}
//void bubble_sort(void* base, size_t sz,size_t width,int (*cmp)(const void* e1,const void* e2))
//{
//	size_t i = 0;
//	for (i = 0;i < sz - 1;i++)
//	{
//		size_t j = 0;
//		for (j = 0;j < sz - 1 - i;j++)
//		{
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
//			{
//				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//			}
//		}
//	}
//}
//struct Stu
//{
//	char name[20];
//	int age;
//};
//int cmp_stu_by_age(const void* e1, const void* e2)
//{
//	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
//}
//int cmp_stu_by_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
//}
//void test2()
//{
//	struct Stu s[3] = { { "zhangsan",20 },{"lisi",50},{"wangwu",33} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	//bubble_sort(s, 3, sizeof(s[0]), cmp_stu_by_age);
//	bubble_sort(s, 3, sizeof(s[0]), cmp_stu_by_name);
//}
//void test1()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
//	int i = 0;
//	for (i = 0;i < sz;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//	//test1();
//	test2();
//	return 0;
//}


//sizeof返回的是size_t,类型是unsigned int
//#include<stdio.h>
//int main()
//{
//	int a[] = { 1,2,3,4 };
//	printf("%zu\n", sizeof(a));      //16
//	printf("%zu\n", sizeof(a + 0));  //首元素的地址,数组一个元素的地址
//	printf("%zu\n", sizeof(*a));     //数组首元素,计算数组首元素的大小
//	printf("%zu\n", sizeof(a + 1));  //a+1是第2个元素的地址,地址大小是4个或8个字节
//	printf("%zu\n", sizeof(a[1]));   //a[1]是第二个元素,计算的是第2个元素的大小
//	printf("%zu\n", sizeof(&a));     //&a取出的是整个数组的地址
//	printf("%zu\n", sizeof(*&a));    //&a取出的是整个数组的地址,就是整个数组
//	printf("%zu\n", sizeof(&a + 1)); //&a取出的是整个数组的地址,&a+1指向的是数组后面的空间
//	printf("%zu\n", sizeof(&a[0]));  //&a[0]取出的首元素的地址
//	printf("%zu\n", sizeof(&a[0] + 1));//&a[0]+1计算的是数组第2个元素的地址
//	return 0;
//}


//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//	printf("%zu\n", sizeof(arr));//arr单独放在sizeof内部,计算的是整个数组的大小,单位是字节
//	printf("%zu\n", sizeof(arr + 0));//arr+0首元素的地址
//	printf("%zu\n", sizeof(*arr));//*arr是数组的首元素,计算的是首元素的大小
//	printf("%zu\n", sizeof(arr[1]));//arr[1]是第二个元素
//	printf("%zu\n", sizeof(&arr));//取出的是数组的地址,数组的地址也是地址
//	printf("%zu\n", sizeof(&arr + 1));//&arr+1取出的是整个数组的地址,&arr+1指向的是数组后面的空间
//	printf("%zu\n", sizeof(&arr[0] + 1));//&arr[0]+1取出的是数组第二个元素的地址
//	printf("%zd\n", strlen(arr));//随机值
//	printf("%zd\n", strlen(arr + 0));//随机值
//	printf("%zd\n", strlen(*arr));//错误的
//	printf("%zd\n", strlen(arr[1]));//错误的
//	printf("%zd\n", strlen(&arr));//随机值
//	printf("%zd\n", strlen(&arr + 1));//随机值
//	printf("%zd\n", strlen(&arr[0] + 1));//随机值
//	return 0;
//}


//sizeof只关注占用内存空间的大小,单位是字节,不关心内存中存放的是什么
//sizeof是操作符
//strlen是求字符串长度的
//统计的是\0之前出现的字符个数,一定要找到\0才算结束,所以可能存在越界访问的
//strlen是函数
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr[] = "abcdef";
//	printf("%zu\n", sizeof(arr));//数组名单独放在sizeof内部,计算的是数组的总大小,单位是字节
//	printf("%zu\n", sizeof(arr + 0));//arr+0是首元素的地址
//	printf("%zu\n", sizeof(*arr));//*arr是数组首元素的大小
//	printf("%zu\n", sizeof(arr[1]));//arr[1]是数组第二个元素的大小
//	printf("%zu\n", sizeof(&arr));//&arr是数组的地址
//	printf("%zu\n", sizeof(&arr + 1));//&arr+1取出的是整个数组的地址,&arr+1指向的是数组后面的空间
//	printf("%zu\n", sizeof(&arr[0] + 1));//&arr[0]+1取出的是数组第二个元素的地址
//	printf("%zd\n", strlen(arr));//arr是数组首元素的地址
//	printf("%zd\n", strlen(arr + 0));//arr+0是数组首元素的地址
//	//printf("%zd\n", strlen(*arr));//*arr是字符a传给strlen是一个非法的地址,会非法访问
//	//printf("%zd\n", strlen(arr[1]));//arr[1]是字符b
//	printf("%zd\n", strlen(&arr));
//	printf("%zd\n", strlen(&arr + 1));//&arr+1跳过数组后的地址,统计字符串的长度是随机值
//	printf("%zd\n", strlen(&arr[0] + 1));
//	return 0;
//}


//strlen函数的作用是计算字符串的长度
//要求传入的参数是一个指向以空字符'\0'结尾的字符数组的指针
//也就是字符串的首地址。
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	const char* p = "abcdef";
//	printf("%zu\n", sizeof(p));//p是指针变量
//	printf("%zu\n", sizeof(p + 1));//p+1是b的地址
//	printf("%zu\n", sizeof(*p));//*p是字符'a'
//	printf("%zu\n", sizeof(p[0]));//p[0]==*(p+0)==*p
//	printf("%zu\n", sizeof(&p));//&p是二级指针
//	printf("%zu\n", sizeof(&p + 1));//&p+1是跳过p变量后的地址
//	printf("%zu\n", sizeof(&p[0] + 1));//p[0]是'a',&p[0]就是a的地址,+1是b的地址
//	printf("%zd\n", strlen(p));//求字符串长度
//	printf("%zd\n", strlen(p + 1));//p+1是b的地址,求字符串长度就是5
//	printf("%zd\n", strlen(*p));//error p是a的地址,*p是'a'也就是97,97是数字,不是地址
//	printf("%zd\n", strlen(p[0]));//error p[0]是'a'也就是97,97是数字,不是地址
//	printf("%zd\n", strlen(&p));
//	//&p拿到的是p这个指针变量的起始地址,从这里开始,求字符串完全是随机值
//	printf("%zd\n", strlen(&p + 1));
//	//&p+1跳过p变量的起始地址,从这里开始,求字符串完全是随机值
//	printf("%zd\n", strlen(&p[0] + 1));
//	//&p[0]是b的地址,从b的地址向后数字符串的长度是5
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	printf("%zu\n", sizeof('a'));//C:4//C++:1
//	printf("%zu\n", sizeof(97));//4
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	char a = 1;
//	printf("a = %zu\n", sizeof(a));
//	printf("a = %zu\n", sizeof(+a));
//	printf("a = %zu\n", sizeof(-a));
//	int b = 1;
//	printf("b = %zu\n", sizeof(b));
//	printf("b = %zu\n", sizeof(+b));
//	printf("b = %zu\n", sizeof(-b));
//	return 0;
//}


//a[0]是第一行数组名,数组名单独放在sizeof内部,计算的是数组的大小
//sizeof是根据类型来计算变量的大小,不会越界访问,sizeof是在编译期间执行的
//计算表达式的值是在运行期间计算的
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int a[3][4] = { 0 };
//	printf("%zu\n", sizeof(a));//a的大小
//	printf("%zu\n", sizeof(a[0][0]));
//	printf("%zu\n", sizeof(a[0]));//a[0]是第一行数组名
//	printf("%zu\n", sizeof(a[0] + 1));
//	//printf("%p\n", &a[0][0]);
//	//printf("%p\n", &a[0][1]);
//	//a[0]作为第一行的数组名,没有单独放在sizeof内部,没有取地址
//	//表示的就是数组首元素的地址,即a[0][0],a[0]+1是a[0][1]的地址
//	printf("%zu\n", sizeof(*(a[0] + 1)));
//	//*(a[0]+1)是第一行第二个元素,计算的是元素的大小,即4个字节
//	printf("%zu\n", sizeof(a + 1));
//	//a是二维数组的数组名,数组名表示首元素的地址
//	//就是第一行的地址,a+1就是第二行的地址
//	printf("%zu\n", sizeof(*(a + 1)));
//	//第二行的大小
//	printf("%zu\n", sizeof(&a[0] + 1));
//	//第二行的地址
//	printf("%zu\n", sizeof(*(&a[0] + 1)));
//	//第二行的地址解引用,得到的是第二行,计算的是第二行的大小
//	printf("%zu\n", sizeof(*a));
//	//a是第一行的地址,*a就是第一行,计算的是第一行的大小
//	printf("%zu\n", sizeof(a[3]));
//	//如果数组存在第4行,a[3]就是第4行的数组名
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	short s = 3;
//	int a = 10;
//	printf("%d\n", sizeof(s = a + 2));
//	printf("%d\n", s);
//	return 0;
//}


//C语言表达式有2个属性
//2+3
//值属性:5
//类型属性:int


//#include<stdio.h>
//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));
//	return 0;
//}


//结构体Test类型的变量大小是20个字节
//#include<stdio.h>
//struct Test
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}*p;
//int main()
//{
//	p = (struct Test*)0x100000;
//	printf("0x%p\n", p + 0x1);
//	//0x100000 + 0x14 == 0x00100014
//	printf("0x%p\n", (unsigned long)p + 0x1);
//	//0x100000 + 1 == 0x00100001
//	printf("0x%p\n", (unsigned int*)p + 0x1);//跳过一个整形
//	//0x100000 + 4 == 0x00100004
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int a[4] = { 1, 2, 3, 4 };
//	int* ptr1 = (int*)(&a + 1);
//	int* ptr2 = (int*)((int)a + 1);
//	printf("%x,%x", ptr1[-1], *ptr2);
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int a[3][2] = { (0, 1), (2, 3), (4, 5) };//逗号表达式
//	int a[3][2] = { {1,3}, {5,0}, {0,0} };
//	int* p;
//	p = a[0];
//	printf("%d", p[0]);//p[0] == *(p + 0)
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int a[5][5];
//	int(*p)[4];//+1跳过4个整型
//	p = a;
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//	return 0;
//}
//1000 0000 0000 0000 0000 0000 0000 0100
//111111111111111111111111111111111111011
//111111111111111111111111111111111111100
//FF FF FF FC


//#include<stdio.h>
//int main()
//{
//	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	char** pa = a;
//	pa++;
//	printf("%s\n", *pa);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };
//	char** cp[] = { c + 3,c + 2,c + 1,c };
//	char*** cpp = cp;
//	printf("%s\n", **++cpp);
//	printf("%s\n", *-- * ++cpp + 3);
//	printf("%s\n", *cpp[-2] + 3);
//	printf("%s\n", cpp[-1][-1] + 1);
//	return 0;
//}