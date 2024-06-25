#define _CRT_SECURE_NO_WARNINGS

// Implement single linked list
// 实现单链表

#include"Link_List_Func.h"


// 判空单链表数据
bool LinkNode_Empty(LinkNode*& pln)
{
	return pln == NULL ? true : false;
}

// 打印单链表数据
void LinkNode_Print(LinkNode*& pln)
{
	LinkNode* cur = pln;
	cout << "单链表中数据如下：" << endl;
	while (cur)
	{
		cout << cur->data << " => ";
		cur = cur->next;
	}
	cout << "NULL" << endl;
}

// 建立结点
LinkNode* Buy_Node(LinkDatatype x)
{
	LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
	if (newnode == NULL)
	{
		perror("Buy_Node malloc fail");
		return NULL;
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

// 头插数据
void LinkNode_Push_Front(LinkNode*& pln, LinkDatatype x)
{
	// 建立结点
	LinkNode* newnode = Buy_Node(x);

	// 插入数据
	newnode->next = pln;
	pln = newnode;
}

// 尾插数据
void LinkNode_Push_Back(LinkNode*& pln, LinkDatatype x)
{
	// 建立结点
	LinkNode* newnode = Buy_Node(x);

	// 插入数据
	LinkNode* tail = pln;
	while (tail->next)
	{
		tail = tail->next;
	}
	tail->next = newnode;
}

// 头删数据
void LinkNode_Pop_Front(LinkNode*& pln)
{
	// 判空
	assert(!LinkNode_Empty(pln));

	LinkNode* cur = pln;
	pln = cur->next;
	cur->next = NULL;
	free(cur);
}

// 尾删数据
void LinkNode_Pop_Back(LinkNode*& pln)
{
	// 判空
	assert(!LinkNode_Empty(pln));

	LinkNode* tail = pln;
	while (tail->next && tail->next->next)
	{
		tail = tail->next;
	}
	if (pln->next == NULL)
	{
		free(pln);
		pln = NULL;
	}
	else
	{
		free(tail->next);
		tail->next = NULL;
	}

}

// 在pos位置之前插入一个数据
void LinkNode_Insert(LinkNode*& pln, LinkNode* pos, LinkDatatype x)
{
	// 建立结点
	LinkNode* newnode = Buy_Node(x);

	// 插入数据
	LinkNode* cur = pln;
	while (cur->next != pos)
	{
		cur = cur->next;
	}
	newnode->next = pos;
	cur->next = newnode;

}

// 删除pos位置的数据
void LinkNode_Erase(LinkNode*& pln, LinkNode* pos)
{
	// 判空
	assert(!LinkNode_Empty(pln));

	// 删除数据
	LinkNode* tail = pln;
	while (tail->next != pos)
	{
		tail = tail->next;
	}
	tail->next = pos->next;
	free(pos);
	pos->next = NULL;
}


// 查找某一数据
LinkNode* LinkNode_Find(LinkNode*& pln, LinkDatatype x)
{
	LinkNode* fine = pln;
	while (fine)
	{
		if (fine->data == x)
		{
			return fine;
		}
		fine = fine->next;
	}
	return NULL;
}


// 销毁单链表数据
void LinkNode_Destroy(LinkNode*& pln)
{
	LinkNode* cur = pln;
	while (cur)
	{
		LinkNode* curnext = cur->next;
		free(cur);
		cur = curnext;
	}
}