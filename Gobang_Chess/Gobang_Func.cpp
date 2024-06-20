#define _CRT_SECURE_NO_WARNINGS

// Wuzi chess source program

#include "Gobang.h"


// ��ʼ������
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


// ��ӡ����
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


// �������
void Gobang_Player(char arr[ROW][COL], int row, int col, char ret)
{
	int x = 0;
	int y = 0;

	cout << "�������" << endl;
	while (1)
	{
		cout << "������Ҫ��������꣺> ";
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
				cout << "�����걻ռ�ã�����������" << endl;
			}
		}
		else
		{
			cout << "��������Ƿ�������������!!!" << endl;
		}
	}
}


// ��������
void Gobang_Computer(char arr[ROW][COL], int row, int col, char ret)
{
	int x = 0;
	int y = 0;

	cout << "��������" << endl;
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


// �ж���Ӯ
// ���Ӯ--'*'
// ����Ӯ--'#'
// ƽ��----'Q'
// ����----'C'

// ƽ���ж�
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

	// ���ж�
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

	// ���ж�
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

	// �Խ��ߣ�����-���£��ж�
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

	// �Խ��ߣ�����-���ϣ��ж�
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

	// ƽ���ж�
	if (Is_Same(arr, row, col))
	{
		return 'Q';
	}

	// ����
	return 'C';
}