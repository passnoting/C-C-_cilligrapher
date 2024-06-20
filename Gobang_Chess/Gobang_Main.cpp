#define _CRT_SECURE_NO_WARNINGS

// Wuzi chess source program

#include "Gobang.h"


void menu()
{
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << "1-play    0-exit" << endl;
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
}

// 游戏函数
void gobang_game()
{
	char ch = 0;
	char arr[ROW][COL] = { 0 };

	// 初始化棋盘
	Gobang_Init(arr, ROW, COL);

	// 打印棋盘
	Gobang_Print(arr, ROW, COL);

	while (1)
	{
		// 玩家下棋
		Gobang_Player(arr, ROW, COL, '*');
		Gobang_Print(arr, ROW, COL);
		ch = Is_Win(arr, ROW, COL);
		if (ch != 'C')
		{
			break;
		}

		// 电脑下棋
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
		cout << "$恭喜你，赢啦$" << endl;
		break;
	case '#':
		cout << "$很遗憾，你输了$" << endl;
		break;
	case 'Q':
		cout << "$此局是平局$" << endl;
		break;
	default:
		cout << "错误错误！" << endl;
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
		cout << "请输入你的选择：> ";
		cin >> input;
		switch (input)
		{
		case 0:
			cout << "退出游戏" << endl;
			break;
		case 1:
			gobang_game();
			break;
		default:
			cout << "输入非法，请重新输入" << endl;
			break;
		}

	} while (input);

	return 0;
}
