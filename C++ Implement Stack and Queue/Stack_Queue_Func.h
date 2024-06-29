#pragma once

// C++ 实现栈和队列
// C++ Implementation Stack and Queue

#include<iostream>
#include<stdbool.h>
#include<assert.h>
using namespace std;

// 实现栈
typedef int STDatatype;
class Stack
{
public:
	// 构造函数
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
	// 判空
	bool Empty();

	// 入栈
	void Push(STDatatype x);

	// 出栈
	void Pop();

	// 取栈顶
	STDatatype Top();

	// 获取栈中元素个数
	int Size();

	// 析构函数
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



// 实现队列
typedef int QDatatype;

// 结点
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
	// 判空
	bool Empty();

	// 入队
	void Push(QDatatype x);

	// 出队
	void Pop();

	// 获取队列元素个数
	int Size();

	// 获取对头元素
	QDatatype Head();

	// 获取队尾元素
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



