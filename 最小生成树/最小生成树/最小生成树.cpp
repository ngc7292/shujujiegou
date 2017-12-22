// 最小生成树.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<io.h>
#include<math.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100

typedef int Status;
typedef char VertexType;//顶点的类型
typedef int EdgeType;

typedef struct EdgeNode
{
	int adjvex;//邻接点域，储存该节点的下标
	EdgeType info;//存储权值
	struct EdgeNode *next;//指向下一个邻接点
}EdgeNode;

typedef struct VertexNode
{
	VertexType data;//存储顶点信息
	EdgeNode *fristedge;//边表头指针
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numNodes, numEdges;//图中当前顶点数及边数
}GraghAdjList;

void CreateALGraph(GraghAdjList *G)
{
	int i, j, k;
	EdgeNode *e;
	printf("input the node of dingdian and bianshu:");
	scanf("%d,%d", &G->numNodes, &G->numEdges);
	for (i = 0; i <= G->numNodes; i++)
	{
		scanf(&G->adjList[i].data);
		G->adjList[i].fristedge = NULL;//将边表置为空表
	}

	for (k = 0; k <= G->numEdges; k++)
	{
		printf("input the number of vi and vj:");
		scanf("%d,%d", &i, &j);
		e = (EdgeNode *)malloc(sizeof(EdgeNode));//生成边表结点
		e->adjvex = j;
		e->next = G->adjList[i].fristedge;//将e的next指针赋给当前顶点的结点
		G->adjList[i].fristedge = e;//将当前顶点赋给e

		e = (EdgeNode *)malloc(sizeof(EdgeNode));//生成边表结点
		e->adjvex = i;
		e->next = G->adjList[i].fristedge;
		G->adjList[j].fristedge = e;
	}
}



int main()
{
	GraghAdjList G;
	CreateALGraph(&G);
    return 0;
}

