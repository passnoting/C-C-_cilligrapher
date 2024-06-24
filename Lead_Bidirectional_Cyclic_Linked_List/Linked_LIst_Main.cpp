#define _CRT_SECURE_NO_WARNINGS

// Lead bidirectional cyclic linked list

#include"Linked_LIst_Func.h"

int main()
{
	LBCLNode* plbcl = LBCL_Init(plbcl);

	// 头插数据
	LBCLNode_Push_Front(plbcl, 1);
	LBCLNode_Push_Front(plbcl, 2);
	LBCLNode_Push_Front(plbcl, 3);
	LBCLNode_Push_Front(plbcl, 4);

	LBCL_Print(plbcl);

	// 尾插数据
	LBCLNode_Push_Back(plbcl, 11);
	LBCLNode_Push_Back(plbcl, 22);
	LBCLNode_Push_Back(plbcl, 33);
	LBCLNode_Push_Back(plbcl, 44);

	LBCL_Print(plbcl);

	// 前删数据
	LBCLNode_Pop_Front(plbcl);
	LBCLNode_Pop_Front(plbcl);

	LBCL_Print(plbcl);

	// 尾删数据‘
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
		// 在pos位置之前插入数据
		LBCLNode_Insert_Before(pos, 100);
		LBCL_Print(plbcl);
		// 在pos位置之后插入数据
		LBCLNode_Insert_After(pos, 200);
		LBCL_Print(plbcl);
		// 删除pos位置的数据
		LBCLNode_Erase(pos);
		LBCL_Print(plbcl);
	}

	return 0;
}