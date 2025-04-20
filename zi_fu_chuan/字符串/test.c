#define _CRT_SECURE_NO_WARNINGS 0
//函数介绍
//strlen
//字符串已经'\0'作为结束标志
//strlen函数返回的是在字符串中'\0'前面出现的字符个数(不包含'\0')
//size_t strlen(const char* str);
//参数指向的字符串必须要以'\0'结束
//求出的长度不可能是负数,函数的返回值为size_t,是无符号的
//学会strlen函数的模拟实现
//指针-指针
//#include<stdio.h>
//#include<assert.h>
//int my_strlen(const char* arr)
//{
//	assert(arr != NULL);
//	const char* s = arr;
//	while (*s != '\0')
//	{
//		s++;
//	}
//	return s - arr;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int ret = my_strlen(arr);
//	printf("%d\n", ret);
//	return 0;
//}


//计数器
//#include<stdio.h>
//#include<assert.h>
//int my_strlen(char* arr)
//{
//	assert(arr != NULL);
//	int count = 0;
//	char* s = arr;
//	while (*s != '\0')
//	{
//		s++;
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int ret = my_strlen(arr);
//	printf("%d\n", ret);
//	return 0;
//}


//递归
//#include<stdio.h>
//#include<assert.h>
//int my_strlen(char* arr)
//{
//	assert(arr != NULL);
//	if (*arr != '\0')
//	{
//		return 1 + my_strlen(1 + arr);
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int ret = my_strlen(arr);
//	printf("%d\n", ret);
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	const char* str1 = "abcdef";
//	const char* str2 = "bbb";
//	//3 - 6 == -3,是无符号数,没有负数,else语句永远不执行
//	if (strlen(str2) - strlen(str1) > 0)
//	{
//		printf("str2 > str1\n");
//	}
//	else
//	{
//		printf("srt1 > str2\n");
//	}
//	return 0;
//}


//strcpy
//Copies the C string pointed by source into the array pointed by destination
//including the terminating null character(and stopping at that point).
//源字符串必须以'\0'结束
//会将源字符串中的'\0'拷贝到目标空间
//目标空间必须足够大,以确保能存放源字符串
//目标空间必须可变
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr1[20] = "xxxxxxxxxxxxxxx";
//	char arr2[] = "he\0llo world!";
//	strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}


//模拟实现strcpy
//#include<stdio.h>
//#include<assert.h>
//char* my_strcpy(char* dest, const char* src)
//{
//	char* ret = dest;
//	assert(dest && src);
//	while (*dest++ = *src++);
//	return ret;
//}
//int main()
//{
//	char arr1[20] = { 0 };
//	char arr2[] = "he\0llo world!";
//	my_strcpy(arr1, arr2);
//	printf("%s", arr1);
//	return 0;
//}


//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//int my_strcpy(char* arr1, char* arr2)
//{
//	assert(arr1 != NULL);
//	assert(arr2 != NULL);
//	char* s = arr2;
//	int count = 0;
//	while (*s != '\0')
//	{
//		arr1[count++] = *s;
//		s++;
//	}
//	return count;
//}
//int main()
//{
//	char arr1[20] = { 0 };
//	char arr2[] = "he\0llo world!";
//	int ret = my_strcpy(arr1, arr2);
//	int i = 0;
//	for (i = 0;i < ret;i++)
//	{
//		printf("%c", arr1[i]);
//	}
//	printf("\n");
//	return 0;
//}


//strcat
//Appends a copy of the source string to the destination string.
//The terminating null character in destination is overwritten 
//by the first character of source, 
//and a null - character is included at the end of the new string formed 
//by the concatenation of both in destination.
//源字符串必须以'\0'结束
//目标空间必须有足够的大,能容纳下源字符串的内容
//目标空间必须可修改
//字符串自己给自己追加,如何
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr1[20] = "hello ";
//	char arr2[20] = "world!";
//	strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}


//模拟实现strcat
//#include<stdio.h>
//#include<assert.h>
//char* my_strcat(char* dest, const char* src)
//{
//	char* ret = dest;
//	assert(dest && src);
//	//找目标空间的'\0
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	//追加
//	while (*dest++ = *src++);
//	return ret;
//}
//int main()
//{
//	char arr1[20] = "hello ";
//	char arr2[20] = "wor\0ld!";
//	my_strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}


