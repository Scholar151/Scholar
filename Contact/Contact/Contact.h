#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>


#define NAME_MAX 20
#define SEX_MAX 10
#define TELE_MAX 12
#define ADDR_MAX 30
#define DEFAULT_SZ 3
#define INC_SZ 2

//各种操作
enum Operation
{
	Exit,
	Add,
	Del,
	Search,
	Modify,
	Show,
	Qort
};

//人的信息
typedef struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
}PeoInfo;

//通讯录
typedef struct Contact
{
	PeoInfo* data;
	int count;
	int capacity;
}Contact;

//初始化通讯录
int ContactInit(Contact* pc);

//增加通讯录人数
void AddContact(Contact* pc);

//删除通讯录的人数
void DelContact(Contact* pc);

//显示通讯录中的信息
void ShowContact(Contact* pc);

//搜索通讯录里的信息
void SearchContact(Contact* pc);

//修改通讯里的信息
void ModifyContatct(Contact* pc);

//按名字对通讯录里的信息进行排序
void QsortContact(Contact* pc);

//销毁通讯录,释放内存
void DestoryContact(Contact* pc);

//保存通讯录中的信息到文件中
void SaveContact(const Contact* pc);