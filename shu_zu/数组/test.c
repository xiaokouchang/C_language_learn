#define _CRT_SECURE_NO_WARNINGS 1 

//数组
//数组是⼀组相同类型元素的集合
//数组中存放的是1个或者多个数据,但是数组元素个数不能为0
//数组中存放的多个数据,类型是相同的
//数组分为⼀维数组和多维数组,多维数组⼀般比较多见的是⼆维数组
//⼀维数组创建的基本语法如下:
//type arr_name[常量值]; arr_name --- 数组名,type --- 类型,常量值 --- 元素个数
//数组的创建
//#include<stdio.h>
//int main()
//{
//	int arr[20];
//	char ch[8];
//	return 0;
//}


//数组的初始化
//#include<stdio.h>
//int main()
//{
//	int arr1[5] = { 1,2,3,4,5 };//完全初始化
//	int arr2[5] = { 1 };//不完全初始化,剩余的元素默认为0
//	int arr3[5] = { 1,2,3,4,5,6 };//初始化太多
//	return 0;
//}


//数组的类型
//#include<stdio.h>
//int main()
//{
//	int a;
//	int data1[5];//int --- 数组元素的类型
//	//数组的类型是:去掉数组名剩下的是类型,int [5]
//	int data2[10];
//	//data2的类型是int [10]
//	return 0;
//}


//数组类型的大小
//#include<stdio.h>
//int main()
//{
//	double d = 8;
//	printf("%zd\n", sizeof(double));
//	printf("%zd\n", sizeof(d));
//	int data[5] = { 0 };
//	printf("%zd\n", sizeof(data));//5 * sizeof(int) = 20
//	printf("%zd\n", sizeof(int [5]));
//	return 0;
//}


//数组下标 --- 访问元素 
//C语言规定数组是有下标的
//下标是从0开始的,假设数组有n个元素,最后⼀个元素的下标是n-1,下标就相当于数组元素的编号
//[] --- 下标引用操作符
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	//            0 1 2 3 4 5 6 7 8 9
//	arr[3] = 40;//改变数组元素
//	printf("%d\n", arr[3]);
//	return 0;
//}


//arr[i]是数组元素,需要地址。
//arr是数组,不需要地址
//整型元素的操作是逐个元素去处理的,没办法一次性输入,也没办法一次性输出,必须使用循环
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	//输入数据
//	for (i = 0;i < 10;i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	//输出数据
//	for (i = 0;i < 10;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//字符数组当存放多个字符的时候,如果末位有\0,就可以当做字符串
//#include<stdio.h>
//int main()
//{
//	char arr[10] = { 'a','b','c','d'};
//	char arr[10] = "abcd";//arr里放着abcd\0
//	//第一种方法
//	//int i = 0;
//	//for (i = 0;i < 4;i++)
//	//{
//	//	printf("%c ", arr[i]);
//	//}
//	//第二种方法
//	printf("%s\n", arr);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int arr1[10] = {1,2,3,4,5,6};
//	int arr2[] = { 1,2,3,4,5,6 };
//
//	return 0;
//}


//x64表示编译产生地址为64位的程序
//x86表示编译产生地址为32位的程序
//一维数组的所有元素在内存中是连续依次存放的,由小(低)到(高)变化
//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int arr[10] = { 0 };
//	int i = 0;
//	for (i = 0;i < 10;i++)
//	{
//		printf("&arr[%d] = %p\n", i, &arr[i]);
//	}
//	return 0;
//}


//sizeof计算数组元素个数
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	//printf("%zd\n", sizeof(arr));//计算的是数组的总长度,单位是字节
//	//printf("%zd\n", sizeof(arr)/sizeof(arr[0]));//计算的是数组的总长度
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0;i < sz;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//一维数组的元素都是内置类型的,如果我们把⼀维数组做为数组的元素,这时候就是⼆维数组
//⼆维数组作为数组元素的数组被称为三维数组,⼆维数组以上的数组统称为多维数组。
//⼆维数组呢语法如下：
//type arr_name[常量值1][常量值2]

