// stdafx.cpp : 只包括标准包含文件的源文件
// $safeprojectname$.pch 将作为预编译标头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"

// TODO: 在 STDAFX.H 中引用任何所需的附加头文件，
//而不是在此文件中引用

void student::input()
{
	cout << "please input the number of student";
	cin >> student_no;
	cout << "please input the name of student";
	cin >> name;
	cout << "please input the score of the student";
	cin >> score;
}


/*
初始化函数
L为list对象，ms为设定的最大值，不能超过100
*/
void list::init(list *L, int ms)
{
	L->length = 0;
	L->max_size = ms;
}

/*
遍历整个线性表并输出
*/
Status list::list_traverse()
{
	if (list_empty())
	{
		return ERROR;
	}
	int i = 0;
	cout << "student number" << "          " << "student name" << "         " << "student score" << endl;
	for (i = 0; i <= length; i++)
	{
		cout << stu[i].student_no << "          " << stu[i].name << "         " <<stu[i].score<<endl;
	}
	return OK;
}

/*
获取特定student的no值
并且返回在线性表的位置
no为student的student_no，e为接收student
*/
Status list::get_student_by_no(string no,student &e)
{
	if (list_empty())
	{
		return ERROR;
	}
	int i;
	for (i = 0; i <= length; i++)
	{
		if (no == stu[i].student_no)
		{
			e = stu[i];
			return OK;
		}
	}
	return FALSE;
}

/*
获取特定student的no值
并且返回在线性表的位置
name为student的name，e为接收student no的int类型值
*/
Status list::get_student_by_name(string name, student &e)
{
	if (list_empty())
	{
		return ERROR;
	}
	int i;
	for (i = 0; i <= length; i++)
	{
		if (name == stu[i].name)
		{
			e = stu[i];
			return OK;
		}
	}
	return FALSE;
}

/*
通过给定的no删除相应的student，并且返回其值
no为通过上面函数得到的student的no值
data为返回student的指针
*/
Status list::list_delete(int no, student &data)
{
	if (list_empty() || no<0 || no>max_size)
	{
		return ERROR;
	}
	else
	{
		data = stu[no];
		int i = no+1;
		for (i; i <= length; i++)
		{
			stu[i - 1] = stu[i];
		}
		free(&stu[length]);
		length -= 1;
		return OK;
	}
}

/*
插入student信息，并且返回
no为插入位置信息，
data为student的指针
*/
Status list::insert_student(int no, student &data)
{
	if (no > length || no < 0||no > max_size)
		return ERROR;
	else
	{
		length += 1;
		for (int i = length; i > no; i--)
		{
			stu[i] = stu[i - 1];
		}
		stu[no].name = data.name;
		stu[no].student_no = data.student_no;
		stu[no].score = data.score;
		return OK;
	}
}


/*
更新student信息，
no为更新位置信息，
data为替换后的student
*/
Status list::update_student(int no, student &data)
{
	if (list_empty() || no >= length || no < 0 || no > max_size)
	{
		return ERROR;
	}
	else
	{
		stu[no] = data;
		return OK;
	}
}