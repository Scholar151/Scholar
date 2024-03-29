#define _CRT_SECURE_NO_WARNINGS

#include "SqList.h"

//��ʼ��˳���
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

//����˳���
void DestorySqList(SqList* L)
{
	free(L->data);
	L->data = NULL;
}

//���˳���
void ClearSqList(SqList* L)
{
	L->length = 0;
}

//��˳���ĳ���
int GetLength(SqList* L)
{
	return L->length;
}

//�ж�˳����Ƿ�Ϊ��
int IsEmpty(SqList* L)
{
	if (L->length == 0)
		return 1;
	else
		return 0;
}

//ȡ��˳���ĵ�i��Ԫ��
int GetElem(SqList* L, int i, ElemType* x)
{
	if (i<1 || i>L->length)
		return 0;
	*x = L->data[i - 1];
	return 1;
}

//��ֵ����˳����е�ֵ
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

//˳����в���һ��Ԫ��
int SqListInsert(SqList* L, int i, ElemType x)
{
	if (i<1 || i>L->length + 1)
	{
		printf("����λ�ô���\n");
		return -1;
	}
	if (L->length == MAXSIZE)
	{
		printf("˳������������ܲ���\n");
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

//ɾ��˳����е�Ԫ��
int SqListDelet(SqList* L, int i)
{
	if (i<1 || i>L->length)
	{
		printf("ɾ��λ�ô���\n");
		return 0;
	}
	if (L->length == 0)
	{
		printf("˳���Ϊ�գ�����ɾ��Ԫ��\n");
		return 0;
	}
	for (int j = i - 1; j < L->length; j++)
	{
		L->data[j] = L->data[j + 1];
	}
	L->length--;
	return 1;
}

//��ӡ˳����е�Ԫ��
void DisplaySqList(SqList* L, int length)
{
	for (int i = 1; i <= L->length; i++)
	{
		printf("%-5d ", L->data[i-1]);
	}
	printf("\n");
}

//����˳���
void CreateSqList(SqList* L, int n)
{
	printf("������˳����Ԫ��\n");
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &L->data[i - 1]);
	}
	L->length = n;
}



