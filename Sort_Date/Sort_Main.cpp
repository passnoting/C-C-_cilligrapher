#define _CRT_SECURE_NO_WARNINGS


#include"Sort_Func.h"



// √∞≈›≈≈–Ú
void Bubble_Test()
{
	int a[] = { 2,7,1,9,4,6,10,8,0,3 };
	int sz = sizeof(a) / sizeof(a[0]);
	cout << "√∞≈›≈≈–Ú«∞£∫=> ";
	Print(a, sz);
	Bubble_Sort(a, sz);
	cout << "√∞≈›≈≈–Ú∫Û£∫=> ";
	Print(a, sz);
	cout << endl;
}

// ≤Â»Î≈≈–Ú
void Insert_Test()
{
	int a[] = { 2,7,1,9,4,6,10,8,0,3 };
	int sz = sizeof(a) / sizeof(a[0]);
	cout << "≤Â»Î≈≈–Ú«∞£∫=> ";
	Print(a, sz);
	Insert_Sort(a, sz);
	cout << "≤Â»Î≈≈–Ú∫Û£∫=> ";
	Print(a, sz);
	cout << endl;
}

// —°‘Ò≈≈–Ú
void Select_Test()
{
	int a[] = { 2,7,1,9,4,6,10,8,0,3 };
	int sz = sizeof(a) / sizeof(a[0]);
	cout << "—°‘Ò≈≈–Ú«∞£∫=> ";
	Print(a, sz);
	Select_Sort(a, sz);
	cout << "—°‘Ò≈≈–Ú∫Û£∫=> ";
	Print(a, sz);
	cout << endl;
}


// º∆ ˝≈≈–Ú
void Count_Test()
{
	int a[] = { 2,7,1,9,4,6,10,8,0,3 };
	int sz = sizeof(a) / sizeof(a[0]);
	cout << "º∆ ˝≈≈–Ú«∞£∫=> ";
	Print(a, sz);
	Count_Sort(a, sz);
	cout << "º∆ ˝≈≈–Ú∫Û£∫=> ";
	Print(a, sz);
	cout << endl;
}

int main()
{
	// √∞≈›≈≈–Ú
	Bubble_Test();

	// ≤Â»Î≈≈–Ú
	Insert_Test();

	// —°‘Ò≈≈–Ú
	Select_Test();

	// º∆ ˝≈≈–Ú
	Count_Test();

	return 0;
}