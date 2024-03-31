#define _CRT_SECURE_NO_WARNINGS

#include "LinkList.h"

//��ʼ������
int InitList(LinkList* L)
{
	L = (LinkList*)malloc(sizeof(LinkList));
	if (L == NULL)
	{
		perror("InitList");
		return 0;
	}
	L->next = NULL;
	return 1;
}

//�ж������Ƿ�Ϊ��
int EmptyList(LinkList* L)
{
	if (L->next == NULL)
		return 1;
	else
		return 0;
}

//��������
int DestoryList(LinkList* L)
{
	LinkList* p;
	while (L)
	{
		p = L;
		L = L->next;
		free(p);
	}
	return 1;
}

//�������
int ClearList(LinkList* L)
{
	LinkList* p, * q;
	p = L->next;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
	printf("���������\n");
	return 1;
}

//������ĳ���
int LengthList(LinkList* L)
{
	LinkList* p;
	p = L->next;
	int i = 0;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

//ȡ�������еĵ�i��Ԫ��(��������ĵ�i��Ԫ��)
int GetElem(LinkList* L, int i, Elem* x)
{
	LinkList* p;
	int j = 1;
	p = L->next;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return 0;
	*x = p->data;    //���ҵ���ֵ��x
	return 1;
}

//���������е�Ԫ��Ϊx��ֵ�����������ַ
LinkList* Locate_P(LinkList* L, Elem x)
{
	LinkList* p;
	p = L->next;
	while (p && p->data != x)
	{
		p = p->next;
	}
	return p;
}

//���������е�Ԫ��Ϊx��ֵ����������λ��
int Locate(LinkList* L, Elem x)
{
	LinkList* p;
	int i = 1;
	p = L->next;
	while (p && p->data != x)
	{
		p = p->next;
		i++;
	}
	if (p)
		return i;
	else
		return 0;
}

//�������еĵ�i��λ�ò���һ��Ԫ��
int ListInsert(LinkList* L, int i, Elem x)
{
	LinkList* p;
	int j = 0;
	p = L;
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL || j > i - 1)
		return 0;
	LinkList* s = (LinkList*)malloc(sizeof(LinkList));
	if (s == NULL)
	{
		perror("s");
		return 0;
	}
	s->data = x;
	s->next = p->next;
	p->next = s;
	printf("����ɹ�\n");
	return 1;
}

//ɾ�������е�һ��Ԫ��
int DeleList(LinkList* L, int i, Elem* x)
{
	LinkList* p, * q;
	int j = 0;
	p = L;
	while (p->next != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (p->next == NULL || j > i - 1)
		return 0;
	q = p->next;
	p->next = q->next;
	*x = q->data;
	free(q);
	printf("ɾ���ɹ�\n");
	return 1;
}

//ͷ�巨��������
void CreateListH(LinkList* L, int n)
{
	LinkList* p;
	printf("������n��Ԫ��:>");
	for (int i = 0; i < n; i++)
	{
		p = (LinkList*)malloc(sizeof(LinkList));
		if (p == NULL)
		{
			perror("CreateList");
			return;
		}
		scanf("%d", &p->data);
		p->next = L->next;
		L->next = p;
	}
	printf("�����ѽ���\n");
}

//β�巨��������
void CreateListL(LinkList* L, int n)
{
	LinkList* R = L;
	printf("������n��Ԫ��:>");
	for (int i = 0; i < n; i++)
	{
	LinkList* p = (LinkList*)malloc(sizeof(LinkList));
		if (p == NULL)
		{
			perror("CreateListL");
			return;
		}
		scanf("%d", &p->data);
		p->next = NULL;
		R->next = p;
		R = p;
	}
	printf("�����ѽ���\n");
}

//��ʾ�����е�Ԫ��
void DispList(LinkList* L)
{
	LinkList* p;
	p = L->next;
	printf("�����е�Ԫ����:\n");
	while (p)
	{
		printf("%-5d", p->data);
		p = p->next;
	}
	printf("\n");
}








