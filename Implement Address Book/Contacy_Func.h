#pragma once

// Implement Address Book


#include<iostream>
#include<stdlib.h>
using namespace std;


#define Be_Max 3

enum Contact_Switch
{
	Contact_Exit,		// 通讯录退出
	Contact_Add,		// 通讯录添加
	Contact_Del,		// 通讯录删除
	Contact_Edit,		// 通讯录修改
	Contact_Inq,		// 通讯录查询
	Contact_Show,		// 通讯录显示
	Contact_Sort,		// 通讯录排序
	Contact_Clear		// 通讯录清空
};



// 通讯录对象
typedef struct Peo_Info
{
	char name[20];			// 姓名
	int age;				// 年龄
	char sex[5];			// 性别
	char phone[15];			// 电话
	char address[30];		// 地址
}Peo_Info;

// 通讯录
typedef struct Contact
{
	Peo_Info* data;
	int size;
	int capacity;
}Contact;


// 初始化通讯录
void Contact_Init(Contact& pon);

// 添加联系人信息
void Add_Peo_Info(Contact& pon);

// 删除联系人信息
void Del_Peo_Info(Contact& pon);

// 联系修改人信息
void Edit_Peo_Info(Contact& pon);

// 查询联系人信息
void Inq_Peo_Info(Contact& pon);

// 显示联系人信息
void Show_Peo_Info(Contact& pon);

// 排序联系人信息
void Sort_Peo_Info(Contact& pon);

// 清空通讯录中信息
void Clear_Peo_Info(Contact& pon);


// 保存联系人信息
void Sava_Peo_Info(Contact& pon);

// 销毁通讯录
void Destroy_Contact(Contact& pon);