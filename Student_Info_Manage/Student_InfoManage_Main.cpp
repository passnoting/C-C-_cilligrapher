#define _CRT_SECURE_NO_WARNINGS

// 学生信息管理系统

// 管理员
// 学生
// 密码
// 文件操作

#include "Student_InfoManage_Func.h"

//教师menu
void Tea_Menu()
{
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << "0-退出系统        1-添加学生信息" << endl;
	cout << "2-删除学生信息    3-修改学生信息" << endl;
	cout << "4-查询学生信息    5-显示学生信息" << endl;
	cout << "6-排序学生信息    7-清空学生信息" << endl;
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
}


// 教师Main

void Tea_M(InfoManage& img)
{
	int input = 0;
	do
	{
		Tea_Menu();
		cout << "请输入您的选择：> ";
		cin >> input;
		switch (input)
		{
		case 0:
			cout << "退出系统" << endl;
			Save_Stu_Info(&img);
			Tea_Manage_Exit(&img);
			break;
		case 1:
			cout << "添加学生信息" << endl;
			Tea_Manage_Add(&img);
			break;
		case 2:
			cout << "删除学生信息" << endl;
			Tea_Manage_Del(&img);

			break;
		case 3:
			cout << "修改学生信息" << endl;
			Tea_Manage_Edit(&img);

			break;
		case 4:
			cout << "查询学生信息" << endl;
			Tea_Manage_Inq(&img);

			break;
		case 5:
			cout << "显示学生信息" << endl;
			Tea_Manage_Show(&img);

			break;
		case 6:
			cout << "排序学生信息" << endl;
			Tea_Manage_Sort(&img);

			break;
		case 7:
			cout << "清空学生信息" << endl;
			Tea_Manage_Clear(&img);

			break;
		default:
			cout << "输入非法，请重新输入" << endl;
			break;
		}
	} while (input);
}

void Tea_Main(InfoManage& img)
{

	cout << "请输入账号(职工号)与密码(身份证后六位)：> " << endl;
	cout << "请输入账号：=> ";
	char account[20] = { 0 };
	cin >> account;
	cout << "请输入密码：=> ";
	char passwd[20] = { 0 };
	cin >> passwd;
	if ((strcmp(account, "02001") == 0) && (strcmp(passwd, "111111") == 0))
	{
		cout << "密码成功，进入系统" << endl;
		Tea_M(img);
	}
	else
	{
		cout << "密码错误，请重新输入" << endl;
	}
}

// 学生Main

void Stu_M(InfoManage& img)
{
	int input = 0;

	do
	{
		cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
		cout << "1-查询信息  2-显示信息  0-退出系统" << endl;
		cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
		cout << "请输入你的选择：> ";
		cin >> input;
		switch (input)
		{
		case 0:
			cout << "退出系统成功" << endl;
			break;
		case 1:
			Tea_Manage_Inq(&img);
			break;
		case 2:
			Tea_Manage_Show(&img);
			break;
		default:
			break;
		}
	} while (input);
}

void Stu_Main(InfoManage& img)
{

	cout << "请输入账号(学号)与密码(身份证后六位)：> " << endl;
	cout << "请输入账号：=> ";
	char account[20] = { 0 };
	cin >> account;
	cout << "请输入密码：=> ";
	char passwd[20] = { 0 };
	cin >> passwd;
	if ((strcmp(account, "2211103034") == 0) && (strcmp(passwd, "222222")==0))
	{
		cout << "密码成功，进入系统" << endl;
		Stu_M(img);
	}
	else
	{
		cout << "密码错误，请重新输入" << endl;
	}
}

int main()
{
	char iden[10] = { 0 };

	InfoManage img = { 0 };
	Init_Manage(&img);

	cout << "请输入你的身份（教师/学生）：> ";
	cin >> iden;
	if (strcmp(iden, "教师") == 0)
	{
		Tea_Main(img);
	}
	else if (strcmp(iden, "学生") == 0)
	{
		Stu_Main(img);
	}
	else
	{
		cout << "输入身份错误，请重新输入" << endl;
	}

	return 0;
}
