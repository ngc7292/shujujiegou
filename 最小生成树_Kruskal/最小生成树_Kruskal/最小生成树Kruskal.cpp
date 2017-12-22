// 最小生成树Kruskal.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<io.h>
#include<time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

#define MAXEDGE 20
#define MAXVEX 20
#define INFINITY 65535

typedef struct
{
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;//边数以及顶点数
}MGraph;

typedef struct
{
	int begin;
	int end;
	int weight;//权重
}Edge;//对边集数组进行定义

void CreateMGraph(MGraph *G)
{
	int i, j;
	G->numEdges = 15;
	G->numVertexes = 9;
	//初始化图
	for (i = 0; i < G->numVertexes; i++)
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			if (i == j)
			{
				G->arc[i][j] = 0;
			}
			else
			{
				G->arc[i][j] = G->arc[j][i] = INFINITY;
			}
		}
	}

	G->arc[0][1] = 10;
	G->arc[0][5] = 11;
	G->arc[1][2] = 18;
	G->arc[1][8] = 12;
	G->arc[1][6] = 16;
	G->arc[2][8] = 8;
	G->arc[2][3] = 22;
	G->arc[3][8] = 21;
	G->arc[3][6] = 24;
	G->arc[3][7] = 16;
	G->arc[3][4] = 20;
	G->arc[4][7] = 7;
	G->arc[4][5] = 26;
	G->arc[5][6] = 17;
	G->arc[6][7] = 19;

	for (i = 0; i < G->numVertexes; i++)
	{
		for (j = i; j < G->numVertexes; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}

//交换权值
void Swapn(Edge *edges, int i, int j)
{
	int temp;
	temp = edges[i].begin;
	edges[i].begin = edges[j].begin;
	edges[j].begin = temp;
	temp = edges[i].end;
	edges[i].end = edges[j].end;
	edges[j].end = temp;
	temp = edges[i].weight;
	edges[i].weight = edges[j].weight;
	edges[j].weight = temp;
}

//对权值进行排序
void sort(Edge *edges, MGraph *G)
{
	int i, j;
	for (i = 0; i < G->numEdges; i++)
	{
		for (j = i + 1; j < G->numEdges; j++)
		{
			if (edges[i].weight > edges[j].weight)
			{
				Swapn(edges, i, j);
			}
		}
	}
	printf("权排序之后的为：\n");
	for (i = 0; i < G->numEdges; i++)
	{
		printf("(%d,%d) %d", edges[i].begin, edges[i].end, edges[i].weight);
	}
}

//查找连线顶点的尾部下标
int Find(int *parent, int f)
{
	while (parent[f] > 0)
	{
		f = parent[f];
	}
	return f;
}

void MiniSpanTree(MGraph G)
{
	int i, j, n, m;
	int k = 0;
	int parent[MAXVEX];//判断边与边之间是否形成环路

	Edge edges[MAXEDGE];//定义边集数组，edge的结构为begin,end,weight

	//用来构建边集数组
	for (i = 0; i < G.numVertexes - 1; i++)
	{
		for (j = i + 1; j < G.numVertexes; j++)
		{
			if (G.arc[i][j] < INFINITY)
			{
				edges[k].begin = i;
				edges[k].end = j;
				edges[k].weight = G.arc[i][j];
				k++;
			}
		}
	}
	sort(edges, &G);

	for ( i = 0; i < G.numEdges; i++)
	{
		n = Find(parent, edges[i].begin);
		m = Find(parent, edges[i].end);
		if (n != m)
		{
			parent[n] = m;
			printf("(%d, %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
		}
	}

}
int main()
{
	MGraph G;
	CreateMGraph(&G);
	MiniSpanTree(G);
    return 0;
}

