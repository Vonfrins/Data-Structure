#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

// 二叉树 的顺序存储
 
// 注意：只适合存储 完全二叉树

#define MAXSIZE[100]
struct TreeNode
{ 
	ElemType data;   // 结点中存储的数据元素
	bool isEmpty;    // 结点是否为空
};


// 初始化
TreeNode t[MAXSIZE];   // 定义一个长度为MAXSIZE的数组t，按照从上至下，从左至右的顺序依次存储完全二叉树中的各个节点
for (int i = 0; i < MAXSIZE; i++)
{
	t[i].isEmpty = true;    // 初始化时所有结点标记为空
}



// 二叉树 的链式存储

struct ElemType
{
	int val;
};

typedef struct BiTNode
{
	ElemType data;       // 数据域
	struct BiTNode* lchild, * rchild;        // 左，右孩子指针
}BiTNode,*BiTree;


// 定义一棵空树
BiTree root = NULL;

// 插入根结点
root = (BiTNode*)malloc(sizeof(BiTNode));
root->data = { 1 };
root->lchild = NULL;      // 初始根节点的左，右孩子都为空
root->rchild = NULL;

// 插入新结点
BiTNode* p = (BiTNode*)malloc(sizeof(BiTNode));
p->data = { 2 };
p->lchild = NULL;
p->rchild = NULL;
root->lchild = p;        // 作为根结点的左孩子



// 创建一棵二叉树  (根据前序遍历创建)
BiTree createBinaryTree()
{
	int data;
	printf("请输入节点的值（-1表示节点为空）：\n");
	scanf("%d", &data);

	if (data == -1)
	{
		return NULL;
	}

	BiTree node = (BiTNode*)malloc(sizeof(BiTNode));
	node->data = data;
	node->lchild = createBinaryTree();
	node->rchild = createBinaryTree();
	return node;
}





// 由于在二叉链表中定义了左右孩子指针，所以对于找寻结点 p 的左右孩子非常简单
// 但是，对于寻找 p的父结点 却只能从根结点开始遍历（非常复杂）

// 为解决这个问题引入了：

// 三叉链表
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode* lchild, * rchild;
	struct BiTNode* parent;             // 在原有的定义基础上，增加父节点指针
}BiTNode,*BiTree;