//arr[i] == *(arr + i)
//&arr[i] == arr + i

//二维数组的创建
//#include<stdio.h>
//
//int main()
//{
//	int arr1[3][5];//3行5列
//	double data[5][8];
//	return 0;
//}


//二维数组的初始化
//可以省略行,不能省略列
//#include<stdio.h>
//int main()
//{
//	int arr1[3][5] = { 1,2,3 };//不完全初始化
//	int arr2[3][5] = { 1,2,3,4,5,6 };//不完全初始化
//	int arr3[3][5] = { 1,2,3,4,5,6,7,8,9,0,5,4,3,2,1 };//完全初始化
//	int arr4[3][5] = { {1,2,3},{4,5,6,7,8},{9,0,5,4} };//按行初始化
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int arr[3][5] = { 1,2,3,4,5, 2,3,4,5,6, 3,4,5,6,7 };//数组是3行5列
//	//1 2 3 4 5
//	//2 3 4 5 6
//	//3 4 5 6 7
//	printf("%d\n", arr[2][4]);//数组的元素
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int arr[3][5] = { 1,2,3,4,5, 2,3,4,5,6, 3,4,5,6,7 };//数组是3行5列
//	int i = 0;
//	int num = 1;
//	for (i = 0;i < 3;i++)
//	{
//		int j = 0;
//		for (j = 0;j < 5;j++)
//		{
//			arr[i][j] = num++;
//		}
//	}
//	int* p = &arr[0][0];
//	for (i = 0;i < 15;i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	printf("\n");
//	return 0;
//}


//每⼀⾏内部的每个元素都是相邻的,地址之间相差4个字节
//跨⾏位置处的两个元素之间也是差4个字节,所以⼆维数组中的每个元素都是连续存放的
//#include<stdio.h>
//int main()
//{
//	int arr[3][5] = { 0 };
//	int i = 0;
//	for (i = 0;i < 3;i++)
//	{
//		int j = 0;
//		for (j = 0;j < 5;j++)
//		{
//			printf("arr[%d][%d] = %p\n",i,j,&arr[i][j]);
//		}
//	}
//	/*for (i = 0;i < 3;i++)
//	{
//		int j = 0;
//		for (j = 0;j < 5;j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//	}
//	printf("\n");
//
//	int* p = &arr[0][0];
//	for (i = 0;i < 12;i++)
//	{
//		printf("%d ", *(p + i));
//	}*/
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int arr[3][5];
//	int i = 0;
//	for (i = 0;i < 3;i++)
//	{
//		int j = 0;
//		for (j = 0;j < 5;j++)
//		{
//			arr[i][j] = 1;
//		}
//	}
//	for (i = 0;i < 3;i++)
//	{
//		int j = 0;
//		for (j = 0;j < 5;j++)
//		{
//			printf("arr[%d][%d] = %p\n", i, j, &arr[i][j]);
//		}
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int arr1[10] = { 0 };
//	int arr2[3][5] = {0};
//	return 0;
//}


//VS2022使用MSVC
//C99中的变长数组
//在C99标准之前,C语言在创建数组的时候,数组⼤小的指定只能使⽤常量、常量表达式
//如果我们初始化数据的话,可以省略数组⼤小
//C99中给⼀个变长数组,允许我们可以使⽤变量指定数组⼤小
//变长数组的根本特征:数组长度只有运行时才能确定,所以变长数组不能初始化
//它的好处是随意为数组指定⼀个估计的长度,程序可以在运行时为数组分配精确的长度
//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[n];
//	int i = 0;
//	for (i = 0;i < n;i++)
//	{
//		arr[i] = i;
//	}
//	for (i = 0;i < n;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	char arr1[] = { "welcome to xuexiao!!!" };
//	char arr2[] = { "*********************" };
//	printf("%s\n", arr2);
//	int sz = sizeof(arr2) / sizeof(arr2[0]);
//	int right = sz - 2;
//	int left = 0;
//	for (left = 0,right = sz - 2;left <= right;left++,right--)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//	}
//	return 0;
//}


