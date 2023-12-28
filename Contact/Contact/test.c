#define _CRT_SECURE_NO_WARNINGS

#include "Contact.h"

//通讯录菜单
void menu()
{
	printf("*******************************\n");
	printf("**** 1. add      2. del    ****\n");
	printf("**** 3. search   4. modify ****\n");
	printf("**** 5.show      6. qort   ****\n");
	printf("**** 0. exit               ****\n");
	printf("*******************************\n");
}

int main()
{
	int input = 0;
	Contact con;//创建通讯录
	//初始化通讯录
	ContactInit(&con);
	do
	{
		menu();
		printf("请输入你的选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case Exit:
			SaveContact(&con);
			DestoryContact(&con);
			printf("退出通讯录\n");
			break;
		case Add:
			AddContact(&con);
			break;
		case Del:
			DelContact(&con);
			break;
		case Search:
			SearchContact(&con);
			break;
		case Modify:
			ModifyContatct(&con);
			break;
		case Show:
			ShowContact(&con);
			break;
		case Qort:
			QsortContact(&con);
			break;
		default:
			printf("你的选择有误,请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}