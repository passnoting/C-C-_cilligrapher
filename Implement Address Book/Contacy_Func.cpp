#define _CRT_SECURE_NO_WARNINGS

// Implement Address Book

#include"Contacy_Func.h"

// 检查容量
void Check_Capacity(Contact& pon)
{
	if (pon.capacity == pon.size)
	{
		int newcapacity = pon.capacity == 0 ? 4:pon.capacity * 2;
		Peo_Info* tmp = (Peo_Info*)realloc(pon.data, sizeof(Peo_Info) * newcapacity);
		if (tmp == NULL)
		{
			perror("Check_Capacity realloc fail");
			return;
		}
		pon.data = tmp;
		pon.capacity = newcapacity;
	}
}

// 从文件中读取数据
void Contact_Txt(Contact& pon)
{
	// 打开文件
	FILE* pf = fopen("Contact_Peo_Info.txt", "rb");
	if (pf == NULL)
	{
		perror("Contact_Txt fopen fail");
		return;
	}
	// 读入数据
	Peo_Info tmp = { 0 };

	while (fread(&tmp, sizeof(Peo_Info), 1, pf))
	{
		// 检查容量
		Check_Capacity(pon);

		pon.data[pon.size] = tmp;
		++pon.size;
	}

	// 关闭文件
	fclose(pf);
	pf = NULL;
}

// 初始化通讯录
void Contact_Init(Contact& pon)
{
	pon.data = (Peo_Info*)malloc(sizeof(Peo_Info) * Be_Max);
	if (pon.data == NULL)
	{
		perror("Contact_Init malloc");
		return;
	}
	pon.capacity = Be_Max;
	pon.size = 0;

	Contact_Txt(pon);

}

// 添加联系人信息
void Add_Peo_Info(Contact& pon)
{
	// 监察容量
	Check_Capacity(pon);

	cout << "请输入要添加联系人的姓名：=> ";
	cin >> pon.data[pon.size].name;
	cout << "请输入要添加联系人的年龄：=> ";
	cin >> pon.data[pon.size].age;
	cout << "请输入要添加联系人的性别：=> ";
	cin >> pon.data[pon.size].sex;
	cout << "请输入要添加联系人的电话：=> ";
	cin >> pon.data[pon.size].phone;
	cout << "请输入要添加联系人的住址：=> ";
	cin >> pon.data[pon.size].address;

	pon.size++;
	cout << "$添加联系人信息成功$" << endl;
}

