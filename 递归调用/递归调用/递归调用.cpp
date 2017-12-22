// 递归调用.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;


int fac(int n)
{

	if (n == 1)
		return 1;
	else
	{
		return n*fac(n - 1);
	}
}

int hanno(int n)
{
	int cnt;
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return 2 * hanno(n - 1) + 1;
	}
}

void move(int n, char A, char B, char C)
{
	if (n == 1)
	{
		cout << A << "->" << C << endl;
	}
	else
	{
		move(n - 1, A, C, B);
		cout << A << "->" << C << endl;
		move(n - 1, B, A, C);
	}
}
int main()
{
	int a = hanno(5);
	move(3, 'a', 'b', 'c');
	cout << a << endl;
    return 0;
}

