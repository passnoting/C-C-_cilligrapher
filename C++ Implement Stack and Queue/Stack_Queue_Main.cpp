#define _CRT_SECURE_NO_WARNINGS

// C++ 实现栈和队列
// C++ Implementation Stack and Queue

#include"Stack_Queue_Func.h"

int main()
{
	cout << "@@@@@   栈   @@@@@" << endl;

	Stack st(100);
	int i = 0;
	for (i = 0; i < 100; i++)
	{
		st.Push(i);
	}
	cout << "栈内元素个数：=>" << st.Size() << endl;
	while (!st.Empty())
	{
		cout << st.Top() << " ";
		st.Pop();
	}
	cout << endl;

	cout << "@@@@@   队列   @@@@@" << endl;
	Queue q;

	i = 0;
	for (i = 0; i < 100; i++)
	{
		q.Push(i);
	}
	cout << "队列内元素个数：=>" << q.Size() << endl;
	while (!q.Empty())
	{
		cout << q.Head() << " ";
		q.Pop();
	}
	cout << endl;

	return 0;
}