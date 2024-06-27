#pragma once

// Implementation of Stack
// ʵ��ջ

#include<iostream>
#include<stdbool.h>
using namespace std;

// ջ�Ľṹ
typedef int STDatatype;
typedef struct Stack
{
	STDatatype* a;
	int top;			// ջ��
	int capacity;		// ����
}ST;

// ��ʼ��ջ
void ST_Init(ST& pst);

// �п�
bool ST_Empty(ST& pst);

// ��ջ
void ST_Push(ST& pst, STDatatype x);

// ��ջ
void ST_Pop(ST& pst);

// ��ȡջ��Ԫ��
STDatatype ST_Top(ST& pst);

// ��ȡջ��Ԫ�ظ���
int ST_Count(ST& pst);

// ����ջ
void ST_Destroy(ST& pst);
