#define _CRT_SECURE_NO_WARNINGS

// Implementation of Stack
// ʵ��ջ

#include"Stack_Func.h"


// ��ʼ��ջ
void ST_Init(ST& pst)
{
	pst.a = NULL;
	pst.top = 0;
	pst.capacity = 0;
}

// �п�
bool ST_Empty(ST& pst)
{
	return pst.top == 0;
}

// ��ջ
void ST_Push(ST& pst, STDatatype x)
{
	// �������
	if (pst.capacity == pst.top)
	{
		int newcapacity = pst.capacity == 0 ? 4 : pst.capacity * 2;
		STDatatype* tmp = (STDatatype*)realloc(pst.a, sizeof(STDatatype) * newcapacity);
		if (tmp == NULL)
		{
			perror("ST_Push realloc fail");
			return;
		}
		pst.a = tmp;
		pst.capacity = newcapacity;
	}

	// ��ʼ��ջ
	pst.a[pst.top] = x;
	++pst.top;
}

// ��ջ
void ST_Pop(ST& pst)
{
	pst.top--;
}

// ��ȡջ��Ԫ��
STDatatype ST_Top(ST& pst)
{
	return pst.a[pst.top - 1];
}

// ��ȡջ��Ԫ�ظ���
int ST_Count(ST& pst)
{
	return pst.top;
}

// ����ջ
void ST_Destroy(ST& pst)
{
	free(pst.a);
	pst.a = NULL;
	pst.capacity = pst.top = 0;
}
