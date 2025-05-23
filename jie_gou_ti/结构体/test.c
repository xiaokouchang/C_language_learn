#define _CRT_SECURE_NO_WARNINGS 1
//结构体
//结构是一些值的集合,这些值称为成员变量
//结构的每个成员可以是不同类型的变量
//结构体的声明
//struct tag
//{
//	member-list;
//}variable-list;
//#include<stdio.h>
//struct stu
//{
//	char name[20];
//	int age;
//	char sex[10];
//	float score;
//}s4,s5;//s4,s5也是结构体变量 -- 全局的
//struct stu s6;//单独定义 --- 全局的
//int main()
//{
//	struct stu s1, s2, s3;//s1,s2,s3也是结构体变量 --- 局部的
//	return 0;
//}





//结构体变量初始化
//#include<stdio.h>
////类型
//struct stu
//{
//	char name[20];
//	int age;
//	char sex[10];
//	float score;
//};
////变量
//int main()
//{
//	struct stu s1 = { "zhangsan",20,"nan",95.5f};
//	struct stu s2 = { "lisi",22,"girl",80.2f };
//	struct stu s3 = { "xiaohong",30,"girl",95.4f };
//	printf("%s %d %s %f\n", s1.name, s1.age, s1.sex, s1.score);
//	printf("%s %d %s %f\n", s2.name, s2.age, s2.sex, s2.score);
//	printf("%s %d %s %f\n", s3.name, s3.age, s3.sex, s3.score);
//	return 0;
//}


//#include <stdio.h>
//struct Student
//{
//    char name[50];
//    int age;
//    float score;
//};
//int main()
//{
//    struct Student stu2 = { .name = "Jerry", .age = 21, .score = 90.0 };
//    return 0;
//}


////可以放在主函数里面
//#include<stdio.h>
////变量
//int main()
//{
//	//类型
//	struct stu
//	{
//		char name[20];
//		int age;
//		char sex[10];
//		float score;
//	};
//	struct stu s1 = { "zhangsan",20,"nan",95.5f };
//	struct stu s2 = { "lisi",22,"girl",80.2f };
//	struct stu s3 = { "xiaohong",30,"girl",95.4f };
//	printf("%s %d %s %f\n", s1.name, s1.age, s1.sex, s1.score);
//	printf("%s %d %s %f\n", s2.name, s2.age, s2.sex, s2.score);
//	printf("%s %d %s %f\n", s3.name, s3.age, s3.sex, s3.score);
//	return 0;
//}


//结构体成员访问
//函数传参的时候,参数是需要压栈的。
//传递一个结构体对象的时候,结构体过大,参数压栈的的系统开销比较大
//会导致性能的下降。
//结构体传参的时候,要传结构体的地址。
//#include<stdio.h>
//struct S
//{
//	int a;
//	char c;
//};
//struct b
//{
//	double d;
//	struct S s;
//	float f;
//};
//struct P
//{
//	double d;
//	struct S s;
//	float f;
//};
//void Print1(struct P sp)//变量
//{
//	printf("%lf %d %c %f\n", sp.d, sp.s.a, sp.s.c, sp.f);
//}
//void Print2(struct P* p1)//指针
//{
//	printf("%lf %d %c %f\n", (*p1).d, (*p1).s.a, (*p1).s.c, (*p1).f);
//	printf("%lf %d %c %f\n", p1->d, p1->s.a, p1->s.c, p1->f);
//}
//int main()
//{
//	struct P p = { 5.5,{100,'b'},3.14f };
//	//printf("%lf %d %c %f\n", p.d, p.s.a, p.s.c, p.f);
//	Print1(p);//传值调用
//	Print2(&p);//传址调用
//	return 0;
//}


//#include<stdio.h>
//struct S
//{
//	int a;
//	char c;
//};
//struct P
//{
//	double d;
//	struct S s;
//	float f;
//};
//int main()
//{
//	struct P p = { 5.5,{100,'b'},3.14f };
//	scanf("%d %c", &(p.s.a), &(p.s.c));
//	printf("%lf %d %c %f\n", p.d, p.s.a, p.s.c, p.f);
//	return 0;
//}


