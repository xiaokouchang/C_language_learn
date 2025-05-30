#define _CRT_SECURE_NO_WARNINGS 0 

//测试通讯录

//通讯录
//人的信息:姓名+年龄+性别+地址+电话
//通讯录可以存放100个人的信息
//增加联系人,删除指定联系人,查找指定联系人的信息
//显示所有联系人的信息
//排序(名字,年龄)
#include "contact.h"
enum Option
{
	EXIT,//0
	ADD,//1
	DELETE,//2
	SEARCH,//3
	MODIFY,//4
	SHOW,//5
	SORT//6
};
void menu()
{
	printf("*******************************************\n");
	printf("********   1. add      2. delete   ********\n");
	printf("********   3. search   4. modify   ********\n");
	printf("********   5. show     6. sort     ********\n");
	printf("********   0. exit                 ********\n");
	printf("*******************************************\n");
}
void test()
{
	int input = 0;
	//创建通讯录
	contact con;
	//初始化通讯录
	Initcontact(&con);
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			//保存通讯录信息到文件中
			SaveContact(&con);
			DestoryContact(&con);//销毁通讯录
			printf("退出通讯录\n");
			break;
		case ADD:
			Addcontact(&con);
			break;
		case DELETE:
			Delcontact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			Modifycontact(&con);
			break;
		case SHOW:
			Showcontact(&con);
			break;
		case SORT:
			Sortcontact(&con);
			break;
		default:
			printf("选择错误,请重新输入\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}
