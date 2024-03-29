#pragma once

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

//����һ��˳���
typedef struct
{
	ElemType* data;
	int length;
}SqList;

//˳���ĸ��ֲ���
enum Operation
{
	Destory,
	Create,
	Clear,
	Length,
	Get,
	Loc,
	Insert,
	Delet,
	Display,
	Empty
};

//��ʼ��˳���
int InitSqList(SqList* L);

//����˳���
void DestorySqList(SqList* L);

//���˳���
void ClearSqList(SqList* L);

//��˳���ĳ���
int GetLength(SqList* L);

//�ж�˳����Ƿ�Ϊ��
int IsEmpty(SqList* L);

//ȡ��˳���ĵ�i��Ԫ��
int GetElem(SqList* L, int i, ElemType* x);

//��ֵ����˳����е�ֵ
int Locate(SqList* L, ElemType e);

//˳����в���һ��Ԫ��
int SqListInsert(SqList* L, int i, ElemType x);

//ɾ��˳����е�Ԫ��
int SqListDelet(SqList* L, int i);

//��ӡ˳����е�Ԫ��
void DisplaySqList(SqList* L, int length);

//����˳���
void CreateSqList(SqList* l, int n);


