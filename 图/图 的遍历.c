#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_VERTEX_NUM 100

// 广度优先遍历 BFS (伪代码表示)
// (树的层序遍历)

bool visited[MAX_VERTEX_NUM];  // 访问标记数组 (初始都为false)

void BFSTraverse(Graph G)  // 对图G进行广度优先遍历
{
	for (int i = 0;i<G.vexnum; i++)
	{
		visited[i] = false;    // 访问标记数组初始化
	}
	InitQueue(Q);  // 初始化辅助队列Q
	for (int i = 0; i < G.vexnum; i++)  // 从0号顶点开始遍历
	{
		if (!visited[i])  // 对每个连通分量调用一次 BFS
			BFS(G, i);    // vi 未访问过，从vi开始 BFS
	}

}


void BFS(Graph G, int v)    // 从顶点出发，广度优先遍历图G
{
	visit(v);     // 访问初始顶点v
	visited[v] = TRUE;   // 对v做已访问标记
	Enqueue(Q, v);   // 顶点v入队列Q
	while (!is_Empty(Q))     
	{
		Dequeue(Q, v);   // 顶点v出队列
		for (w = FirstNeighbor(Q, v); w >= 0; w = NextNeighbor(Q, v, w))   // 检测v的所有邻接点
		{
			if (!visited[w])    // w为v尚未访问的邻接顶点
			{
				visit(w);       // 访问顶点w
				visited[w] = TRUE;  // 对w做已访问标记
				EnQueue(Q, w);  // 顶点w入队
			}
		}
	}
}




// 深度优先遍历 DFS (伪代码表示)
// (树的先根遍历)

bool visited[MAX_VERTEX_NUM];   // 访问标记数组

void DFSTraverse(Graph G)  // 对图 G进行深度优先遍历
{
	for (int i = 0; i < vexnum; i++)
		visited[i] = false;
	for (int i = 0; i < vexnum; i++)
	{
		if (!visited[i])
			DFS(G, i);
	}
}


void DFS(Graph G, int v)   // 从顶点v 出发， 深度优先遍历图G
{
	visit(v);   // 访问顶点v
	visited[v] = true;   // 对v做已访问标记
	for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) 
	{
		if (!visited[w])   // w为v的尚未访问的邻接顶点 
			DFS(G, w);
	}

}
