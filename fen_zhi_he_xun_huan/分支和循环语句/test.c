#define _CRT_SECURE_NO_WARNINGS 1 

#define _CRT_SECURE_NO_WARNINGS 1 
//if语句的语法形式如下:
//if(表达式)
//     语句
//输入一个整数,判断是否为奇数
//== --- 判断相等
// = --- 赋值
//#include<stdio.h>
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	if (num % 2 == 1)
//	{
//		printf("这个数是奇数\n");
//	}
//	return 0;
//}


//if -  else语句的语法形式如下:
//if(表达式)
//     语句
//else
//     语句
//#include<stdio.h>
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	if (num % 2 == 1)//可以不写==1,结果是0,为假,不执行
//	{
//		printf("这个数是奇数\n");
//	}
//	else
//	{
//		printf("这个数是偶数\n");
//	}
//	return 0;
//}


//输⼊⼀个年龄,>=18岁就输出：成年,否则就输出：未成年
//#include<stdio.h>
//
//int main()
//{
//	int age = 0;
//	scanf("%d", &age);
//	if (age >= 18)//if默认后面只能控制一条语句,如果要包括多条语句,使用大括号
//	{
//		printf("成年人\n");
//	}
//	else
//	{
//		printf("未成年\n");
//	}
//	return 0;
//}


//if -  else if - else 语句的语法形式如下:
//if(表达式)
//		语句
//else if(表达式)
//		语句
//else
//		语句
//#include<stdio.h>
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	if (num == 0)
//	{
//		printf("是0\n");
//	}
//	else if (num > 0)
//	{
//		printf("这个数是正数\n");
//	}
//	else
//	{
//		printf("这个数是负数\n");
//	}
//	return 0;
//}


//if else的嵌套
//输⼊⼀个整数，如果是正数，再判断是奇数还是偶数，并输出；如果不是正数则输出：⾮正数。
//#include <stdio.h>
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	if(num > 0)
//	{
//		if (num % 2 == 0)
//			printf("偶数\n");
//		else
//			printf("奇数\n");
//	} 
//	else
//	{
//		printf("非正数\n");
//	}
//	return 0;
//}


//输入⼀个人的年龄
//如果年龄<18岁,打印"少年"
//如果年龄在18岁⾄44岁打印"⻘年"
//如果年龄在45岁⾄59岁打印"中⽼年"
//如果年龄在60岁⾄89岁打印"⽼年"
//如果90岁及以上打印"⽼寿星"
//#include<stdio.h>
//
//int main()
//{
//	int age = 0;
//	scanf("%d", &age);
//	if (age < 18)
//	{
//		printf("少年\n");
//	}
//	else if (age >= 18 && age <= 44)
//	{
//		printf("青年\n");
//	}
//	else if (age >= 45 && age <= 59)
//	{
//		printf("中年\n");
//	}
//	else if (age >= 60 && age <= 89)
//	{
//		printf("老年\n");
//	}
//	else
//	{
//		printf("老寿星\n");
//	}
//	return 0;
//}


//悬空else
//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)
//		if (b == 2)
//			printf("hehe\n");
//		else
//			printf("haha\n");
//	return 0;
//}
//如果有多个if和else,可以记住这样⼀条规则else总是跟最接近的if匹配。
//让else和第⼀个if语句对⻬,让我们以为else是和第⼀个if匹配的
//当if语句不成⽴的时候,⾃然想到的就是执⾏else⼦句,打印haha
//实际上else是和第⼆个if进⾏匹配的,这样后边的if...else语句是嵌套在第⼀个if语句中的
//如果第⼀个if语句就不成⽴嵌套if和else就没机会执⾏了,最终啥都不打印。


//关系操作符
//>= <= == > < !=
//0 || 1
//#include<stdio.h>
//
//int main()
//{
//	int r = 20 > 12;
//	printf("%d\n", r);
//	return 0;
//}


//如果一个变量和一个常量比较大小时,建议将常量写在等号左边
//#include<stdio.h>
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	if (3 == a)
//	{
//		printf("hehe\n");
//	}
//	else
//	{
//		printf("haha\n");
//	}
//	return 0;
//}


