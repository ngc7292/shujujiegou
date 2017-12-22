// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<io.h>
#include<time.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100
#define INFINITY 65535

typedef int Status;
typedef char VertexType;
typedef int EdgeType;

typedef struct
{
	VertexType vexs[MAXVEX] = {0};//顶点表
	EdgeType arc[MAXVEX][MAXVEX];//途中当前顶点数与边数
	int numNodes, numEdges;
}MGraph;

void CreateMGraph(MGraph *G)
{
	int i, j, k, w;
	printf("input the point of ding\n");
	scanf_s("%d,%d", &G->numNodes, &G->numEdges);
	for (i = 0; i < G->numNodes; i++)
	{
		scanf_s(&G->vexs[i]);
	}
	for (i = 0; i < G->numNodes; i++)
	{
		for (j = 0; j < G->numNodes; j++)
		{
			G->arc[i][j] = INFINITY;//邻接矩阵初始化
		}
	}
	for (k = 0; k < G->numEdges; k++)
	{
		printf("input vi vj and w \n");
		scanf_s("%d,%d,%d", &i, &j, &w);
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];
	}
}

int main()
{
	MGraph G;
	CreateMGraph(&G);
    return 0;
}