//#include<stdio.h>
//#include<assert.h>
//int my_strlen(char* dest)
//{
//	char* s = dest;
//	while (*s != '\0')
//	{
//		s++;
//	}
//	return s - dest;
//}
//void my_strcat(char* dest, char* src)
//{
//	assert(dest && src);
//	int ret = my_strlen(dest);
//	char* s = src;
//	while (*s != '\0')
//	{
//		dest[ret++] = *s;
//		s++;
//	}
//}
//int main()
//{
//	char arr1[20] = "hello ";
//	char arr2[20] = "wor\0ld!";
//	my_strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}


//strcmp
//int strcmp(const char* str1, const char* str2);
//This function starts comparing the first character of each string.
//If they are equal to each other
//it continues with the following pairs until the 
//characters differ or until a terminating null - character is reached
//标准规定:
//第一个字符串大于第二个字符串,则返回大于0的数字
//第一个字符串等于第二个字符串,则返回0
//第一个字符串小于第二个字符串,则返回小于0的数字
//那么如何判断两个字符串?
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr1[20] = "abc";
//	char arr2[20] = "abc";
//	int ret = strcmp(arr1, arr2);
//	printf("%d\n", ret);
//	return 0;
//}


//模拟实现strcmp
//方法1
//#include<stdio.h>
//#include<assert.h>
//#include<string.h>
//int my_strcmp(const char* str1,const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//		{
//			return 0;
//		}
//		str1++;
//		str2++;
//	}
//	if (*str1 > *str2)
//	{
//		return 1;
//	}
//	else
//	{
//		return -1;
//	}
//}
//int main()
//{
//	char arr1[] = "abq";
//	char arr2[] = "abqef";
//	int ret1 = my_strcmp(arr1, arr2);
//	int ret2 = strcmp(arr1, arr2);
//	printf("ret1 = %d\n", ret1);
//	printf("ret2 = %d\n", ret2);
//	return 0;
//}


//方法2
//#include<stdio.h>
//#include<assert.h>
//#include<string.h>
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//		{
//			return 0;
//		}
//		str1++;
//		str2++;
//	}
//	return *str1 - *str2;
//}
//int main()
//{
//	char arr1[] = "abq";
//	char arr2[] = "abqef";
//	int ret1 = my_strcmp(arr1, arr2);
//	int ret2 = strcmp(arr1, arr2);
//	printf("ret1 = %d\n", ret1);
//	printf("ret2 = %d\n", ret2);
//	return 0;
//}


//方法3
//#include<stdio.h>
//#include<assert.h>
//int my_strcmp(const char* src, const char* dst)
//{
//	int ret = 0;
//	assert(src != NULL);
//	assert(dst != NULL);
//	while (!(ret = *(unsigned char*)src - *(unsigned char*)dst) && *dst)
//	{
//		++src, ++dst;
//	}
//	if (ret < 0)
//	{
//		ret = -1;
//	}
//	else if (ret > 0)
//	{
//		ret = 1;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[] = "abq";
//	char arr2[] = "abqef";
//	int ret1 = my_strcmp(arr1, arr2);
//	int ret2 = strcmp(arr1, arr2);
//	printf("ret1 = %d\n", ret1);
//	printf("ret2 = %d\n", ret2);
//	return 0;
//}


//方法4
//#include<stdio.h>
//#include<assert.h>
//#include<string.h>
//int my_strcmp(char* arr1, char* arr2)
//{
//	assert(arr1 && arr2);
//	int flag = 0;
//	char* a = arr1;
//	char* b = arr2;
//	while (*a != '\0' && *b != '\0')
//	{
//		if (*a == *b)
//		{
//			a++;
//			b++;
//			continue;
//		}
//		else if (*a > *b)
//		{
//			flag = 1;
//			return 1;
//		}
//		else if (*a < *b)
//		{
//			flag = 1;
//			return -1;
//		}
//	}
//	if (flag == 0)
//	{
//		if (*a == '\0' && *b == '\0')
//		{
//			return 0;
//		}
//		else if (*a == '\0' && *b != '\0')
//		{
//			return -1;
//		}
//		else
//		{
//			return 1;
//		}
//	}
//}
//int main()
//{
//	char arr1[] = "abq";
//	char arr2[] = "abc";
//	int ret1 = my_strcmp(arr1, arr2);
//	int ret2 = strcmp(arr1, arr2);
//	printf("ret1 = %d\n", ret1);
//	printf("ret2 = %d\n", ret2);
//	return 0;
//}


