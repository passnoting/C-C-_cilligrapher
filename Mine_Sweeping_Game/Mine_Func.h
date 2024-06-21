#pragma once

// Mine_Sweeping_Game

#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;


#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define Mine_Count 10

// 初始化
void Init_Board(char arr[ROWS][COLS], int rows, int cols, char ret);

// 打印
void Print_Board(char arr[ROWS][COLS], int row, int col);


// 设置雷
void Set_Mine(char arr[ROWS][COLS], int row, int col, char ret);

// 排雷
void Search_Mine(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col);