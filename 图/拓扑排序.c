// AOV网 ： 用顶点表示活动的网络的一种有向无环图

// 拓扑排序算法 (伪代码)
// (基于邻接表的存储方式)

// 此处省略了对 indegree[i] （当前顶点的入度）和 print[i] （记录拓扑序列） 两个数组的声明

bool TopologicalSort(Graph G)
{
	InitStack(S);  // 初始化栈，存储入度为0的顶点
	for (int i = 0; i < G.vexnum; i++)
	{
		if (indegree[i] == 0)
			Push(S, i);  // 将所有入度为0的顶点进栈
	}
	int count = 0; // 计数，记录当前已经输出的顶点数
	while (!isEmpty(S))   // 栈不空，则存入入度为0的顶点
	{
		Pop(S, i); // 栈顶元素出栈
		print[count++] = i;    // 输出顶点i
		for (p = G.vertices[i].firstarc; p; p = p->nextarc)  // 将所有i指向的顶点的入度减1，并且将入度减为0的顶点压入栈S
		{
			v = p->adjvex;
			if (!(--indegree[v]))
				Push(S, v);   // 入度为0，则入栈
		}
	}

	if (count < G.vexnum)
		return false;     // 排序失效，有向图中有回路
	else
		return true;      // 拓扑排序成功
}





// 逆拓扑排序 （伪代码）
// （基于DFS算法）

void DFSTraverse(Graph G)
{
	for (int v = 0; v < G.vexnum; v++)
		visited[v] = FALSE;     // 初始化已访问标记数据
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