//#include<stdio.h>
//struct stu
//{
//	char name[20];
//	int age;
//}s1, s2;//全局变量,s1和s2是两个结构体变量
//int main()
//{
//	struct stu s3, s4;//局部变量
//	return 0;
//}


//重命名
//#include<stdio.h>
//typedef struct stu
//{
//	char name[20];
//	int age;
//}Stu;//全局变量,s1和s2是两个结构体变量
//int main()
//{
//	struct stu s3, s4;//局部变量
//	Stu s2, s3;//局部变量
//	return 0;
//}


//匿名结构体类型 --- 没有名字
//不完全声明
//#include<stdio.h>
//struct
//{
//	char name[20];
//	int age;
//}x;


//不正确
//#include<stdio.h>
//struct
//{
//	int a;
//	char c;
//	double d;
//}x;
//struct
//{
//	int a;
//	char c;
//	double d;
//}*p;
//int main()
//{
//	p = &x;
//	return 0;
//}


//结构的自引用
//同类型的下一个结点
//链表
//数据结构 --- 数据在内存中存储的结构
//#include<stdio.h>
//struct Node
//{
//	int data;
//	struct Node* next;
//};


//#include<stdio.h>
////可以重命名
//typedef struct Node
//{
//	int data;
//	struct Node* next;
//}Node;
//int main()
//{
//	struct Node n1;
//	struct Node n2;
//	n1.next = &n2;
//	return 0;
//}


//#include<stdio.h>
//struct Point
//{
//	int x;
//	int y;
//}p1 = { 10,20 };
//struct Point p2 = { 0,0 };
//struct S
//{
//	int num;
//	char ch;
//	struct Point p;
//	float d;
//};
//int main()
//{
//	struct Point p3 = { 1,2 };
//	struct S s = { 100,'w',{2,3},3.14f };
//	struct S s2 = { .d = 1.2f,.p.x = 3,.p.y = 5,.ch = 'w',.num = 200 };
//	printf("%d %c %d %d %.2f\n", s.num, s.ch, s.p.x, s.p.y, s.d);
//	printf("%d %c %d %d %.2f\n", s2.num, s2.ch, s2.p.x, s2.p.y, s2.d);
//	return 0;
//}


//结构体内存对齐
//结构体的对齐规则:
//第一个成员在与结构体变量偏移量为0的地址处
//其他成员变量要对齐到某个数字(对齐数)的整数倍的地址处
//对齐数 = 编译器默认的一个对齐数与该成员大小的较小值
//VS中默认的值为8
//Linux gcc没有默认对齐数,对齐数是成员自身大小
//结构体总大小为最大对齐数(每个成员变量都有一个对齐数)的整数倍
//如果嵌套了结构体的情况,嵌套的结构体对齐到自己的最大对齐数的整数倍处
//结构体的整体大小就是所有最大对齐数(含嵌套结构体的对齐数)的整数倍
//为什么存在内存对齐
//平台原因(移植原因):
//不是所有的硬件平台都能访问任意地址上的任意数据的
//某些硬件平台只能在某些地址处取某些特定类型的数据,否则抛出硬件异常
//性能原因:
//数据结构(尤其是栈)应该尽可能地在自然边界上对齐
//为了访问未对齐的内存,处理器需要作两次内存访问;而对齐的内存访问仅需要一次访问
//结构体的内存对齐是拿空间来换取时间的做法
//在设计结构体的时候,我们既要满足对齐,又要节省空间,让占用空间小的成员尽量集中在一起。
//#include<stdio.h>
//#include<stddef.h>
////offsetof --- 宏
//struct s1
//{
//	//0
//	//4
//	//8
//	//12
//	char c1;
//	int i;
//	char c2;
//};
//
//struct s2
//{
//	char c1;
//	char c2;
//	int i;
//	//0
//	//1
//	//4
//	//8
//};
//struct s3
//{
//	//7
//	//8
//	//12
//	//16
//	double d;
//	char c;
//	int i;
//};
//struct s4
//{
//	//0
//	//4
//	//8
//	float d;
//	char c;
//	int i;
//};
//struct s5
//{
//	//0
//	//8
//	//9
//	//11
//	//15
//	//22
//	//24
//	char c1;
//	struct s3 s3;
//	double d;
//};
//int main()
//{
//	printf("%zd\n", sizeof(struct s1));
//	printf("%zd\n", sizeof(struct s2));
//	printf("%zd\n", sizeof(struct s3));
//	printf("%zd\n", sizeof(struct s4));
//	printf("%zd\n", sizeof(struct s5));
//	printf("%zd\n", offsetof(struct s1, c1));
//	printf("%zd\n", offsetof(struct s1, i));
//	printf("%zd\n", offsetof(struct s1, c2));
//	printf("%zd\n", offsetof(struct s2, c1));
//	printf("%zd\n", offsetof(struct s2, c2));
//	printf("%zd\n", offsetof(struct s2, i));
//	printf("%zd\n", offsetof(struct s3, d));
//	printf("%zd\n", offsetof(struct s3, c));
//	printf("%zd\n", offsetof(struct s3, i));
//	printf("%zd\n", offsetof(struct s4, d));
//	printf("%zd\n", offsetof(struct s4, c));
//	printf("%zd\n", offsetof(struct s4, i));
//	return 0;
//}