// 查找某一联系人是否存在
int Find_Peo(Contact& pon, char* name)
{
	int i = 0;
	for (i = 0; i < pon.size; i++)
	{
		if (strcmp(pon.data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

// 删除联系人信息
void Del_Peo_Info(Contact& pon)
{
	char name[20] = { 0 };
	cout << "请输入你要删除联系人的姓名：=> ";
	cin >> name;
	int i = Find_Peo(pon, name);
	if (i != -1)
	{
		int j = i + 1;
		while (j < pon.size)
		{
			pon.data[j-1] = pon.data[j];
			j++;
		}
		pon.size--;
		cout << "$删除联系人成功$" << endl;
	}
	else
	{
		cout << "$该通讯录中查无此人$" << endl;
	}
}


// 联系修改人信息
void Edit_Peo_Info(Contact& pon)
{
	char name[20] = { 0 };
	cout << "请输入你要修改的联系人的姓名：=> ";
	cin >> name;
	int i = Find_Peo(pon, name);
	if (i != -1)
	{
		cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
		cout << "1-修改姓名  2-修改年龄  3-修改电话  4-修改地址  5-全部修改" << endl;
		cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
		
		int put = 0;
		cout << "请输入你的选择：=> ";
		cin >> put;
		switch (put)
		{
		case 1:
			cout << "请输入修改后的姓名：=> ";
			cin >> pon.data[i].name;
			break;
		case 2:
			cout << "请输入修改后的年龄：=> ";
			cin >> pon.data[i].age;
			break;
		case 3:
			cout << "请输入修改后的电话：=> ";
			cin >> pon.data[i].phone;
			break;
		case 4:
			cout << "请输入修改后的住址：=> ";
			cin >> pon.data[i].address;
			break;
		case 5:
			cout << "请输入修改后的姓名：=> ";
			cin >> pon.data[i].name;
			cout << "请输入修改后的年龄：=> ";
			cin >> pon.data[i].age;
			cout << "请输入修改后的性别：=> ";
			cin >> pon.data[i].sex;
			cout << "请输入修改后的电话：=> ";
			cin >> pon.data[i].phone;
			cout << "请输入修改后的住址：=> ";
			cin >> pon.data[i].address;
			break;
		default:
			cout << "$您的输入非法$" << endl;
			break;
		}
		cout << "修改成功" << endl;
	}
	else
	{
		cout << "$该通讯录中查无此人$" << endl;
	}
}

// 查询联系人信息
void Inq_Peo_Info(Contact& pon)
{
	char name[20] = { 0 };
	cout << "请输入你要查询的联系人的姓名：=> ";
	cin >> name;
	int i = Find_Peo(pon, name);
	if (i != -1)
	{
		printf("%-20s %-10s %-10s %-15s %-30s\n", "姓名", "年龄", "性别", "电话号码", "家庭住址");
		printf("%-20s %-10d %-10s %-15s %-30s\n", pon.data[i].name, pon.data[i].age
			, pon.data[i].sex, pon.data[i].phone, pon.data[i].address);
	}
	else
	{
		cout << "$该通讯录中查无此人$" << endl;
	}
}

// 显示联系人信息
void Show_Peo_Info(Contact& pon)
{
	int i = 0;
	printf("%-20s %-10s %-10s %-15s %-30s\n", "姓名", "年龄", "性别", "电话号码","家庭住址");
	for (i = 0; i < pon.size; i++)
	{
		printf("%-20s %-10d %-10s %-15s %-30s\n", pon.data[i].name, pon.data[i].age
			, pon.data[i].sex, pon.data[i].phone, pon.data[i].address);
	}
}

// 排序姓名
int cmp_name(const void* p1, const void* p2)
{
	return strcmp(((Peo_Info*)p1)->name, ((Peo_Info*)p2)->name);
}

// 排序年龄
int cmp_age(const void* p1, const void* p2)
{
	return ((Peo_Info*)p1)->name - ((Peo_Info*)p2)->name;
}

// 排序电话号码
int cmp_phone(const void* p1, const void* p2)
{
	return strcmp(((Peo_Info*)p1)->phone, ((Peo_Info*)p2)->phone);
}

// 排序家庭住址
int cmp_address(const void* p1, const void* p2)
{
	return strcmp(((Peo_Info*)p1)->address, ((Peo_Info*)p2)->address);
}

// 排序联系人信息
void Sort_Peo_Info(Contact& pon)
{
	int input = 0;
	cout << "##############################################################" << endl;
	cout << "1-按姓名排序  2-按年龄排序  3-按电话号码排序  4-按家庭住址排序" << endl;
	cout << "##############################################################" << endl;
	
	cout << "请输入你的选择：=> ";
	cin >> input;
	switch (input)
	{
	case 1:
		qsort(pon.data, pon.size, sizeof(Peo_Info), cmp_name);
		break;
	case 2:
		qsort(pon.data, pon.size, sizeof(Peo_Info), cmp_age);
		break;
	case 3:
		qsort(pon.data, pon.size, sizeof(Peo_Info), cmp_phone);
		break;
	case 4:
		qsort(pon.data, pon.size, sizeof(Peo_Info), cmp_address);
		break;
	default:
		cout << "输入非法" << endl;
		break;
	}
}


// 清空通讯录中信息
void Clear_Peo_Info(Contact& pon)
{
	Contact_Init(pon);
}



// 保存联系人信息
void Sava_Peo_Info(Contact& pon)
{
	// 打开文件
	FILE* pf = fopen("Contact_Peo_Info.txt", "wb");
	if (pf == NULL)
	{
		perror("Sava_Peo_Info fopen");
		return;
	}
	// 写文件
	int i = 0;
	for (i = 0; i < pon.size; i++)
	{
		fwrite(pon.data + i, sizeof(Peo_Info), 1, pf);
	}

	// 关闭文件
	fclose(pf);
	pf = NULL;
}


// 销毁通讯录
void Destroy_Contact(Contact& pon)
{
	free(pon.data);
	pon.capacity = pon.size = 0;
}