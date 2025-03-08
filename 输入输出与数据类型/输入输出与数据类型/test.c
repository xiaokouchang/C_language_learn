#define _CRT_SECURE_NO_WARNINGS 1 

#define _CRT_SECURE_NO_WARNINGS 1 

//数据类型
//char       字符数据类型
//short      短整型
//int        整形
//long       长整型
//long long  更长的整形
//float      单精度浮点数
//double     双精度浮点数


//#include<stdio.h>
//#include<stdbool.h>
//int main()
//{
//	printf("%zd\n", sizeof(char));
//  printf("%zd\n", sizeof(bool));
//	printf("%zd\n", sizeof(short));
//	printf("%zd\n", sizeof(int));
//	printf("%zd\n", sizeof(long));  //C语言规定sizeof(long) >= sizeof(int）
//	printf("%zd\n", sizeof(long long));
//	printf("%zd\n", sizeof(float));
//	printf("%zd\n", sizeof(double));//8
//	printf("%zd\n", sizeof(long double));
//	return 0;
//}



//sizeof不计算表达式
//sizeof在代码进⾏编译的时候,就根据表达式的类型确定了,类型的常⽤,⽽表达式的执⾏却要在
//程序运⾏期间才能执⾏,在编译期间已经将sizeof处理掉了,所以在运⾏期间就不会执⾏表达式了
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	short s = 2;
//	int b = 10;
//	printf("%zd\n", sizeof(int));
//	printf("%zd\n", sizeof(a));
//	printf("%zd\n", sizeof(a + 3));//int + int = int
//	printf("%zd\n", sizeof(a + 3.14));//int + double = double
//	printf("%zd\n", sizeof(a + 3.14));//int + double = double
//	printf("%zd\n", sizeof(s = b + 1));//int + int > short
//	printf("%d\n", s);
//	return 0;
//}


//unsigned
//signed
//signed   ---- 关键字,表⽰⼀个类型带有正负号,包含负值
//unsigned ---- 关键字,表⽰该类型不带有正负号,只能表⽰零和正整数
//对于int类型,默认是带有正负号的,也就是说int等同于signed int
//整数变量声明为unsigned的好处是,同样长度的内存能够表⽰的最⼤整数值,增⼤了⼀倍
//C语言规定char类型默认是否带有正负号,由当前系统决定。 
//这就是说,char不等同于signed char,它有可能是signed char,也有可能是unsigned char
//%d ---- 打印有符号的整数 ---- signed int
//%u ---- 打印无符号的整数 ---- unsigned int
//%lu ---- unsigned long
//%llu ---- unsigned long


//变量:经常变化的值
//常量:不变的值
//数据类型+变量名
//#include<stdio.h>
//#include<limits.h>//整型类型的取值范围
//#include<float.h>//浮点型类型的取值范围
//
//int main()
//{
//	int age = 20;//初始化
//	char ch = 'q';
//  double price = 66.6;
//	return 0;
//}


//常量：不变的量
//变量
//#include<stdio.h>
//
//int main()
//{	
//	short age = 20;
//	int high = 180;
//	float weight = 88.5;
//	return 0;
//}


//局部变量:{}内部定义的变量
//全局变量:{}外部定义的变量
//当全局变量和局部变量的名字相同的情况下,局部变量优先
//全局变量：在⼤括号外部定义的变量就是全局变量
//作用域
//局部变量的作用域是变量所在的局部范围。
//全局变量的作用域是整个工程。
//生命周期
//局部变量的生命周期是：进入作用域生命周期开始，出作用域生命周期结束。
//全局变量的生命周期是：整个程序的生命周期。
//局部变量是放在内存的栈区
//全局变量是放在内存的静态区

//#include<stdio.h>
//
//a = 100;
//int main()
//{
//	int a = 10;
//	printf("%d\n", a);
//	return 0;
//}


//#include<stdio.h>
//
//extern int val;//声明外部符号
//
//int main()
//{
//	printf("%d\n", val);
//	return 0;
//}


//#include<stdio.h>
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int sum = 0;
//	scanf("%d %d", &a, &b);//输入函数
//	sum = a + b;
//	printf("%d\n", sum);//输出函数
//	return 0;
//}


//常量
//字面常量
//#include<stdio.h>
//
//int main()
//{
//	30;
//	3.14;
//	'w';
//	"abc"//字符串常量
//	return 0;
//}