//长度不受限制的字符串函数
//strcat strcmp strcpy
//strncpy
//Copies the first num characters of source to destination.
//If the end of the source C string(which is signaled by a null - character) 
//is found before num characters have been copied,
//destination is padded with zeros until a total of num characters 
//have been written to it.
//拷贝num个字符从源字符串到目标空间
//如果源字符串的长度小于num,则拷贝完源字符串之后,在目标的后边追加\0,直到num个
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr1[20] = "xxxxxxxxxxxxxxxxx";
//	const char arr2[20] = "abcdef";
//	strncpy(arr1, arr2, 10);
//	printf("%s\n", arr1);
//	return 0;
//}


//strncat
//Appends the first num characters of source to destination
//plus a terminating null - character.

//If the length of the C string in source is less than num
//only the content up to the terminating null - character is copied.
//char* strncat(char* destination, const char* source, size_t num);
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char str1[20];
//	char str2[20];
//	strcpy(str1, "To be ");
//	strcpy(str2, "or not to be");
//	strncat(str1, str2, 6);
//	puts(str1);
//	return 0;
//}


//追加完后放置一个'\0'来保证字符串
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char str1[20] = "abc\0xxxxxxxxxxxxxxx";
//	char str2[20] = "def";
//	strncat(str1, str2, 2);
//	printf("%s\n", str1);
//	//puts(str1);
//	return 0;
//}


//strncmp
//int strncmp(const char* str1, const char* str2, size_t num);
//比较到出现另个字符不一样或者一个字符串结束或者num个字符全部比较完
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char str[][5] = { "R2D2" , "C3PO" , "R2A6" };
//	int n;
//	puts("Looking for R2 astromech droids...");
//	for (n = 0; n < 3; n++)
//	{
//		if (strncmp(str[n], "R2xx", 2) == 0)
//		{
//			printf("found %s\n", str[n]);
//		}
//	}
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char p1[] = "abcdef";
//	char p2[] = "abcqwer";
//	int ret = strncmp(p1, p2, 4);
//	//比前4个和前5个一样
//	printf("%d\n", ret);
//	return 0;
//}


//strstr
//char* strstr(const char* str1, const char* str2);
//Returns a pointer to the first occurrence of str2 in str1, 
//or a null pointer if str2 is not part of str1.
/* strstr example */
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char str[] = "This is a simple string";
//	char* pch;
//	pch = strstr(str, "simple");
//	strncpy(pch, "sample", 6);
//	puts(str);
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr1[] = "abbcdef";
//	char arr2[] = "bab";
//	char* ret = strstr(arr1, arr2);
//	if (ret == NULL)
//	{
//		printf("找不到\n");
//	}
//	else
//	{
//		printf("找到了\n");
//
//	}
//	return 0;
//}


//模拟实现strstr
//情况1
//abcdef
//bc
//情况2
//abbbcdef
//bbc
//方法1
//#include <string.h>
//#include <assert.h>
//#include <stdio.h>
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	if (*str2 == '\0')
//	{
//		return (char*)str1;
//	}
//	//const char* a = str1;
//	while (*str1 != '\0')
//	{
//		const char* m = str1;
//		const char* n = str2;
//		while (*m != '\0' && *n != '\0' && *m == *n)
//		{
//			m++;
//			n++;
//		}
//		if (*n == '\0')
//		{
//			return (char*)str1;
//		}
//		str1++;
//	}
//	return NULL;
//}
//int main()
//{
//	char arr1[] = "abbbbcdef";
//	char arr2[] = "bbc";
//	char* ret1 = my_strstr(arr1, arr2);
//	char* ret2 = strstr(arr1, arr2);
//	if (ret1 == NULL)
//	{
//		printf("ret1 = 找不到\n");
//	}
//	else
//	{
//		printf("ret1 = 找到了\n");
//	}
//	if (ret2 == NULL)
//	{
//		printf("ret2 = 找不到\n");
//	}
//	else
//	{
//		printf("ret2 = 找到了\n");
//	}
//	return 0;
//}


