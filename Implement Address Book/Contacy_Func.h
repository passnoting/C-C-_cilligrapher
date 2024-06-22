#pragma once

// Implement Address Book


#include<iostream>
#include<stdlib.h>
using namespace std;


#define Be_Max 3

enum Contact_Switch
{
	Contact_Exit,		// ͨѶ¼�˳�
	Contact_Add,		// ͨѶ¼���
	Contact_Del,		// ͨѶ¼ɾ��
	Contact_Edit,		// ͨѶ¼�޸�
	Contact_Inq,		// ͨѶ¼��ѯ
	Contact_Show,		// ͨѶ¼��ʾ
	Contact_Sort,		// ͨѶ¼����
	Contact_Clear		// ͨѶ¼���
};



// ͨѶ¼����
typedef struct Peo_Info
{
	char name[20];			// ����
	int age;				// ����
	char sex[5];			// �Ա�
	char phone[15];			// �绰
	char address[30];		// ��ַ
}Peo_Info;

// ͨѶ¼
typedef struct Contact
{
	Peo_Info* data;
	int size;
	int capacity;
}Contact;


// ��ʼ��ͨѶ¼
void Contact_Init(Contact& pon);

// �����ϵ����Ϣ
void Add_Peo_Info(Contact& pon);

// ɾ����ϵ����Ϣ
void Del_Peo_Info(Contact& pon);

// ��ϵ�޸�����Ϣ
void Edit_Peo_Info(Contact& pon);

// ��ѯ��ϵ����Ϣ
void Inq_Peo_Info(Contact& pon);

// ��ʾ��ϵ����Ϣ
void Show_Peo_Info(Contact& pon);

// ������ϵ����Ϣ
void Sort_Peo_Info(Contact& pon);

// ���ͨѶ¼����Ϣ
void Clear_Peo_Info(Contact& pon);


// ������ϵ����Ϣ
void Sava_Peo_Info(Contact& pon);

// ����ͨѶ¼
void Destroy_Contact(Contact& pon);