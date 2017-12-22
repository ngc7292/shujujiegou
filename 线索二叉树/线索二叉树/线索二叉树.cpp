// 线索二叉树.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<math.h>
#include<time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100//存储空间初始分配量

typedef int Status;//状态码
typedef char TElemType;

typedef enum {Link,Thread} PointerTag;//指向左右两孩子的指针


typedef struct BiThrNode //线索二叉树的存储结构
{
	TElemType data;//数据块
	struct BiThrNode *lchild, *rchild;//指向左右孩子的指针
	PointerTag LTag, RTag;
}BiThrNode,*BiThrTree;

TElemType Nil = '#';

Status visit(TElemType e)
{
	printf("%c", e);
	return OK;
}

//前序输入二叉树线索树中结点的值，构造二叉树T
Status CreateBiThrTree(BiThrTree *T)
{
	TElemType h;
	scanf("%c", &h);
	if (h == Nil)
		*T = NULL;
	else
	{
		*T = (BiThrTree)malloc(sizeof(BiThrNode));
		if (!*T)
			exit(ERROR);
		(*T)->data = h;//生成根节点
		CreateBiThrTree(&(*T)->lchild);//构造左子树
		if ((*T)->lchild)
			(*T)->LTag = Link;

		CreateBiThrTree(&(*T)->rchild);
		if ((*T)->rchild)
			(*T)->RTag = Link;
	}
	return OK;
}

BiThrTree pre;//指向刚刚访问的结点

			  
//中序遍历
void InThreading(BiThrTree p)
{
	if (p)
	{
		InThreading(p->lchild);//遍历左子树
		if (!p->lchild)
		{
			p->LTag = Thread;
			p->rchild = pre;
		}
		if (!p->rchild)
		{
			pre->RTag = Thread;
			pre->rchild = p;
		}
		pre = p;
		InThreading(p->rchild);
	}
}
//中序遍历二叉树T并将其中序线索化，thrt指向头结点
Status InOrderThreading(BiThrTree *Thrt, BiThrTree T)
{
	*Thrt = (BiThrTree)malloc(sizeof(BiThrNode));
	if (!*Thrt)
		exit(ERROR);
	(*Thrt)->LTag = Link;//建立头结点
	(*Thrt)->RTag = Thread;
	(*Thrt)->rchild = (*Thrt);//右指针回指
	if (!T)
		(*Thrt)->lchild = *Thrt;
	else
	{
		(*Thrt)->lchild = T;
		pre = (*Thrt);
		InThreading(T);//中序遍历进行中序线索化
		pre->rchild = *Thrt;
		pre->RTag = Thread;
		(*Thrt)->rchild = pre;
	}
	return OK;
}

//中序遍历二叉树的非递归算法
//以循环来代替递归
Status InOrderTraverse_Thr(BiThrTree T)
{
	BiThrTree p;
	p = T->lchild;//设置p为根节点
	while (p != T)
	{
		while (p->LTag == Link)
		{
			p = p->lchild;
		}
		if (!visit(p->data))//若左结点是空
		{
			return ERROR;
		}
		while (p->RTag == Thread && p->rchild !=T)
		{
			p = p->rchild;
			visit(p->data);//访问后继结点
		}
		p = p->rchild;
	}
	return OK;
}

int main() 
{
	BiThrTree H, T;
	printf("plese input a two cha shu and the example is'ABDH##I##EJ###CF##G##'\n");
	CreateBiThrTree(&T);
	InOrderThreading(&H, T);
	printf("output the tree by order");
	InOrderTraverse_Thr(H);
	printf("\n");
    return 0;
}

