#define _CRT_SECURE_NO_WARNINGS 0 

#include "contact.h"
//初始化通讯录
void Initcontact(contact* pc)
{
	assert(pc);
	pc->sz = 0;
	PeoInfo* ptr = (PeoInfo*)calloc(DEFAULT_SZ, sizeof(PeoInfo));
	if (ptr == NULL)
	{
		perror("Initcontact");
		return;
	}
	pc->data = ptr;
	pc->capacity = DEFAULT_SZ;
	//加载文件信息到通讯录
	LoadContact(pc);
}

//动态添加人数
void Addcontact(contact* pc)
{
	assert(pc);
	check_capacity(pc);
	printf("请输入名字:>\n");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄:>\n");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入性别:>\n");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入地址:>\n");
	scanf("%s", pc->data[pc->sz].addr);
	printf("请输入电话:>\n");
	scanf("%s", pc->data[pc->sz].tele);
	pc->sz++;
}

//显示通讯录
//声明和定义保持一致
void Showcontact(const contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%-20s\t%-4s\t%-5s\t%-20s\t%-12s\n", "姓名", "年龄", "性别", "地址", "电话");
	for (i = 0;i < pc->sz;i++)
	{
		printf("%-20s\t%-4d\t%-5s\t%-20s\t%-12s\n", pc->data[i].name, pc->data[i].age,
			pc->data[i].sex, pc->data[i].addr, pc->data[i].tele);
	}
}

//删除指定联系人
void Delcontact(contact* pc)
{
	assert(pc);
	if (pc->sz == 0)
	{
		printf("通讯录为空,无法删除\n");
		return;
	}
	char name[MAX] = { 0 };
	printf("请输入要删除人的名字:>\n");
	scanf("%s", name);
	int ret = find_by_name(pc, name);
	int i = 0;
	if (-1 == ret)
	{
		printf("要删除的人不存在\n");
		return;
	}
	else
	{
		//删除
		for (i = ret;i < pc->sz - 1;i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->sz--;
		printf("删除成功\n");
	}
}

//查找联系人
int find_by_name(const contact* pc, char name[MAX])
{
	assert(pc);
	int i = 0;
	for (i = 0;i < pc->sz;i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}


void SearchContact(const contact* pc)
{
	assert(pc);
	char name[NAME_MAX] = { 0 };
	printf("请输入要查找人的名字:>\n");
	scanf("%s", name);
	int pos = find_by_name(pc, name);
	if (-1 == pos)
	{
		printf("要查找的人不存在\n");
		return;
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-20s\t%-12s\n", "姓名", "年龄", "性别", "地址", "电话");
		printf("%-20s\t%-4d\t%-5s\t%-20s\t%-12s\n", 
			pc->data[pos].name, pc->data[pos].age,
			pc->data[pos].sex, pc->data[pos].addr, 
			pc->data[pos].tele);
	}
}

//修改通讯录
void Modifycontact(contact* pc)
{
	assert(pc);
	char name[NAME_MAX] = { 0 };
	printf("请输入要修改人的名字:>\n");
	scanf("%s", name);
	int pos = find_by_name(pc, name);
	if (-1 == pos)
	{
		printf("要修改的人不存在\n");
		return;
	}
	printf("请输入名字:>\n");
	scanf("%s", pc->data[pos].name);
	printf("请输入年龄:>\n");
	scanf("%d", &(pc->data[pos].age));
	printf("请输入性别:>\n");
	scanf("%s", pc->data[pos].sex);
	printf("请输入地址:>\n");
	scanf("%s", pc->data[pos].addr);
	printf("请输入电话:>\n");
	scanf("%s", pc->data[pos].tele);
	printf("修改完成\n");
}

//增加容量
void check_capacity(contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		//增加容量
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
		if (ptr == NULL)
		{
			perror("check_capacity::realloc");
			return;
		}
		pc->data = ptr;
		pc->capacity += INC_SZ;
	}
}

//销毁通讯录
void DestoryContact(contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
}

void SaveContact(contact* pc)
{
	//写数据
	//打开文件
	FILE* pf = fopen("contact.txt", "wb");
	if (pf == NULL)
	{
		perror("SaveContact");
	}
	else
	{
		//写数据
		int i = 0;
		for (i = 0; i < pc -> sz; i++)
		{
			fwrite(pc->data + i, sizeof(PeoInfo), 1, pf);
		}
		fclose(pf);
		pf = NULL;
	}
	printf("保存数据成功\n");
}

//加载文件信息到通讯录
void LoadContact(contact* pc)
{
	//打开文件
	FILE* pf = fopen("contact.txt", "rb");
	if (NULL == pf)
	{
		perror("LoadContact");
	}
	else
	{
		//读数据
		PeoInfo tmp = { 0 };
		int i = 0;
		while (fread(&tmp, sizeof(PeoInfo), 1, pf))
		{
			check_capacity(pc);
			pc->data[i] = tmp;
			pc->sz++;
			i++;
		}
		fclose(pf);
		pf = NULL;
	}
}


void Sortcontact(contact* pc)
{
	assert(pc);
	int input = 0;
	printf("请输入你想以0. 名字 1. 电话 2. 年龄 排序的数字:>\n");
	scanf("%d", &input);
	if (input == 0)
	{
		qsort(pc->data, pc->sz, sizeof(PeoInfo), cmp_contact_by_name);
		Showcontact(pc);
	}
	else if (input == 1)
	{
		qsort(pc->data, pc->sz, sizeof(PeoInfo), cmp_contact_by_tele);
		Showcontact(pc);
	}
	else if (input == 2)
	{
		qsort(pc->data, pc->sz, sizeof(PeoInfo), cmp_contact_by_age);
		Showcontact(pc);
	}
	else
	{
		printf("无效输入\n");
	}
}
int cmp_contact_by_name(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

int cmp_contact_by_age(const void* e1, const void* e2)
{
	return ((PeoInfo*)e1)->age - ((PeoInfo*)e2)->age;
}

int cmp_contact_by_tele(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->tele, ((PeoInfo*)e2)->tele);
}