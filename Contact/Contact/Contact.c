#define _CRT_SECURE_NO_WARNINGS

#include "Contact.h"

//增容
static void CheckCapacity(Contact* pc)
{
	assert(pc);
	if (pc->count == pc->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
		if (ptr == NULL)
		{
			printf("CheckCapacity : %s\n", strerror(errno));
			return;
		}
		else
		{
			pc->data = ptr;
			pc->capacity += INC_SZ;
			printf("增容成功\n");
		}
	}
}

//加载通讯录里的信息
void LoadContact(Contact* pc)
{
	assert(pc);
	//打开文件
	FILE* pfRead = fopen("contact.txt", "rb");
	if (pfRead == NULL)
	{
		perror("LoadContact");
		return;
	}
	//加载文件信息
	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pfRead) == 1)
	{
		CheckCapacity(pc);
		pc->data[pc->count] = tmp;
		pc->count++;
	}
	//关闭文件
	fclose(pfRead);
	pfRead = NULL;
}


//初始化通讯录
int ContactInit(Contact* pc)
{
	    assert(pc);
		pc->count = 0;
		pc->data = (PeoInfo*)calloc(DEFAULT_SZ, sizeof(PeoInfo));
		if (pc->data == NULL)
		{
			printf("ContactInit : %s\n", strerror(errno));
			return 1;
		}
		pc->capacity = DEFAULT_SZ;
		//加载文件信息到通讯录
		LoadContact(pc);
		return 0;
}


//增加通讯录人数
void AddContact(Contact* pc)
{
	assert(pc);
	CheckCapacity(pc);
	printf("输入姓名>:");
	scanf("%s", pc->data[pc->count].name);
	printf("输入年龄>:");
	scanf("%d", &pc->data[pc->count].age);
	printf("输入性别>:");
	scanf("%s", pc->data[pc->count].sex);
	printf("输入电话>:");
	scanf("%s", pc->data[pc->count].tele);
	printf("输入地址>:");
	scanf("%s", pc->data[pc->count].addr);
	pc->count++;
	printf("增加成功\n");
}

//查找
static int FindByName(Contact* pc, char name[])
{
	assert(pc);
	for (int i = 0; i < pc->count; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

//删除通讯录的人数
void DelContact(Contact* pc)
{
	assert(pc);
	char name[NAME_MAX];
	if (pc->count == 0)
	{
		printf("通讯录为空,无法删除信息\n");
		return;
	}
	printf("输入你要删除的人的名字\n");
	scanf("%s", name);
    
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	for (int i = pos; i < pc->count - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("删除成功\n");
}

//显示通讯录中的信息
void ShowContact(Contact* pc)
{
	assert(pc);
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
	for (int i = 0; i < pc->count; i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
	}
}

//搜索通讯录里的信息
void SearchContact(Contact* pc)
{
	assert(pc);
	char name[20] = { 0 };
	printf("请输入你要查找的人的名字:>");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("你找查找的人的信息不存在\n");
		return;
	}
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
	printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n", pc->data[ret].name, pc->data[ret].age, pc->data[ret].sex, pc->data[ret].tele, pc->data[ret].addr);
}

//修改通讯里的信息
void ModifyContatct(Contact* pc)
{
	assert(pc);
	char name[20] = { 0 };
	printf("请输入你要修改的人的名字:>");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("你要修改的人的信息不存在,无法修改\n");
		return;
	}
	printf("请输入修改后的姓名>:");
	scanf("%s", pc->data[ret].name);
	printf("请输入修改后的年龄>:");
	scanf("%d", &pc->data[ret].age);
	printf("请输入修改后的性别>:");
	scanf("%s", pc->data[ret].sex);
	printf("请输入修改后的电话>:");
	scanf("%s", pc->data[ret].tele);
	printf("请输入修改后的地址>:");
	scanf("%s", pc->data[ret].addr);
	printf("修改成功\n");
}

//按名字进行排序
static int NameByCmp(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

//按名字对通讯录里的信息进行排序
void QsortContact(Contact* pc)
{
	assert(pc);
	qsort(pc->data, pc->count, sizeof(PeoInfo), NameByCmp);
	printf("排序成功\n");
}

//销毁通讯录,释放内存
void DestoryContact(Contact* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
}

//保存通讯录中的信息到文件中
void SaveContact(const Contact* pc)
{
	assert(pc);
	//打开文件
	FILE* pfWrite = fopen("contact.txt", "wb");
	if (pfWrite == NULL)
	{
		perror("SaveContact");
		return;
	}
	//写文件
	for (int i = 0; i < pc->count; i++)
	{
	  fwrite(pc->data + i, sizeof(PeoInfo), 1, pfWrite);	
	}
	//关闭文件
	fclose(pfWrite);
	pfWrite = NULL;
}




