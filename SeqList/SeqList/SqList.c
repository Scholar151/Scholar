#define _CRT_SECURE_NO_WARNINGS

#include "SqList.h"

void Menu()
{
	printf("**************************************\n");
	printf("          顺序表的各种操作             \n");
	printf("**************************************\n");
	printf("*****    0 . 销毁顺序表            ****\n");
	printf("*****    1 . 建立顺序表            ****\n");
	printf("*****    2 . 清空顺序表            ****\n");
	printf("*****    3 . 求顺序表的长度        ****\n");
	printf("*****    4 . 取出顺序表的第i个元素  ****\n");
	printf("*****    5 . 按值查找顺序表中的值   ****\n");
	printf("*****    6 . 顺序表中插入一个元素   ****\n");
	printf("****     7 . 删除顺序表中的元素     ****\n");
	printf("****     8 . 打印顺序表中的元素     ****\n");
	printf("****     9 . 判断表是否为空         ****\n");
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
	printf("          已经初始化顺序表             \n");
	InitSqList(&L);
	do
	{
		Menu();
		printf("请输入你要选择的操作:>");
		scanf("%d", &input);
		switch (input)
		{
		case Destory:
			printf("顺序表已被销毁，程序退出\n");
			DestorySqList(&L);
			break;
		case Create:
			printf("请输入建立的表的元素个数:>");
			scanf("%d", &n);
			CreateSqList(&L, n);
			break;
		case Clear:
			ClearSqList(&L);
			break;
		case Length:
		   len=GetLength(&L);
		   printf("表的长度为%d\n", len);
		   break;
		case Get:
			printf("请输入你要取出的第i个元素:>");
			scanf("%d", &i);
			GetElem(&L, i, &x);
			printf("该元素是%d", x);
			break;
		case Loc:
			printf("请输入你要查找的元素:>");
			scanf("%d", &elem);
		    num=Locate(&L, elem);
			printf("该元素是第%d个元素\n", num);
			break;
		case Insert:
			printf("请输入你要插入的位置:>");
			scanf("%d", &i);
			printf("请输入你要插入的元素:>");
			scanf("%d", &elem);
			SqListInsert(&L, i, elem);
			break;
		case Delet:
			printf("请输入你要删除元素的位置:>");
			scanf("%d", &i);
			SqListDelet(&L, i);
			break;
		case Display:
			printf("顺序表中的元素为:\n");
			DisplaySqList(&L, len);
			break;
		case Empty:
			if (IsEmpty(&L))
				printf("表为空\n");
			else
				printf("表不为空\n");
			break;
		default:
			printf("你的选择有误，请重新选择\n");
			break;
		}
	} while (input);

	return 0;
}