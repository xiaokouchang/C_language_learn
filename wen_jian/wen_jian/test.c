#define _CRT_SECURE_NO_WARNINGS 1 
//文件
//磁盘上的文件是文件
//程序文件、数据文件
//程序文件
//包括源程序文件(后缀为.c),目标文件(windows环境后缀为.obj),可执行程序(windows环境后缀为.exe)
//数据文件
//文件的内容不一定是程序,而是程序运行时读写的数据
//比如程序运行需要从中读取数据的文件,或者输出内容的文件
//文件名
//一个文件要有一个唯一的文件标识,以便用户识别和引用
//文件名包含3部分:文件路径+文件名主干+文件后缀
//例如:c:\code\test.txt
//为了方便起见,文件标识常被称为文件名
//操作文件
//1.打开文件(读/写)
//定义fp是一个指向FILE类型数据的指针变量
//可以使pf指向某个文件的文件信息区(是一个结构体变量)
//通过该文件信息区中的信息就能够访问该文件。
//通过文件指针变量能够找到与它关联的文件
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	//FILE* fp = fopen("D:\\VS_dai_ma\\gitee\\c-language-learning\\test1.txt", "r");
//	FILE* fp = fopen("test2.txt", "w");//根目录,test.c文件的位置
//	//FILE* fp = fopen("../test3.txt", "r");//../表示上一级
//	if (fp == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	else
//	{
//		printf("打开文件成功\n");
//	}
//	//读文件
//	//关闭文件
//	fclose(fp);
//	fp = NULL;
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	FILE* pf = fopen("test2.txt", "w");//根目录,test.c文件的位置
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	else
//	{
//		printf("打开文件成功\n");
//	}
//	//fputc
//	//写文件
//	//fputc('a', pf);
//	//fputc('b', pf);
//	//fputc('c', pf);
//	//fputc('d', pf);
//	//int i = 0;
//	//char c = 0;
//	//for (i = 0;i < 26;i++)
//	//{
//	//	c = i + 'a';
//	//	fputc(c, pf);
//	//	fputc(' ', pf);
//	//}
//	//char ch = 0;
//	//for (ch = 'a';ch <= 'z';ch++)
//	//{
//	//	fputc(ch, pf);
//	//	fputc(' ', pf);
//	//}
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	FILE* pf = fopen("test2.txt", "r");//根目录,test.c文件的位置
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	else
//	{
//		printf("打开文件成功\n");
//	}
//	char ch = 0;
//	for (ch = 'a';ch <= 'z';ch++)
//	{
//		fputc(ch, pf);
//		//fputc(' ', pf);
//	}
//	int ch1 = fgetc(pf);
//	printf("%c\n", ch1);
//	ch1 = fgetc(pf);
//	printf("%c\n", ch1);
//	ch1 = fgetc(pf);
//	printf("%c\n", ch1);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


#include <stdio.h>
#include <string.h>
int main()
{
	FILE* pf = fopen("test.txt", "r");//根目录,test.c文件的位置
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	char arr[20]= { 0 };
	fgets(arr, 19, pf);
	printf("%s", arr);
	fgets(arr, 19, pf);
	printf("%s", arr);
	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}


//fputs
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	FILE* pf = fopen("test2.txt", "r");//根目录,test.c文件的位置
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	else
//	{
//		printf("打开文件成功\n");
//	}
//	fputs("Hello World!\n", pf);
//	fputs("Hello World!\n", pf);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//fgets
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	FILE* pf = fopen("test2.txt", "r");//根目录,test.c文件的位置
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	char arr[20];
//	fgets(arr, 19, pf);//文件有'\n'
//	printf("%s", arr);//放'\0'
//	fgets(arr, 19, pf);
//	printf("%s", arr);//放'\0'
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//键盘---(输入\读)--->内存---(输出\写)---->屏幕上
//文件---(输入\读)--->内存---(输出\写)---->文件
//#include <stdio.h>
//#include <string.h>
//struct S
//{
//	char name[20];
//	int age;
//	float score;
//};
//int main()
//{
//	struct S s = { "zhangsan",20,95.5 };
//	FILE* pf = fopen("test2.txt", "r");//根目录,test.c文件的位置
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fprintf(pf, "%s %d %f\n", s.name, s.age, s.score);
//	fscanf(pf, "%s %d %f\n", s.name, &(s.age), &(s.score));
//	printf("%s %d %f\n", s.name, s.age, s.score);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//C语言程序--->数据--->流---->(屏幕、文件、网络)
//任何一个C语言程序运行的时候都会默认打开3个流
//stdin  --- 标准输入(键盘)
//stdout --- 标准输出(屏幕)
//stderr --- 标准错误(屏幕)
//#include<stdio.h>
//struct S
//{
//	char name[20];
//	int age;
//	float score;
//};
//int main()
//{
//	struct S s = { 0 };
//	//格式化输入输出
//	fscanf(stdin, "%s %d %f", s.name, &(s.age), &(s.score));
//	fprintf(stdout, "%s %d %f\n", s.name, s.age, s.score);
//	
//	//int ch = fgetc(stdin);//从键盘
//	//fputc(ch, stdout);
//	return 0;
//}


