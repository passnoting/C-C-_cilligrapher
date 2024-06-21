#define _CRT_SECURE_NO_WARNINGS

// Mine_Sweeping_Game

#include"Mine_Func.h"

// 菜单
void menu()
{
	cout << "@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << "1-play    0-exit" << endl;
	cout << "@@@@@@@@@@@@@@@@@@@@@@" << endl;
}

// 函数实现
void Mine_Game()
{
	char show[ROWS][COLS] = { 0 };
	char mine[ROWS][COLS] = { 0 };

	// 初始化
	Init_Board(show, ROWS, COLS, '*');
	Init_Board(mine, ROWS, COLS, '0');

	// 打印
	Print_Board(show, ROW, COL);
	Print_Board(mine, ROW, COL);

	// 设置雷
	Set_Mine(mine, ROW, COL, '1');
	// Print_Board(mine, ROW, COL);

	// 排雷
	Search_Mine(show, mine, ROW, COL);
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		cout << "请输入你的选择：> ";
		cin >> input;
		switch (input)
		{
		case 0:
			cout << "退出游戏" << endl;
			break;
		case 1:
			Mine_Game();
			break;
		default:
			cout << "输入非法，请重新输入" << endl;
			break;
		}
	} while (input);

	return 0;
}