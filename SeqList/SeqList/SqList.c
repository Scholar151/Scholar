#define _CRT_SECURE_NO_WARNINGS

#include "SqList.h"

void Menu()
{
	printf("**************************************\n");
	printf("          ˳���ĸ��ֲ���             \n");
	printf("**************************************\n");
	printf("*****    0 . ����˳���            ****\n");
	printf("*****    1 . ����˳���            ****\n");
	printf("*****    2 . ���˳���            ****\n");
	printf("*****    3 . ��˳���ĳ���        ****\n");
	printf("*****    4 . ȡ��˳���ĵ�i��Ԫ��  ****\n");
	printf("*****    5 . ��ֵ����˳����е�ֵ   ****\n");
	printf("*****    6 . ˳����в���һ��Ԫ��   ****\n");
	printf("****     7 . ɾ��˳����е�Ԫ��     ****\n");
	printf("****     8 . ��ӡ˳����е�Ԫ��     ****\n");
	printf("****     9 . �жϱ��Ƿ�Ϊ��         ****\n");
	printf("***************************************\n");
}

int main()
{
	int input = 0;
	int elem = 0;
	int n = 0;
	int len = 0;
	int x = 0;
	int i = 0;
	int num = 0;
	SqList L;
	printf("          �Ѿ���ʼ��˳���             \n");
	InitSqList(&L);
	do
	{
		Menu();
		printf("��������Ҫѡ��Ĳ���:>");
		scanf("%d", &input);
		switch (input)
		{
		case Destory:
			printf("˳����ѱ����٣������˳�\n");
			DestorySqList(&L);
			break;
		case Create:
			printf("�����뽨���ı��Ԫ�ظ���:>");
			scanf("%d", &n);
			CreateSqList(&L, n);
			break;
		case Clear:
			ClearSqList(&L);
			break;
		case Length:
		   len=GetLength(&L);
		   printf("��ĳ���Ϊ%d\n", len);
		   break;
		case Get:
			printf("��������Ҫȡ���ĵ�i��Ԫ��:>");
			scanf("%d", &i);
			GetElem(&L, i, &x);
			printf("��Ԫ����%d", x);
			break;
		case Loc:
			printf("��������Ҫ���ҵ�Ԫ��:>");
			scanf("%d", &elem);
		    num=Locate(&L, elem);
			printf("��Ԫ���ǵ�%d��Ԫ��\n", num);
			break;
		case Insert:
			printf("��������Ҫ�����λ��:>");
			scanf("%d", &i);
			printf("��������Ҫ�����Ԫ��:>");
			scanf("%d", &elem);
			SqListInsert(&L, i, elem);
			break;
		case Delet:
			printf("��������Ҫɾ��Ԫ�ص�λ��:>");
			scanf("%d", &i);
			SqListDelet(&L, i);
			break;
		case Display:
			printf("˳����е�Ԫ��Ϊ:\n");
			DisplaySqList(&L, len);
			break;
		case Empty:
			if (IsEmpty(&L))
				printf("��Ϊ��\n");
			else
				printf("��Ϊ��\n");
			break;
		default:
			printf("���ѡ������������ѡ��\n");
			break;
		}
	} while (input);

	return 0;
}