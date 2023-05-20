#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_VERTEX_NUM 100

// ������ȱ��� BFS (α�����ʾ)
// (���Ĳ������)

bool visited[MAX_VERTEX_NUM];  // ���ʱ������ (��ʼ��Ϊfalse)

void BFSTraverse(Graph G)  // ��ͼG���й�����ȱ���
{
	for (int i = 0;i<G.vexnum; i++)
	{
		visited[i] = false;    // ���ʱ�������ʼ��
	}
	InitQueue(Q);  // ��ʼ����������Q
	for (int i = 0; i < G.vexnum; i++)  // ��0�Ŷ��㿪ʼ����
	{
		if (!visited[i])  // ��ÿ����ͨ��������һ�� BFS
			BFS(G, i);    // vi δ���ʹ�����vi��ʼ BFS
	}

}


void BFS(Graph G, int v)    // �Ӷ��������������ȱ���ͼG
{
	visit(v);     // ���ʳ�ʼ����v
	visited[v] = TRUE;   // ��v���ѷ��ʱ��
	Enqueue(Q, v);   // ����v�����Q
	while (!is_Empty(Q))     
	{
		Dequeue(Q, v);   // ����v������
		for (w = FirstNeighbor(Q, v); w >= 0; w = NextNeighbor(Q, v, w))   // ���v�������ڽӵ�
		{
			if (!visited[w])    // wΪv��δ���ʵ��ڽӶ���
			{
				visit(w);       // ���ʶ���w
				visited[w] = TRUE;  // ��w���ѷ��ʱ��
				EnQueue(Q, w);  // ����w���
			}
		}
	}
}




// ������ȱ��� DFS (α�����ʾ)
// (�����ȸ�����)

bool visited[MAX_VERTEX_NUM];   // ���ʱ������

void DFSTraverse(Graph G)  // ��ͼ G����������ȱ���
{
	for (int i = 0; i < vexnum; i++)
		visited[i] = false;
	for (int i = 0; i < vexnum; i++)
	{
		if (!visited[i])
			DFS(G, i);
	}
}


void DFS(Graph G, int v)   // �Ӷ���v ������ ������ȱ���ͼG
{
	visit(v);   // ���ʶ���v
	visited[v] = true;   // ��v���ѷ��ʱ��
	for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) 
	{
		if (!visited[w])   // wΪv����δ���ʵ��ڽӶ��� 
			DFS(G, w);
	}

}
