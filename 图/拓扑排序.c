// AOV�� �� �ö����ʾ��������һ�������޻�ͼ

// ���������㷨 (α����)
// (�����ڽӱ�Ĵ洢��ʽ)

// �˴�ʡ���˶� indegree[i] ����ǰ�������ȣ��� print[i] ����¼�������У� �������������

bool TopologicalSort(Graph G)
{
	InitStack(S);  // ��ʼ��ջ���洢���Ϊ0�Ķ���
	for (int i = 0; i < G.vexnum; i++)
	{
		if (indegree[i] == 0)
			Push(S, i);  // ���������Ϊ0�Ķ����ջ
	}
	int count = 0; // ��������¼��ǰ�Ѿ�����Ķ�����
	while (!isEmpty(S))   // ջ���գ���������Ϊ0�Ķ���
	{
		Pop(S, i); // ջ��Ԫ�س�ջ
		print[count++] = i;    // �������i
		for (p = G.vertices[i].firstarc; p; p = p->nextarc)  // ������iָ��Ķ������ȼ�1�����ҽ���ȼ�Ϊ0�Ķ���ѹ��ջS
		{
			v = p->adjvex;
			if (!(--indegree[v]))
				Push(S, v);   // ���Ϊ0������ջ
		}
	}

	if (count < G.vexnum)
		return false;     // ����ʧЧ������ͼ���л�·
	else
		return true;      // ��������ɹ�
}





// ���������� ��α���룩
// ������DFS�㷨��

void DFSTraverse(Graph G)
{
	for (int v = 0; v < G.vexnum; v++)
		visited[v] = FALSE;     // ��ʼ���ѷ��ʱ������
	for (int v = 0; v < G.vexnum; v++)
		if (!visited[v])
			DFS(G, v);
}

void DFS(Graph G,int v)
{
	visited[v] = True;
	for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
		if (!visited[w])
		{
			DFS(G, w);
		}
	print(v);           
}