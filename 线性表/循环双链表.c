#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

// 循环双链表的定义

typedef struct DNode
{
	int data;
	struct DNode* next, * prior;
}DNode,*DLinkList;


//  初始化一个空的循环双链表
bool InitDLinkList(DLinkList L)
{
	L = (DNode*)malloc(sizeof(DNode));       // 分配一个头结点
	if (L == NULL)            // 内存不足，分配失败
		return false;

	L->next = L;      //头结点的next指向头结点
	L->prior = L;     //头结点的prior指向头结点

	return true;

}

void testDLinkList()
{
	DLinkList L;
	InitDLinkList(L);

}



// 判断循环双链表是否为空
bool Empty(DLinkList L)
{
	if (L->next = L)
		return true;
	else
		return false;
}


// 判断结点p是否为循环双链表的表尾结点
bool isTail(DLinkList L, DNode*p)
{
	if (p->next = L)
		return true;
	else
		return false;

}




// 循环双链表的操作


// 插入操作

// 在p结点之后插入s结点
bool InsertNextNode(DNode* p, DNode* s)
{
	s->next = p->next;
	p->next->prior = s;
	s->prior = p;
	p->next = s;
}


// 删除操作

// 删除 p 的后继结点 q
bool DeleteNextNode(DNode *p,DNode *q)
{
	p->next=q->next;
	q->next->prior = p;
	free(q);

}