//+ - * /
//对除号来说,如果两边的数都是整数,计算的是整数的除法,不会得到小数的
//除号的两端有小数,计算的是小数除法
//%f是用来打印小数的,小数点默认是6位的
//#include<stdio.h>
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("%d\n", 2 - 1);
//	printf("%d\n", a + 4);
//	printf("%d\n", a * b);
//	printf("%.1f\n", 6.0 / 4.0);
//	return 0;
//}


//% ---- 取模(余)运算符 --- 只能用于整数
//获得整除后的余数
//负数求模的规则是结果的正负号由第⼀个运算数的正负号决定
//#include <stdio.h>
//int main()
//{
//	int score = 5;
//	score = (score / 20.0) * 100;
//	printf("%d\n", score);
//	printf("%d\n", 6 % 5);
//	printf("%d\n", 6 % -5);
//	printf("%d\n", -6 % 5);
//	printf("%d\n", -6 % -5);
//	return 0;
//}


//= --- 赋值操作符
//#include<stdio.h>
//int main()
//{
//	//int a = 0;//初始化,创建变量,不是赋值
//	//a = 10;//赋值
//	int a = 3;
//	int b = 5;
//	int c = 7;
//	c = b = a + 3;//连续赋值
//	printf("c = %d b = %d\n", c, b);
//	return 0;
//}


// += -= *= /=
//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	a += 3;//a = a + 3;
//	return 0;
//}


//单目操作符
//++ -- 
//#include<stdio.h>
//int main()
//{
//	int a = 5;
//	int b = a++;//后置++,a一定会+1,先使用,后+1
//	int c = ++a;//前置++,a一定会+1,先+1,后使用
//	printf("a = %d b = %d\n", a, b);
//	printf("a = %d c = %d\n", a, c);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int a = 5;
//	int b = a--;//后置--,a一定会-1,先使用,后-1
//	int c = --a;//前置--,a一定会-1,先-1,后使用
//	printf("a = %d b = %d\n", a, b);
//	printf("a = %d c = %d\n", a, c);
//	return 0;
//}



//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	printf("%d\n", a--);
//	printf("%d\n", a);
//	return 0;
//}


//#include <stdio.h>
//#include <limits.h>
//int main() 
//{
//    printf("INT_MIN = %d\n", INT_MIN);
//    printf("INT_MAX = %d\n", INT_MAX);
//    return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int a = 1;
//	printf("%d\n", (++a) + (++a) + (++a));//错误的,语法没错误
//	return 0;
//}


//运算符 + 对正负值没有影响,是⼀个完全可以省略的运算符
//运算符-⽤来改变⼀个值的正负号,负数的前⾯加上-就会得到正数,正数的前⾯加上-会得到负数
//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	printf("%d\n", +a);
//	printf("%d\n", -a);
//	return 0;
//}


//强制类型转换 --- 操作符
//#include<stdio.h>
//int main()
//{
//	int a = (int)3.14;
//	printf("%d\n", a);//只保留整数部分
//	return 0;
//}


//scanf  printf
//printf的作⽤是将参数⽂本输出到屏幕。
//printf⾥⾯的f代表format(格式化),表⽰可以定制输出⽂本的格式
//占位符,就是这个位置可以用其他值替换
//占位符的第⼀个字符⼀律为百分号%,第⼆个字符表⽰占位符的类型,%d表⽰这里代入的值必须是⼀个整数


//#include <stdio.h>
//int main() 
//{
//    int num1 = 10, num2 = 20, num3 = 30;
//    // 使用多个%d占位符输出整数
//    printf("三个整数分别为：%d，%d，%d\n", num1, num2, num3);
//
//    return 0;
//}


//#include<stdio.h>
//
//int main()
//{
//	printf("%d\n", 100);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	printf("there are %d apples\n", 3);
//	printf("%s will come tonight\n", "zhangsan");
//	return 0;
//}


//如果有n个占位符,printf()的参数就应该有n+1个。
//如果参数个数少于对应的占位符,printf()可能会输出内存中的任意值
//多个占位符
//#include<stdio.h>
//int main()
//{
//	printf("%s says it is %d o'clock\n","zhangsan",8);
//	return 0;
//}


