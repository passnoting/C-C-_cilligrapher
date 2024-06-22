#define _CRT_SECURE_NO_WARNINGS

// Implement Address Book

#include"Contacy_Func.h"

void Contact_Menu()
{
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << "0-�˳�ϵͳ          1-�����ϵ����Ϣ" << endl;
	cout << "2-ɾ����ϵ����Ϣ    3-�޸���ϵ����Ϣ" << endl;
	cout << "4-��ѯ��ϵ����Ϣ    5-��ʾ��ϵ����Ϣ" << endl;
	cout << "6-������ϵ����Ϣ    7-�����ϵ����Ϣ" << endl;
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
}

int main()
{
	int input = 0;

	Contact con;

	// ��ʼ��ͨѶ¼
	Contact_Init(con);

	do
	{
		Contact_Menu();
		cout << "���������ѡ��=> ";
		cin >> input;
		switch (input)
		{
		case Contact_Exit:
			cout << "�˳�ͨѶ¼" << endl;
			Sava_Peo_Info(con);
			Destroy_Contact(con);
			break;
		case Contact_Add:
			cout << "�����ϵ����Ϣ" << endl;
			Add_Peo_Info(con);
			break;
		case Contact_Del:
			cout << "ɾ����ϵ����Ϣ" << endl;
			Del_Peo_Info(con);
			break;
		case Contact_Edit:
			cout << "�޸���ϵ����Ϣ" << endl;
			Edit_Peo_Info(con);
			break;
		case Contact_Inq:
			cout << "��ѯ��ϵ����Ϣ" << endl;
			Inq_Peo_Info(con);
			break;
		case Contact_Show:
			cout << "��ʾ��ϵ����Ϣ" << endl;
			Show_Peo_Info(con);
			break;
		case Contact_Sort:
			cout << "������ϵ����Ϣ" << endl;
			Sort_Peo_Info(con);
			break;
		case Contact_Clear:
			cout << "���ͨѶ¼����Ϣ" << endl;
			Clear_Peo_Info(con);
			break;
		default:
			cout << "����Ƿ�������������" << endl;
			break;
		}
	} while (input);

	return 0;
}