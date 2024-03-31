#pragma once

#include<stdio.h>
#include<stdlib.h>

typedef int Elem;

//第一链表的各种操作
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

//定义一个链表节点
typedef struct Linknode
{
	Elem data;
	struct Linknode* next;
}LinkList;

//初始化链表
int InitList(LinkList* L);

//判断链表是否为空
int EmptyList(LinkList* L);

//销毁链表
int DestoryList(LinkList* L);

//清空链表
int ClearList(LinkList* L);

//求链表的长度
int LengthList(LinkList* L);

//取出链表中的第i个元素(查找链表的第i个元素)
int GetElem(LinkList* L, int i, Elem* x);

//查找链表中的元素为x的值，并返回其地址
LinkList* Locate_P(LinkList* L, Elem x);

//查找链表中的元素为x的值，并返回其位置
int Locate(LinkList* L, Elem x);

//在链表中的第i个位置插入一个元素
int ListInsert(LinkList* L, int i, Elem x);

//删除链表中的一个元素
int DeleList(LinkList* L, int i, Elem* x);

//头插法建立链表
void CreateListH(LinkList* L, int n);

//尾插法建立链表
void CreateListL(LinkList* L, int n);

//显示链表中的元素
void DispList(LinkList* L);



