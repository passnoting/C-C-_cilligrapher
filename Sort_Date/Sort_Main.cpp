#define _CRT_SECURE_NO_WARNINGS


#include"Sort_Func.h"



// ð������
void Bubble_Test()
{
	int a[] = { 2,7,1,9,4,6,10,8,0,3 };
	int sz = sizeof(a) / sizeof(a[0]);
	cout << "ð������ǰ��=> ";
	Print(a, sz);
	Bubble_Sort(a, sz);
	cout << "ð�������=> ";
	Print(a, sz);
	cout << endl;
}

// ��������
void Insert_Test()
{
	int a[] = { 2,7,1,9,4,6,10,8,0,3 };
	int sz = sizeof(a) / sizeof(a[0]);
	cout << "��������ǰ��=> ";
	Print(a, sz);
	Insert_Sort(a, sz);
	cout << "���������=> ";
	Print(a, sz);
	cout << endl;
}

// ѡ������
void Select_Test()
{
	int a[] = { 2,7,1,9,4,6,10,8,0,3 };
	int sz = sizeof(a) / sizeof(a[0]);
	cout << "ѡ������ǰ��=> ";
	Print(a, sz);
	Select_Sort(a, sz);
	cout << "ѡ�������=> ";
	Print(a, sz);
	cout << endl;
}


// ��������
void Count_Test()
{
	int a[] = { 2,7,1,9,4,6,10,8,0,3 };
	int sz = sizeof(a) / sizeof(a[0]);
	cout << "��������ǰ��=> ";
	Print(a, sz);
	Count_Sort(a, sz);
	cout << "���������=> ";
	Print(a, sz);
	cout << endl;
}

int main()
{
	// ð������
	Bubble_Test();

	// ��������
	Insert_Test();

	// ѡ������
	Select_Test();

	// ��������
	Count_Test();

	return 0;
}