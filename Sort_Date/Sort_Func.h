#pragma once

// 排序数据
// 
// 冒泡排序
// 插入排序
// 选择排序
// 计数排序
// 
// 希尔排序
// 堆排序
// 快速排序
// 归并排序


#include<iostream>
using namespace std;

// 打印数据
void Print(int* a, int sz);

// 冒泡排序
void Bubble_Sort(int* a, int sz);

// 插入排序
void Insert_Sort(int* a, int sz);

// 选择排序
void Select_Sort(int* a, int sz);

// 计数排序
void Count_Sort(int* a, int sz);
