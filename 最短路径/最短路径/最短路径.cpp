// 最短路径.cpp: 定义控制台应用程序的入口点。
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

#define MAXEDGE 20
#define MAXVEX 20
#define INFINITY 65535

typedef int Status;

//定义一个图
typedef struct
{
	//顶点表
	int vexs[MAXVEX];
	//邻接矩阵
	int arc[MAXVEX][MAXVEX];
	//顶点数以及边数
	int numVertexes, numEdges;
}MGraph;

typedef int Patharc[MAXVEX];
typedef int ShortPathTable[MAXVEX];

//创建图
void CreateMGraph(MGraph *G)
{
	int i, j;

	G->numEdges = 16;
	G->numVertexes = 9;

	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
	{
		G->vexs[i] = i;
	}

	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			if (i == j)
				G->arc[i][j] = 0;
			else
				G->arc[i][j] = G->arc[j][i] = INFINITY;
		}
	}

	G->arc[0][1] = 1;
	G->arc[0][2] = 5;
	G->arc[1][2] = 3;
	G->arc[1][3] = 7;
	G->arc[1][4] = 5;

	G->arc[2][4] = 1;
	G->arc[2][5] = 7;
	G->arc[3][4] = 2;
	G->arc[3][6] = 3;
	G->arc[4][5] = 3;

	G->arc[4][6] = 6;
	G->arc[4][7] = 9;
	G->arc[5][7] = 5;
	G->arc[6][7] = 2;
	G->arc[6][8] = 7;

	G->arc[7][8] = 4;


	for (i = 0; i < G->numVertexes; i++)
	{
		for (j = i; j < G->numVertexes; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}

//dijkstra算法，求有向网v0到其余顶点的最短路径与带权长度
//P[v]是前驱顶点的下标，D[v]表示v0到v的最短路径之和
void ShorttestPath_Dijkstra(MGraph G, int v0, Patharc *P, ShortPathTable *D)
{
	int v, k, w, min;
	int final[MAXVEX];

	for (v = 0; v < G.numVertexes; v++)//初始化数据
	{
		final[v] = 0;
		(*D)[v] = G.arc[v0][v];//将与v0点有连线的顶点加上权值
		(*P)[v] = -1;//初始化路径为-1
	}


	(*D)[v0] = 0;
	final[v0] = 1;
	for (v = 1; v < G.numVertexes; v++)
	{
		min = INFINITY;
		for (w = 0; w < G.numVertexes; w++)
		{
			if (!final[w] && (*D)[w] < min)
			{
				k = w;
				min = (*D)[w];
			}
		}
		final[k] = 1;
		for ( w = 0; w < G.numVertexes; w++)
		{
			if (!final[w] && (min + G.arc[k][w] < (*D)[w]))
			{
				(*D)[w] = min + G.arc[k][w];
				(*P)[w] = k;
			}
		}		
	}
}





int main()
{
	MGraph G;
	Patharc P;
	ShortPathTable D;
	int i, j, v0 = 0;
	CreateMGraph(&G);

	ShorttestPath_Dijkstra(G, v0, &P, &D);

	printf("最短路径倒序如下:\n");
	for (i = 1; i<G.numVertexes; ++i)
	{
		printf("v%d - v%d : ", v0, i);
		j = i;
		while (P[j] != -1)
		{
			printf("%d ", P[j]);
			j = P[j];
		}
		printf("\n");
	}
	printf("\n源点到各顶点的最短路径长度为:\n");
	for (i = 1; i<G.numVertexes; ++i)
		printf("v%d - v%d : %d \n", G.vexs[0], G.vexs[i], D[i]);

    return 0;
}

