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

//���ֲ���
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

//�˵���Ϣ
typedef struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
}PeoInfo;

//ͨѶ¼
typedef struct Contact
{
	PeoInfo* data;
	int count;
	int capacity;
}Contact;

//��ʼ��ͨѶ¼
int ContactInit(Contact* pc);

//����ͨѶ¼����
void AddContact(Contact* pc);

//ɾ��ͨѶ¼������
void DelContact(Contact* pc);

//��ʾͨѶ¼�е���Ϣ
void ShowContact(Contact* pc);

//����ͨѶ¼�����Ϣ
void SearchContact(Contact* pc);

//�޸�ͨѶ�����Ϣ
void ModifyContatct(Contact* pc);

//�����ֶ�ͨѶ¼�����Ϣ��������
void QsortContact(Contact* pc);

//����ͨѶ¼,�ͷ��ڴ�
void DestoryContact(Contact* pc);

//����ͨѶ¼�е���Ϣ���ļ���
void SaveContact(const Contact* pc);