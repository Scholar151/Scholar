#define _CRT_SECURE_NO_WARNINGS

#include "LinkList.h"

void Menu()
{
	printf("***************************************\n");
	printf("****       ����ĸ��ֲ���           ****\n");
	printf("***************************************\n");
	printf("****      0 . ��������              ****\n");
	printf("****      1 . ͷ�巨��������         ****\n");
	printf("****      2 . β�巨��������         ****\n");
	printf("****      3 . �ж������Ƿ�Ϊ��       ****\n");
	printf("****      4 . �������              ****\n");
	printf("****      5 . ��������            ****\n");
	printf("****      6 . ȡ������ĵ�i��Ԫ��    ****\n");
	printf("****      7 . ���������е�Ԫ��Ϊx��ֵ ****\n");
	printf("****      8 . �������в���һ��Ԫ��    ****\n");
	printf("****      9 . ��������ɾ��һ��Ԫ��    ****\n");
	printf("***       10 . ��ʾ����Ԫ��          ****\n");
	printf("****************************************\n");
}

int main()
{
	LinkList L;
	int x = 0;
	int i = 0;
	int n = 0;
	int len = 0;
	int input = 0;
	printf("-----------�����Ѿ���ʼ��-----------\n");
	InitList(&L);
	do
	{
		Menu();
		printf("���������ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case Destory:
			printf("�����ѱ����٣������˳�\n");
			break;
		case CreateH:
			printf("�����뽨����������:>");
			scanf("%d", &n);
			CreateListH(&L, n);
			break;
		case CreateL:
			printf("�����뽨����������:>");
			scanf("%d", &n);
			CreateListL(&L, n);
			break;
		case Empty:
			if (EmptyList(&L))
				printf("��Ϊ��\n");
			else
				printf("��Ϊ��\n");
			break;
		case Clear:
			ClearList(&L);
			break;
		case Length:
			len = LengthList(&L);
			printf("����ĳ�����%d\n", len);
			break;
		case Get:
			printf("��������Ҫȥ�ĵ�i��Ԫ��:>");
			scanf("%d", &i);
			if (GetElem(&L, i, &x));
			printf("��Ԫ����%d\n", x);
			break;
		case Lc:
			printf("��������Ҫ���ҵ�Ԫ��:>");
			scanf("%d", &x);
			i = Locate(&L, x);
			if (i)
				printf("��Ԫ���ǵ�%d��Ԫ��\n", i);
			else
				printf("������û�и�Ԫ��\n");
			break;
		case Insert:
			printf("��������Ҫ�����λ�ú�Ԫ��:>");
			scanf("%d%d", &i, &x);
			ListInsert(&L, i, x);
			break;
		case Delet:
			printf("��������Ҫɾ��Ԫ�ص�λ��:>");
			scanf("%d", &i);
			DeleList(&L, i, &x);
			printf("��ɾ����Ԫ����%d\n", x);
			break;
		case Disp:
			DispList(&L);
			break;
		default:
			printf("���ѡ����������������\n");
			break;
		}

	} while (input);

	return 0;
}