//C语言关系运算符不适合连用,使用与或非
//#include<stdio.h>
//
//int main()
//{
//	int i = 3;
//	int j = 4;
//	int k = 5;
//	if (i < j < k)
//	{
//		printf("hehe\n");
//	}
//	else
//	{
//		printf("haha\n");
//	}
//	return 0;
//}


//我们输⼊⼀个年龄,如果年龄在18岁~36岁之间,我们输出⻘年。 
//#include<stdio.h>
//
//int main()
//{
//	int age = 0;
//	scanf("%d", &age);
//	if (age >= 18 || age <= 36)
//	{
//		printf("青年\n");
//	}
//	return 0;
//}


//条件操作符也叫三⽬操作符,C语言唯一一个,需要接受三个操作数的,形式如下：
//exp1 ? exp2 : exp3
//条件操作符的计算逻辑是：如果exp1为真,exp2计算的结果是整个表达式的结果
//如果exp1为假,exp3计算的结果是整个表达式的结果。
//#include<stdio.h>
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d", &a);
//	b = a > 5 ? 3 : -3;
//	printf("%d\n", b);
//	return 0;
//}


//逻辑操作符：&&, || , ！
//逻辑运算符提供逻辑判断功能,⽤于构建更复杂的表达式,主要有下⾯三个运算符。
//!  ：逻辑取反运算符(改变单个表达式的真假)。
//&& ：逻辑与运算符,就是并且的意思(两侧的表达式都为真,则为真,否则为假)。
//|| ：逻辑或运算符,就是或者的意思(两侧⾄少有⼀个表达式为真,则为真,否则为假)。
//注：C语言中,非0表⽰真,0表⽰假
//#include<stdio.h>
//
//int main()
//{
//	int flag = 0;
//	scanf("%d", &flag);
//	if (!flag)//flag为假做什么
//	{
//		printf("hehe\n");
//	}
//	else
//	{
//		printf("haha\n");
//	}
//	return 0;
//}


//闰年的判断
//能被4整除并且不能被100整除是闰年 
//能被400整除是闰年
//第一种方法
//#include<stdio.h>
//
//int main()
//{
//	int year = 0;
//	scanf("%d", &year);
//	if (year % 4 == 0 && year % 100 != 0)
//	{
//		printf("这年是闰年\n");
//	}
//	else if (year % 400 == 0)
//	{
//		printf("这年是闰年\n");
//	}
//	else
//	{
//		printf("这年不是闰年\n");
//	}
//	return 0;
//}


//第二种方法
//#include<stdio.h>
//
//int main()
//{
//	int year = 0;
//	scanf("%d", &year);
//	if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//	{
//		printf("这年是闰年\n");
//	}
//	else
//	{
//		printf("这年不是闰年\n");
//	}
//	return 0;
//}


//C语言逻辑运算符还有⼀个特点,它总是先对左侧的表达式求值,再对右边的表达式求值
//如果左边的表达式满⾜逻辑运算符的条件,就不再对右边的表达式求值。这种情况称为“短路”
//根据左操作数的结果就能知道整个表达式的结果,不再对右操作数进⾏计算的运算称为短路求值
//#include <stdio.h>
//int main()
//{
//	int i = 0, a = 0, b = 2, c = 3, d = 4;
//	i = a++ && ++b && d++;
//	//i = a++||++b||d++;
//	printf("a = %d\n b = %d\n c = %d\nd = %d\n", a, b, c, d);//不会计算
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int i = 0, a = 1, b = 2, c = 3, d = 4;
//	i = a++ && ++b && d++;
//	//i = a++||++b||d++;
//	printf("a = %d\n b = %d\n c = %d\nd = %d\n", a, b, c, d);//不会计算
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int i = 0, a = 0, b = 2, c = 3, d = 4;
//	//i = a++ && ++b && d++;
//	i = a++||++b||d++;
//	printf("a = %d\n b = %d\n c = %d\nd = %d\n", a, b, c, d);//不会计算
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int i = 0, a = 1, b = 2, c = 3, d = 4;
//	//i = a++ && ++b && d++;
//	i = a++||++b||d++;
//	printf("a = %d\n b = %d\n c = %d\nd = %d\n", a, b, c, d);//不会计算
//	return 0;
//}


