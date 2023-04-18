#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

// 循环单链表的定义

typedef struct LNode
{
	int data;
	struct LNode* next;

}LNode,*LinkList;


// 初始化一个循环单链表

bool InitList(LinkList L)
{
	L = (LNode*)malloc(sizeof(LNode));   //分配一个头结点
	if (L == NULL)
		return false;     //内存不足分配失败

	// 区别于普通单链表

	L->next = L;          // 头结点next指向头结点

	return true;
}



// 判断循环单链表是否为空 
bool Empty(LinkList L)
{
	if (L->next == NULL)
		return true;
	else
		return false;
}


// 判断结点p是否为循环单链表的表尾结点
bool isTail(LinkList L, LNode* p)
{
	if (p->next == L)
		return true;
	else
		return false;

}