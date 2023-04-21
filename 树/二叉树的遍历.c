#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

// 二叉树的遍历

// 递归方式

typedef struct BiTNode          // 定义二叉树结点
{
	Elemtype data;
	struct BiTNode* rchild, * lchild;
}BiTNode,*BiTree;


// 先序遍历 (PreOrder) 

// 先序遍历的遍历顺序是 根，左，右
void PreOrder(BiTree T)
{
	if (T != NULL)
	{ 
		visit(T);      // 访问根节点
		PreOrder(T->lchild);      // 递归遍历左子树
		PreOrder(T->rchild);      // 递归遍历右子树
	}
}


// 中序遍历 (InOrder)

// 中序遍历的遍历顺序是 左，根，右
void InOrder(BiTree T)
{
	if (T != NULL)
	{
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}

}



// 后序遍历 (PostOrder)

// 后序遍历的遍历顺序是 左，右，根
void PostOrder(BiTree T)
{
	if (T != NULL)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		visit(T);
	}

}



// 非递归方式




// 二叉树的层次遍历 

// 利用辅助链式队列遍历

typedef struct BiTNode          // 定义二叉树结点
{
	ElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;

typedef struct LinkNode        // 定义队列节点
{
	BiTree node;
	struct LinkNode* next;
}LinkNode;

typedef struct Queue          // 定义队列
{
	LinkNode* front, * rear;
}Queue,*LinkQueue;

// 初始化队列
LinkQueue InitQueue()
{
	LinkQueue queue = (Queue*)malloc(sizeof(Queue));
	queue->front = NULL;
	queue->rear = NULL;

	return queue;
}

// 判断队空
bool isEmpty(LinkQueue queue)
{
	if (queue->front == NULL)
		return true;
	else
		return false;
}

// 入队操作
void EnQueue(LinkQueue queue,BiTree node)
{
	LinkNode* queuenode = (LinkNode*)malloc(sizeof(LinkNode));
	queuenode->node = node;
	queuenode->next = NULL;

	if (queue->front == NULL)
	{
		queue->front = queuenode;
		queue->rear = queuenode;
	}
	else
	{
		queue->rear->next = queuenode;
		queue->rear = queuenode;
	}
}


// 出队操作
void DeQueue(LinkQueue queue,BiTree node)
{
	if (isEmpty(queue))
		return false;

	LinkNode* queuenode = queue->front;
	node = queuenode->node;
	queue->front = queuenode->next;

	if (queue->rear == queuenode)
	{
		queue->front = NULL;
		queue->rear = NULL;
	}
	free(queuenode);
}

// 创建一个二叉树
BiTree createBinaryTree()
{
	int data;
	printf("请输入节点的值 (-1表示结点为空):\n");
	scanf("%d", &data);

	if (data == -1)
		return NULL;

	BiTree node = (BiTree)malloc(sizeof(BiTNode));
	node->data = data;
	node->lchild = createBinaryTree();
	node->rchild = createBinaryTree();
	return node;
}


// 层次遍历 (LevelOrder)
void LevelOrder(BiTree T)
{
	LinkQueue queue;   // 声明一个队列
	InitQueue(queue);  // 初始化辅助队列
	BiTree p = T;
	EnQueue(queue, p);      // 根节点入队列
	while (!isEmpty(queue)) // 队列不为空 循环
	{
		DeQueue(queue, p);  // 队头结点出队
		visit(p);           // 访问出队结点
		if (p->lchild != NULL)
			EnQueue(queue, p->lchild);    // 左孩子入队
		if (p->rchild != NULL)
			EnQueue(queue, p->rchild);    // 右孩子入队
	}

}

