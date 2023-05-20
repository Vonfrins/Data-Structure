// 1. 邻接矩阵法   (二维数组实现)
// 缺点：空间复杂度高(O(n^2))，不适合存储稀疏图
// 表示方式唯一

#define MAXVertexNum 100    // 顶点数目的最大值
typedef struct
{
	char Vex[MAXVertexNum];     // 顶点表
	int Edge[MAXVertexNum][MAXVertexNum];   // 邻接矩阵，边表
	int vexnum, arcnum;      // 图的当前顶点数和 边数/弧数
}MGraph;



    // 邻接矩阵法存储 带权图
	#define MAXVertexNum 100
	#define INFINITY 最大的int值(可用int的上限值表示"无穷")    // 宏定义常量 "无穷" 
	typedef char VertexType;      // 顶点的数据类型
	typedef int EdgeType;         // 带权图中边上的权值的数据类型
	typedef struct
	{
		VertexType Vex[MAXVertexNum];    // 顶点
 		EdgeType Edge[MAXVertexNum][MAXVertexNum];   // 边的权值
		int vexnum, arcnum;    // 图的当前顶点数 和 弧数
	}MGraph;





// 2. 邻接表法  (顺序+链式存储)
// 表示当时不唯一0

// 声明"边"和"弧"
	typedef struct ArcNode
	{
		int adjvex;       // 边/弧指向哪个结点
		struct ArcNode* next;   // 指向下一条弧的指针
		// InfoType info;  // 边权值
	}ArcNode;


// 声明"顶点"
	typedef struct VNode
	{
		VertexType data;  // 顶点信息
		ArcNode* first;   // 第一条边/弧
	}VNode,AdjList[MAXVertexNum];

// 用邻接表存储的图
	typedef struct
	{
		AdjList vertices;
		int vexnum, arcnum;
	}ALGraph;


