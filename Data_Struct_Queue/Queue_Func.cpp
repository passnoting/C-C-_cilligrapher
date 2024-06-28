#define _CRT_SECURE_NO_WARNINGS

// Implement a queue


#include"Queue_Func.h"

// �п�
bool QN_Empty(QN& pqn)
{
	return pqn.phead == NULL && pqn.ptail == NULL;
}

// ��ʼ������
void QN_Init(QN& pqn)
{
	pqn.phead = NULL;
	pqn.ptail = NULL;
	pqn.size = 0;
}

// �����ڵ�
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


// ��������
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

// ɾ������
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


// ��ȡ��ͷԪ��
QUDatatype QN_Head(QN& pqn)
{
	return (pqn.phead)->data;
}

// ��ȡ��βԪ��
QUDatatype QN_Tail(QN& pqn)
{
	return (pqn.ptail)->data;
}


// ��ȡ������Ԫ�ظ���
int QN_Size(QN& pqn)
{
	return pqn.size;
}

// ���ٶ���
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