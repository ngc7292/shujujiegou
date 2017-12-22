// 关键路径.cpp: 定义控制台应用程序的入口点。
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

#define MAXEDGE 30
#define MAXVEX 30
#define INIFINITY 65535

typedef int Status;

int *etv, *ltv;
int *stack2;
int top2;

typedef struct
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

typedef struct EdgeNode
{
	int adjvex;
	int weight;
	struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode
{
	int in;
	int data;
	EdgeNode *fristedge;
}VertexNode,AdjList;

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges;
}graphAdjList,*GraphAdjList;


int main()
{
    return 0;
}

