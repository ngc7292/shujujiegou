// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <malloc.h>
#include<iostream>
#include<string>

using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define MAXSIZE 100

typedef int Status;






// TODO: 在此处引用程序需要的其他头文件


/*
学生类，包括学号，姓名以及成绩
*/
class student
{
public:
	string student_no;//学生序号
	string name;//姓名
	float score;//成绩

	void input();
};



/*
list作为线性表，保存学生的各种信息
并提供各种查询，获取，更新等接口
*/
class list
{
private:
	student stu[MAXSIZE];
	int length;
	int max_size;

public:
	void init(list *L, int ms);
	void destory_list(list L) { free(&L); }
	void clear_list() { length = 0; }
	bool list_empty() {return length == 0; }
	bool list_full() { return length == MAXSIZE; }
	int list_length() { return length; }
	Status list_traverse();//遍历整个线性表，并输出
	Status get_student_by_no(string no, student &e);//通过no获取student
	Status get_student_by_name(string name, student &e);//通过name获取student
	Status list_delete(int no,student &data);//删除某个student
	Status insert_student(int no, student &data);//插入student信息
	Status update_student(int no, student &data);//更新student的状态
};