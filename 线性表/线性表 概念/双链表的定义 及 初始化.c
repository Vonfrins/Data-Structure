#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

// 双链表的定义

typedef struct DNode
{
	int data;                          // 定义数据域
	struct DNode* prior, * next;       // 定义前驱和后继结点指针

}DNode,*DLinkList;

// "D" 表示 double

// DLinkList 强调一个链表
// DNode *   强调一个结点



// 初始化双链表

typedef struct DNode
{
	int data;
	struct DNode* prior, * next;

}DNode,*DLinkList;

bool InitList(DLinkList *L)
{
	L = (DNode*)malloc(sizeof(DNode));    // 分配一个头结点
	if (L == NULL)
		return false;
	L->prior = NULL;             // 头结点的前驱 prior 永远指向 NULL
	L->next = NULL;              // 头结点后暂时无结点

	return true;
}


// 判断双链表是否为空（带头结点）
bool Empty(DLinkList L)
{
	if (L->next == NULL)
		return true;
	else
		return false;

}

void main()
{
	DLinkList L;
	InitList(&L);

}