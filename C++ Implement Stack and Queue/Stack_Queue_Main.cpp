#define _CRT_SECURE_NO_WARNINGS

// C++ ʵ��ջ�Ͷ���
// C++ Implementation Stack and Queue

#include"Stack_Queue_Func.h"

int main()
{
	cout << "@@@@@   ջ   @@@@@" << endl;

	Stack st(100);
	int i = 0;
	for (i = 0; i < 100; i++)
	{
		st.Push(i);
	}
	cout << "ջ��Ԫ�ظ�����=>" << st.Size() << endl;
	while (!st.Empty())
	{
		cout << st.Top() << " ";
		st.Pop();
	}
	cout << endl;

	cout << "@@@@@   ����   @@@@@" << endl;
	Queue q;

	i = 0;
	for (i = 0; i < 100; i++)
	{
		q.Push(i);
	}
	cout << "������Ԫ�ظ�����=>" << q.Size() << endl;
	while (!q.Empty())
	{
		cout << q.Head() << " ";
		q.Pop();
	}
	cout << endl;

	return 0;
}