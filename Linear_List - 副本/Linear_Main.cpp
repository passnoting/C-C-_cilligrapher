#define _CRT_SECURE_NO_WARNINGS

// Implementing a linear list

#include"Linear_Func.h"

int main()
{
	SL s;

	// ��ʼ��˳���
	SL_Init(s);

	// ǰ������
	SL_Push_Front(s, 1);
	SL_Push_Front(s, 2);
	SL_Push_Front(s, 3);
	SL_Push_Front(s, 4);

	SL_Print(s);

	// β������
	SL_Push_Back(s, 11);
	SL_Push_Back(s, 22);
	SL_Push_Back(s, 33);
	SL_Push_Back(s, 44);

	SL_Print(s);

	// ǰɾ����
	SL_Pop_Front(s);
	SL_Pop_Front(s);

	SL_Print(s);

	// βɾ����
	SL_Pop_Back(s);
	SL_Pop_Back(s);

	SL_Print(s);

	// ��posλ�ò�������
	SL_Insert(s, 1, 1000);
	SL_Insert(s, 0, 2000);

	SL_Print(s);

	// ɾ��posλ���ϵ�����
	SL_Erase(s, 3);
	SL_Erase(s, 1);

	SL_Print(s);

	// ����ĳһ����
	int i = SL_Find(s, 11);
	s.a[i] = 666;

	SL_Print(s);

	// ����˳���
	SL_Destroy(s);

	return 0;
}
