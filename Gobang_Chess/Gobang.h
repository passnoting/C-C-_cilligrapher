#pragma once

// Wuzi chess source program

#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>

using namespace std;


#define ROW 5
#define COL 5

// 初始化棋盘
void Gobang_Init(char arr[ROW][COL], int row, int col);

// 打印棋盘
void Gobang_Print(char arr[ROW][COL], int row, int col);

// 玩家下棋
void Gobang_Player(char arr[ROW][COL], int row, int col, char ret);

// 电脑下棋
void Gobang_Computer(char arr[ROW][COL], int row, int col, char ret);

// 判断输赢
char Is_Win(char arr[ROW][COL], int row, int col);