//占位符
//%a   ：⼗六进制浮点数,字⺟输出为⼩写。
//%A   ：⼗六进制浮点数,字⺟输出为⼤写。
//%c   ：字符 
//%d   ：⼗进制整数。
//%e   ：使⽤科学计数法的浮点数,指数部分的e为⼩写。
//%E   ：使⽤科学计数法的浮点数,指数部分的E为⼤写。
//%i   ：整数,基本等同于%d。
//%f   ：⼩数(包含float类型和double类型)。//float %f    double - %lf 
//%g   ：6个有效数字的浮点数。整数部分⼀旦超过6位,就会⾃动转为科学计数法,指数部分的e为⼩写。
//%G   ：等同于%g,唯⼀的区别是指数部分的E为⼤写。
//%hd  ：⼗进制short int 类型。
//%ho  ：⼋进制short int 类型。
//%hx  ：⼗六进制short int 类型。
//%hu  ：unsigned short int 类型。
//%ld  ：⼗进制long int类型。
//%lo  ：八进制long int类型。
//%lx  ：⼗六进制long int类型。
//%lu  ：unsignedlong int类型。
//%lld ：⼗进制long long int类型。
//%llo ：⼋进制long long int类型。
//%llx ：⼗六进制long long int类型。
//%llu ：unsigned long long int类型。
//%Le  ：科学计数法表⽰的long double类型浮点数。
//%Lf  ：long double 类型浮点数。
//%n   ：已输出的字符串数量。该占位符本⾝不输出，只将值存储在指定变量之中。
//%o   ：⼋进制整数。
//%p   ：指针（⽤来打印地址）。
//%s   ：字符串。
//%u   ：⽆符号整数（unsigned int）。
//%x   ：⼗六进制整数。
//%zd  ： size_t 类型。
//%%   ：输出⼀个百分号。


//限定宽度
//%5d表⽰这个占位符的宽度⾄少为5位。如果不满5位,对应的值的前⾯会添加空格。
//输出的值默认是右对⻬,即输出内容前⾯会有空格
//如果希望改成左对⻬,在输出内容后⾯添加空格,可以在占位符的%的后⾯插⼊⼀个-号
//#include<stdio.h>
//int main()
//{
//	printf("%dxxxx\n", 123);
//	printf("%05dxxxx\n", 123);//右对齐,可以用0填充,不能用其他的
//	printf("%-5dxxxx\n", 123);//左对齐
//	printf("%dxxxx\n", 123456);
//	return 0;
//}


//限定小数位数
//#include<stdio.h>
//int main()
//{
//	printf("%12f\n", 123.456);//默认小数点后面6位
//	printf("%12.3f\n", 123.456);
//	printf("%.2f\n", 123.456);//如果不足,则四舍五入
//	printf("%*.*f\n", 5,2,0.5);//5对应%*.*f中的第一个*,2对应%*.*f的第二个*。0.5对应%*.*f
//	return 0;
//}


//总是显示正负号
//#include<stdio.h>
//int main()
//{
//	printf("%+d\n", 12);
//	printf("%-d\n", -12);
//	return 0;
//}


//输出部分字符串
//#include<stdio.h>
//int main()
//{
//	printf("%s\n", "abcdefg");
//	printf("%.3s\n", "abcdefg");
//	printf("%10s\n", "abcdefg");//输出宽度
//	return 0;
//}


//scanf
//不能检测放进数的多少
//scanf_s是vs提供的,其他编译器不认识,代码存在跨平台性问题
//不建议使用scanf_s,建议使用scanf
//如果不点显示所有模版,之间新建源文件,开头没有#define _CRT_SECURE_NO_WARNINGS 1 
//一个占位符
//#include<stdio.h>
//int main()
//{
//	int score = 0;
//	printf("请输入成绩:");
//	scanf("%d", &score);
//	printf("成绩是:%d\n", score);
//	return 0;
//}


//scanf()函数⽤于读取⽤⼾的键盘输入。
//程序运行到这个语句时,会停下来,等待⽤户从键盘输入。
//⽤户输入数据、按下回车键后,scanf()就会处理⽤户的输⼊,将其存入变量
//scanf()处理数值占位符时,会⾃动过滤空⽩字符,包括空格、制表符、换⾏符等
//多个占位符
//#include<stdio.h>
//int main()
//{
//	int i,j;
//	float m, n;
//	scanf("%d%d%f%f", &i,&j,&m,&n);//输入数据时中间加空格
//	printf("i = %d\nj = %d\nm = %.1f\nn = %.0f\n", i,j,m,n);
//	return 0;
//}


