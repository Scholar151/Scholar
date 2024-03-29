#pragma once

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

//定义一个顺序表
typedef struct
{
	ElemType* data;
	int length;
}SqList;

//顺序表的各种操作
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

//初始化顺序表
int InitSqList(SqList* L);

//销毁顺序表
void DestorySqList(SqList* L);

//清空顺序表
void ClearSqList(SqList* L);

//求顺序表的长度
int GetLength(SqList* L);

//判断顺序表是否为空
int IsEmpty(SqList* L);

//取出顺序表的第i个元素
int GetElem(SqList* L, int i, ElemType* x);

//按值查找顺序表中的值
int Locate(SqList* L, ElemType e);

//顺序表中插入一个元素
int SqListInsert(SqList* L, int i, ElemType x);

//删除顺序表中的元素
int SqListDelet(SqList* L, int i);

//打印顺序表中的元素
void DisplaySqList(SqList* L, int length);

//建立顺序表
void CreateSqList(SqList* l, int n);