//方法2
//#include <string.h>
//#include <stdio.h>
//int my_strlen(char* arr2)
//{
//	char* s = arr2;
//	while (*s != '\0')
//	{
//		s++;
//	}
//	return s - arr2;
//}
//char* my_strstr(const char* arr1, const char* arr2)
//{
//	int len = my_strlen(arr2);
//	char* a = arr1;
//	int i = 0;
//	while (*a != '\0')
//	{
//		char* b = a;
//		int flag = 0;
//		if (*b == *arr2)
//		{
//			for (i = 0;i < len;i++)
//			{
//				if (*b == arr2[i])
//				{
//					b++;
//				}
//				else
//				{
//					flag = 1;
//					break;
//				}
//			}
//			if (flag == 0)
//			{
//				return 1;
//			}
//		}
//		a++;
//	}
//	return NULL;
//}
//int main()
//{
//	char arr1[] = "abbbcdef";
//	char arr2[] = "bbc";
//	char* ret1 = my_strstr(arr1, arr2);
//	char* ret2 = strstr(arr1, arr2);
//	if (ret1 == NULL)
//	{
//		printf("ret1 = 找不到\n");
//	}
//	else
//	{
//		printf("ret1 = 找到了\n");
//	}
//	if (ret2 == NULL)
//	{
//		printf("ret2 = 找不到\n");
//	}
//	else
//	{
//		printf("ret2 = 找到了\n");
//	}
//	return 0;
//}


//strtok
//char* strtok(char* str, const char* sep);
//sep参数是个字符串,定义了用作分隔符的字符集合
//第一个参数指定一个字符串
//它包含了0个或者多个由sep字符串中一个或者多个分隔符分割的标记
//strtok函数找到str中的下一个标记,并将其用\0结尾,返回一个指向这个标记的指针
//strtok函数会改变被操作的字符串
//所以在使用strtok函数切分的字符串一般都是临时拷贝的内容并且可修改
//strtok函数的第一个参数不为NULL,函数将找到str中第一个标记
//strtok函数将保存它在字符串中的位置
//strtok函数的第一个参数为NULL,函数将在同一个字符串中被保存的位置开始,查找下一个标记
//如果字符串中不存在更多的标记,则返回NULL指针
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char str[] = "- This, a sample string.";
//	char* pch;
//	printf("Splitting string \"%s\" into tokens:\n", str);
//	pch = strtok(str, " ,.-");
//	while (pch != NULL)
//	{
//		printf("%s\n", pch);
//		pch = strtok(NULL, " ,.-");
//	}
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	char* p = "zhangpengwei@bitedu.tech";
//	const char* sep = ".@";
//	char arr[30];
//	char* str = NULL;
//	strcpy(arr, p);//将数据拷贝一份，处理arr数组的内容
//	for (str = strtok(arr, sep); str != NULL; str = strtok(NULL, sep))
//	{
//		printf("%s\n", str);
//	}
//}


//根据上次的地址切割
//第一种写法
//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//int main()
//{
//	char arr[] = "zxcv@yas.net";
//	char* p = "@.";
//	char buf[20] = { 0 };
//	strcpy(buf, arr);
//	char* pa = strtok(buf, p);
//	printf("%s\n", pa);
//	pa = strtok(NULL, p);
//	printf("%s\n", pa);
//	pa = strtok(NULL, p);
//	printf("%s\n", pa);
//	return 0;
//}


//使用循环
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr[] = "zxcv@yas.net";
//	char* p = "@.";
//	char buf[20] = { 0 };
//	strcpy(buf, arr);
//	char* ret = NULL;
//	for (ret = strtok(buf, p);ret != NULL;ret = strtok(NULL, p))
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}


//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr[] = "192.168.120.85";
//	char* p = "2";
//	char buf[20] = { 0 };
//	strcpy(buf, arr);
//	char* ret = NULL;
//	for (ret = strtok(buf, p);ret != NULL;ret = strtok(NULL, p))
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}


//strerror
//返回错误码,所对应的错误信息
//char* strerror(int errnum);
//C语言的库函数在运行的时候,如果发生错误,会将错误码存在一个变量中,这个变量是errno
//错误码是一些数字
//需要将错误码翻译成错误信息
//返回首字符的地址
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	printf("strerror(0) = %s\n", strerror(0));
//	printf("strerror(1) = %s\n", strerror(1));
//	printf("strerror(2) = %s\n", strerror(2));
//	printf("strerror(3) = %s\n", strerror(3));
//	printf("strerror(4) = %s\n", strerror(4));
//	printf("strerror(5) = %s\n", strerror(5));
//	printf("strerror(6) = %s\n", strerror(6));
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//	FILE* pa = fopen("test.txt", "r");
//	if (pa == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	fclose(pa);
//	return 0;
//}


//perror
//perror是直接打印错误信息,在打印错误信息前会先打印自定义的信息
//perror = printf + strerror
//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//	FILE* pa = fopen("test.txt", "r");
//	if (pa == NULL)
//	{
//		//printf("%s\n", strerror(errno));
//		perror("pa");
//		return 1;
//	}
//	fclose(pa);
//}


