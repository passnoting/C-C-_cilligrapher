#pragma once

// Implement single linked list
// ʵ�ֵ�����

#include<iostream>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>
using namespace std;


typedef int LinkDatatype;
typedef struct LinkNode
{
	LinkDatatype data;
	struct LinkNode* next;
}LinkNode;


// �пյ���������
bool LinkNode_Empty(LinkNode*& pln);

// ��ӡ����������
void LinkNode_Print(LinkNode*& pln);

// ͷ������
void LinkNode_Push_Front(LinkNode*& pln, LinkDatatype x);

// β������
void LinkNode_Push_Back(LinkNode*& pln, LinkDatatype x);

// ͷɾ����
void LinkNode_Pop_Front(LinkNode*& pln);

// βɾ����
void LinkNode_Pop_Back(LinkNode*& pln);

// ��posλ��֮ǰ����һ������
void LinkNode_Insert(LinkNode*& pln, LinkNode* pos,LinkDatatype x);

// ɾ��posλ�õ�����
void LinkNode_Erase(LinkNode*& pln, LinkNode* pos);


// ����ĳһ����
LinkNode* LinkNode_Find(LinkNode*& pln, LinkDatatype x);


// ���ٵ���������
void LinkNode_Destroy(LinkNode*& pln);