#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

// 链式队列的定义
typedef struct LinkNode              // 定义链式队列的结点
{
	ElemType data;
	struct LinkNode* next;

}LinkNode;

typedef struct                      // 定义一个链式队列
{
	LinkNode* front, * rear;        // 定义链式队列的队头，队尾指针
}LinkQueue;



// 初始化（带头结点）

// 判断队列是否为空
bool IsEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}

void InitQueue(LinkQueue &Q)    // 初始化
{
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));   // 初始时，front 和 rear 都指向头结点
	Q.front->next = NULL;                                    
}

void testLinkQueue()
{
	LinkQueue Q;          // 声明一个队列
	InitQueue(Q);         // 初始化队列

	// ......后续操作
}





// 初始化 （不带头结点）

// 判断队列是否为空
bool IsEmpty(LinkQueue Q)
{
	if (Q.front == NULL)
		return true;
	else
		return false;

}


void InitQueue(LinkQueue& Q)           // 初始时，队头，队尾指针都指向NULL  
{
	Q.front = NULL;            
	Q.rear = NULL;
}





// 入队操作 （带头结点）
void EnQueue(LinkQueue& Q, ElemType x)
{
	LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;       // 新结点插入到 队尾指针rear指向结点 之后
	Q.rear = s;             // 修改队尾指针 rear
}


// (不带头结点)
void EnQueue(LinkQueue& Q, ElemType x)
{
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	if (Q.front==NULL)        // 空队列中插入第一个元素，不带头结点的队列，第一个元素入队时需要特殊处理 
	{
		Q.front = s;          // 修改队 头尾指针
		Q.rear = s;         
	}
	else
	{
		Q.rear->next = s;     // 新结点插入到 rear结点之后
		Q.rear = s;           // 修改 rear指针
	}

}




// 出队操作 （带头结点）
bool DeQueue(LinkQueue &Q, ElemType &x)
{
	if (Q.front == Q.rear)            // 空队
		return false;
	LinkNode* p = Q.front->next;
	x = p->data;                           // 用变量x返回队头元素
	Q.front->next = p->next;               // 修改头结点的 next 指针
	if (Q.rear == p)                       // 若此次是最后一个结点出队
		Q.rear = Q.front;                  // 修改队尾指针 
	free(p);                               // 释放结点空间
	return true;
}



// 出队操作 （不带头结点）
bool DeQueue(LinkQueue &Q,ElemType& x)
{
	if (Q.front == NULL)
		return false;
	LinkNode* p=Q.front;            // p指向此次出队的结点
	x = p->data;                    // 用变量x 返回队头元素
	Q.front = p->next;              // 修改 front 指针
	if (Q.rear == p)                // 此次是最后一个结点出队
	{
		Q.front = NULL;             // 队头,尾指针指向NULL
		Q.rear = NULL;
	}
	free(p);             // 释放
	
	return true;
}



