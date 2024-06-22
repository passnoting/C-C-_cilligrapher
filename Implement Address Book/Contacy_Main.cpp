#define _CRT_SECURE_NO_WARNINGS

// Implement Address Book

#include"Contacy_Func.h"

void Contact_Menu()
{
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << "0-退出系统          1-添加联系人信息" << endl;
	cout << "2-删除联系人信息    3-修改联系人信息" << endl;
	cout << "4-查询联系人信息    5-显示联系人信息" << endl;
	cout << "6-排序联系人信息    7-清空联系人信息" << endl;
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
}

int main()
{
	int input = 0;

	Contact con;

	// 初始化通讯录
	Contact_Init(con);

	do
	{
		Contact_Menu();
		cout << "请输入你的选择：=> ";
		cin >> input;
		switch (input)
		{
		case Contact_Exit:
			cout << "退出通讯录" << endl;
			Sava_Peo_Info(con);
			Destroy_Contact(con);
			break;
		case Contact_Add:
			cout << "添加联系人信息" << endl;
			Add_Peo_Info(con);
			break;
		case Contact_Del:
			cout << "删除联系人信息" << endl;
			Del_Peo_Info(con);
			break;
		case Contact_Edit:
			cout << "修改联系人信息" << endl;
			Edit_Peo_Info(con);
			break;
		case Contact_Inq:
			cout << "查询联系人信息" << endl;
			Inq_Peo_Info(con);
			break;
		case Contact_Show:
			cout << "显示联系人信息" << endl;
			Show_Peo_Info(con);
			break;
		case Contact_Sort:
			cout << "排序联系人信息" << endl;
			Sort_Peo_Info(con);
			break;
		case Contact_Clear:
			cout << "清空通讯录中信息" << endl;
			Clear_Peo_Info(con);
			break;
		default:
			cout << "输入非法，请重新输入" << endl;
			break;
		}
	} while (input);

	return 0;
}