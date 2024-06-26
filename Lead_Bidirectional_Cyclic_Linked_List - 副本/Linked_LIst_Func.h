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


// 初始化
LBCLNode* LBCL_Init(LBCLNode*& pl);

// 判空
bool LBCL_Empty(LBCLNode*& pl);

// 打印数据
void LBCL_Print(LBCLNode*& pl);

// 头插数据
void LBCLNode_Push_Front(LBCLNode*& pl, LBCLDatatype x);

// 尾插数据
void LBCLNode_Push_Back(LBCLNode*& pl, LBCLDatatype x);

// 前删数据
void LBCLNode_Pop_Front(LBCLNode*& pl);

// 尾删数据
void LBCLNode_Pop_Back(LBCLNode*& pl);

// 在pos位置之前插入数据
void LBCLNode_Insert_Before(LBCLNode* pos, LBCLDatatype x);

// 在pos位置之后插入数据
void LBCLNode_Insert_After(LBCLNode* pos, LBCLDatatype x);

// 删除pos位置的数据
void LBCLNode_Erase(LBCLNode* pos);


// 查找链表中某一数据
LBCLNode* LBCL_Find(LBCLNode*& pl, LBCLDatatype x);

// 销毁
void LBCL_Destroy(LBCLNode*& pl);
