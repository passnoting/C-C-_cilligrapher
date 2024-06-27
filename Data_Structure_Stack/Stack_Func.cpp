#define _CRT_SECURE_NO_WARNINGS

// Implementation of Stack
// 实现栈

#include"Stack_Func.h"


// 初始化栈
void ST_Init(ST& pst)
{
	pst.a = NULL;
	pst.top = 0;
	pst.capacity = 0;
}

// 判空
bool ST_Empty(ST& pst)
{
	return pst.top == 0;
}

// 入栈
void ST_Push(ST& pst, STDatatype x)
{
	// 检查容量
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

	// 开始入栈
	pst.a[pst.top] = x;
	++pst.top;
}

// 出栈
void ST_Pop(ST& pst)
{
	pst.top--;
}

// 获取栈顶元素
STDatatype ST_Top(ST& pst)
{
	return pst.a[pst.top - 1];
}

// 获取栈内元素个数
int ST_Count(ST& pst)
{
	return pst.top;
}

// 销毁栈
void ST_Destroy(ST& pst)
{
	free(pst.a);
	pst.a = NULL;
	pst.capacity = pst.top = 0;
}
