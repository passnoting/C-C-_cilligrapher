#define _CRT_SECURE_NO_WARNINGS

// ѧ����Ϣ����ϵͳ

// ����Ա
// ѧ��
// ����
// �ļ�����

#include "Student_InfoManage_Func.h"

//��ʦmenu
void Tea_Menu()
{
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << "0-�˳�ϵͳ        1-���ѧ����Ϣ" << endl;
	cout << "2-ɾ��ѧ����Ϣ    3-�޸�ѧ����Ϣ" << endl;
	cout << "4-��ѯѧ����Ϣ    5-��ʾѧ����Ϣ" << endl;
	cout << "6-����ѧ����Ϣ    7-���ѧ����Ϣ" << endl;
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
}


// ��ʦMain

void Tea_M(InfoManage& img)
{
	int input = 0;
	do
	{
		Tea_Menu();
		cout << "����������ѡ��> ";
		cin >> input;
		switch (input)
		{
		case 0:
			cout << "�˳�ϵͳ" << endl;
			Save_Stu_Info(&img);
			Tea_Manage_Exit(&img);
			break;
		case 1:
			cout << "���ѧ����Ϣ" << endl;
			Tea_Manage_Add(&img);
			break;
		case 2:
			cout << "ɾ��ѧ����Ϣ" << endl;
			Tea_Manage_Del(&img);

			break;
		case 3:
			cout << "�޸�ѧ����Ϣ" << endl;
			Tea_Manage_Edit(&img);

			break;
		case 4:
			cout << "��ѯѧ����Ϣ" << endl;
			Tea_Manage_Inq(&img);

			break;
		case 5:
			cout << "��ʾѧ����Ϣ" << endl;
			Tea_Manage_Show(&img);

			break;
		case 6:
			cout << "����ѧ����Ϣ" << endl;
			Tea_Manage_Sort(&img);

			break;
		case 7:
			cout << "���ѧ����Ϣ" << endl;
			Tea_Manage_Clear(&img);

			break;
		default:
			cout << "����Ƿ�������������" << endl;
			break;
		}
	} while (input);
}

void Tea_Main(InfoManage& img)
{

	cout << "�������˺�(ְ����)������(���֤����λ)��> " << endl;
	cout << "�������˺ţ�=> ";
	char account[20] = { 0 };
	cin >> account;
	cout << "���������룺=> ";
	char passwd[20] = { 0 };
	cin >> passwd;
	if ((strcmp(account, "02001") == 0) && (strcmp(passwd, "111111") == 0))
	{
		cout << "����ɹ�������ϵͳ" << endl;
		Tea_M(img);
	}
	else
	{
		cout << "�����������������" << endl;
	}
}

// ѧ��Main

void Stu_M(InfoManage& img)
{
	int input = 0;

	do
	{
		cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
		cout << "1-��ѯ��Ϣ  2-��ʾ��Ϣ  0-�˳�ϵͳ" << endl;
		cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
		cout << "���������ѡ��> ";
		cin >> input;
		switch (input)
		{
		case 0:
			cout << "�˳�ϵͳ�ɹ�" << endl;
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

	cout << "�������˺�(ѧ��)������(���֤����λ)��> " << endl;
	cout << "�������˺ţ�=> ";
	char account[20] = { 0 };
	cin >> account;
	cout << "���������룺=> ";
	char passwd[20] = { 0 };
	cin >> passwd;
	if ((strcmp(account, "2211103034") == 0) && (strcmp(passwd, "222222")==0))
	{
		cout << "����ɹ�������ϵͳ" << endl;
		Stu_M(img);
	}
	else
	{
		cout << "�����������������" << endl;
	}
}

int main()
{
	char iden[10] = { 0 };

	InfoManage img = { 0 };
	Init_Manage(&img);

	cout << "�����������ݣ���ʦ/ѧ������> ";
	cin >> iden;
	if (strcmp(iden, "��ʦ") == 0)
	{
		Tea_Main(img);
	}
	else if (strcmp(iden, "ѧ��") == 0)
	{
		Stu_Main(img);
	}
	else
	{
		cout << "������ݴ�������������" << endl;
	}

	return 0;
}
