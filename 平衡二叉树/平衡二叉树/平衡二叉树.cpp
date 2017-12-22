// 平衡二叉树.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

using namespace std;

#define OK 1
#define ERROR 0
#define FALSE 0
#define TRUE 1
#define MAXSIZE 100

typedef int Status;

//二叉树链式表示
typedef struct bi_node
{
	int data;
	int bf;//节点的平衡因子
	struct bi_node *lchild, *rchild;
}bi_node , *bi_tree;

//右旋
void right_route(bi_tree *p)
{
	bi_tree L;
	L = (*p)->lchild;
	(*p)->lchild = L->rchild;
	L->rchild = (*p);
	*p = L;
}

//左旋
void left_route(bi_tree *p)
{
	bi_tree R;
	R = (*p)->rchild;
	(*p)->rchild = R->lchild;
	R->lchild = (*p);
	*p = R;
}

#define LH +1
#define EH 0
#define RH -1

void left_balance(bi_tree *T)
{
	bi_tree L, Lr;
	L = (*T)->lchild;
	switch (L->bf)
	{
	case LH:
		(*T)->bf = L->bf = EH;
		right_route(T);
		break;
	case RH:
		Lr = L->rchild;
		switch (Lr->bf)
		{
		case LH:
			(*T)->bf = RH;
			L->bf = EH;
			break;
		case EH:
			(*T)->bf = L->bf = EH;
			break;
		case RH :
			(*T)->bf = EH;
			L->bf = LH;
			break;
		}
		Lr->bf = EH;
		left_route(&(*T)->lchild);
		right_route(T);
	}
}

void right_balance(bi_tree *T)
{
	bi_tree R, Rl;
	R = (*T)->rchild;
	switch (R->bf)
	{
	case RH:
		(*T)->bf = R->bf = EH;
		left_route(T);
		break;
	case LH:
		Rl = R->lchild;
		switch (Rl->bf)
		{
		case RH:
			(*T)->bf = LH;
			R->bf = EH;
			break;
		case EH:
			(*T)->bf = R->bf = EH;
			break;
		case LH:
			(*T)->bf = EH;
			R->bf = RH;
			break;
		}
		Rl->bf = EH;
		right_route(&(*T)->rchild);
		left_route(T);
	}
}

//插入元素e若失去平衡，则做平衡旋转处理
Status insert_avl(bi_tree *T, int e, Status *taller)
{
	if (!*T)
	{
		*T = (bi_tree)malloc(sizeof(bi_node));
		(*T)->data = e;
		(*T)->lchild = NULL;
		(*T)->bf = EH;
		*taller = TRUE;
	}
	else
	{
		if (e == (*T)->data)
		{
			*taller = FALSE;
			return FALSE;
		}
		if (e < (*T)->data)
		{
			if (!insert_avl(&(*T)->lchild, e, taller))
				return FALSE;
			if (*taller)
			{
				switch ((*T)->bf)
				{
				case LH:
					left_balance(T);
					*taller = FALSE;
					break;
				case EH:
					(*T)->bf = LH;
					*taller = TRUE;
					break;
				case RH:
					(*T)->bf = EH;
					*taller = FALSE;
					break;
				}
			}
		}
		else
		{
			if (!insert_avl(&(*T)->rchild, e, taller))
				return FALSE;
			if (*taller)
			{
				switch((*T)->bf)
				{
				case LH:
					(*T)->bf = EH;
					*taller = FALSE;
					break;
				case EH:
					(*T)->bf = RH;
					*taller = TRUE;
					break;
				case RH:
					right_balance(T);
					*taller = TRUE;
					break;
				}
			}
		}
	}
	return TRUE;
}
int main()
{
	int i;
	int a[10] = { 3,2,1,4,5,6,7,8,9,10 };
	bi_tree T = NULL;
	Status taller;
	for (i = 0; i < 10; i++)
	{
		insert_avl(&T, a[i], &taller);
	}
	return 0;
}