//switch
//switch语句⽤于判断条件有多个结果的情况。
//它把多重的else if改成更易⽤、可读性更好的形式。
//switch后的expression必须是整型表达式
//case后的值必须是整形常量表达式
//switch (expression) -----整型
//{
//case value1: statement
//case value2: statement
//	...
//default: statement
//}
//输入任意一个整数值,计算除3之后的余数
//if else
//#include<stdio.h>
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	if (num % 3 == 0)
//	{
//		printf("余数是0\n");
//	}
//	else if(num % 3 == 1)
//	{
//		printf("余数是1\n");
//	}
//	else
//	{
//		printf("余数是2\n");
//	}
//	return 0;
//}


//switch case语句 
//case决定入口,break决定出口
//#include<stdio.h>
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	switch (num % 3)
//	{
//	case 0:
//		printf("没有余数\n");
//		break;
//	case 1:
//		printf("余数是1\n");
//		break;
//	case 2:
//		printf("余数是2\n");
//		break;
//	}
//	return 0;
//}


//输入1~7的数字,打印对应的星期几
//#include<stdio.h>
//int main()
//{
//	int day = 0; 
//	scanf("%d", &day);
//	switch(day)
//	{
//	case 1:
//		printf("星期一\n");
//		break;
//	case 2:
//		printf("星期二\n"); 
//		break;
//	case 3:
//		printf("星期三\n"); 
//		break;
//	case 4:
//		printf("星期四\n"); 
//		break;
//	case 5:
//		printf("星期五\n");
//		break;
//	case 6:
//		printf("星期六\n");
//		break;
//	case 7:
//		printf("星期日\n");
//		break;
//	}
//	return 0;
//}


//输⼊1~5,输出的是⼯作⽇; 输⼊6~7,输出休息⽇
//default和case没有顺序要求,取决于编码习惯
//#include<stdio.h>
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("工作日\n");
//		break;
//	case 6:
//	case 7:
//		printf("休息日\n");
//		break;
//    default:
//		printf("输入错误,请输入1~7的数字\n");
//		break;
//	}
//	return 0;
//}


//ctrl+shift+v----显示剪贴板
//编辑----高级----快捷键
//0表示假
//非0表示真
//打印1~10
//#include<stdio.h>
//int main()
//{
//	int i = 1;
//	while (i<=10)
//	{
//		printf("%d\n",i);
//		i++;
//	}
//	return 0;
//}


//输入一个整数,逆序打印这个数的每一位
//#include<stdio.h>
//int main()
//{
//	int num;
//	scanf("%d", &num);
//	while (num != 0)
//	{
//		printf("%d ", num % 10);
//		num = num / 10;
//	}
//	return 0;
//}


//for循环的语法形式如下：
//for循环固定的循环次数
//for (表达式1; 表达式2; 表达式3)
//	语句;//如果循环体想包含更多的语句，可以加上⼤括号
//表达式1 ⽤于循环变量的初始化
//表达式2 ⽤于循环结束条件的判断
//表达式3 ⽤于循环变量的调整
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 10; i++)
//	{
//		printf("%d ", i);
//	}
//	return 0;
//}


//计算1~100之间3的倍数的数字之和
//方法一
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int sum = 0;
//	for (i = 1; i < 101; i++)
//	{
//		if (i % 3 == 0)
//		{
//			sum = sum + i;
//		}
//	}
//	printf("sum = %d\n", sum);
//	return 0;
//}


//方法二
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int sum = 0;
//	for (i = 3; i < 101; i += 3)
//	{
//		sum = sum + i;
//	}
//	printf("sum = %d\n", sum);
//	return 0;
//}


//在循环语句中do while语句的使⽤最少,它的语法如下：
//do
//	语句;
//while(表达式);
//do while循环至少循环一次
//#include<stdio.h>
//int main()
//{
//	int i = 1;
//	do
//	{
//		printf("%d ", i);
//		i++;
//	} while (i <= 10);
//	return 0;
//}


//输⼊⼀个正整数,计算这个整数是⼏位数
//例如:
//输⼊:1234    输出：4
//输⼊:12      输出：2
//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	int count = 0;
//	scanf("%d", &n);
//	do
//	{
//		count++;
//		n = n / 10;
//	} while (n != 0);
//	printf("%d\n", count);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
//		{
//			break;
//		}
//		printf("%d ", i);
//		i++;
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
//		{
//			continue;
//		}
//		printf("%d ", i);
//		i++;
//	}
//	return 0;
//}


