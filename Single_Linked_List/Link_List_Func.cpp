#define _CRT_SECURE_NO_WARNINGS

// Implement single linked list
// ʵ�ֵ�����

#include"Link_List_Func.h"


// �пյ���������
bool LinkNode_Empty(LinkNode*& pln)
{
	return pln == NULL ? true : false;
}

// ��ӡ����������
void LinkNode_Print(LinkNode*& pln)
{
	LinkNode* cur = pln;
	cout << "���������������£�" << endl;
	while (cur)
	{
		cout << cur->data << " => ";
		cur = cur->next;
	}
	cout << "NULL" << endl;
}

// �������
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

// ͷ������
void LinkNode_Push_Front(LinkNode*& pln, LinkDatatype x)
{
	// �������
	LinkNode* newnode = Buy_Node(x);

	// ��������
	newnode->next = pln;
	pln = newnode;
}

// β������
void LinkNode_Push_Back(LinkNode*& pln, LinkDatatype x)
{
	// �������
	LinkNode* newnode = Buy_Node(x);

	// ��������
	LinkNode* tail = pln;
	while (tail->next)
	{
		tail = tail->next;
	}
	tail->next = newnode;
}

// ͷɾ����
void LinkNode_Pop_Front(LinkNode*& pln)
{
	// �п�
	assert(!LinkNode_Empty(pln));

	LinkNode* cur = pln;
	pln = cur->next;
	cur->next = NULL;
	free(cur);
}

// βɾ����
void LinkNode_Pop_Back(LinkNode*& pln)
{
	// �п�
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

// ��posλ��֮ǰ����һ������
void LinkNode_Insert(LinkNode*& pln, LinkNode* pos, LinkDatatype x)
{
	// �������
	LinkNode* newnode = Buy_Node(x);

	// ��������
	LinkNode* cur = pln;
	while (cur->next != pos)
	{
		cur = cur->next;
	}
	newnode->next = pos;
	cur->next = newnode;

}

// ɾ��posλ�õ�����
void LinkNode_Erase(LinkNode*& pln, LinkNode* pos)
{
	// �п�
	assert(!LinkNode_Empty(pln));

	// ɾ������
	LinkNode* tail = pln;
	while (tail->next != pos)
	{
		tail = tail->next;
	}
	tail->next = pos->next;
	free(pos);
	pos->next = NULL;
}


// ����ĳһ����
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


// ���ٵ���������
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