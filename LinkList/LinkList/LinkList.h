#pragma once

#include<stdio.h>
#include<stdlib.h>

typedef int Elem;

//��һ����ĸ��ֲ���
enum Operation
{
	Destory,
	CreateH,
	CreateL,
	Empty,
	Clear,
	Length,
	Get,
	Lc,
	Insert,
	Delet,
	Disp
};

//����һ������ڵ�
typedef struct Linknode
{
	Elem data;
	struct Linknode* next;
}LinkList;

//��ʼ������
int InitList(LinkList* L);

//�ж������Ƿ�Ϊ��
int EmptyList(LinkList* L);

//��������
int DestoryList(LinkList* L);

//�������
int ClearList(LinkList* L);

//������ĳ���
int LengthList(LinkList* L);

//ȡ�������еĵ�i��Ԫ��(��������ĵ�i��Ԫ��)
int GetElem(LinkList* L, int i, Elem* x);

//���������е�Ԫ��Ϊx��ֵ�����������ַ
LinkList* Locate_P(LinkList* L, Elem x);

//���������е�Ԫ��Ϊx��ֵ����������λ��
int Locate(LinkList* L, Elem x);

//�������еĵ�i��λ�ò���һ��Ԫ��
int ListInsert(LinkList* L, int i, Elem x);

//ɾ�������е�һ��Ԫ��
int DeleList(LinkList* L, int i, Elem* x);

//ͷ�巨��������
void CreateListH(LinkList* L, int n);

//β�巨��������
void CreateListL(LinkList* L, int n);

//��ʾ�����е�Ԫ��
void DispList(LinkList* L);



