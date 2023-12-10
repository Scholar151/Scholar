#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

//��ʼ������
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

//��ӡ����
void Display(char arr[ROWS][COLS], int row, int col)
{
	printf("-------ɨ����Ϸ-------\n");
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

//������
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

//ͳ��(x,y)������Χ�׵ĸ���
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

//�Ų���
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//������Ҫ���ҵ�����
	int x = 0;
	int y = 0;
	int win = 0;//ͳ��ɨ���Ĳ����׵ĸ���
	while (win< (row*col)-LEI_COUNT)
	{
		printf("��������Ҫ���ҵ�����\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//�ж�����Ϸ���
		{
			if (mine[x][y] == '1')
			{
				printf("���ź����㱻��ը����\n");
				Display(mine, row, col);//��Ϸʧ��
				break;
			}
			else
			{
				if (show[x][y] == '*')//�ж��Ƿ��Ѿ����Ų��
				{
					int ret = GetLeiCount(mine, x, y);//ͳ���׵ĸ���
					show[x][y] = ret + '0';
					win++;
					Display(show, row, col);
				}
				else
				{
					printf("�������Ѿ����Ų����,������������Ҫ�Ų������\n");
				}
			}
		}
		else
		{
			printf("�������������������������\n");
		}
		if (win == (row * col) - LEI_COUNT)
		{
			printf("��ϲ�㣬ɨ�׳ɹ�\n");//��Ϸʤ��
		}
	}
}