//strlen是求字符串长度的,统计字符串中\0之前的字符个数
//#include<string.h>
//#include<stdio.h>
//#include<Windows.h>
//int main()
//{
//	char arr1[] = { "welcome to xuexiao!!!" };
//	char arr2[] = { "*********************" };
//	int right = strlen(arr2) - 1;
//	int left = 0;
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(1000);//单位是毫秒,
//		system("cls");//清理屏幕
//		left++;
//		right--;
//	}
//	return 0;
//}


//在⼀个升序的数组中查找指定的数字n,找到了就打印下标,找不到就打印找不到
//遍历数组
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int flag = 0;
//	for (i = 0;i < sz;i++)
//	{
//		if (k == arr[i])
//		{
//			flag = 1;
//			printf("找到了,下标是: %d\n", i);
//			break;
//		}
//	}
//	if(flag == 0)
//	{
//		printf("找不到\n");
//	}
//	return 0;
//}


//二分查找(折半查找) ---- 有序
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	printf("请输入你要找的数:");
//	scanf("%d", &k);
//	int left = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int right = sz - 1;
//	int flag = 0;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("找到了,下标是:%d\n", mid);
//			flag = 1;
//			break;
//		}
//	}
//	if (flag == 0)
//	{
//		printf("找不到\n");
//	}
//	return 0;
//}


//排序
//数组传参本质上是数组首元素的地址
//冒泡排序 --- 升序
//两两相邻的元素进行比较
//n个数字需要n - 1次
//#include<stdio.h>
//void sort(int arr[], int x)//void sort(int* arr,int x)//效率高
//{
//	int i = 0;
//	int j = 0;
//  //一次冒泡排序
//	for (j = 0;j < x - 1;j++)
//	{
//		//一次冒泡排序,进行多少对比较
//		for (i = 0;i < x - 1 - j;i++)
//		{
//			if (arr[i] > arr[i + 1])
//			{
//				arr[i] = arr[i] + arr[i + 1];
//				arr[i + 1] = arr[i] - arr[i + 1];
//				arr[i] = arr[i] - arr[i + 1];
//				/*int temp = arr[i];
//				arr[i] = arr[i + 1];
//				arr[i + 1] = temp;*/
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 2,3,0,5,1,4,7,6,9,8 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	sort(arr,sz);
//	int i = 0;
//	for (i = 0;i < sz;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//数组名
//数组名是数组首元素的地址
//但是有两个例外
//1.sizeof(数组名),这里的数组名表示的是整个数组
//计算的是数组的大小,单位是字节
//2.&数组名,这里的数组名是表示整个数组,&数组名取出的是数组的地址
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	//值一样
//	//printf("%p\n", arr);
//	//printf("%p\n", &arr[0]);
//	//printf("%p\n", &arr);
//
//	printf("%p\n", arr);
//	printf("%p\n", arr+1);
//	printf("%p\n", &arr[0]);
//	printf("%p\n", &arr[0]+1);//跳过一个元素
//	printf("%p\n", &arr);
//	printf("%p\n", &arr+1);//跳过整个数组
//	//printf("%d\n", sizeof(arr));
//}


//#include<stdio.h>
//int Add(int x, int y)//x,y是num1,num2的一份临时拷贝
//{
//	return x + y;
//}
//int main()
//{
//	int num1 = 0;
//	int num2 = 0;
//	scanf("%d %d", &num1, &num2);
//	int ret = Add(num1, num2);//传值调用
//	printf("%d\n", ret);
//	return 0;
//}


//#include<stdio.h>
//#include<string.h>
//void sort(int arr[], int sz)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0;i < sz - 1;i++)//进行sz - 1次比较
//	{
//		for (j = 0;j < sz - 1 - i;j++)//进行sz - 1 - i已经排好的数
//		{
//			if (arr[j] < arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//}
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	int arr[100];
//	memset(arr, 0, sizeof(arr));
//	int i = 0;
//	for (i = 0;i < num;i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int sz = num;
//	sort(arr, sz);
//	for (i = 0;i < sz;i++)
//	{
//		printf("%d ",arr[i]);
//	}
//	return 0;
//}