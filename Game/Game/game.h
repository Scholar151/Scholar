#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define LEI_COUNT 10

//��ʼ������
void Init(char arr[ROWS][COLS], int rows, int cols, char set);

//��ӡ����
void Display(char arr[ROWS][COLS], int row, int col);

//����������
void SetMine(char arr[ROWS][COLS], int row, int col);

//ɨ��
void FindMine(char arr[ROWS][COLS], char show[ROWS][COLS], int row, int col);
