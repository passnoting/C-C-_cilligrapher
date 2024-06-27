#define _CRT_SECURE_NO_WARNINGS

// Implementation of Stack
// ʵ��ջ

#include"Stack_Func.h"


int main()
{
	ST st;

	// ��ʼ��ջ
	ST_Init(st);

	// ��ջ
	ST_Push(st, 1);
	ST_Push(st, 2);
	ST_Push(st, 3);
	ST_Push(st, 4);
	ST_Push(st, 11);
	ST_Push(st, 33);
	ST_Push(st, 22);
	ST_Push(st, 55);
	cout << "ջ��Ԫ�ظ�����=> " << ST_Count(st) << endl;

	while (!ST_Empty(st))
	{
		cout << ST_Top(st) << " ";
		ST_Pop(st);
	}
	cout << endl;

	ST_Destroy(st);

	return 0;
}