#pragma once

// 学生信息管理系统

// 管理员
// 学生
// 密码
// 文件操作

#include<iostream>
#include<stdlib.h>
#include<assert.h>

using namespace std;

#define Name_Max 20
#define Sid_Max 10
#define Sex_Max 5
#define Max_Count 3


// 修改enum
enum Edit_Switch
{
	Edit_Name=1,
	Edit_Sid,
	Edit_Age,
	Edit_Grade,
	Edit_All
};

// 排序enum
enum Sort_Switch
{
	Sort_Name=1,
	Sort_Sid,
	Sort_Age,
	Sort_Grade
};

// 学生信息
typedef struct Student_Info
{
	char name[Name_Max];		// 姓名
	char sid[Sid_Max];		// 学号
	int age;			// 年龄
	char sex[Sex_Max];		// 性别
	float grade;		// 成绩
}Student_Info;

// 学生信息系统
typedef struct InfoManage
{
	Student_Info* data;
	int size;
	int capacity;
}InfoManage;


// 初始化系统
void Init_Manage(InfoManage* pg);


// 退出系统
void Tea_Manage_Exit(InfoManage* pg);

// 添加学生信息
void Tea_Manage_Add(InfoManage* pg);

// 删除学生信息
void Tea_Manage_Del(InfoManage* pg);


// 修改学生信息
void Tea_Manage_Edit(InfoManage* pg);

// 查询学生信息
void Tea_Manage_Inq(InfoManage* pg);


// 显示学生信息
void Tea_Manage_Show(InfoManage* pg);

// 排序学生信息
void Tea_Manage_Sort(InfoManage* pg);

// 清空学生信息
void Tea_Manage_Clear(InfoManage* pg);

// 保存学生信息
void Save_Stu_Info(InfoManage* pg);