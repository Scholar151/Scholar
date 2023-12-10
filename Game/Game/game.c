#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

//初始化棋盘
void Init(char arr[ROWS][COLS], int rows, int cols, char set)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = set;
		}
	}
}

//打印棋盘
void Display(char arr[ROWS][COLS], int row, int col)
{
	printf("-------扫雷游戏-------\n");
	for (int j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	       printf("\n");
	for (int i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}

//设置雷
void SetMine(char arr[ROWS][COLS], int row, int col)
{
	int count = LEI_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (arr[x][y] != '1')
				{
					arr[x][y] = '1';
					count--;
				}
			}
		}
	}
}

//统计(x,y)坐标周围雷的个数
static int GetLeiCount(char(*mine)[COLS], int x, int y)
{
	int sum = 0;
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			sum += mine[i][j] - '0';
		}
	}
	return sum;
}

//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//输入你要查找的坐标
	int x = 0;
	int y = 0;
	int win = 0;//统计扫出的不是雷的个数
	while (win< (row*col)-LEI_COUNT)
	{
		printf("请输入你要查找的坐标\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//判断坐标合法性
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被雷炸死了\n");
				Display(mine, row, col);//游戏失败
				break;
			}
			else
			{
				if (show[x][y] == '*')//判断是否已经被排查过
				{
					int ret = GetLeiCount(mine, x, y);//统计雷的个数
					show[x][y] = ret + '0';
					win++;
					Display(show, row, col);
				}
				else
				{
					printf("该坐标已经被排查过了,请重新输入你要排查的坐标\n");
				}
			}
		}
		else
		{
			printf("你输入的坐标有误，请重新输入\n");
		}
		if (win == (row * col) - LEI_COUNT)
		{
			printf("恭喜你，扫雷成功\n");//游戏胜利
		}
	}
}