//#include<stddef.h>
//#include<stdio.h>
//typedef struct s1
//{
//	char c1;
//	int i;
//	char c2;
//}s1;
//struct s2
//{
//	char c1;
//	s1 s1;
//	int c2[5];
//};
//int main()
//{
//	printf("%zd\n", sizeof(struct s2));
//	printf("%zd\n", offsetof(struct s2, c1));
//	printf("%zd\n", offsetof(struct s1, i));
//	printf("%zd\n", offsetof(struct s1, c2));
//	printf("%zd\n", offsetof(struct s2, c2));
//	return 0;
//}


//#include<stdio.h>
//#include<stddef.h>
////offsetof --- 宏
//struct s1
//{
//	//0
//	//4
//	//8
//	//12
//	char c1;
//	int i;
//	char c2;
//};
//
//struct s2
//{
//	char c1;
//	char c2;
//	int i;
//	//0
//	//1
//	//4
//	//8
//};
//struct s3
//{
//	//7
//	//8
//	//12
//	//16
//	double d;
//	char c;
//	int i;
//};
//struct s4
//{
//	//0
//	//4
//	//8
//	float d;
//	char c;
//	int i;
//};
//struct s5
//{
//	//0
//	//8
//	//9
//	//11
//	//15
//	//22
//	//24
//	char c1;
//	struct s3 s3;
//	double d;
//};
//int main()
//{
//	printf("%zd\n", sizeof(struct s1));
//	printf("%zd\n", sizeof(struct s2));
//	printf("%zd\n", sizeof(struct s3));
//	printf("%zd\n", sizeof(struct s4));
//	printf("%zd\n", sizeof(struct s5));
//	printf("%zd\n", offsetof(struct s1, c1));
//	printf("%zd\n", offsetof(struct s1, i));
//	printf("%zd\n", offsetof(struct s1, c2));
//	printf("%zd\n", offsetof(struct s2, c1));
//	printf("%zd\n", offsetof(struct s2, c2));
//	printf("%zd\n", offsetof(struct s2, i));
//	printf("%zd\n", offsetof(struct s3, d));
//	printf("%zd\n", offsetof(struct s3, c));
//	printf("%zd\n", offsetof(struct s3, i));
//	printf("%zd\n", offsetof(struct s4, d));
//	printf("%zd\n", offsetof(struct s4, c));
//	printf("%zd\n", offsetof(struct s4, i));
//	return 0;
//}


