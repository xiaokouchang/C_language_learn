#define _CRT_SECURE_NO_WARNINGS 1

//结构体
//结构是一些值的集合,这些值称为成员变量。
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
//struct stu
//{
//	char name[20];
//	int age;
//	char sex[10];
//	float score;
//};
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
//int main()
//{
//	struct P p = { 5.5,{100,'b'},3.14f };
//	scanf("%d %c", &(p.s.a), &(p.s.c));
//	printf("%lf %d %c %f\n", p.d, p.s.a, p.s.c, p.f);
//	return 0;
//}


