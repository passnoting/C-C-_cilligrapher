#define _CRT_SECURE_NO_WARNINGS

// Implement a queue


#include"Queue_Func.h"

int main()
{
	QN qn;

	// 初始化队列
	QN_Init(qn);

	// 插入数据
	QN_Push(qn, 1);
	QN_Push(qn, 2);
	QN_Push(qn, 3);
	QN_Push(qn, 4);
	QN_Push(qn, 5);
	QN_Push(qn, 6);
	QN_Push(qn, 7);
	QN_Push(qn, 8);

	cout << "数据元素个数：=> " << QN_Size(qn) << endl;

	while (!QN_Empty(qn))
	{
		cout << QN_Head(qn) << " ";
		QN_Pop(qn);
	}

	// 销毁队列
	QN_Destroy(qn);

	return 0;
}