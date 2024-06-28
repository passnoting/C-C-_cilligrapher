#pragma once

// Implement a queue

#include<iostream>
#include<stdbool.h>
#include<assert.h>
using namespace std;


// ���ṹ��
typedef int QUDatatype;
typedef struct QNode
{
	QUDatatype data;
	struct QNode* next;
}QNode;


// ���нṹ��
typedef struct QueueNode
{
	QNode* phead;
	QNode* ptail;
	int size;
}QN;


// �п�
bool QN_Empty(QN& pqn);


// ��ʼ������
void QN_Init(QN& pqn);

// ��������
void QN_Push(QN& pqn, QUDatatype x);

// ɾ������
void QN_Pop(QN& pqn);

// ��ȡ��ͷԪ��
QUDatatype QN_Head(QN& pqn);

// ��ȡ��βԪ��
QUDatatype QN_Tail(QN& pqn);

// ��ȡ������Ԫ�ظ���
int QN_Size(QN& pqn);

// ���ٶ���
void QN_Destroy(QN& pqn);