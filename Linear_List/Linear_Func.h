#pragma once

// Implementing a linear list

#include<iostream>
#include<stdlib.h>
#include<assert.h>
using namespace std;


typedef int SLDatatype;
typedef struct SeqList
{
	SLDatatype* a;
	int size;
	int capacity;
}SL;


// 初始化顺序表
void SL_Init(SL& ps);

// 顺序表判空
bool SL_Empty(SL& ps);

// 打印数据
void SL_Print(SL& ps);

// 头插数据
void SL_Push_Front(SL& ps, SLDatatype x);

// 尾插数据
void SL_Push_Back(SL& ps, SLDatatype x);

// 头删数据
void SL_Pop_Front(SL& ps);

// 尾删数据
void SL_Pop_Back(SL& ps);

// 在pos位置插入数据
void SL_Insert(SL& ps, int pos, SLDatatype x);

// 删除pos位置上的数据
void SL_Erase(SL& ps, int pos);

// 查找某一数据	(找到返回其下标，找不到返回-1)
int SL_Find(SL& ps, SLDatatype x);

// 销毁顺序表
void SL_Destroy(SL& ps);
