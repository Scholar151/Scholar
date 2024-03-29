#define _CRT_SECURE_NO_WARNINGS

#include "SqList.h"

//初始化顺序表
int InitSqList(SqList* L)
{
	L->data = malloc(sizeof(SqList) * MAXSIZE);
	if (L->data == NULL)
	{
		perror("InitSqList");
		return 0;
	}
	L->length = 0;
	return 1;
}

//销毁顺序表
void DestorySqList(SqList* L)
{
	free(L->data);
	L->data = NULL;
}

//清空顺序表
void ClearSqList(SqList* L)
{
	L->length = 0;
}

//求顺序表的长度
int GetLength(SqList* L)
{
	return L->length;
}

//判断顺序表是否为空
int IsEmpty(SqList* L)
{
	if (L->length == 0)
		return 1;
	else
		return 0;
}

//取出顺序表的第i个元素
int GetElem(SqList* L, int i, ElemType* x)
{
	if (i<1 || i>L->length)
		return 0;
	*x = L->data[i - 1];
	return 1;
}

//按值查找顺序表中的值
int Locate(SqList* L, ElemType e)
{
	int i = 0;
	for (i = 0; i < L->length; i++)
	{
		if (L->data[i] == e)
			return i + 1;
	}
	return 0;
}

//顺序表中插入一个元素
int SqListInsert(SqList* L, int i, ElemType x)
{
	if (i<1 || i>L->length + 1)
	{
		printf("插入位置错误\n");
		return -1;
	}
	if (L->length == MAXSIZE)
	{
		printf("顺序表已满，不能插入\n");
		 return -1;
	}
	for (int j = L->length - 1; j >= i - 1; j--)
	{
		L->data[j + 1] = L->data[j];
	}
	L->data[i - 1] = x;
	L->length++;
	return 1;
}

//删除顺序表中的元素
int SqListDelet(SqList* L, int i)
{
	if (i<1 || i>L->length)
	{
		printf("删除位置错误\n");
		return 0;
	}
	if (L->length == 0)
	{
		printf("顺序表为空，不能删除元素\n");
		return 0;
	}
	for (int j = i - 1; j < L->length; j++)
	{
		L->data[j] = L->data[j + 1];
	}
	L->length--;
	return 1;
}

//打印顺序表中的元素
void DisplaySqList(SqList* L, int length)
{
	for (int i = 1; i <= L->length; i++)
	{
		printf("%-5d ", L->data[i-1]);
	}
	printf("\n");
}

//建立顺序表
void CreateSqList(SqList* L, int n)
{
	printf("请输入顺序表的元素\n");
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &L->data[i - 1]);
	}
	L->length = n;
}



