// 数据结构.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

#define OK 1
#define NO 0
#define MAXSIZE 20
#define TURE 1
#define FALSE 0
#define ERROR 0

using namespace std;

//欧几里得算法
int gcd(int a,int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		gcd(b, a%b);
	}
}

//线性表
typedef int ElemType;
typedef int Status;

typedef struct lnode
{
	ElemType data[MAXSIZE];
	int length;
}sqlist;

Status visit(ElemType c)
{
	printf("%d", c);
	return OK;
}

Status InitEmpty(sqlist L)
{
	if (L.length == 0)
	{
		return TURE;
	}
	else
	{
		return ERROR;
	}
}

Status ClearList(sqlist *L)
{
	L->length = 0;
	return OK;
}

Status GetElem(sqlist L,int i,ElemType *e)
{
	if (L.length == 0 || i < 1||i>L.length)
	{
		return ERROR;
	}
	*e = L.data[i - 1];
	return OK;
}

Status ListInsert(sqlist *L,int i,ElemType e)
{
	int k;
	if (L->length == MAXSIZE)return ERROR;
	if (i < 1 || i > L->length + 1)return ERROR;
	if (i <= L->length)
	{
		for (k = L->length - 1; k >= i-1; k--)
		{
			L->data[k + 1] = L->data[k];
		}
	}
	L->data[i - 1] = e;
	L->length++;
	return OK;
}

int LocateElem(sqlist L, ElemType e)
{
	int i;
	if (L.length == 0)
	{
		return 0;
	}
	for (i = 0; i <= L.length; i++)
	{
		if (L.data[i] == e)
			break;
	}
	if (i >= L.length)
		return 0;
	return i + 1;
}

Status ListDelete(sqlist *L, int i, ElemType *e)
{
	int k;
	if (L->length == 0)return ERROR;
	if (i < 1 || i >= L->length) return ERROR;
	*e = L->data[i - 1];
	if (i < L->length)
	{
		for (k = i; k <= L->length; k++)
		{
			L->data[k - 1] = L->data[k];
		}
	}
	L->length--;
	return OK;
}

Status ListTraverse(sqlist L)
{
	for (int i = 0; i < L.length; i++)
	{
		visit(L.data[i]);
	}
	printf("\n");
	return OK;
}

int ListLength(sqlist L)
{
	return L.length;
}

void unionL(sqlist *La, sqlist Lb)
{
	int La_len, Lb_len, i;
	ElemType e;
	La_len = ListLength(*La);
	Lb_len = ListLength(Lb);
	for (i = 1; i <= Lb_len; i++)
	{
		GetElem(Lb, i, &e);
		if (!LocateElem(*La, e))
			ListInsert(La, ++La_len, e);
	}
}
//链表
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;

typedef struct Node *LinkList;

Status GetElemFromNode(LinkList L, int i,ElemType *e)
{
	int j;
	LinkList p;
	p = L->next;
	j = 1;
	while (p&&j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
	{
		return ERROR;
	}
	*e = p->data;
	return OK;
}

Status DelElemFromNode(LinkList *L, int i, ElemType *e)
{
	int j;
	LinkList p,q;
	p = *L;
	j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || j > i)
	{
		return ERROR;
	}
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}

Status InsertToNode(LinkList *L,int i,ElemType e)
{
	int j;
	LinkList p, s;
	p = *L;
	j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j < i) return ERROR;
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;

}

Status lengthToNode(LinkList L, int i, ElemType e)
{
	LinkList p;
	p = L->next;
	int j = 0;
	while (L->next)
	{
		j++;
	}

	return j;
}

//头插法
LinkList *CreateListHead(LinkList *L, int n)
{
	LinkList p;
	int i;
	srand(23);
	(*L)->next = NULL;
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
	return L;
}

LinkList *CreateListTail(LinkList *L, int n)
{
	LinkList p,r;
	int i;
	srand(23);
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		r->next = p;
		r = p;
	}
	r->next = NULL;
	return L;
}

int main()
{
	sqlist L;
	sqlist Lb;

	ElemType e;
	Status i;
	int j, k;

	i = ClearList(&L);
	printf("L.lenth = %d\n", L.length);
	for (j = 1; j <= 10; j++)
	{
		ListInsert(&L, j, j);
	}
	printf("L.data = ");
	ListTraverse(L);

	printf("L.lenth = %d\n", L.length);

	printf("L.Empty = %d\n", InitEmpty(L));

	i = ClearList(&Lb);
	
	for (j = 6; j <= 15; j++)
		i = ListInsert(&Lb, 1, j);
	unionL(&L, Lb);
	printf("\n");
	ListTraverse(L);
	return 0;
}

