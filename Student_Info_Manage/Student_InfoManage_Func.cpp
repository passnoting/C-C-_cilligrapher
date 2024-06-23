#define _CRT_SECURE_NO_WARNINGS

// ѧ����Ϣ����ϵͳ

// ����Ա
// ѧ��
// ����
// �ļ�����

#include "Student_InfoManage_Func.h"

// �������
void CheckCapacity(InfoManage* pg)
{
	if (pg->size == pg->capacity)
	{
		int newcapacity = pg->capacity == 0 ? 4 : pg->capacity * 2;
		Student_Info* tmp = (Student_Info*)realloc(pg->data, sizeof(Student_Info) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		pg->data = tmp;
		pg->capacity = newcapacity;
	}
}

// �����ݴ��ļ����ó���
void Stu_Info_Acq(InfoManage* pg)
{
	// ���ļ�
	FILE* pf = fopen("Stu_Info.txt", "rb");
	if (pf == NULL)
	{
		perror("Stu_Info_Acq fopen");
		return;
	}
	// ��ȡ�ļ�

	Student_Info tmp = { 0 };

	while (fread(&tmp, sizeof(Student_Info), 1, pf))
	{
		// �������
		CheckCapacity(pg);

		pg->data[pg->size] = tmp;
		pg->size++;

	}

	// �ر��ļ���
	fclose(pf);
	pf = NULL;
}

// ��ʼ��ϵͳ
void Init_Manage(InfoManage* pg)
{
	pg->data = (Student_Info*)malloc(sizeof(Student_Info) * Max_Count);
	pg->capacity = 3;
	pg->size = 0;

	Stu_Info_Acq(pg);
}




// ���ѧ����Ϣ
void Tea_Manage_Add(InfoManage* pg)
{
	assert(pg);
	CheckCapacity(pg);

	cout << "������ѧ��������> ";
	cin >> pg->data[pg->size].name;
	cout << "������ѧ��ѧ�ţ�> ";
	cin >> pg->data[pg->size].sid;
	cout << "������ѧ�����䣺> ";
	cin >> pg->data[pg->size].age;
	cout << "������ѧ���Ա�> ";
	cin >> pg->data[pg->size].sex;
	cout << "������ѧ���ɼ���> ";
	cin >> pg->data[pg->size].grade;

	pg->size++;
	cout << "ѧ����Ϣ��ӳɹ�" << endl;
}

// ��ĳһѧ���Ƿ����
int Find_Stu(InfoManage* pg,char* sid)
{
	int i = 0;
	for (i = 0; i < pg->size; i++)
	{
		if (strcmp(sid, pg->data[i].sid) == 0)
		{
			return i;
		}
	}
	return -1;
}

// ɾ��ѧ����Ϣ
void Tea_Manage_Del(InfoManage* pg)
{
	assert(pg);

	char sid[Sid_Max] = { 0 };
	cout << "������Ҫɾ��ѧ����ѧ�ţ�> ";
	cin >> sid;
	int i = Find_Stu(pg, sid);
	if (i != -1)
	{
		int j = 0;
		for (j = i + 1; j < pg->size; j++)
		{
			pg->data[j - 1] = pg->data[j];
		}
		pg->size--;
		cout << "ѧ����Ϣɾ���ɹ�" << endl;
	}
	else
	{
		cout << "��ѧ��������" << endl;
	}
}


// �޸�ѧ����Ϣ
// �޸�ȫ����Ϣ
void Edit_Stu_All(InfoManage* pg, int i)
{
	cout << "�������޸ĺ��ѧ��������> ";
	cin >> pg->data[i].name;
	cout << "�������޸ĺ��ѧ��ѧ�ţ�> ";
	cin >> pg->data[i].sid;
	cout << "�������޸ĺ��ѧ�����䣺> ";
	cin >> pg->data[i].age;
	cout << "�������޸ĺ��ѧ���Ա�> ";
	cin >> pg->data[i].sex;
	cout << "�������޸ĺ��ѧ���ɼ���> ";
	cin >> pg->data[i].grade;

}

void Tea_Manage_Edit(InfoManage* pg)
{
	assert(pg);

	char sid[Sid_Max] = { 0 };
	cout << "������Ҫ�޸�ѧ����ѧ�ţ�> ";
	cin >> sid;
	int i = Find_Stu(pg, sid);
	if (i != -1)
	{
		cout << "1-�޸�����  2-�޸�ѧ��  3-�޸�����  4-�޸ĳɼ�  5-ȫ���޸�" << endl;
		cout << "����������ѡ��> ";
		int put = 0;
		cin >> put;
		switch (put)
		{
		case Edit_Name:
			cout << "�������޸ĺ��������> ";
			cin >> pg->data[i].name;
			break;
		case Edit_Sid:
			cout << "�������޸ĺ��ѧ�ţ�> ";
			cin >> pg->data[i].sid;
			break;
		case Edit_Age:
			cout << "�������޸ĺ�����䣺> ";
			cin >> pg->data[i].age;
			break;
		case Edit_Grade:
			cout << "�������޸ĺ�ĳɼ���> ";
			cin >> pg->data[i].grade;
			break;
		case Edit_All:
			Edit_Stu_All(pg, i);
			break;
		}
		cout << "ѧ����Ϣ�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "��ѧ��������" << endl;
	}
}


// ��ѯѧ����Ϣ
void Tea_Manage_Inq(InfoManage* pg)
{
	char sid[Sid_Max] = { 0 };
	cout << "������Ҫ��ѯѧ����ѧ�ţ�> ";
	cin >> sid;
	int i = Find_Stu(pg, sid);
	if (i != -1)
	{
		printf("%-20s %-10s %-10s %-10s %-10s\n", "����", "ѧ��", "����", "�Ա�", "�ɼ�");
		printf("%-20s %-10s %-10d %-10s %-10.2lf\n", pg->data[i].name,
			pg->data[i].sid, pg->data[i].age, pg->data[i].sex, pg->data[i].grade);
	}
	else
	{
		cout << "��ѧ��������" << endl;
	}

}


// ��ʾѧ����Ϣ
void Tea_Manage_Show(InfoManage* pg)
{
	assert(pg);
	int i = 0;
	printf("%-20s %-10s %-10s %-10s %-10s\n", "����", "ѧ��", "����", "�Ա�", "�ɼ�");
	for (i = 0; i < pg->size; i++)
	{
		printf("%-20s %-10s %-10d %-10s %-10.2lf\n", pg->data[i].name,
			pg->data[i].sid, pg->data[i].age, pg->data[i].sex, pg->data[i].grade);
	}
}

// ����ѧ����Ϣ

// ��������
int cmp_name(const void* p1, const void* p2)
{
	return strcmp(((Student_Info*)p1)->name, ((Student_Info*)p2)->name);
}
// ����ѧ��
int cmp_sid(const void* p1, const void* p2)
{
	return strcmp(((Student_Info*)p1)->sid, ((Student_Info*)p2)->sid);
}
// ��������
int cmp_age(const void* p1, const void* p2)
{
	return ((Student_Info*)p1)->age - ((Student_Info*)p2)->age;
}
// ����ɼ�
int cmp_grade(const void* p1, const void* p2)
{
	return (int)((Student_Info*)p1)->grade - ((Student_Info*)p2)->grade;
}


void Tea_Manage_Sort(InfoManage* pg)
{
	assert(pg);

	cout << "1-��������  2-ѧ������  3-��������  4-�ɼ�����" << endl;
	int input = 0;
	cout << "��ѡ������ʽ��> ";
	cin >> input;
	switch (input)
	{
	case Sort_Name:
		qsort(pg->data, pg->size, sizeof(Student_Info), cmp_name);
		break;
	case Sort_Sid:
		qsort(pg->data, pg->size, sizeof(Student_Info), cmp_sid);
		break;
	case Sort_Age:
		qsort(pg->data, pg->size, sizeof(Student_Info), cmp_age);
		break;
	case Sort_Grade:
		qsort(pg->data, pg->size, sizeof(Student_Info), cmp_grade);
		break;
	}
	cout << "�������" << endl;
}

// ���ѧ����Ϣ
void Tea_Manage_Clear(InfoManage* pg)
{
	assert(pg);
	Init_Manage(pg);
}


// �˳�ϵͳ
void Tea_Manage_Exit(InfoManage* pg)
{
	assert(pg);
	free(pg->data);
	pg->size = pg->capacity = 0;
}


// ����ѧ����Ϣ
void Save_Stu_Info(InfoManage* pg)
{
	// ���ļ�
	FILE* pf = fopen("Stu_Info.txt", "wb");
	if (pf == NULL)
	{
		perror("Save_Stu_Info fopen");
		return;
	}
	// д���ݵ��ļ�
	int i = 0;
	for (i = 0; i < pg->size; i++)
	{
		fwrite(pg->data + i, sizeof(Student_Info), 1, pf);
	}

	// �ر��ļ�
	fclose(pf);
	pf = NULL;
}