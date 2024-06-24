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


// ��ʼ��˳���
void SL_Init(SL& ps);

// ˳����п�
bool SL_Empty(SL& ps);

// ��ӡ����
void SL_Print(SL& ps);

// ͷ������
void SL_Push_Front(SL& ps, SLDatatype x);

// β������
void SL_Push_Back(SL& ps, SLDatatype x);

// ͷɾ����
void SL_Pop_Front(SL& ps);

// βɾ����
void SL_Pop_Back(SL& ps);

// ��posλ�ò�������
void SL_Insert(SL& ps, int pos, SLDatatype x);

// ɾ��posλ���ϵ�����
void SL_Erase(SL& ps, int pos);

// ����ĳһ����	(�ҵ��������±꣬�Ҳ�������-1)
int SL_Find(SL& ps, SLDatatype x);

// ����˳���
void SL_Destroy(SL& ps);
