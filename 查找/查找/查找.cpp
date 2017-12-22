// 查找.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

using namespace std;

int A[5] = { 30,20,50,40,25 };

void out_put()
{
	int i;
	for (i = 0; i < sizeof(A) / sizeof(A[0]); i++)
	{
		cout << A[i] << endl;
	}
	cout << endl;
}

void insert_sort(int Array[],int length)
{
	int i, j;
	int tmp;
	for (i = 0; i < length; i++)
	{
		tmp = Array[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (tmp < Array[j])
			{
				Array[j + 1] = Array[j];
			}
			else
			{
				break;
			}
		}
		Array[j + 1] = tmp;
		out_put();
	}
}

void select_sort(int Array[], int length)
{
	int i, j, min;
	int tmp;
	for (i = 0; i < length - 1; i++)
	{
		min = i;
		for (j = i + 1; j < length; j++)
		{
			if (Array[j] < Array[min])
			{
				min = j;
			}
		}
		if(min != i)
		{
			tmp = Array[i];
			Array[i] = Array[min];
			Array[min] = tmp;
		}
		out_put();
	}
}

int main()
{
	insert_sort(A, 5);
	//select_sort(A,5);
    return 0;
}

