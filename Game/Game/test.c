#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

//��ӡ��Ϸ�˵�
void menu()
{
	printf("*******************\n");
	printf("***** 0. exit  ****\n");
	printf("***** 1. play  ****\n");
	printf("*******************\n");
}

//��Ϸʵ��
void game()
{
	srand((unsigned int)time(NULL));
	//������������
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//��ʼ������
	Init(mine, ROWS, COLS, '0');
	Init(show, ROWS, COLS, '*');
	//������
	SetMine(mine, ROW, COL);
	//ɨ��
	FindMine(mine, show, ROW, COL);
}

int main()
{
	int input = 0;
	do
	{
		menu();
		printf("���������ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("��Ϸ�˳�\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("�����������,����������\n");
			break;
		}

	} while (input);
	return 0;
}