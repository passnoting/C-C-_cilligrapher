#pragma once

// Implementation of Stack
// 实现栈

#include<iostream>
#include<stdbool.h>
using namespace std;

// 栈的结构
typedef int STDatatype;
typedef struct Stack
{
	STDatatype* a;
	int top;			// 栈顶
	int capacity;		// 容量
}ST;

// 初始化栈
void ST_Init(ST& pst);

// 判空
bool ST_Empty(ST& pst);

// 入栈
void ST_Push(ST& pst, STDatatype x);

// 出栈
void ST_Pop(ST& pst);

// 获取栈顶元素
STDatatype ST_Top(ST& pst);

// 获取栈内元素个数
int ST_Count(ST& pst);

// 销毁栈
void ST_Destroy(ST& pst);
