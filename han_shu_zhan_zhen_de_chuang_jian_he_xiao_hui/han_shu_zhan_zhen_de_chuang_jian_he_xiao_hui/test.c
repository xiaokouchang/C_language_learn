#define _CRT_SECURE_NO_WARNINGS 1 

//局部变量是怎么创建的?
//为什么局部变量的值是随机值?
//函数是怎么传参的?传参的顺序是怎样的>
//形参和实参是什么关系?
//函数调用是怎么做的?
//函数调用是结束后怎么返回的?


//寄存器
//eax
//ebx
//ecx
//edx
//ebp
//esp


//esp和ebp这两个寄存器中存放的是地址,这两个地址是用来维护函数栈帧的
//每一个函数调用,都要在栈区创建一个空间
#include<stdio.h>
int Add(int x, int y)
{
	int z = 0;
	z = x + y;
	return z;
}
//反汇编
//lea --- Load effective address(加载有效地址)
//push --- 压栈
//pop --- 出栈
//dword --- word是2个字节,dword是4个字节
//call --- 下一条指令的地址
int main()
{
	int a = 10;
	int b = 20;
	int c = 0;
	c = Add(a, b);
	printf("%d\n", c);
	return 0;
}