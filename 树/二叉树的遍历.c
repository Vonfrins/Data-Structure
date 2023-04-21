#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

// �������ı���

// �ݹ鷽ʽ

typedef struct BiTNode          // ������������
{
	Elemtype data;
	struct BiTNode* rchild, * lchild;
}BiTNode,*BiTree;


// ������� (PreOrder) 

// ��������ı���˳���� ��������
void PreOrder(BiTree T)
{
	if (T != NULL)
	{ 
		visit(T);      // ���ʸ��ڵ�
		PreOrder(T->lchild);      // �ݹ����������
		PreOrder(T->rchild);      // �ݹ����������
	}
}


// ������� (InOrder)

// ��������ı���˳���� �󣬸�����
void InOrder(BiTree T)
{
	if (T != NULL)
	{
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}

}



// ������� (PostOrder)

// ��������ı���˳���� ���ң���
void PostOrder(BiTree T)
{
	if (T != NULL)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		visit(T);
	}

}



// �ǵݹ鷽ʽ




// �������Ĳ�α��� 

// ���ø�����ʽ���б���

typedef struct BiTNode          // ������������
{
	ElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;

typedef struct LinkNode        // ������нڵ�
{
	BiTree node;
	struct LinkNode* next;
}LinkNode;

typedef struct Queue          // �������
{
	LinkNode* front, * rear;
}Queue,*LinkQueue;

// ��ʼ������
LinkQueue InitQueue()
{
	LinkQueue queue = (Queue*)malloc(sizeof(Queue));
	queue->front = NULL;
	queue->rear = NULL;

	return queue;
}

// �ж϶ӿ�
bool isEmpty(LinkQueue queue)
{
	if (queue->front == NULL)
		return true;
	else
		return false;
}

// ��Ӳ���
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


// ���Ӳ���
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

// ����һ��������
BiTree createBinaryTree()
{
	int data;
	printf("������ڵ��ֵ (-1��ʾ���Ϊ��):\n");
	scanf("%d", &data);

	if (data == -1)
		return NULL;

	BiTree node = (BiTree)malloc(sizeof(BiTNode));
	node->data = data;
	node->lchild = createBinaryTree();
	node->rchild = createBinaryTree();
	return node;
}


// ��α��� (LevelOrder)
void LevelOrder(BiTree T)
{
	LinkQueue queue;   // ����һ������
	InitQueue(queue);  // ��ʼ����������
	BiTree p = T;
	EnQueue(queue, p);      // ���ڵ������
	while (!isEmpty(queue)) // ���в�Ϊ�� ѭ��
	{
		DeQueue(queue, p);  // ��ͷ������
		visit(p);           // ���ʳ��ӽ��
		if (p->lchild != NULL)
			EnQueue(queue, p->lchild);    // �������
		if (p->rchild != NULL)
			EnQueue(queue, p->rchild);    // �Һ������
	}

}

