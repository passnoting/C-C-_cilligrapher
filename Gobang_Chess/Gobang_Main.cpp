#define _CRT_SECURE_NO_WARNINGS

// Wuzi chess source program

#include "Gobang.h"


void menu()
{
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << "1-play    0-exit" << endl;
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
}

// ��Ϸ����
void gobang_game()
{
	char ch = 0;
	char arr[ROW][COL] = { 0 };

	// ��ʼ������
	Gobang_Init(arr, ROW, COL);

	// ��ӡ����
	Gobang_Print(arr, ROW, COL);

	while (1)
	{
		// �������
		Gobang_Player(arr, ROW, COL, '*');
		Gobang_Print(arr, ROW, COL);
		ch = Is_Win(arr, ROW, COL);
		if (ch != 'C')
		{
			break;
		}

		// ��������
		Gobang_Computer(arr, ROW, COL, '#');
		Gobang_Print(arr, ROW, COL);
		ch = Is_Win(arr, ROW, COL);
		if (ch != 'C')
		{
			break;
		}
	}
	switch (ch)
	{
	case '*':
		cout << "$��ϲ�㣬Ӯ��$" << endl;
		break;
	case '#':
		cout << "$���ź���������$" << endl;
		break;
	case 'Q':
		cout << "$�˾���ƽ��$" << endl;
		break;
	default:
		cout << "�������" << endl;
		break;
	}

}

int main()
{
	int input = 0;

	srand((unsigned int)time(NULL));
	
	do
	{
		menu();
		cout << "���������ѡ��> ";
		cin >> input;
		switch (input)
		{
		case 0:
			cout << "�˳���Ϸ" << endl;
			break;
		case 1:
			gobang_game();
			break;
		default:
			cout << "����Ƿ�������������" << endl;
			break;
		}

	} while (input);

	return 0;
}
