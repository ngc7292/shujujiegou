// 成绩管理.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

Status traverse_list(list &L)
{
	L.list_traverse();
	return OK;
}

Status insert_list(list &L)
{
	student stu;
	stu.input();
	int length = L.list_length();
	L.insert_student(length + 1, stu);
	cout << "insert " << stu.student_no << "    " << stu.name << "   " << stu.score << endl;
	return OK;
}

Status delete_list(list &L)
{
	cout << "input the student number you want to delete";
	int no;
	student stu;
	cin >> no;
	if (L.list_delete(no, stu))
	{
		cout << "have delete " << stu.name << endl;
		return OK;
	}
	return ERROR;
}

Status update_list(list &L)
{
	student stu;
	stu.input();
	int num;
	int length = L.list_length();
	cout << "input the number of 0 ~ " << length;
	cin >> num;
	L.update_student(num, stu);
	cout << "insert " << stu.student_no << "    " << stu.name << "   " << stu.score << endl;
	return ERROR;
}

Status get_elm_list(list &l)
{
	int num;
	student stu;
	cout << "input the number choose model" << endl;
	cout << "1. get student by no 2.get student by name";
	cin >> num;
	switch (num)
	{
	case 1:
	{
		string no;
		cin >> no;
		l.get_student_by_no(no,stu);
		break;
	}
	case 2:
	{
		string name;
		cin >> name;
		l.get_student_by_name(name, stu);
		break;
	}
	default:
		break;
	}
	cout << "the student score is " << stu.score << endl;
	cout << "the student no is " << stu.student_no << endl;
	cout << "the student name is " << stu.name << endl;
	return OK;
}



int main()
{
	int size = 100,real_length;
	int choose;

	student stu;
	list *l;

	l = (list *)malloc(sizeof(list));

	l->init(l, size);

	while (true)
	{
		cout << "please input the student count";
		cin >> real_length;
		real_length -= 1;
		if (real_length < size)
			break;
		else
			cout << "you input is so big to init" << endl;
	}

	for (int i = 0; i <= real_length; i++)
	{
		stu.input();
		l->insert_student(i, stu);
	}

	cout << "you have fininshed the init" << endl;
	cout << "1.traverse the list 2.insert student to the list" << endl;
	cout << "3.delete the student from the list 4.update student message in this list" << endl;
	cout << "5.get message from this list and input others is quit this system" << endl;
	cout << "please input number to choose function";
	cin >> choose;
	
	switch (choose)
	{
	case 1:
		traverse_list(*l);
		break;
	case 2:
		insert_list(*l);
		break;
	case 3:
		delete_list(*l);
		break;
	case 4:
		update_list(*l);
		break;
	case 5:
		get_elm_list(*l);
		break;
	default:
		break;
	}
    return 0;
}

