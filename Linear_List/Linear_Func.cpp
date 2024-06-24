#define _CRT_SECURE_NO_WARNINGS

// Implementing a linear list

#include"Linear_Func.h"


// 初始化顺序表
void SL_Init(SL& ps)
{
	ps.a = NULL;
	ps.capacity = 0;
	ps.size = 0;
}

// 检查容量
void Check_Capacity(SL& ps)
{
	if (ps.capacity == ps.size)
	{
		int newcapacity = ps.capacity == 0 ? 4 : ps.capacity * 2;
		SLDatatype* tmp = (SLDatatype*)realloc(ps.a, sizeof(SLDatatype) * newcapacity);
		if (tmp == NULL)
		{
			perror("Check_Capacity realloc fail");
			return;
		}
		ps.a = tmp;
		ps.capacity = newcapacity;
	}
}

// 顺序表判空
bool SL_Empty(SL& ps)
{
	return ps.size == 0 ? true : false;
}

// 打印数据
void SL_Print(SL& ps)
{
	int i = 0;
	cout << "顺序表中数据如下：=> " << endl;
	for (i = 0; i < ps.size; i++)
	{
		cout << ps.a[i] << " ";
	}
	cout << endl;
}


// 头插数据
void SL_Push_Front(SL& ps, SLDatatype x)
{
	// 检查容量
	Check_Capacity(ps);

	// 插入数据
	int i = 0;
	for (i = ps.size - 1; i >= 0; i--)
	{
		ps.a[i+1] = ps.a[i];
	}
	ps.a[0] = x;

	// ++size
	++ps.size;
}

// 尾插数据
void SL_Push_Back(SL& ps, SLDatatype x)
{
	// 检查容量
	Check_Capacity(ps);

	// 插入数据
	ps.a[ps.size] = x;

	// ++size
	++ps.size;
}

// 头删数据
void SL_Pop_Front(SL& ps)
{
	// 判断是否为空
	assert(!SL_Empty(ps));

	// 删除数据
	int i = 0;
	for (i = 1; i < ps.size; i++)
	{
		ps.a[i-1] = ps.a[i];
	}

	// --size
	--ps.size;
}

// 尾删数据
void SL_Pop_Back(SL& ps)
{
	// 判断是否为空
	assert(!SL_Empty(ps));

	// 删除数据
	ps.size--;
}

// 在pos位置插入数据
void SL_Insert(SL& ps, int pos, SLDatatype x)
{
	// 检查容量
	Check_Capacity(ps);

	// 插入数据
	int i = 0;
	for (i = ps.size - 1; i >= pos; i--)
	{
		ps.a[i+1] = ps.a[i];
	}
	ps.a[pos] = x;

	// ++size
	++ps.size;
}

// 删除pos位置上的数据
void SL_Erase(SL& ps, int pos)
{
	// 判断是否为空
	assert(!SL_Empty(ps));

	// 删除数据
	int i = 0;
	for (i = pos + 1; i < ps.size; i++)
	{
		ps.a[i-1] = ps.a[i];
	}

	// --size
	ps.size--;
}

// 查找某一数据	(返回其下标)
int SL_Find(SL& ps, SLDatatype x)
{
	int i = 0;
	for (i = 0; i < ps.size; i++)
	{
		if (ps.a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

// 销毁顺序表
void SL_Destroy(SL& ps)
{
	free(ps.a);
	ps.capacity = ps.size = 0;
}