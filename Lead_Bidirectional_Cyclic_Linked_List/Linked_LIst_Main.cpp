#define _CRT_SECURE_NO_WARNINGS

// Lead bidirectional cyclic linked list

#include"Linked_LIst_Func.h"

int main()
{
	LBCLNode* plbcl = LBCL_Init(plbcl);

	// ͷ������
	LBCLNode_Push_Front(plbcl, 1);
	LBCLNode_Push_Front(plbcl, 2);
	LBCLNode_Push_Front(plbcl, 3);
	LBCLNode_Push_Front(plbcl, 4);

	LBCL_Print(plbcl);

	// β������
	LBCLNode_Push_Back(plbcl, 11);
	LBCLNode_Push_Back(plbcl, 22);
	LBCLNode_Push_Back(plbcl, 33);
	LBCLNode_Push_Back(plbcl, 44);

	LBCL_Print(plbcl);

	// ǰɾ����
	LBCLNode_Pop_Front(plbcl);
	LBCLNode_Pop_Front(plbcl);

	LBCL_Print(plbcl);

	// βɾ���ݡ�
	LBCLNode_Pop_Back(plbcl);
	LBCLNode_Pop_Back(plbcl);

	LBCL_Print(plbcl);

	//LBCLNode_Pop_Back(plbcl);
	//LBCLNode_Pop_Back(plbcl);
	//LBCLNode_Pop_Back(plbcl);
	//LBCLNode_Pop_Back(plbcl);

	//LBCL_Print(plbcl);

	LBCLNode* pos = LBCL_Find(plbcl, 11);
	if (pos)
	{
		// ��posλ��֮ǰ��������
		LBCLNode_Insert_Before(pos, 100);
		LBCL_Print(plbcl);
		// ��posλ��֮���������
		LBCLNode_Insert_After(pos, 200);
		LBCL_Print(plbcl);
		// ɾ��posλ�õ�����
		LBCLNode_Erase(pos);
		LBCL_Print(plbcl);
	}

	return 0;
}