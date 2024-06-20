#define _CRT_SECURE_NO_WARNINGS

// Wuzi chess source program

#include "Gobang.h"


// 初始化棋盘
void Gobang_Init(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			arr[i][j] = ' ';
		}
	}
}


// 打印棋盘
//   |  |  
// --|--|--
//   |  |  
// --|--|--
//   |  |
void Gobang_Print(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			cout << " " << arr[i][j] << " ";
			if (j < col - 1)
			{
				cout << "|";
			}
		}
		cout << endl;

		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				cout << "---";
				if (j < col - 1)
				{
					cout << "|";
				}
			}
			cout << endl;
		}

	}
}


// 玩家下棋
void Gobang_Player(char arr[ROW][COL], int row, int col, char ret)
{
	int x = 0;
	int y = 0;

	cout << "玩家下棋" << endl;
	while (1)
	{
		cout << "请输入要下入的坐标：> ";
		cin >> x >> y;
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (arr[x - 1][y - 1] == ' ')
			{
				arr[x - 1][y - 1] = ret;
				break;
			}
			else
			{
				cout << "该坐标被占用，请重新输入" << endl;
			}
		}
		else
		{
			cout << "输入坐标非法，请重新输入!!!" << endl;
		}
	}
}


// 电脑下棋
void Gobang_Computer(char arr[ROW][COL], int row, int col, char ret)
{
	int x = 0;
	int y = 0;

	cout << "电脑下棋" << endl;
	while (1)
	{
		x = rand() % row;
		y = rand() % col;

		if (arr[x][y] == ' ')
		{
			arr[x][y] = ret;
			break;
		}
	}
}


// 判断输赢
// 玩家赢--'*'
// 电脑赢--'#'
// 平局----'Q'
// 继续----'C'

// 平局判断
bool Is_Same(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (arr[i][j] == ' ')
			{
				return false;
			}
		}
	}
	return true;
}

char Is_Win(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int win = 0;

	// 行判断
	for (i = 0; i < row; i++)
	{
		win = 0;
		for (j = 0; j < col-1; j++)
		{
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] != ' ')
			{
				win++;
			}
		}
		if (win == col - 1)
		{
			return arr[i][j];
		}
	}

	// 列判断
	for (i = 0; i < col; i++)
	{
		win = 0;
		for (j = 0; j < row-1; j++)
		{
			if (arr[j][i] == arr[j+1][i] && arr[j][i] != ' ')
			{
				win++;
			}
		}
		if (win == row - 1)
		{
			return arr[j][i];
		}
	}

	// 对角线（左上-右下）判断
	win = 0;
	for (i = 0, j = 0; i < row - 1 && j < col - 1; i++, j++)
	{
		if (arr[i][j] == arr[i + 1][j + 1] && arr[i][j] != ' ')
		{
			win++;
		}
	}
	if (win == row - 1)
	{
		return arr[i][j];
	}

	// 对角线（左下-右上）判断
	win = 0;
	for (i = 0, j = col-1; i < row - 1, j>0; i++, j--)
	{
		if (arr[i][j] == arr[i + 1][j - 1] && arr[i][j] != ' ')
		{
			win++;
		}
	}
	if (win == row - 1)
	{
		return arr[i][j];
	}

	// 平局判断
	if (Is_Same(arr, row, col))
	{
		return 'Q';
	}

	// 继续
	return 'C';
}