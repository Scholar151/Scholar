#define _CRT_SECURE_NO_WARNINGS

#include "Contact.h"

//ͨѶ¼�˵�
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
	Contact con;//����ͨѶ¼
	//��ʼ��ͨѶ¼
	ContactInit(&con);
	do
	{
		menu();
		printf("���������ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case Exit:
			SaveContact(&con);
			DestoryContact(&con);
			printf("�˳�ͨѶ¼\n");
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
			printf("���ѡ������,������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}