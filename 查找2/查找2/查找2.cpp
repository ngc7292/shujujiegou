// 查找2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;//状态码

int F[100];//斐波那契数列

int aeq_search(int *a, int n, int key)
{
	int i;
	for (i = 0; i <= n; i++)
	{
		if (a[i] == key)
			return i;
	}
	return ERROR;
}

int seq2_search(int *a, int n, int key)
{
	int i;
	a[0] = key;
	i = n;
	while (a[i]!=key)
	{
		i--;  
	}
	return i;
}

int binary_search(int *a, int n, int key)
{
	int low, high, mid;
	low = 1;
	high = n;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key < a[mid])
		{
			high = mid - 1;
		}
		else if (key > a[mid])
		{
			low = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return ERROR;
}

int insert_sort(int *a,int n,int key)
{
	int low, high, mid;
	low = 1;
	high = n;

	while (low <= high)
	{
		mid = low + (high - low)*((key - a[low]) / a[high] - a[low]);
		if (key < a[mid])
		{
			high = mid - 1;
		}
		else if (key > a[mid])
		{
			low = mid + 1;
		}
		else
		{
			return mid;
		}

	}
	return 0;
}

int fibonacci_search(int *a,int n,int key)
{
	int low, high, mid;
	int i, k = 0;

	low = 0;
	high = n;
	while (n > F[k]-1)
	{
		k++;
	}
	for (i = n; i < F[k] - 1; i++)
		a[i] = a[n];

	while (low <= high)
	{
		mid = low + F[k - 1] - 1;
		if (key < a[mid])
		{
			high = mid - 1;
			k = k - 1;
		}
		else if(key > a[mid])
		{
			low = mid + 1;
			k = k - 2;
		}
		else
		{
			if (mid <= n)
				return mid;
			else
				return FALSE;
		}
	}
	return ERROR;
}

/*
以上是对线性结构进行查询
*/

//二叉树排序
typedef struct bi_node
{
	int data;
	bi_node *lchild, *rchild;
}bi_node,*bi_Tree;

//递归寻找二叉树
//f指向T的双亲，初始化为NULL
//若查找成功，p指向元素节点，并返回其指针
Status BFS_search(bi_Tree T, int key, bi_Tree f, bi_Tree *p)
{
	if (!T)
	{
		*p = f;
		return ERROR;
	}
	else if (key == T->data)
	{
		*p = T;
		return OK;
	}
	else if (key < T->data)
		return BFS_search(T->lchild, key, T, p);
	else
		return BFS_search(T->rchild, key, T, p);
}

//二叉树的插入操作，当二叉树不存在关键字等于一的数据元素的时候，插入key
int insert_BFS(bi_Tree *T, int key)
{
	bi_Tree p, s;
	if (!BFS_search(*T, key, NULL, &p))
	{
		s = (bi_Tree)malloc(sizeof(bi_node));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if (!p)
			*T = s;
		else if (key < p->data)
			p->lchild = s;
		else
			p->rchild = s;
		return TRUE;
	}
	else
		return FALSE;
}

Status delete_BFS(bi_Tree *p)
{
	bi_Tree q, s;
	if ((*p)->rchild == NULL)
	{
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	else if ((*p)->lchild == NULL)
	{
		q = *p;
		*p = (*p)->rchild;
		free(q);
	}
	else
	{
		q = *p;
		s = (*p)->lchild;
		while (s->rchild)
		{
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data;
		if (q != *p)
			q->rchild = s->lchild;
		else
			q->lchild = s->lchild;
		free(s);
	}
	return TRUE;
}

Status delete_BST(bi_Tree *T, int key)
{
	if (!*T)
		return FALSE;
	else
	{
		if (key == (*T)->data)
			return delete_BFS(T);
		else if (key < (*T)->data)
			return delete_BST(&(*T)->lchild, key);
		else
			return delete_BST(&(*T)->rchild, key);
	}
}

int main()
{
    return 0;
}

