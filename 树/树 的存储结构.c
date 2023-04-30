#include<stdio.h>


// 双亲表示法
// 每个结点中保存指向双亲的“指针”

#define MAX_TREE_SIZE 100   //树中最多的节点数
typedef struct
{
	Elemtype data;
	int parent;       // 双亲位置域
}PTNode;

typedef struct      // 树的类型定义
{
	PTNode nodes[MAX_TREE_SIZE];    // 双亲表示 (由结点组成的数组)
	int n;            // 结点数
}PTree;



// 孩子表示法
// （相当于 顺序存储+链式存储）

struct CTNode  // （链表中的）孩子结点
{
	int child;     // 孩子结点在数组中的位置
	struct CTNode* next;   // 下一个孩子
};

typedef struct  // （数组中的）第一个孩子结点
{
	Elemtype data;
	struct CTNode* firstChild;     // 第一个孩子
}CTBox;

typedef struct
{
	CTBox nodes[MAX_TREE_SIZE];
	int n, r;      // 结点数和根的位置
}CTree;




// ！！！孩子兄弟表示法
// （纯链式存储）

typedef struct CSNode
{
	Elemtype data;       // 数据域
	struct CSNode* firstchild, * nextsibling;   // 第一个孩子和左兄弟指针
}CSNode,*CSTree;












