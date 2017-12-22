// 搜索.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<io.h>
#include<time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int Boolean;

typedef char VertexType;
typedef int EdgeType;

#define MAXSIZE 9
#define MAXEDGE 15
#define MAXVEX 9
#define INFINITY 65535

typedef struct
{
	VertexType vexs[MAXVEX];//顶点表
	EdgeType arc[MAXVEX][MAXVEX];//邻接矩阵
	int numVertexes, numEdges;//顶点数以及边数
}MGraph;

typedef struct
{
	int data[MAXSIZE];
	int front;
	int rear;//尾指针，若队列不空，尾指针指向下一个指针
}Queue;

Status InitQueue(Queue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

Status QueueEmpty(Queue Q)
{
	if (Q.front == Q.rear)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

Status EnQueue(Queue *Q, int e)//插入队列
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)
		return ERROR;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;

	return OK;
}

Status DeQueue(Queue *Q, int *e)//删除队列中头元素
{
	if (Q->front == Q->rear)
		return ERROR;
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return OK;
}

void CreateMGraph(MGraph *G)
{
	int i, j;
	G->numEdges = 15;
	G->numVertexes = 9;

	G->vexs[0] = 'A';
	G->vexs[1] = 'B';
	G->vexs[2] = 'C';
	G->vexs[3] = 'D';
	G->vexs[4] = 'E';
	G->vexs[5] = 'F';
	G->vexs[6] = 'G';
	G->vexs[7] = 'H';
	G->vexs[8] = 'I';

	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j] = 0;
		}
	}

	G->arc[0][1] = 1;
	G->arc[0][5] = 1;

	G->arc[1][2] = 1;
	G->arc[1][8] = 1;
	G->arc[1][6] = 1;

	G->arc[2][3] = 1;
	G->arc[2][8] = 1;

	G->arc[3][4] = 1;
	G->arc[3][7] = 1;
	G->arc[3][6] = 1;
	G->arc[3][8] = 1;

	G->arc[4][5] = 1;
	G->arc[4][7] = 1;

	G->arc[5][6] = 1;

	G->arc[6][7] = 1;


	for (i = 0; i < G->numVertexes; i++)
	{
		for (j = i; j < G->numVertexes; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}

Boolean visited[MAXVEX];

//邻接矩阵的广度搜索
Boolean DFS(MGraph G, int i)
{
	int j;
	visited[i] = TRUE;
	printf("%c", G.vexs[i]);//打印顶点，或者其他操作
	for (j = 0; j < G.numVertexes; j++)
	{
		if (G.arc[i][j] == 1 && !visited[j])
			DFS(G, j);//递归执行其他节点
	}
	return OK;
}
//邻接矩阵的深度遍历操作
Boolean DFSTraverse(MGraph G)
{
	int i;
	for (i = 0; i < G.numVertexes; i++)
	{
		visited[i] = FALSE;//初始化所有的顶点
	}
	for (i = 0; i < G.numVertexes; i++)
		if (!visited[i])
			DFS(G, i);
	return OK;
}

//邻接矩阵的广度遍历算法
Boolean BFSTraverse(MGraph G)
{
	int i, j;
	Queue Q;
	for (i = 0; i < G.numVertexes; i++)
	{
		visited[i] = FALSE;//初始化队列
	}
	InitQueue(&Q);
	for (i = 0; i < G.numVertexes; i++)//对每个顶点进行循环
	{
		if (!visited[i])
		{
			visited[i] = TRUE;
			printf("%c", G.vexs[i]);//打印顶点
			EnQueue(&Q, i);//将此顶点置入队列
			while (!QueueEmpty(Q))
			{
				DeQueue(&Q, &i);//将队列元素赋值给i
				for (j = 0; j < G.numVertexes; j++)
				{
					//判断其他顶点若当前顶点未能访问
					if (G.arc[i][j] == 1 && !visited[j])
					{
						visited[j] = TRUE;
						printf("%c", G.vexs[j]);
						EnQueue(&Q, j);
					}
				}

			}

		}
	}
	return OK;
}




int main()
{
	MGraph G;
	CreateMGraph(&G);
	printf("shendubianli");
	DFSTraverse(G);
	printf("gaundubianli");
	BFSTraverse(G);
    return 0;
}

