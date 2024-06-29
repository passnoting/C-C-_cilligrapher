#pragma once

// C++ ʵ��ջ�Ͷ���
// C++ Implementation Stack and Queue

#include<iostream>
#include<stdbool.h>
#include<assert.h>
using namespace std;

// ʵ��ջ
typedef int STDatatype;
class Stack
{
public:
	// ���캯��
	Stack(size_t n = 4)
	{
		if (n == 0)
		{
			a = nullptr;
			top = capacity = 0;
		}
		else
		{
			a = (STDatatype*)malloc(sizeof(STDatatype) * n);
			if (a == nullptr)
			{
				perror("Stack malloc fail");
				exit(-1);
			}
			capacity = n;
		}
	}
	// �п�
	bool Empty();

	// ��ջ
	void Push(STDatatype x);

	// ��ջ
	void Pop();

	// ȡջ��
	STDatatype Top();

	// ��ȡջ��Ԫ�ظ���
	int Size();

	// ��������
	~Stack()
	{
		if (a)
		{
			free(a);
			a = nullptr;
			top = capacity = 0;
		}
	}
private:
	STDatatype* a;
	int top;
	int capacity;
};



// ʵ�ֶ���
typedef int QDatatype;

// ���
class Node
{
public:
	QDatatype data;
	Node* next;
};


class Queue
{
public:
	Queue()
	{
		size = 0;
		ptail = phead = nullptr;
	}
	// �п�
	bool Empty();

	// ���
	void Push(QDatatype x);

	// ����
	void Pop();

	// ��ȡ����Ԫ�ظ���
	int Size();

	// ��ȡ��ͷԪ��
	QDatatype Head();

	// ��ȡ��βԪ��
	QDatatype Tail();

	~Queue()
	{
		Node* cur = ptail;
		while (cur)
		{
			Node* curnext = cur->next;
			free(cur);
			cur = curnext;
		}
		size = 0;
	}

private:
	int size;
	Node* ptail;
	Node* phead;
};



