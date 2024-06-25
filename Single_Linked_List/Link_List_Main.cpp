#define _CRT_SECURE_NO_WARNINGS

// Implement single linked list
// ʵ�ֵ�����

#include"Link_List_Func.h"

int main()
{
	LinkNode* pl = NULL;

	// ͷ������
	LinkNode_Push_Front(pl, 1);
	LinkNode_Push_Front(pl, 2);
	LinkNode_Push_Front(pl, 3);
	LinkNode_Push_Front(pl, 4);

	LinkNode_Print(pl);

	// β������
	LinkNode_Push_Back(pl, 11);
	LinkNode_Push_Back(pl, 22);
	LinkNode_Push_Back(pl, 33);
	LinkNode_Push_Back(pl, 44);

	LinkNode_Print(pl);

	// ͷɾ����
	LinkNode_Pop_Front(pl);
	LinkNode_Pop_Front(pl);

	LinkNode_Print(pl);

	// βɾ����
	LinkNode_Pop_Back(pl);
	LinkNode_Pop_Back(pl);

	LinkNode_Print(pl);

	// ����ĳһ����
	LinkNode* pos = LinkNode_Find(pl, 11);
	// cout << pos << endl;
	if (pos)
	{
		LinkNode_Insert(pl, pos, 1000);
		LinkNode_Print(pl);

		LinkNode_Erase(pl, pos);
		LinkNode_Print(pl);
	}

	// ���ٵ�����
	LinkNode_Destroy(pl);

	return 0;
}
