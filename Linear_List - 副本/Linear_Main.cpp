#define _CRT_SECURE_NO_WARNINGS

// Implementing a linear list

#include"Linear_Func.h"

int main()
{
	SL s;

	// 初始化顺序表
	SL_Init(s);

	// 前插数据
	SL_Push_Front(s, 1);
	SL_Push_Front(s, 2);
	SL_Push_Front(s, 3);
	SL_Push_Front(s, 4);

	SL_Print(s);

	// 尾插数据
	SL_Push_Back(s, 11);
	SL_Push_Back(s, 22);
	SL_Push_Back(s, 33);
	SL_Push_Back(s, 44);

	SL_Print(s);

	// 前删数据
	SL_Pop_Front(s);
	SL_Pop_Front(s);

	SL_Print(s);

	// 尾删数据
	SL_Pop_Back(s);
	SL_Pop_Back(s);

	SL_Print(s);

	// 在pos位置插入数据
	SL_Insert(s, 1, 1000);
	SL_Insert(s, 0, 2000);

	SL_Print(s);

	// 删除pos位置上的数据
	SL_Erase(s, 3);
	SL_Erase(s, 1);

	SL_Print(s);

	// 查找某一数据
	int i = SL_Find(s, 11);
	s.a[i] = 666;

	SL_Print(s);

	// 销毁顺序表
	SL_Destroy(s);

	return 0;
}