//fwrite
//#include<stdio.h>
//struct S
//{
//	char name[20];
//	int age;
//	float score;
//};
//int main()
//{
//	struct S s = { "zhangsan",23,96.5 };
//	FILE* pf = fopen("test.txt", "wb");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//写文件
//	fwrite(&s, sizeof(struct S), 1, pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//读文件
//#include<stdio.h>
//struct S
//{
//	char name[20];
//	int age;
//	float score;
//};
//int main()
//{
//	struct S s = { "zhangsan",23,96.5 };
//	FILE* pf = fopen("test.txt", "rb");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//读文件
//	fread(&s, sizeof(struct S), 1, pf);
//	printf("%s %d %f\n", s.name, s.age, s.score);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//scanf   --- 从键盘上读取格式化的数据
//printf  --- 把数据写到(输出)屏幕上
//fscanf  --- 针对所有输入流的格式化的输入函数:stdin,打开的文件
//fprintf --- 针对所有输出流的格式化的输出函数:stdout,打开的文件
//sscanf  --- 从一个字符串中还原出一个格式化的数据
//sprintf --- 把一个格式化的数据存放在(转换成)一个字符串
//#include<stdio.h>
//struct S
//{
//	char name[20];
//	int age;
//	float score;
//};
//int main()
//{
//	struct S s = { "zhangsan",20,98.5 };
//	char buf[100] = { 0 };
//	sprintf(buf, "%s %d %f", s.name, s.age, s.score);
//	printf("%s\n", buf);//按照字符串打印的
//	struct S tmp = { 0 };
//	sscanf(buf, "%s %d %f", tmp.name, &(tmp.age), &(tmp.score));
//	printf("%s %d %f\n", tmp.name, tmp.age, tmp.score);//按照结构体打印的
//	return 0;
//}


//文件的随机读写
//fseek
//#include<stdio.h>
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	else
//	{
//		int ch = fgetc(pf);
//		printf("%c\n", ch);
//		ch = fgetc(pf);
//		printf("%c\n", ch);
//		ch = fgetc(pf);
//		printf("%c\n", ch);
//		//fseek(pf, -2, SEEK_CUR);
//		fseek(pf, 1, SEEK_SET);
//		ch = fgetc(pf);
//		printf("%c\n", ch);
//		fclose(pf);
//		pf = NULL;
//	}
//	return 0;
//}


//ftell
//#include<stdio.h>
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	else
//	{
//		int ch = fgetc(pf);
//		printf("%c\n", ch);
//		ch = fgetc(pf);
//		printf("%c\n", ch);
//		ch = fgetc(pf);
//		printf("%c\n", ch);
//		//fseek(pf, -2, SEEK_CUR);
//		fseek(pf, 1, SEEK_SET);
//		ch = fgetc(pf);
//		printf("%c\n", ch);
//		printf("%d\n", ftell(pf));//偏移量
//		fclose(pf);
//		pf = NULL;
//	}
//	return 0;
//}


//rewind
//让文件指针的位置回到文件的起始位置
//#include<stdio.h>
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	else
//	{
//		int ch = fgetc(pf);
//		printf("%c\n", ch);
//		ch = fgetc(pf);
//		printf("%c\n", ch);
//		ch = fgetc(pf);
//		printf("%c\n", ch);
//		//fseek(pf, -2, SEEK_CUR);
//		fseek(pf, 1, SEEK_SET);
//		ch = fgetc(pf);
//		printf("%c\n", ch);
//		printf("%d\n", ftell(pf));//偏移量
//		rewind(pf);
//		ch = fgetc(pf);
//		printf("%c\n", ch);
//		fclose(pf);
//		pf = NULL;
//	}
//	return 0;
//}


//文本文件和二进制文件
//根据数据的组织形式,数据文件被称为文本文件或者二进制文件
//数据在内存中以二进制的形式存储,如果不加转换的输出到外存,就是二进制文件
//如果要求在外存上以ASCII码的形式存储,则需要在存储前转换。
//以ASCII字符的形式存储的文件就是文本文件
//字符一律以ASCII形式存储,数值型数据既可以用ASCII形式存储,也可以使用二进制形式存储
//如有整数10000,如果以ASCII码的形式输出到磁盘,则磁盘中占用5个字节(每个字符一个字节)
//而二进制形式输出,则在磁盘上只占4个字节(VS2013测试)
//#include <stdio.h>
//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "wb");
//	fwrite(&a, 4, 1, pf);//二进制的形式写到文件中
//	//10       27       00       00
//	//00010000 00010111 00000000 00000000
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//EOF
//feof
//在文件读取过程中,不能用feof函数的返回值直接用来判断文件的是否结束
//而是应用于当文件读取结束的时候,判断是读取失败结束,还是遇到文件尾结束
//文本文件读取是否结束,判断返回值是否为EOF(fgetc),或者NULL(fgets)
//fgetc判断是否为EOF
//fgets判断返回值是否为NULL
//二进制文件的读取结束判断,判断返回值是否小于实际要读的个数
//fread判断返回值是否小于实际要读的个数
//首先文件读取结束了,结束后想知道文件读取的原因
//feof   --- 返回真,就说明是正常读取遇到了结束标志而结束
//ferror --- 返回真说明是文件读取过程中出错了,结束了