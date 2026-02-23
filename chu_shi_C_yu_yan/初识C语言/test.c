#define _CRT_SECURE_NO_WARNINGS 1 
//C语言规定
//main函数为程序的入口,main函数有且仅有一个
//main函数在一个工程中只能有一个
//#include<stdio.h>
//
//int main()
//{
//	printf("hello world!\n");
//	return 0;
//}


//%d ---- 打印整数
//%f ---- 打印浮点数
//%c ---- 打印字符
//%s ---- 打印字符串
//占位符,会被后面的值替换


//关键字
//auto break case char do double else const continue
//default enum extern float for goto if int register
//return short signed sizeof static struct switch typedef
//union unsigned void volatile while


//字符和ASCII码表
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 48; i++)
//	{
//		printf("%c ", i);
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	printf("%d\n", 'a'-32);
//}


//#include<stdio.h>
//int main()
//{
//	printf("%x\n", 32);
//	return 0;
//}


//字符串-----%s打印
//'a'
//"abcdef"
//字符串的结束标志-----'\0'
//#include<stdio.h>
//
//int main()
//{
//	char arr1[] = { 'a','b','c','d','e','f'};
//	char arr2[] = "abcdef";
//	printf("%s\n", arr1);
//	printf("%s\n", arr2);
//	return 0;
//}


//转义字符
// /?---书写连续多个?时使用,防止被解析成三字母词
// ??) ---> ]
// ??( ---> (
// ??> ---> }
// ??< ---> {
// \'----- 用于表示字符常量 --- 打印'
// \"----- 用于表示字符常量 --- 打印"
// \\----- 用于表示一个反斜杠,防止它被解释成一个序列转义符
// \a ---- 警报，这会使得终端发出警报声或出现闪烁，或者两者同时发⽣。
// \b ---- 退格键，光标回退⼀个字符，但不删除字符。
// \f ---- 换页符，光标移到下⼀⻚。在现代系统上，这已经反映不出来了，行为改成类似于 \v 。
// \n ---- 换行符。
// \r ---- 回车符，光标移到同⼀⾏的开头。
// \t ---- 制表符，光标移到下⼀个水平制表位，通常是下⼀个4或者8的倍数。
// \v ---- 垂直分隔符，光标移到下⼀个垂直制表位，通常是下一行的同⼀列
//#include<stdio.h>
//
//int main()
//{
//	printf("abcd\nef");
//	printf("\n");
//	printf("(are you ok\?\?)\n");
//	printf("%c\n", '\'');
//	printf("%s\n", "\"");
//	printf("c:test\\test117\\add.c");
//	printf("\a");
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	printf("%.2f\n", 0.5);
//	printf("%6.2f\n", 0.5);
//	printf("%-6.2f\n", 0.5);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{	
//	printf("abcdef\bx\n");//覆盖掉原有的值
//	printf("abcdefghijkl\n");
//	printf("a\tbcdef\tghijkl\n");
//	// \t表示占8个字符,包括前面的字符,a是1个字符后面有\t填充7个空格
//	printf("zhangsan\t20\n");// \t ---- 产生内容上的对齐
//	printf("lisi\t\t30\n");
//	//getchar();
//	return 0;
//}


// \ddd ---- d d d表示1-3个8进制数字 ---- 一个字符
// \xdd ---- d d 
// \0:null字符,代表没有内容
// \0就是\ddd这类转义字符的⼀种,⽤于字符串的结束标志，其ASCII码值是0
//#include<stdio.h>
//
//int main()
//{
//	printf("%c\n", '\130');//8进制的数字转化为10进制,然后对应相应的ASCII码
//	printf("%c\n", '\x30');//16进制的数字转化为10进制,然后对应相应的ASCII码
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int a, b, c;
//	float d, e;
//	char r;
//	scanf("%*f %*f %d", &c);
//	printf("%d\n", c);
//	return 0;
//}


//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int len = strlen("c:\test\abc\181\bit.c");//求字符串长度,\181是三个字符
//	printf("%d\n", len);
//	return 0;
//}


//空语句是最简单的，⼀个分号就是⼀条语句，是空语句。
//表达式语句就是在表达式的后边加上分号
//函数调⽤的时候，也会加上分号，就是函数调⽤语句。
//复合语句其实就是代码块，成对括号中的代码就构成⼀个代码块，也被称为复合语句
//控制语句⽤于控制程序的执⾏流程，以实现程序的各种结构⽅式（C语⾔支持三种结构：顺序结构、选
//择结构、循环结构），它们由特定的语句定义符组成，C语言有九种控制语句。
//可分成以下三类：
//1. 条件判断语句也叫分⽀语句：if语句、switch语句；
//2. 循环执⾏语句：do while语句、while语句、for语句；
//3. 转向语句：break语句、goto语句、continue语句、return语句。
//注释/* ---   */


//#include<stdio.h>
//#include<stdbool.h>
//int main()
//{
//	_Bool n = true;
//	if (n)
//	{
//		printf("I like C\n");
//	}
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	printf("%5d\n", 123);//默认右对齐
//	printf("%-5d\n", 123);//左对齐
//	return 0;
//}
