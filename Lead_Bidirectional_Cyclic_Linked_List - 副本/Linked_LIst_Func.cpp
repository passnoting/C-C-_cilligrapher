#define _CRT_SECURE_NO_WARNINGS

// Lead bidirectional cyclic linked list

#include"Linked_LIst_Func.h"

// 建立一个结点、
LBCLNode* Buy_Node(LBCLDatatype x)
{
	LBCLNode* newnode = (LBCLNode*)malloc(sizeof(LBCLNode));
	if (newnode == NULL)
	{
		perror("Buy_Node malloc fail");
		return NULL;
	}
	newnode->data = x;
	newnode->next = newnode;
	newnode->prev = newnode;
	return newnode;
}

// 初始化
LBCLNode* LBCL_Init(LBCLNode*& pl)
{
	LBCLNode* newnode = Buy_Node(-1);
	newnode->next = newnode;
	newnode->prev = newnode;
	return newnode;
}


// 判空
bool LBCL_Empty(LBCLNode*& pl)
{
	return (pl->next == pl) && (pl->prev == pl) ? true : false;
}

// 打印数据
void LBCL_Print(LBCLNode*& pl)
{
	LBCLNode* cur = pl->next;

	cout << "正向打印" << endl;

	cout << "链表头<==>";
	while (cur != pl)
	{
		cout << cur->data << "<==>";
		cur = cur->next;
	}
	cout << endl;

	//cout << "反向打印" << endl;
	//LBCLNode* tail = pl->prev;
	//cout << "链表头<==>";
	//while (tail != pl)
	//{
	//	cout << tail->data << "<==>";
	//	tail = tail->prev;
	//}
	//cout << endl;


	//cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;


}

// 头插数据
void LBCLNode_Push_Front(LBCLNode*& pl, LBCLDatatype x)
{
	LBCLNode* newnode = Buy_Node(x);

	LBCLNode* cur = pl->next;
	newnode->next = cur;
	cur->prev = newnode;
	pl->next = newnode;
	newnode->prev = pl;

}

// 尾插数据
void LBCLNode_Push_Back(LBCLNode*& pl, LBCLDatatype x)
{
	LBCLNode* newnode = Buy_Node(x);

	LBCLNode* tail = pl->prev;
	newnode->next = pl;
	pl->prev = newnode;
	tail->next = newnode;
	newnode->prev = tail;
}

// 前删数据
void LBCLNode_Pop_Front(LBCLNode*& pl)
{
	assert(!LBCL_Empty(pl));

	LBCLNode* cur = pl->next;
	LBCLNode* curnext = cur->next;
	pl->next = curnext;
	curnext->prev = pl;
	free(cur);
}

// 尾删数据
void LBCLNode_Pop_Back(LBCLNode*& pl)
{
	assert(!LBCL_Empty(pl));

	LBCLNode* tail = pl->prev;
	LBCLNode* tailprev = tail->prev;
	tailprev->next = pl;
	pl->prev = tailprev;
	free(tail);
}


// 在pos位置之前插入数据
void LBCLNode_Insert_Before(LBCLNode* pos, LBCLDatatype x)
{
	LBCLNode* newnode = Buy_Node(x);

	LBCLNode* posprev = pos->prev;
	newnode->next = pos;
	pos->prev = newnode;
	posprev->next = newnode;
	newnode->prev = posprev;
}

// 在pos位置之后插入数据
void LBCLNode_Insert_After(LBCLNode* pos, LBCLDatatype x)
{
	LBCLNode* newnode = Buy_Node(x);

	LBCLNode* posnext = pos->next;
	newnode->next = posnext;
	posnext->prev = newnode;
	pos->next = newnode;
	newnode->prev = pos;
}


// 删除pos位置的数据
void LBCLNode_Erase(LBCLNode* pos)
{
	assert(pos);
	LBCLNode* posprev = pos->prev;
	LBCLNode* posnext = pos->next;

	posprev->next = posnext;
	posnext->prev = posprev;
	free(pos);
}


// 查找链表中某一数据
LBCLNode* LBCL_Find(LBCLNode*& pl, LBCLDatatype x)
{
	LBCLNode* cur = pl->next;
	while (cur != pl)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

// 销毁
void LBCL_Destroy(LBCLNode*& pl)
{
	LBCLNode* cur = pl->next;
	while (cur != pl)
	{
		LBCLNode* curnext = cur->next;
		free(cur);
		cur = curnext;
	}
	free(cur);

}