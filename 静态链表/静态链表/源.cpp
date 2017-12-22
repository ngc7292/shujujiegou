#include "stdafx.h"
#include<stdio.h>

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define FALSE 0
#define TRUE 1

typedef int SElemType;
typedef int Status;

typedef struct
{
	SElemType data[MAXSIZE];
	int top;
}SqStack;

Status visit(SElemType c)
{
	printf_s("%d", c);
	return OK;
}

Status InitStack(SqStack *S)
{
	S->top = -1;
	return OK;
}

Status ClearStack(SqStack *S)
{
	S->top = -1;
	return 0;
}

Status StackEmpty(SqStack S)
{
	if (S.top == -1)
	{
		return TRUE;
	}
	else
		return FALSE;
}

int StackLength(SqStack S)
{
	return S.top + 1;
}

Status GetTop(SqStack S, SElemType *e)
{
	if (S.top == -1)
		return ERROR;
	else
		*e = S.data[S.top];
	return OK;
}

Status Push(SqStack *S, SElemType e)
{
	if (S->top == MAXSIZE - 1)
		return ERROR;
	S->top++;
	S->data[S->top] = e;
	return OK;
}

Status Pop(SqStack *S, SElemType *e)
{
	if (S->top == -1)
		return ERROR;
	*e = S->data[S->top];
	S->top--;
	return OK;
}

Status StackTraverse(SqStack S)
{
	int i;
	i = 0;
	while (i <= S.top)
	{
		visit(S.data[i++]);
	}
	printf_s("\n");
	return OK;
}

int main()
{
	int j;
	SqStack s;
	int e;
	if (InitStack(&s) == OK)
	{
		for (j = 1; j <= 10; j++)
		{
			Push(&s, j);
		}
	}
	printf_s("Õ»ÖÐÔªËØÒÀ´ÎÊÇ£º ");
	StackTraverse(s);
	Pop(&s, &e);
	printf("µ¯³öµÄÕ»¶¥ÔªËØ e=%d\n", e);
	printf("Õ»¿Õ·ñ£º%d(1:¿Õ 0:·ñ)\n", StackEmpty(s));
	GetTop(s, &e);
	printf("Õ»¶¥ÔªËØ e=%d Õ»µÄ³¤¶ÈÎª%d\n", e, StackLength(s));
	ClearStack(&s);
	printf("Çå¿ÕÕ»ºó£¬Õ»¿Õ·ñ£º%d(1:¿Õ 0:·ñ)\n", StackEmpty(s));
	return 0;
}