//scanf()处理⽤⼾输入的原理是,⽤户的输入先放入缓存,等到按下回车键后,按照占位符对缓存进⾏解读。
//解读⽤户输⼊时,会从上⼀次解读遗留的第⼀个字符开始,直到读完缓存,或者遇到第⼀个不符合条件的字符为⽌
//如果输入    -13.45e12# 0,读到13会停止,不读小数点
//小数可能在内存中不能精确保存
//#include<stdio.h>
//
//int main()
//{
//	int x;
//	float y;
//	scanf("%d", &x);
//	printf("%d\n", x);
//	scanf("%d", &y);
//	printf("%d\n", y);
//	return 0;
//}


//scanf()的返回值是⼀个整数,表⽰成功读取的变量个数。
//如果没有读取任何项,或者匹配失败,则返回0。
//如果在成功读取任何数据之前,发⽣了读取错误或者遇到读取到⽂件结尾,则返回常量EOF(-1)。
//EOF - end of file ⽂件结束标志
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int r = scanf("%d%d%d", &a, &b, &c);
//	printf("a = %d b = %d c =%d\n", a, b, c);
//	printf("r = %d\n", r);//按三次ctrl+z,输出r为-1,即EOF,scanf会读取失败
//	return 0;
//}
//Devc++按一次就可以


//scanf的返回值
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	while(scanf("%d %d", &a, &b)!= EOF)//scanf的返回值
//	{
//		int r = a + b;
//		printf("%d\n", r);
//	}
//	return 0;
//}


//占位符
//%c  ：字符
//%d  ：整数
//%f  ：float类型浮点数
//%lf ：double类型浮点数
//%Lf ：long double 类型浮点数
//%s  ：字符串
//%[] ：在⽅括号中指定⼀组匹配的字符(⽐如%[0-9]),遇到不在集合之中的字符,匹配会停⽌。
//上⾯所有占位符之中,除了%c以外,都会⾃动忽略起首的空⽩字符
//%c不忽略空⽩字符,总是返回当前第⼀个字符,⽆论该字符是否为空格
//#include<stdio.h>
//int main()
//{
//	char ch = 0;
//	scanf("%c", &ch);//输入空格,scanf不会跳过空格,%前面加上空格,会跳过空格
//	printf("----%c----\n", ch);
//	return 0;
//}


//占位符%s,它其实不能简单地等同于字符串。
//从当前第⼀个非空白字符开始读起,直到遇到空⽩字符(即空格、换⾏符、制表符等)为⽌。
//因为%s不会包含空白字符,所以无法⽤来读取多个单词,除非多个%s⼀起使⽤。
//scanf()不适合读取可能包含空格的字符串,比如书名或歌曲名。
//scanf()遇到%s占位符,会在字符串变量末尾存储⼀个空字符\0
//#include<stdio.h>
//int main()
//{
//	char arr[20] = { 0 };
//	//输入hello world会输出hello,scanf不能读取空格,且会在hello后面加上\0
//	//想要读取单词,写成如下形式
//	//scanf("%[^\n]s", arr);//一直读取,直到遇到\n为止
//	//scanf("%s", &arr);
//	printf("%s", arr);
//	return 0;
//}


//scanf()将字符串读⼊字符数组时, 不会检测字符串是否超过了数组⻓度。
//储存字符串时很可能会超过数组的边界
//为了防止这种情况,使⽤%s占位符时,应该指定读入字符串的最长长度。
//即写成%[m]s,其中的[m]是⼀个整数,表⽰读取字符串的最⼤长度,后⾯的字符将被丢弃
//#include <stdio.h>
//int main()
//{
//	char name[11];
//	scanf("%10s", name);//最多读10个,因为后面有\0
//	return 0;
//}


//scanf()提供了⼀个赋值忽略符只要把*加在任何占位符的百分号后⾯
//该占位符就不会返回值,解析后将被丢弃
//#include<stdio.h>
//int main()
//{
//	int year = 0;
//	int month = 0;
//	int day = 0;
//	scanf("%d%*c%d%*c%d", &year, &month, &day);
//	printf("year = %d\nmonth = %02d\nday = %02d\n", year, month, day);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int year = 0;
//	int month = 0;
//	int day = 0;
//	scanf("%4d%2d%2d", &year, &month, &day);
//	printf("year = %d\nmonth = %02d\nday = %02d\n", year, month, day);
//	return 0;
//}