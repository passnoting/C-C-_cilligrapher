#define _CRT_SECURE_NO_WARNINGS

// Implement a queue


#include"Queue_Func.h"

// 判空
bool QN_Empty(QN& pqn)
{
	return pqn.phead == NULL && pqn.ptail == NULL;
}

// 初始化队列
void QN_Init(QN& pqn)
{
	pqn.phead = NULL;
	pqn.ptail = NULL;
	pqn.size = 0;
}

// 建立节点
QNode* Buy_Node(QUDatatype x)
{
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("Buy_Node malloc fail");
		return NULL;
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}


// 插入数据
void QN_Push(QN& pqn, QUDatatype x)
{
	QNode* newnode = Buy_Node(x);

	if (QN_Empty(pqn))
	{
		pqn.phead = pqn.ptail = newnode;
	}
	else
	{
		pqn.ptail->next = newnode;
		pqn.ptail = newnode;
	}
	pqn.size++;
}

// 删除数据
void QN_Pop(QN& pqn)
{
	assert(!QN_Empty(pqn));

	QNode* cur = pqn.phead;
	if (pqn.phead == pqn.ptail)
	{
		pqn.phead = pqn.ptail = NULL;
	}
	else
	{
		pqn.phead = cur->next;
	}
	free(cur);
	pqn.size--;
}


// 获取对头元素
QUDatatype QN_Head(QN& pqn)
{
	return (pqn.phead)->data;
}

// 获取队尾元素
QUDatatype QN_Tail(QN& pqn)
{
	return (pqn.ptail)->data;
}


// 获取队列中元素个数
int QN_Size(QN& pqn)
{
	return pqn.size;
}

// 销毁队列
void QN_Destroy(QN& pqn)
{
	QNode* cur = pqn.phead;
	while (cur != pqn.ptail)
	{
		QNode* curnext = cur->next;
		free(cur);
		cur = curnext;
	}
	free(cur);
}