#pragma once

// ѧ����Ϣ����ϵͳ

// ����Ա
// ѧ��
// ����
// �ļ�����

#include<iostream>
#include<stdlib.h>
#include<assert.h>

using namespace std;

#define Name_Max 20
#define Sid_Max 10
#define Sex_Max 5
#define Max_Count 3


// �޸�enum
enum Edit_Switch
{
	Edit_Name=1,
	Edit_Sid,
	Edit_Age,
	Edit_Grade,
	Edit_All
};

// ����enum
enum Sort_Switch
{
	Sort_Name=1,
	Sort_Sid,
	Sort_Age,
	Sort_Grade
};

// ѧ����Ϣ
typedef struct Student_Info
{
	char name[Name_Max];		// ����
	char sid[Sid_Max];		// ѧ��
	int age;			// ����
	char sex[Sex_Max];		// �Ա�
	float grade;		// �ɼ�
}Student_Info;

// ѧ����Ϣϵͳ
typedef struct InfoManage
{
	Student_Info* data;
	int size;
	int capacity;
}InfoManage;


// ��ʼ��ϵͳ
void Init_Manage(InfoManage* pg);


// �˳�ϵͳ
void Tea_Manage_Exit(InfoManage* pg);

// ���ѧ����Ϣ
void Tea_Manage_Add(InfoManage* pg);

// ɾ��ѧ����Ϣ
void Tea_Manage_Del(InfoManage* pg);


// �޸�ѧ����Ϣ
void Tea_Manage_Edit(InfoManage* pg);

// ��ѯѧ����Ϣ
void Tea_Manage_Inq(InfoManage* pg);


// ��ʾѧ����Ϣ
void Tea_Manage_Show(InfoManage* pg);

// ����ѧ����Ϣ
void Tea_Manage_Sort(InfoManage* pg);

// ���ѧ����Ϣ
void Tea_Manage_Clear(InfoManage* pg);

// ����ѧ����Ϣ
void Save_Stu_Info(InfoManage* pg);