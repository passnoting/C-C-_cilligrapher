#define _CRT_SECURE_NO_WARNINGS

// Implement a queue


#include"Queue_Func.h"

int main()
{
	QN qn;

	// ��ʼ������
	QN_Init(qn);

	// ��������
	QN_Push(qn, 1);
	QN_Push(qn, 2);
	QN_Push(qn, 3);
	QN_Push(qn, 4);
	QN_Push(qn, 5);
	QN_Push(qn, 6);
	QN_Push(qn, 7);
	QN_Push(qn, 8);

	cout << "����Ԫ�ظ�����=> " << QN_Size(qn) << endl;

	while (!QN_Empty(qn))
	{
		cout << QN_Head(qn) << " ";
		QN_Pop(qn);
	}

	// ���ٶ���
	QN_Destroy(qn);

	return 0;
}