//修改默认对齐数
//#include<stdio.h>
//#include<stddef.h>
//#pragma pack(1) // 修改默认对齐数为1
//struct s1
//{
//	//0
//	//4
//	//5
//	char c1;
//	int i;
//	char c2;
//};
//#pragma pack() //恢复默认对齐数
//int main()
//{
//	printf("%zd\n", sizeof(struct s1));
//	printf("%zd\n", offsetof(struct s1, c1));
//	printf("%zd\n", offsetof(struct s1, i));
//	printf("%zd\n", offsetof(struct s1, c2));
//	return 0;
//}


//结构体传参
//函数传参的时候,参数是需要压栈,会有时间和空间上的系统开销
//如果传递一个结构体对象的时候,结构体过大,参数压栈的的系统开销比较大,所以会导致性能的下降
//结构体传参的时候,要传结构体的地址
//#include<stdio.h>
//typedef struct s1
//{
//	char a;
//	char b;
//	int c;
//}s1;
//void print1(s1 a)
//{
//	printf("%c %c %d\n", a.a, a.b, a.c);
//}
//void print2(s1* a)
//{
//	printf("%c %c %d\n", (*a).a, (*a).b, (*a).c);
//	printf("%c %c %d\n", a->a, a->b, a->c);
//}
//int main()
//{
//	s1 a = { 'a','b',4 };
//	print1(a);
//	print2(&a);
//	return 0;
//}


//位段
//位 --- 二进制位
//位段的成员必须是int、unsigned int 或signed int
//位段的成员名后边有一个冒号和一个数字
//同类型的
//#include <stdio.h>
////int(4*8=32)
////2+5+10+30
//struct A
//{
//	int _a : 2;//2个比特位
//	int _b : 5;//5个比特位
//	int _c : 10;
//	int _d : 30;
//};
//int main()
//{
//	printf("%d\n", sizeof(struct A));
//	return 0;
//}


//位段的内存分配
//位段的成员可以是int unsigned int signed int或者是char(属于整形家族)类型
//位段的空间上是按照需要以4个字节(int)或者1个字节(char)的方式来开辟的
//位段涉及很多不确定因素,位段是不跨平台的,注重可移植的程序应该避免使用位段
//比结构体更节省空间
//从低到高依次使用,如果不够则丢弃,开辟下一个空间
//#include <stdio.h>
//struct S
//{
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};
//int main()
//{
//	//00000000
//	struct S s = { 0 };
//	s.a = 10;
//	//假定从右向左存
//	//第1个字节
//	//10 --- 00001010 --- 3bit --- 发生截断 010
//	//00000010
//	s.b = 12;
//	//8 4 2 1
//	//12 --- 00001100 --- 4bit --- 1100
//	//01100010
//	//62
//	s.c = 3;
//	//第2个字节
//	//3 --- 00000011 --- 5bit --- 00011
//	//00000011
//	//03
//	s.d = 4;
//	//第3个字节
//	//4 --- 00000100 --- 4bit --- 0100
//	//00000100
//	//04
//	printf("%zd\n", sizeof(struct S));
//	return 0;
//}


//位段的跨平台问题
//int位段被当成有符号数还是无符号数是不确定的
//位段中最大位的数目不能确定
//16位机器最大16,32位机器最大32,写成27,在16位机器会出问题
//位段中的成员在内存中从左向右分配，还是从右向左分配标准尚未定义
//当一个结构包含两个位段,第二个位段成员比较大,无法容纳于第一个位段剩余的位时,
//是舍弃剩余的位还是利用,这是不确定的
//跟结构相比,位段可以达到同样的效果,但是可以很好的节省空间,但是有跨平台的问题存在


//#include<stddef.h>
//#include<stdio.h>
//struct S
//{
//	//0
//	//8
//	//16
//	//24
//	int a;
//	char c[5];
//	//5个char元素
//	double d;
//};
//int main()
//{
//	printf("%zd\n", sizeof(struct S));
//	printf("%zd\n", offsetof(struct S, a));
//	printf("%zd\n", offsetof(struct S, c));
//	printf("%zd\n", offsetof(struct S, d));
//	return 0;
//}