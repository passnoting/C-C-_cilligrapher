#pragma once

// Implement single linked list
// 实现单链表

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


// 判空单链表数据
bool LinkNode_Empty(LinkNode*& pln);

// 打印单链表数据
void LinkNode_Print(LinkNode*& pln);

// 头插数据
void LinkNode_Push_Front(LinkNode*& pln, LinkDatatype x);

// 尾插数据
void LinkNode_Push_Back(LinkNode*& pln, LinkDatatype x);

// 头删数据
void LinkNode_Pop_Front(LinkNode*& pln);

// 尾删数据
void LinkNode_Pop_Back(LinkNode*& pln);

// 在pos位置之前插入一个数据
void LinkNode_Insert(LinkNode*& pln, LinkNode* pos,LinkDatatype x);

// 删除pos位置的数据
void LinkNode_Erase(LinkNode*& pln, LinkNode* pos);


// 查找某一数据
LinkNode* LinkNode_Find(LinkNode*& pln, LinkDatatype x);


// 销毁单链表数据
void LinkNode_Destroy(LinkNode*& pln);