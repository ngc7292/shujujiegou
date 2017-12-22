// 线性表插入.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

using namespace std;

#define OK 1
#define ERROR 0
#define TURE 1
#define FALSE 0

#define MAXSIZE 20

typedef int Status;

typedef struct
{
	int length;
	int item[MAXSIZE];
}List;

void init_list(List &L)
{
	L.length = 0;
}

Status empty_list(List &L)
{
	if (L.length == 0)
		return OK;
	else
		return ERROR;
}

int length_list(List &L)
{
	return L.length;
}

Status insert_list(List &L, int e ,int pos)
{
	if (L.length > MAXSIZE)
	{
		return ERROR;
	}
	if (pos <= 0 || pos > MAXSIZE)
	{
		return ERROR;
	}
	for (int i = pos-1 ; i <= L.length - 1; i++)
	{
		L.item[i + 1] = L.item[i];
	}
	L.item[pos] = e;
	L.length++;
	return OK;
}

Status traverse_list(List &L)
{
	for (int i = 0; i < L.length; i++)
	{
		cout << L.item[i] << " ";
	}
	cout << endl;
	return OK;
}

Status get_elm(List &L , int pos , int *data)
{
	if (empty_list(L))
	{
		return FALSE;
	}
	if (pos <= 0 || pos > L.length)
	{
		return FALSE;
	}
	*data = L.item[pos - 1];
	return OK;
}

Status find(List &L, int data)
{
	if (empty_list(L))
		return ERROR;
	for (int i = 0; i <= L.length - 1; i++)
	{
		if (L.item[i] == data)
		{
			return i;
			break;
		}
	}
	return ERROR;
}


int main()
{
    return 0;
}

