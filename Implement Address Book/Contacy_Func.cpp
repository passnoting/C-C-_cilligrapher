#define _CRT_SECURE_NO_WARNINGS

// Implement Address Book

#include"Contacy_Func.h"

// �������
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

// ���ļ��ж�ȡ����
void Contact_Txt(Contact& pon)
{
	// ���ļ�
	FILE* pf = fopen("Contact_Peo_Info.txt", "rb");
	if (pf == NULL)
	{
		perror("Contact_Txt fopen fail");
		return;
	}
	// ��������
	Peo_Info tmp = { 0 };

	while (fread(&tmp, sizeof(Peo_Info), 1, pf))
	{
		// �������
		Check_Capacity(pon);

		pon.data[pon.size] = tmp;
		++pon.size;
	}

	// �ر��ļ�
	fclose(pf);
	pf = NULL;
}

// ��ʼ��ͨѶ¼
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

// �����ϵ����Ϣ
void Add_Peo_Info(Contact& pon)
{
	// �������
	Check_Capacity(pon);

	cout << "������Ҫ�����ϵ�˵�������=> ";
	cin >> pon.data[pon.size].name;
	cout << "������Ҫ�����ϵ�˵����䣺=> ";
	cin >> pon.data[pon.size].age;
	cout << "������Ҫ�����ϵ�˵��Ա�=> ";
	cin >> pon.data[pon.size].sex;
	cout << "������Ҫ�����ϵ�˵ĵ绰��=> ";
	cin >> pon.data[pon.size].phone;
	cout << "������Ҫ�����ϵ�˵�סַ��=> ";
	cin >> pon.data[pon.size].address;

	pon.size++;
	cout << "$�����ϵ����Ϣ�ɹ�$" << endl;
}

// ����ĳһ��ϵ���Ƿ����
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

// ɾ����ϵ����Ϣ
void Del_Peo_Info(Contact& pon)
{
	char name[20] = { 0 };
	cout << "��������Ҫɾ����ϵ�˵�������=> ";
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
		cout << "$ɾ����ϵ�˳ɹ�$" << endl;
	}
	else
	{
		cout << "$��ͨѶ¼�в��޴���$" << endl;
	}
}


// ��ϵ�޸�����Ϣ
void Edit_Peo_Info(Contact& pon)
{
	char name[20] = { 0 };
	cout << "��������Ҫ�޸ĵ���ϵ�˵�������=> ";
	cin >> name;
	int i = Find_Peo(pon, name);
	if (i != -1)
	{
		cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
		cout << "1-�޸�����  2-�޸�����  3-�޸ĵ绰  4-�޸ĵ�ַ  5-ȫ���޸�" << endl;
		cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
		
		int put = 0;
		cout << "���������ѡ��=> ";
		cin >> put;
		switch (put)
		{
		case 1:
			cout << "�������޸ĺ��������=> ";
			cin >> pon.data[i].name;
			break;
		case 2:
			cout << "�������޸ĺ�����䣺=> ";
			cin >> pon.data[i].age;
			break;
		case 3:
			cout << "�������޸ĺ�ĵ绰��=> ";
			cin >> pon.data[i].phone;
			break;
		case 4:
			cout << "�������޸ĺ��סַ��=> ";
			cin >> pon.data[i].address;
			break;
		case 5:
			cout << "�������޸ĺ��������=> ";
			cin >> pon.data[i].name;
			cout << "�������޸ĺ�����䣺=> ";
			cin >> pon.data[i].age;
			cout << "�������޸ĺ���Ա�=> ";
			cin >> pon.data[i].sex;
			cout << "�������޸ĺ�ĵ绰��=> ";
			cin >> pon.data[i].phone;
			cout << "�������޸ĺ��סַ��=> ";
			cin >> pon.data[i].address;
			break;
		default:
			cout << "$��������Ƿ�$" << endl;
			break;
		}
		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "$��ͨѶ¼�в��޴���$" << endl;
	}
}

// ��ѯ��ϵ����Ϣ
void Inq_Peo_Info(Contact& pon)
{
	char name[20] = { 0 };
	cout << "��������Ҫ��ѯ����ϵ�˵�������=> ";
	cin >> name;
	int i = Find_Peo(pon, name);
	if (i != -1)
	{
		printf("%-20s %-10s %-10s %-15s %-30s\n", "����", "����", "�Ա�", "�绰����", "��ͥסַ");
		printf("%-20s %-10d %-10s %-15s %-30s\n", pon.data[i].name, pon.data[i].age
			, pon.data[i].sex, pon.data[i].phone, pon.data[i].address);
	}
	else
	{
		cout << "$��ͨѶ¼�в��޴���$" << endl;
	}
}

// ��ʾ��ϵ����Ϣ
void Show_Peo_Info(Contact& pon)
{
	int i = 0;
	printf("%-20s %-10s %-10s %-15s %-30s\n", "����", "����", "�Ա�", "�绰����","��ͥסַ");
	for (i = 0; i < pon.size; i++)
	{
		printf("%-20s %-10d %-10s %-15s %-30s\n", pon.data[i].name, pon.data[i].age
			, pon.data[i].sex, pon.data[i].phone, pon.data[i].address);
	}
}

// ��������
int cmp_name(const void* p1, const void* p2)
{
	return strcmp(((Peo_Info*)p1)->name, ((Peo_Info*)p2)->name);
}

// ��������
int cmp_age(const void* p1, const void* p2)
{
	return ((Peo_Info*)p1)->name - ((Peo_Info*)p2)->name;
}

// ����绰����
int cmp_phone(const void* p1, const void* p2)
{
	return strcmp(((Peo_Info*)p1)->phone, ((Peo_Info*)p2)->phone);
}

// �����ͥסַ
int cmp_address(const void* p1, const void* p2)
{
	return strcmp(((Peo_Info*)p1)->address, ((Peo_Info*)p2)->address);
}

// ������ϵ����Ϣ
void Sort_Peo_Info(Contact& pon)
{
	int input = 0;
	cout << "##############################################################" << endl;
	cout << "1-����������  2-����������  3-���绰��������  4-����ͥסַ����" << endl;
	cout << "##############################################################" << endl;
	
	cout << "���������ѡ��=> ";
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
		cout << "����Ƿ�" << endl;
		break;
	}
}


// ���ͨѶ¼����Ϣ
void Clear_Peo_Info(Contact& pon)
{
	Contact_Init(pon);
}



// ������ϵ����Ϣ
void Sava_Peo_Info(Contact& pon)
{
	// ���ļ�
	FILE* pf = fopen("Contact_Peo_Info.txt", "wb");
	if (pf == NULL)
	{
		perror("Sava_Peo_Info fopen");
		return;
	}
	// д�ļ�
	int i = 0;
	for (i = 0; i < pon.size; i++)
	{
		fwrite(pon.data + i, sizeof(Peo_Info), 1, pf);
	}

	// �ر��ļ�
	fclose(pf);
	pf = NULL;
}


// ����ͨѶ¼
void Destroy_Contact(Contact& pon)
{
	free(pon.data);
	pon.capacity = pon.size = 0;
}