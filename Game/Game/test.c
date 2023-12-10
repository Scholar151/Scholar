#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

//打印游戏菜单
void menu()
{
	printf("*******************\n");
	printf("***** 0. exit  ****\n");
	printf("***** 1. play  ****\n");
	printf("*******************\n");
}

//游戏实现
void game()
{
	srand((unsigned int)time(NULL));
	//定义两个棋盘
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//初始化棋盘
	Init(mine, ROWS, COLS, '0');
	Init(show, ROWS, COLS, '*');
	//设置雷
	SetMine(mine, ROW, COL);
	//扫雷
	FindMine(mine, show, ROW, COL);
}

int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请输入你的选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("游戏退出\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("你的输入有误,请重新输入\n");
			break;
		}

	} while (input);
	return 0;
}