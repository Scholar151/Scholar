#define _CRT_SECURE_NO_WARNINGS

#include "LinkList.h"

//初始化链表
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

//判断链表是否为空
int EmptyList(LinkList* L)
{
	if (L->next == NULL)
		return 1;
	else
		return 0;
}

//销毁链表
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

//清空链表
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
	printf("链表已清空\n");
	return 1;
}

//求链表的长度
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

//取出链表中的第i个元素(查找链表的第i个元素)
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
	*x = p->data;    //将找到的值给x
	return 1;
}

//查找链表中的元素为x的值，并返回其地址
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

//查找链表中的元素为x的值，并返回其位置
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

//在链表中的第i个位置插入一个元素
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
	printf("插入成功\n");
	return 1;
}

//删除链表中的一个元素
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
	printf("删除成功\n");
	return 1;
}

//头插法建立链表
void CreateListH(LinkList* L, int n)
{
	LinkList* p;
	printf("请输入n个元素:>");
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
	printf("链表已建立\n");
}

//尾插法建立链表
void CreateListL(LinkList* L, int n)
{
	LinkList* R = L;
	printf("请输入n个元素:>");
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
	printf("链表已建立\n");
}

//显示链表中的元素
void DispList(LinkList* L)
{
	LinkList* p;
	p = L->next;
	printf("链表中的元素是:\n");
	while (p)
	{
		printf("%-5d", p->data);
		p = p->next;
	}
	printf("\n");
}








