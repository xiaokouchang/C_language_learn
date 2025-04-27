#pragma once
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define MAX 100
#define NAME_MAX 20
#define SEX_MAX 5
#define ADDR_MAX 30
#define TELE_MAX 12
#define DEFAULT_SZ 3   //默认大小
#define INC_SZ 2   //增加大小
//人的信息
typedef struct PeoInfo
{
	char name[20];
	int age;
	char sex[5];
	char addr[30];
	char tele[12];
}PeoInfo;


//通讯录
//typedef struct contact
//{
//	PeoInfo data[MAX];//存放当前人的信息
//	int sz;//当前已经放的信息的总人数
//}contact;

//动态版本
typedef struct contact
{
	PeoInfo* data;//指向存放当前人的信息的空间
	int sz;//当前已经放的信息的总人数
	int capacity;//当前通讯录的最大容量
}contact;


//通讯录初始化
void Initcontact(contact* pc);

//增加联系人
void Addcontact(contact* pc);

//显示通讯录
void Showcontact(const contact* pc);

//删除通讯录
void Delcontact(contact* pc);

//查找联系人
int find_by_name(const contact* pc,char name[MAX]);

//查找联系人
void SearchContact(const contact* pc);

//修改联系人
void Modifycontact(contact* pc);

//排序
void Sortcontact(contact* pc);

//检查容量
void check_capacity(contact* pc);

//销毁通讯录
void DestoryContact(contact* pc);

//保存通讯录中的信息到文件中
void SaveContact(contact* pc);

//加载文件信息到通讯录
void LoadContact(contact* pc);