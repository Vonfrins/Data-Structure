#include<stdio.h>


// ˫�ױ�ʾ��
// ÿ������б���ָ��˫�׵ġ�ָ�롱

#define MAX_TREE_SIZE 100   //�������Ľڵ���
typedef struct
{
	Elemtype data;
	int parent;       // ˫��λ����
}PTNode;

typedef struct      // �������Ͷ���
{
	PTNode nodes[MAX_TREE_SIZE];    // ˫�ױ�ʾ (�ɽ����ɵ�����)
	int n;            // �����
}PTree;



// ���ӱ�ʾ��
// ���൱�� ˳��洢+��ʽ�洢��

struct CTNode  // �������еģ����ӽ��
{
	int child;     // ���ӽ���������е�λ��
	struct CTNode* next;   // ��һ������
};

typedef struct  // �������еģ���һ�����ӽ��
{
	Elemtype data;
	struct CTNode* firstChild;     // ��һ������
}CTBox;

typedef struct
{
	CTBox nodes[MAX_TREE_SIZE];
	int n, r;      // ������͸���λ��
}CTree;




// �����������ֵܱ�ʾ��
// ������ʽ�洢��

typedef struct CSNode
{
	Elemtype data;       // ������
	struct CSNode* firstchild, * nextsibling;   // ��һ�����Ӻ����ֵ�ָ��
}CSNode,*CSTree;












