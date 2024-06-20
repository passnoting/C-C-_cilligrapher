#pragma once

// Wuzi chess source program

#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>

using namespace std;


#define ROW 5
#define COL 5

// ��ʼ������
void Gobang_Init(char arr[ROW][COL], int row, int col);

// ��ӡ����
void Gobang_Print(char arr[ROW][COL], int row, int col);

// �������
void Gobang_Player(char arr[ROW][COL], int row, int col, char ret);

// ��������
void Gobang_Computer(char arr[ROW][COL], int row, int col, char ret);

// �ж���Ӯ
char Is_Win(char arr[ROW][COL], int row, int col);