#define _CRT_SECURE_NO_WARNINGS 1 

//枚举类型
//枚举顾名思义就是---列举
//把可能的取值---列举
//比如:
//一周的星期一到星期日是有限的7天
//性别有：男、女
//月份有12个月
//#include <stdio.h>
////性别
//typedef enum Sex
//{
//	//MALE = 3,//枚举常量
//	//FEMALE = 2,//初始化修改,尽量不在主函数赋值
//	//SECRET = 4
//	MALE = 3,//默认递增1,不初始化,默认为0
//	FEMALE,
//	SECRET
//}Sex;
////颜色
//enum Color
//{
//	RED,
//	GREEN,
//	blue
//};
//int main()
//{
//	enum Sex s;
//	int age;
//	printf("%zd\n", sizeof(s));//4
//	printf("%d\n", MALE);
//	printf("%d\n", FEMALE);
//	printf("%d\n", SECRET);
//	//MALE = 4;
//	return 0;
//}


//#define 定义的常量是替换的
//增加代码的可读性和可维护性
//和#define定义的标识符比较枚举有类型检查,更加严谨
//防止了命名污染(封装)
//便于调试
//使用方便,一次可以定义多个常量


//联合体(共用体)
//union
//联合也是一种特殊的自定义类型
//这种类型定义的变量也包含一系列的成员
//特征是这些成员公用同一块空间(所以联合也叫共用体)
//#include <stdio.h>
//union UN
//{
//	char c;
//	int i;
//	double d;
//};
//int main()
//{
//	union UN un;
//	printf("%zd\n", sizeof(un));//最大的空间
//	//共同的地址
//	printf("%p\n", &un);
//	printf("%p\n", &un.c);
//	printf("%p\n", &un.i);
//	printf("%p\n", &un.d);
//	return 0;
//}


//联合的成员是共用同一块内存空间的,
//一个联合变量的大小,至少是最大成员的大小(因为联合至少得有能力保存最大的那个成员)
//联合的大小至少是最大成员的大小
//当最大成员大小不是最大对齐数的整数倍的时候,就要对齐到最大对齐数的整数倍
//节省空间
//#include<stdio.h>
//
//union UN
//{
//	char c[5];//5  5/8  5
//	int n; // 4    4/8  4
//};
//union Un2
//{
//	short c[7];//14  2/8  2
//	int i;//4  4/8        4
//};
//int main()
//{
//	printf("%zd\n", sizeof(union UN));
//	printf("%zd\n", sizeof(union Un2));
//	return 0;
//}


//判断当前计算机的大小端存储
//#include<stdio.h>
//int print()
//{
//	int i = 4;
//	char* a = (char*)&i;
//	if (*a == 4)
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
//	int ret = print();
//	if (ret == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}


//#include<stdio.h>
//union UN
//{
//	char c;
//	int i;
//};
//int main()
//{
//	union UN un;
//	un.i = 1;
//	if (un.c == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}
