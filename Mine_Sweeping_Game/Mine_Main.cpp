#define _CRT_SECURE_NO_WARNINGS

// Mine_Sweeping_Game

#include"Mine_Func.h"

// �˵�
void menu()
{
	cout << "@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << "1-play    0-exit" << endl;
	cout << "@@@@@@@@@@@@@@@@@@@@@@" << endl;
}

// ����ʵ��
void Mine_Game()
{
	char show[ROWS][COLS] = { 0 };
	char mine[ROWS][COLS] = { 0 };

	// ��ʼ��
	Init_Board(show, ROWS, COLS, '*');
	Init_Board(mine, ROWS, COLS, '0');

	// ��ӡ
	Print_Board(show, ROW, COL);
	Print_Board(mine, ROW, COL);

	// ������
	Set_Mine(mine, ROW, COL, '1');
	// Print_Board(mine, ROW, COL);

	// ����
	Search_Mine(show, mine, ROW, COL);
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
			Mine_Game();
			break;
		default:
			cout << "����Ƿ�������������" << endl;
			break;
		}
	} while (input);

	return 0;
}