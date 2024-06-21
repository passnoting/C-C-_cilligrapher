#define _CRT_SECURE_NO_WARNINGS

// Mine_Sweeping_Game


#include"Mine_Func.h"


// ��ʼ��
void Init_Board(char arr[ROWS][COLS], int rows, int cols, char ret)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			arr[i][j] = ret;
		}
	}
}


// ��ӡ
void Print_Board(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i <= row; i++)
	{
		cout << i << " ";
	}
	cout << endl;

	for (i = 1; i <= row; i++)
	{
		cout << i << " ";
		for (j = 1; j <= col; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

// ������
void Set_Mine(char arr[ROWS][COLS], int row, int col, char ret)
{
	int x = 0;
	int y = 0;
	int i = 0;

	while (i < Mine_Count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (arr[x][y] == '0')
		{
			arr[x][y] = ret;
			++i;
		}
	}
}


// ����

int Count_Mine_Around(char mine[ROWS][COLS], int x,int y)
{
	return (mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] +
		mine[x][y - 1] + mine[x][y + 1] + mine[x + 1][y - 1] +
		mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0');
}

void Search_Mine(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int i = 0;
	
	while (i < ROW * COL - Mine_Count)
	{
		cout << "������Ҫ�Ų������(�ÿո�ָ���)��> ";
		scanf("%d %d", &x, &y);
		//cin >> x >> y;		�����ã���������
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				cout << "���ź����㱻ը����" << endl;
				break;
			}
			else
			{
				int num = Count_Mine_Around(mine, x, y);
				char ch = num + '0';
				show[x][y] = ch;
				++i;
				Print_Board(show, row, col);
			}
		}
		else
		{
			cout << "��������Ƿ������������룡" << endl;
			// ��ջ�����
			while (getchar() != '\n');

		}
	}
	if (i == ROW * COL - Mine_Count)
	{
		cout << "ɨ����ϣ���ϲ��ʤ����" << endl;
	}
}