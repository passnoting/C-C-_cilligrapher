#define _CRT_SECURE_NO_WARNINGS

#include"Sort_Func.h"

// 打印数据
void Print(int* a, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

// 交换数据
void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

// 冒泡排序
void Bubble_Sort(int* a, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		int j = 0;
		for (j = 1; j < sz - i; j++)
		{
			if (a[j] < a[j - 1])
			{
				Swap(a[j], a[j - 1]);
			}
		}
	}
}

// 插入排序
void Insert_Sort(int* a, int sz)
{
	for (int i = 1; i < sz; i++)
	{
		int tmp = a[i];
		int end = i - 1;
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end+1] = tmp;
	}
}

// 选择排序
void Select_Sort(int* a, int sz)
{
	int begin = 0;
	int end = sz - 1;

	while (begin <= end)
	{
		int i = 0;
		int max = begin;
		int min = begin;
		for (i = begin; i <= end; i++)
		{
			if (a[i] >= a[max])
			{
				max = i;
			}
			else if (a[i] <= a[min])
			{
				min = i;
			}
		}
		Swap(a[min], a[begin]);
		if (max == begin)
		{
			max = min;
		}
		Swap(a[max], a[end]);

		++begin;
		--end;
	}
}

// 计数排序
void Count_Sort(int* a, int sz)
{
	int min = a[0], max = a[0];
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	int range = max - min + 1;
	int* Count_A = (int*)malloc(sizeof(int) * range);
	if (Count_A == nullptr)
	{
		perror("Count_Sort malloc fail");
		exit(-1);
	}
	memset(Count_A, 0, sizeof(int) * range);
	for (i = 0; i < sz; i++)
	{
		Count_A[a[i] - min]++;
	}

	// 排序
	int k = 0;
	int j = 0;
	for (j = 0; j < range; j++)
	{
		while (Count_A[j]--)
		{
			a[k++] = j + min;
		}
	}
}
