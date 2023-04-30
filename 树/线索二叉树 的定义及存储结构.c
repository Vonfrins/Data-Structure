#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>



// 中序遍历
void InOrder(BiTree node)
{
	if (node != NULL)
	{
		InOrder(node->lchild);
		visit(node);
		InOrder(node->rchild);
	}
}



// 线索二叉树 的存储结构

									//线索二叉树结点
									typedef struct ThreadNode    // thread 线，曲线
									{
										ElemType data;
										struct ThreadNode* lchild, * rchild;
										int ltag, rtag;           // 左，右线索标志
									}ThreadNode,*ThreadTree;

									// tag = 0 表示指针 指向孩子
									// tag = 1 表示指针 是一个"线索"


// 中序线索化 （就是一个中序遍历的过程）

// 定义全局变量 pre，指向当前访问结点的前驱
ThreadNode* pre = NULL;

// 中序线索化二叉树 T
void CreateInThread(ThreadTree T)
{
	pre = NULL;         // pre初始为 NULL
	if (T != NULL)      // 非空二叉树才能线索化
	{
		InThread(T);    // 中序线索化二叉树
		if (pre->rchild == NULL)
			pre->rtag = 1;        // 处理遍历最后一个结点
	}
}


void visit(ThreadNode* q)
{
	if (q->lchild == NULL)     // 左子树为空
	{
		q->lchild = pre;       // 建立前驱线索
		q->ltag = 1;
	}
	if (pre!=NULL && pre->rchild==NULL)   // 该节点的前驱不为空 且 前驱结点的 右孩子为空
	{
		pre->rchild = q;       // 建立后继线索
		pre->rtag = 1;
	}
	pre = q;
}


// 中序遍历二叉树，一边遍历一边线索化
void InThread(ThreadTree T)
{
	if (T != NULL)
	{
		InThread(T->lchild);
		visit(T);
		InThread(T->rchild);
	}
}



// 中序线索二叉树 找中序 后继

// 找到以 P 为根节点的子树中第一个被中序遍历的结点
ThreadNode* FirstNode(ThreadNode *p)
{
	// 循环找到最左下的结点（不一定是叶结点）
	while (p->ltag == 0)
		p = p->lchild;
	return p;
}


// 在中序线索二叉树中找到结点 P 的后继结点
ThreadNode* Nextnode(ThreadNode* p)
{
	// 右子树中最左下的结点
	if (p->rtag == 0)
		return FirstNode(p->rchild);
	else
		return p->rchild;     // rtag=1直接返回后继结点
}


// 对 中序线索二叉树 进行中序遍历  （利用线索实现的非递归算法）
void InOrder(ThreadTree T)
{
	for (ThreadNode* p = FirstNode(T); p != NULL; p = NextNode(p))
		visit(p);
}




// 中序线索二叉树 找中序 前驱

// 找到以 P 为根的子树中，最后一个被中序遍历的结点
ThreadNode* LastNode(ThreadNode* p)
{
	//  循环找到最右下结点（不一定是叶结点）
	while (p->rtag == 0)
		p = p->rchild;
	return p;
}


// 在中序线索二叉树中找到结点P 的前驱结点
ThreadNode* PreNode(ThreadNode* p)
{
	// 左子树中最右下结点
	if (p->ltag == 0)
		return LastNode(p->lchild);
	else
		return p->lchild;        // ltag=1 直接返回前驱线索
}


// 对中序线索二叉树进行 逆向 中序遍历
void RevInOrder(ThreadTree T)
{
	for (ThreadNode* p = LastNdoe(T); p != NULL; p = PreNode(p))
		visit(p);
}



//  前序，后序同理0 