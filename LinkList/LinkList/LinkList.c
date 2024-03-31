#define _CRT_SECURE_NO_WARNINGS

#include "LinkList.h"

void Menu()
{
	printf("***************************************\n");
	printf("****       链表的各种操作           ****\n");
	printf("***************************************\n");
	printf("****      0 . 销毁链表              ****\n");
	printf("****      1 . 头插法建立链表         ****\n");
	printf("****      2 . 尾插法建立链表         ****\n");
	printf("****      3 . 判断链表是否为空       ****\n");
	printf("****      4 . 清空链表              ****\n");
	printf("****      5 . 求链表长度            ****\n");
	printf("****      6 . 取出链表的第i个元素    ****\n");
	printf("****      7 . 查找链表中的元素为x的值 ****\n");
	printf("****      8 . 在链表中插入一个元素    ****\n");
	printf("****      9 . 在链表中删除一个元素    ****\n");
	printf("***       10 . 显示链表元素          ****\n");
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
	printf("-----------链表已经初始化-----------\n");
	InitList(&L);
	do
	{
		Menu();
		printf("请输入你的选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case Destory:
			printf("链表已被销毁，程序退出\n");
			break;
		case CreateH:
			printf("请输入建立的链表长度:>");
			scanf("%d", &n);
			CreateListH(&L, n);
			break;
		case CreateL:
			printf("请输入建立的链表长度:>");
			scanf("%d", &n);
			CreateListL(&L, n);
			break;
		case Empty:
			if (EmptyList(&L))
				printf("表为空\n");
			else
				printf("表不为空\n");
			break;
		case Clear:
			ClearList(&L);
			break;
		case Length:
			len = LengthList(&L);
			printf("链表的长度是%d\n", len);
			break;
		case Get:
			printf("请输入你要去的第i个元素:>");
			scanf("%d", &i);
			if (GetElem(&L, i, &x));
			printf("该元素是%d\n", x);
			break;
		case Lc:
			printf("请输入你要查找的元素:>");
			scanf("%d", &x);
			i = Locate(&L, x);
			if (i)
				printf("该元素是第%d个元素\n", i);
			else
				printf("链表中没有该元素\n");
			break;
		case Insert:
			printf("请输入你要插入的位置和元素:>");
			scanf("%d%d", &i, &x);
			ListInsert(&L, i, x);
			break;
		case Delet:
			printf("请输入你要删除元素的位置:>");
			scanf("%d", &i);
			DeleList(&L, i, &x);
			printf("被删除的元素是%d\n", x);
			break;
		case Disp:
			DispList(&L);
			break;
		default:
			printf("你的选择有误，请重新输入\n");
			break;
		}

	} while (input);

	return 0;
}