//for循环的变种
//#include<stdio.h>
//
//int main()
//{
//	int i = 0;
//	for (i = 0;i < 10;i++)//循环的3个步骤可以不写,判断不写恒为真,死循环
//	{
//		printf("%d\n", i);
//	}
//	return 0;
//}


//素数
//方法一
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 100;i <= 200;i++)
//	{
//		int flag = 1;
//		for (j = 2;j <= i - 1;j++)
//		{
//			if (i % j == 0)
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (flag == 1)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}


//方法二
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 101;i <= 999;i+=2)
//	{
//		int flag = 1;
//		for (j = 2;j <= sqrt(i);j++)
//		{
//			if (i % j == 0)
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (flag == 1)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}





//C语言提供了⼀种非常特别的语法,就是goto语句和跳转标号
//goto语句可以实现在同⼀个函数内跳转到设置好的标号处。
//#include <stdio.h>
//int main()
//{
//	printf("hehe\n");
//	goto next;
//	printf("haha\n");
//
//next:
//	printf("跳过了haha的打印\n");
//	return 0;
//}


//for (...)
//{
//	for (...)
//	{
//		if (disaster)
//		{
//			goto error;
//		}
//	}
//}
//error :
//...


//关机程序
//程序运行后,电脑在1分钟后关机
//输入我是猪,取消关机
//shutdown -s -t 60 //倒计时60s关机 
//shutdown -a
//strcmp(str1,str2) int类型
//如果str1 > str2,返回 >0 的数字
//如果str1 = str2,返回 0
//如果str1 < str2,返回 <0 的数字
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<Windows.h>
//int main()
//{
//	int time = 60;
//	char input[20] = { 0 };
//	system("shutdown -s -t 60");
//	while (1)
//	{
//		int i = 0;
//		for (time = 60;time >= 0;time--) 
//		{
//			printf("你的电脑将在%d秒后关机,如果输入:我是猪,就取消关机\n", time);
//			Sleep(1000);
//			scanf("%s", input);
//		}
//		if (time == 0)
//		{
//			printf("时间到,电脑关机\n");
//		}
//		if (strcmp(input, "我是猪") == 0)
//		{
//			system("shutdown -a");
//			printf("八戒真乖\n");
//			printf("取消关机\n");
//			break;
//		}
//	}
//	return 0;
//}


//猜数字游戏
//rand函数会返回⼀个伪随机数,这个随机数的范围是在0~RAND_MAX之间,这个RAND_MAX的⼤⼩是
//依赖编译器上实现的,但是⼤部分编译器上是32767。
//时间戳:当前时间 - 计算机起始时间(1970-1-1 0:0) = 秒数(秒)
//NULL用来初始化指针变量
//a + rand() % (b - a + 1)生成a ~ b之间的随机数


//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
////菜单: 1.玩游戏 0.退出游戏
//void menu()
//{
//	printf("**************************************\n");
//	printf("*******   1.猜数字      ***************\n");
//	printf("*******   0.退出游戏    ***************\n");
//	printf("**************************************\n");
//}
//
//
////猜数字游戏的逻辑
//void game()
//{
//	int guess = 0;
//	int count = 5;
//	//1.生成随机数
//	int r = rand() % 100 + 1;//1 ~ 100
//	//2.猜数字
//	printf("请输入你猜数字的次数:");
//	scanf("%d", &count);
//	while (count)
//	{
//		printf("目前还有%d次机会\n", count);
//		printf("请猜数字:>");
//		scanf("%d", &guess);
//		if (guess < r)
//		{
//			printf("猜小了\n");
//		}
//		else if (guess > r)
//		{
//			printf("猜大了\n");
//		}
//		else
//		{
//			printf("恭喜你,猜对了\n");
//			break;
//		}
//		count--;
//	}
//	if (count == 0)
//	{
//		printf("很遗憾,%d次机会使用完成,没能猜出数字,结果是:%d\n",count,r);
//	}
//}
//
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));//只调用一次
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//	}while (input);
//}


