#define _CRT_SECURE_NO_WARNINGS

// C++ 实现栈和队列
// C++ Implementation Stack and Queue

#include"Stack_Queue_Func.h"

// 实现栈
void Stack::Push(STDatatype x)
{
	if (top == capacity)
	{
		int newcapacity = capacity == 0 ? 4:capacity * 2;
		cout << "栈增容" << endl;
		STDatatype* tmp = (STDatatype*)realloc(a, sizeof(STDatatype) * newcapacity);
		if (tmp == nullptr)
		{
			perror("Stack::Push realloc fail");
			exit(-1);
		}
		a = tmp;
		capacity = newcapacity;
	}
	a[top++] = x;
}

bool Stack::Empty()
{
	return top == 0;
}

void Stack::Pop()
{
	top--;
}

STDatatype Stack::Top()
{
	return a[top - 1];
}

int Stack::Size()
{
	return top;
}


// 实现队列
// 建立一个节点
Node* BuyNode(QDatatype x)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode == nullptr)
	{
		perror("BuyNode malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = nullptr;
	return newnode;
}

bool Queue::Empty()
{
	return size == 0;
}

void Queue::Push(QDatatype x)
{
	Node* newnode = BuyNode(x);
	if (Empty())
	{
		ptail = phead = newnode;
	}
	else
	{
		ptail->next = newnode;
		ptail = newnode;
	}
	++size;
}

void Queue::Pop()
{
	assert(!Empty());
	if (ptail == phead)
	{
		free(ptail);
		ptail = phead = nullptr;
	}
	else
	{
		Node* cur = phead->next;
		free(phead);
		phead = cur;
	}
	--size;
}

STDatatype Queue::Size()
{
	return size;
}

QDatatype Queue::Head()
{
	return phead->data;
}

QDatatype Queue::Tail()
{
	return ptail->data;
}

