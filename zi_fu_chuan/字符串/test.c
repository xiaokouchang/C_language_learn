#define _CRT_SECURE_NO_WARNINGS 0
//��������
//strlen
//�ַ����Ѿ�'\0'��Ϊ������־
//strlen�������ص������ַ�����'\0'ǰ����ֵ��ַ�����(������'\0')
//size_t strlen(const char* str);
//����ָ����ַ�������Ҫ��'\0'����
//����ĳ��Ȳ������Ǹ���,�����ķ���ֵΪsize_t,���޷��ŵ�
//ѧ��strlen������ģ��ʵ��
//ָ��-ָ��
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


//������
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


//�ݹ�
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
//	//3 - 6 == -3,���޷�����,û�и���,else�����Զ��ִ��
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
//Դ�ַ���������'\0'����
//�ὫԴ�ַ����е�'\0'������Ŀ��ռ�
//Ŀ��ռ�����㹻��,��ȷ���ܴ��Դ�ַ���
//Ŀ��ռ����ɱ�
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


//ģ��ʵ��strcpy
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
//Դ�ַ���������'\0'����
//Ŀ��ռ�������㹻�Ĵ�,��������Դ�ַ���������
//Ŀ��ռ������޸�
//�ַ����Լ����Լ�׷��,���
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


//ģ��ʵ��strcat
//#include<stdio.h>
//#include<assert.h>
//char* my_strcat(char* dest, const char* src)
//{
//	char* ret = dest;
//	assert(dest && src);
//	//��Ŀ��ռ��'\0
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	//׷��
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
//��׼�涨:
//��һ���ַ������ڵڶ����ַ���,�򷵻ش���0������
//��һ���ַ������ڵڶ����ַ���,�򷵻�0
//��һ���ַ���С�ڵڶ����ַ���,�򷵻�С��0������
//��ô����ж������ַ���?
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


//ģ��ʵ��strcmp
//����1
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


//����2
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


//����3
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


//����4
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


//���Ȳ������Ƶ��ַ�������
//strcat strcmp strcpy
//strncpy
//Copies the first num characters of source to destination.
//If the end of the source C string(which is signaled by a null - character) 
//is found before num characters have been copied,
//destination is padded with zeros until a total of num characters 
//have been written to it.
//����num���ַ���Դ�ַ�����Ŀ��ռ�
//���Դ�ַ����ĳ���С��num,�򿽱���Դ�ַ���֮��,��Ŀ��ĺ��׷��\0,ֱ��num��
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


//׷��������һ��'\0'����֤�ַ���
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
//�Ƚϵ���������ַ���һ������һ���ַ�����������num���ַ�ȫ���Ƚ���
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
//	//��ǰ4����ǰ5��һ��
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
//		printf("�Ҳ���\n");
//	}
//	else
//	{
//		printf("�ҵ���\n");
//
//	}
//	return 0;
//}


//ģ��ʵ��strstr
//���1
//abcdef
//bc
//���2
//abbbcdef
//bbc
//����1
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
//		printf("ret1 = �Ҳ���\n");
//	}
//	else
//	{
//		printf("ret1 = �ҵ���\n");
//	}
//	if (ret2 == NULL)
//	{
//		printf("ret2 = �Ҳ���\n");
//	}
//	else
//	{
//		printf("ret2 = �ҵ���\n");
//	}
//	return 0;
//}


//����2
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
//		printf("ret1 = �Ҳ���\n");
//	}
//	else
//	{
//		printf("ret1 = �ҵ���\n");
//	}
//	if (ret2 == NULL)
//	{
//		printf("ret2 = �Ҳ���\n");
//	}
//	else
//	{
//		printf("ret2 = �ҵ���\n");
//	}
//	return 0;
//}


//strtok
//char* strtok(char* str, const char* sep);
//sep�����Ǹ��ַ���,�����������ָ������ַ�����
//��һ������ָ��һ���ַ���
//��������0�����߶����sep�ַ�����һ�����߶���ָ����ָ�ı��
//strtok�����ҵ�str�е���һ�����,��������\0��β,����һ��ָ�������ǵ�ָ��
//strtok������ı䱻�������ַ���
//������ʹ��strtok�����зֵ��ַ���һ�㶼����ʱ���������ݲ��ҿ��޸�
//strtok�����ĵ�һ��������ΪNULL,�������ҵ�str�е�һ�����
//strtok���������������ַ����е�λ��
//strtok�����ĵ�һ������ΪNULL,��������ͬһ���ַ����б������λ�ÿ�ʼ,������һ�����
//����ַ����в����ڸ���ı��,�򷵻�NULLָ��
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
//	strcpy(arr, p);//�����ݿ���һ�ݣ�����arr���������
//	for (str = strtok(arr, sep); str != NULL; str = strtok(NULL, sep))
//	{
//		printf("%s\n", str);
//	}
//}


//�����ϴεĵ�ַ�и�
//��һ��д��
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


//ʹ��ѭ��
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
//���ش�����,����Ӧ�Ĵ�����Ϣ
//char* strerror(int errnum);
//C���ԵĿ⺯�������е�ʱ��,�����������,�Ὣ���������һ��������,���������errno
//��������һЩ����
//��Ҫ�������뷭��ɴ�����Ϣ
//�������ַ��ĵ�ַ
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
//perror��ֱ�Ӵ�ӡ������Ϣ,�ڴ�ӡ������Ϣǰ���ȴ�ӡ�Զ������Ϣ
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


//iscntrl �κο����ַ�
//isspace �հ��ַ�""�ո�,��ҳ'\f',����'\n',�س�'\r',�Ʊ��'\t'���ߴ�ֱ�Ʊ��'\v'
//isdigit ʮ��������0~9
//isxdigit ʮ����������,��������ʮ��������,Сд��ĸa~f,��д��ĸA~F
//islower Сд��ĸa~z
//isupper ��д��ĸA~Z
//isalpha ��ĸa~z��A~Z
//isalnum ��ĸ��������,a~z,A~Z,0~9
//ispunct ������,�κβ��������ֻ�����ĸ��ͼ���ַ�(�ɴ�ӡ)
//isgraph �κ�ͼ���ַ�
//isprint �κοɴ�ӡ�ַ�,����ͼ���ַ��Ϳհ��ַ�
//int tolower(int c);   ��д��ĸתСд��ĸ
//int toupper(int c);   Сд��ĸת��д��ĸ
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


//��Сдת��
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


//memcpy --- �ڴ濽������
//#include<stdio.h>
//#include<assert.h>
//#include<string.h>
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	//����1
//	void* ret = dest;
//	char* m = (char*)dest;
//	char* n = (const char*)src;
//	while (num--)
//	{
//		*m = *n;
//		m++;
//		n++;
//	}
//	//����2
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


//�ص�
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
//�Ƚϴ�ptr1��ptr2ָ�뿪ʼ��num���ֽ�
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
//���ֽ�Ϊ��λ�������ڴ��еĺ���
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