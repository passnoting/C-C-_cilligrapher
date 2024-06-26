#define _CRT_SECURE_NO_WARNINGS

// Lead bidirectional cyclic linked list

#include<iostream>
#include<stdbool.h>
#include<assert.h>
using namespace std;


typedef int LBCLDatatype;
typedef struct LBCLNode
{
	LBCLDatatype data;
	struct LBCLNode* next;
	struct LBCLNode* prev;
}LBCLNode;


// ��ʼ��
LBCLNode* LBCL_Init(LBCLNode*& pl);

// �п�
bool LBCL_Empty(LBCLNode*& pl);

// ��ӡ����
void LBCL_Print(LBCLNode*& pl);

// ͷ������
void LBCLNode_Push_Front(LBCLNode*& pl, LBCLDatatype x);

// β������
void LBCLNode_Push_Back(LBCLNode*& pl, LBCLDatatype x);

// ǰɾ����
void LBCLNode_Pop_Front(LBCLNode*& pl);

// βɾ����
void LBCLNode_Pop_Back(LBCLNode*& pl);

// ��posλ��֮ǰ��������
void LBCLNode_Insert_Before(LBCLNode* pos, LBCLDatatype x);

// ��posλ��֮���������
void LBCLNode_Insert_After(LBCLNode* pos, LBCLDatatype x);

// ɾ��posλ�õ�����
void LBCLNode_Erase(LBCLNode* pos);


// ����������ĳһ����
LBCLNode* LBCL_Find(LBCLNode*& pl, LBCLDatatype x);

// ����
void LBCL_Destroy(LBCLNode*& pl);
