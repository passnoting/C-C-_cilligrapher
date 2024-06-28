#pragma once

// Implement a queue

#include<iostream>
#include<stdbool.h>
#include<assert.h>
using namespace std;


// 结点结构体
typedef int QUDatatype;
typedef struct QNode
{
	QUDatatype data;
	struct QNode* next;
}QNode;


// 队列结构体
typedef struct QueueNode
{
	QNode* phead;
	QNode* ptail;
	int size;
}QN;


// 判空
bool QN_Empty(QN& pqn);


// 初始化队列
void QN_Init(QN& pqn);

// 插入数据
void QN_Push(QN& pqn, QUDatatype x);

// 删除数据
void QN_Pop(QN& pqn);

// 获取对头元素
QUDatatype QN_Head(QN& pqn);

// 获取队尾元素
QUDatatype QN_Tail(QN& pqn);

// 获取队列中元素个数
int QN_Size(QN& pqn);

// 销毁队列
void QN_Destroy(QN& pqn);