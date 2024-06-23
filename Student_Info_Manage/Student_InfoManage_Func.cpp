#define _CRT_SECURE_NO_WARNINGS

// 学生信息管理系统

// 管理员
// 学生
// 密码
// 文件操作

#include "Student_InfoManage_Func.h"

// 检查容量
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

// 将数据从文件中拿出来
void Stu_Info_Acq(InfoManage* pg)
{
	// 打开文件
	FILE* pf = fopen("Stu_Info.txt", "rb");
	if (pf == NULL)
	{
		perror("Stu_Info_Acq fopen");
		return;
	}
	// 读取文件

	Student_Info tmp = { 0 };

	while (fread(&tmp, sizeof(Student_Info), 1, pf))
	{
		// 检查容量
		CheckCapacity(pg);

		pg->data[pg->size] = tmp;
		pg->size++;

	}

	// 关闭文件、
	fclose(pf);
	pf = NULL;
}

// 初始化系统
void Init_Manage(InfoManage* pg)
{
	pg->data = (Student_Info*)malloc(sizeof(Student_Info) * Max_Count);
	pg->capacity = 3;
	pg->size = 0;

	Stu_Info_Acq(pg);
}




// 添加学生信息
void Tea_Manage_Add(InfoManage* pg)
{
	assert(pg);
	CheckCapacity(pg);

	cout << "请输入学生姓名：> ";
	cin >> pg->data[pg->size].name;
	cout << "请输入学生学号：> ";
	cin >> pg->data[pg->size].sid;
	cout << "请输入学生年龄：> ";
	cin >> pg->data[pg->size].age;
	cout << "请输入学生性别：> ";
	cin >> pg->data[pg->size].sex;
	cout << "请输入学生成绩：> ";
	cin >> pg->data[pg->size].grade;

	pg->size++;
	cout << "学生信息添加成功" << endl;
}

// 找某一学生是否存在
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

// 删除学生信息
void Tea_Manage_Del(InfoManage* pg)
{
	assert(pg);

	char sid[Sid_Max] = { 0 };
	cout << "请输入要删除学生的学号：> ";
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
		cout << "学生信息删除成功" << endl;
	}
	else
	{
		cout << "此学生不存在" << endl;
	}
}


// 修改学生信息
// 修改全部信息
void Edit_Stu_All(InfoManage* pg, int i)
{
	cout << "请输入修改后的学生姓名：> ";
	cin >> pg->data[i].name;
	cout << "请输入修改后的学生学号：> ";
	cin >> pg->data[i].sid;
	cout << "请输入修改后的学生年龄：> ";
	cin >> pg->data[i].age;
	cout << "请输入修改后的学生性别：> ";
	cin >> pg->data[i].sex;
	cout << "请输入修改后的学生成绩：> ";
	cin >> pg->data[i].grade;

}

void Tea_Manage_Edit(InfoManage* pg)
{
	assert(pg);

	char sid[Sid_Max] = { 0 };
	cout << "请输入要修改学生的学号：> ";
	cin >> sid;
	int i = Find_Stu(pg, sid);
	if (i != -1)
	{
		cout << "1-修改姓名  2-修改学号  3-修改年龄  4-修改成绩  5-全部修改" << endl;
		cout << "请输入您的选择：> ";
		int put = 0;
		cin >> put;
		switch (put)
		{
		case Edit_Name:
			cout << "请输入修改后的姓名：> ";
			cin >> pg->data[i].name;
			break;
		case Edit_Sid:
			cout << "请输入修改后的学号：> ";
			cin >> pg->data[i].sid;
			break;
		case Edit_Age:
			cout << "请输入修改后的年龄：> ";
			cin >> pg->data[i].age;
			break;
		case Edit_Grade:
			cout << "请输入修改后的成绩：> ";
			cin >> pg->data[i].grade;
			break;
		case Edit_All:
			Edit_Stu_All(pg, i);
			break;
		}
		cout << "学生信息修改成功" << endl;
	}
	else
	{
		cout << "此学生不存在" << endl;
	}
}


// 查询学生信息
void Tea_Manage_Inq(InfoManage* pg)
{
	char sid[Sid_Max] = { 0 };
	cout << "请输入要查询学生的学号：> ";
	cin >> sid;
	int i = Find_Stu(pg, sid);
	if (i != -1)
	{
		printf("%-20s %-10s %-10s %-10s %-10s\n", "姓名", "学号", "年龄", "性别", "成绩");
		printf("%-20s %-10s %-10d %-10s %-10.2lf\n", pg->data[i].name,
			pg->data[i].sid, pg->data[i].age, pg->data[i].sex, pg->data[i].grade);
	}
	else
	{
		cout << "此学生不存在" << endl;
	}

}


// 显示学生信息
void Tea_Manage_Show(InfoManage* pg)
{
	assert(pg);
	int i = 0;
	printf("%-20s %-10s %-10s %-10s %-10s\n", "姓名", "学号", "年龄", "性别", "成绩");
	for (i = 0; i < pg->size; i++)
	{
		printf("%-20s %-10s %-10d %-10s %-10.2lf\n", pg->data[i].name,
			pg->data[i].sid, pg->data[i].age, pg->data[i].sex, pg->data[i].grade);
	}
}

// 排序学生信息

// 排序姓名
int cmp_name(const void* p1, const void* p2)
{
	return strcmp(((Student_Info*)p1)->name, ((Student_Info*)p2)->name);
}
// 排序学号
int cmp_sid(const void* p1, const void* p2)
{
	return strcmp(((Student_Info*)p1)->sid, ((Student_Info*)p2)->sid);
}
// 排序年龄
int cmp_age(const void* p1, const void* p2)
{
	return ((Student_Info*)p1)->age - ((Student_Info*)p2)->age;
}
// 排序成绩
int cmp_grade(const void* p1, const void* p2)
{
	return (int)((Student_Info*)p1)->grade - ((Student_Info*)p2)->grade;
}


void Tea_Manage_Sort(InfoManage* pg)
{
	assert(pg);

	cout << "1-姓名排序  2-学号排序  3-年龄排序  4-成绩排序" << endl;
	int input = 0;
	cout << "请选择排序方式：> ";
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
	cout << "排序完成" << endl;
}

// 清空学生信息
void Tea_Manage_Clear(InfoManage* pg)
{
	assert(pg);
	Init_Manage(pg);
}


// 退出系统
void Tea_Manage_Exit(InfoManage* pg)
{
	assert(pg);
	free(pg->data);
	pg->size = pg->capacity = 0;
}


// 保存学生信息
void Save_Stu_Info(InfoManage* pg)
{
	// 打开文件
	FILE* pf = fopen("Stu_Info.txt", "wb");
	if (pf == NULL)
	{
		perror("Save_Stu_Info fopen");
		return;
	}
	// 写数据到文件
	int i = 0;
	for (i = 0; i < pg->size; i++)
	{
		fwrite(pg->data + i, sizeof(Student_Info), 1, pf);
	}

	// 关闭文件
	fclose(pf);
	pf = NULL;
}