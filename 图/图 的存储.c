// 1. �ڽӾ���   (��ά����ʵ��)
// ȱ�㣺�ռ临�Ӷȸ�(O(n^2))�����ʺϴ洢ϡ��ͼ
// ��ʾ��ʽΨһ

#define MAXVertexNum 100    // ������Ŀ�����ֵ
typedef struct
{
	char Vex[MAXVertexNum];     // �����
	int Edge[MAXVertexNum][MAXVertexNum];   // �ڽӾ��󣬱߱�
	int vexnum, arcnum;      // ͼ�ĵ�ǰ�������� ����/����
}MGraph;



    // �ڽӾ��󷨴洢 ��Ȩͼ
	#define MAXVertexNum 100
	#define INFINITY ����intֵ(����int������ֵ��ʾ"����")    // �궨�峣�� "����" 
	typedef char VertexType;      // �������������
	typedef int EdgeType;         // ��Ȩͼ�б��ϵ�Ȩֵ����������
	typedef struct
	{
		VertexType Vex[MAXVertexNum];    // ����
 		EdgeType Edge[MAXVertexNum][MAXVertexNum];   // �ߵ�Ȩֵ
		int vexnum, arcnum;    // ͼ�ĵ�ǰ������ �� ����
	}MGraph;





// 2. �ڽӱ�  (˳��+��ʽ�洢)
// ��ʾ��ʱ��Ψһ0

// ����"��"��"��"
	typedef struct ArcNode
	{
		int adjvex;       // ��/��ָ���ĸ����
		struct ArcNode* next;   // ָ����һ������ָ��
		// InfoType info;  // ��Ȩֵ
	}ArcNode;


// ����"����"
	typedef struct VNode
	{
		VertexType data;  // ������Ϣ
		ArcNode* first;   // ��һ����/��
	}VNode,AdjList[MAXVertexNum];

// ���ڽӱ�洢��ͼ
	typedef struct
	{
		AdjList vertices;
		int vexnum, arcnum;
	}ALGraph;