//iscntrl 任何控制字符
//isspace 空白字符""空格,换页'\f',换行'\n',回车'\r',制表符'\t'或者垂直制表符'\v'
//isdigit 十进制数字0~9
//isxdigit 十六进制数字,包括所有十进制数字,小写字母a~f,大写字母A~F
//islower 小写字母a~z
//isupper 大写字母A~Z
//isalpha 字母a~z或A~Z
//isalnum 字母或者数字,a~z,A~Z,0~9
//ispunct 标点符号,任何不属于数字或者字母的图形字符(可打印)
//isgraph 任何图形字符
//isprint 任何可打印字符,包括图形字符和空白字符
//int tolower(int c);   大写字母转小写字母
//int toupper(int c);   小写字母转大写字母
//#include<stdio.h>
//#include<ctype.h>
//int main()
//{
//	//int ret = islower('1');
//	//int ret = isdigit('1');
//	char arr[10] = { 'a' };
//	//int ret = isdigit(arr[0]);
//	char ret = toupper(arr[0]);
//	printf("%c\n", ret);
//	return 0;
//}


//大小写转换
//#include<stdio.h>
//#include<string.h>
//#include<ctype.h>
//int main()
//{
//	char arr1[] = "I have An apple.";
//	char arr2[20] = { 0 };
//	strcpy(arr2, arr1);
//	int ret = strlen(arr2);
//	int i = 0;
//	for (i = 0;i < ret;i++)
//	{
//		if (isupper(arr2[i]))
//		{
//			arr2[i] = tolower(arr2[i]);
//		}
//		else
//		{
//			arr2[i] = toupper(arr2[i]);
//		}
//	}
//	printf("%s\n", arr1);
//	printf("%s\n", arr2);
//	return 0;
//}


//memcpy --- 内存拷贝函数
//#include<stdio.h>
//#include<assert.h>
//#include<string.h>
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	//方法1
//	void* ret = dest;
//	char* m = (char*)dest;
//	char* n = (const char*)src;
//	while (num--)
//	{
//		*m = *n;
//		m++;
//		n++;
//	}
//	//方法2
//	//while (num--)
//	//{
//	//	*(char*)dest = *(char*)src;
//	//	dest = (char*)dest + 1;
//	//	src = (char*)src + 1;
//	//}
//	return(ret);
//}
//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[10] = { 0 };
//	int num = 1;
//	int i = 0;
//	for (i = 0;i < 10;i++)
//	{
//		int j = 0;
//		my_memcpy(arr2, arr1, num * sizeof(arr1[0]));
//		for (j = 0;j < num;j++)
//		{
//			printf("%2d ", arr2[j]);
//		}
//		num++;
//		printf("\n");
//	}
//	return 0;
//}


//重叠
//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	if (dest < src)
//	{
//		char* m = dest;
//		const char* n = src;
//		while (num--)
//		{
//			*m = *n;
//			m++;
//			n++;
//		}
//	}
//	else
//	{
//		char* m = (char*)dest + num - 1;
//		const char* n = (char*)src + num - 1;
//		while (num > 0)
//		{
//			*m = *n;
//			m--;
//			n--;
//			num--;
//		}
//	}
//}
////1 2 3 4 5 6 7 8 9 10
////3 4 5 6 7
////3 4 5 6 7 6 7 8 9 10
////1 2 3 4 3 4 5 6 7 10
//int main()
//{
//	int num = 0;
//	int i = 0;
//	my_memmove(arr, arr + 2, 5 * sizeof(arr[0]));
//	//memmove(arr + 2, arr, 5 * sizeof(arr[0]));
//	for (i = 0;i < 10;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}


//memcmp
//比较从ptr1和ptr2指针开始的num个字节
//int memcmp(const void* ptr1,const void* ptr2,size_t num);
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int arr1[] = { 1,2,3 };//01 00 00 00 02 00 00 00 03 00 00 00
//	int arr2[] = { 1,2,5 };//01 00 00 00 02 00 00 00 05 00 00 00
//	int ret = memcmp(arr1, arr2, 9);
//	printf("%d\n", ret);
//	return 0;
//}


//memset
//以字节为单位来设置内存中的函数
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr1[] = "Hello world!";
//	memset(arr1 + 6, 'y', 5);
//	//printf("%s\n", arr);
//	int arr[10] = { 0 };
//	memset(arr, 0, 40);
//	int i = 0;
//	for (i = 0;i < 10;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}