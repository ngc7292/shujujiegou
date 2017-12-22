// 树.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h>
#include<io.h>
#include<math.h>
#include<time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100
#define MAX_TREE_SIZE 100

typedef int Status;
typedef int TElemType;
typedef TElemType SqBiTree[MAX_TREE_SIZE];

typedef struct
{
	int level,order;
}Position;

TElemType Nil = 0;

Status visit(TElemType c)
{
	printf("%d", c);
	return OK;
}

Status InitBiTree(SqBiTree T)
{
	int i;
	for (i = 0; i < MAX_TREE_SIZE; i++)
	{
		T[i] = Nil;
	}
	return OK;
}

Status CreateBiTree(SqBiTree T)
{
	int i = 0;
	printf("请按层序输入结点的值(整型)，0表示空结点，输999结束。结点数≤%d:\n", MAX_TREE_SIZE);
	while (i<10)
	{
		T[i] = i + 1;
		if (i != 0 && T[(i + 1) / 2 - 1] == Nil&&T[i] != Nil)
		{
			printf("出现无双亲的非根结点%d\n", T[i]);
			exit(ERROR);
		}
		i++;
	}
	while (i<MAX_TREE_SIZE)
	{
		T[i] = Nil;
		i++;
	}
	return OK;
}

#define ClearBiTree InitBiTree

Status BiTreeEmpty(SqBiTree T)
{
	if (T[0] == Nil)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

Status BiTreeDepth(SqBiTree T)
{
	int i, j = -1;
	for (i = MAX_TREE_SIZE - 1; i >= 0; i--)
	{
		if (T[i] != Nil)
		{
			break;
		}
	}
	i++;
	do
		j++;
	while (i >= pow(2, j));
	return j;
}

Status Root(SqBiTree T,TElemType *e)
{
	if (BiTreeEmpty(T))
	{
		return ERROR;
	}
	else
	{
		*e = T[0];
		return OK;
	}
}

TElemType Value(SqBiTree T, Position e)
{
	return T[(int)powl(2, e.level - 1) + e.order - 2];
}

Status Assign(SqBiTree T, Position e, TElemType value)
{
	int i = (int)powl(2, e.level - 1) + e.order - 2;
	if (value != Nil && (T[i * 2 + 1]!= Nil || T[i * 2 + 2] != Nil))
	{
		return ERROR;
	}
	else if(value == Nil && (T[i * 2 + 1] != Nil || T[i * 2 + 2] != Nil))
	{
		return ERROR;
	}
	T[i] = value;
	return OK;
}
//返回双亲
TElemType Parent(SqBiTree T, TElemType e)
{
	int i;
	if (T[0] = Nil)
		return Nil;
	for(i=1;i<=MAX_TREE_SIZE-1;i++)
		if (T[i] == e)
		{
			return T[(i + 1) / 2 - 1];
		}
	return Nil;
}

//返回左右孩子结点
TElemType LeftChild(SqBiTree T, TElemType e)
{
	int i = 0;
	if (T[0] == Nil)
	{
		return Nil;
	}
	for (i = 0; i <= MAX_TREE_SIZE - 1; i++)
	{
		if (T[i] == e)
			return T[i * 2 + 1];
	}
	return Nil;
}

TElemType RightChild(SqBiTree T, TElemType e)
{
	int i;
	if (T[i] == Nil)
		return Nil;
	for (i = 0; i <= MAX_TREE_SIZE - 1; i++)
	{
		if (T[i] == e)
		{
			return T[i * 2 + 2];
		}
	}
	return Nil;
}

TElemType LeftSibling(SqBiTree T, TElemType e)
{
	int i;
	if (T[0] = Nil)
	{
		return Nil;
	}
	for (i = 1; i <= MAX_TREE_SIZE - 1; i++)
	{
		if (T[i] == e&&i % 2 == 0)
		{
			return T[i - 1];
		}
	}
	return Nil;
}

TElemType RightSibling(SqBiTree T, TElemType e)
{
	int i;
	if (T[0] == Nil)
		return Nil;
	for (i = 1; i <= MAX_TREE_SIZE - 1; i++)
	{
		if (T[i] == e&&i % 2)
			return T[i + 1];
	}
	return Nil;
}

void PreTraverse(SqBiTree T, int e)
{
	visit(T[e]);
	if (T[2 * e + 1] != Nil)
		PreTraverse(T, 2 * e + 1);
	if (T[2 * e + 2] != Nil)
		PreTraverse(T, 2 * e + 2);
}

Status PreOrderTraverse(SqBiTree T)
{
	if (!BiTreeEmpty(T))
		PreTraverse(T, 0);
	printf("\n");
	return OK;
}

void InTraverse(SqBiTree T, int e)
{
	if (T[2 * e + 1] != Nil)
		InTraverse(T, 2 * e + 1);
	visit(T[e]);
	if (T[2 * e + 2] != Nil)
		InTraverse(T, 2 * e + 2);
}

Status InorderTraverse(SqBiTree T)
{
	if (!BiTreeEmpty(T))
	{
		InTraverse(T, 0);
	}
	printf("\n");
	return OK;
}

void PostTraverse(SqBiTree T, int e)
{
	if (T[2 * e + 1] != Nil)
		PostTraverse(T, 2 * e + 1);
	if (T[2 * e + 2] != Nil)
		PostTraverse(T, 2 * e + 2);
	visit(T[e]);
}

Status PostOrderTraverse(SqBiTree T)
{
	if (!BiTreeEmpty(T))
		PostTraverse(T, 0);
	printf("\n");
	return OK;
}

//层序遍历二叉树
void LevelOrderTraverse(SqBiTree T)
{
	int i = MAX_TREE_SIZE - 1, j;
	while (T[i] == Nil)
	{
		i--;
	}
	for (j = 0; j <= i; j--)
	{
		if (T[i] != Nil)
			visit(T[j]);
	}
	printf("\n");
}

//逐层，按本层序号输出二叉树
void Print(SqBiTree T)
{
	int j, k;
	Position p;
	TElemType e;
	for (j = 1; j <= BiTreeDepth(T); j++)
	{
		printf("NO.%d:", j);
		for (k = 1; k <= powl(2, j - 1); k++)
		{
			p.level = j;
			p.order = k;
			e = Value(T, e);
			if (e != Nil)
				printf("%d:%d", k, e);
		}
		printf("\n");
	}
}








int main()
{
    return 0;
}

