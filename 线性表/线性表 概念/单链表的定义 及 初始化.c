#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>


// 代码定义：

struct LNode               // 定义单链表结点类型
{
	int data;                      // (数据域)  每个结点存放一个数据元素
	struct LNode* next;            // (指针域)  指针指向下一个结点

}LNode,*LinkList;

struct LNode* p = (struct LNode*)malloc(sizeof(struct LNode));   // 增加一个新的结点：在内存空间中申请一个结点所需空间，并用指针p指向这个结点


typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode, * LinkList;



//  单链表的初始化

// 1. 不带头结点

typedef struct LNode
{
	int data;
	struct LNode* next;

}LNode, * LinkList;

// 初始化一个空的单链表
bool InitList(LinkList* L)
{
	L = NULL;          // 空表，暂时还没有任何结点
	return true;
}

void test()
{
	LinkList L;   //声明一个指向单链表的指针
	InitList(L);  //初始化一个空表

}


// 2.带头节点 （建议使用带头结点）

typedef struct LNode
{
	int data;
	struct LNode* next;

}LNode, * LinkList;


// 判断单链表是否为空
bool Empty(LinkList L)
{
	if (L->next == NULL)
		return true;
	else
		return false;

}

// 初始化一个单链表
bool InitList(LinkList* L)
{
	L = (LNode*)malloc(sizeof(LNode));      // 分配一个头结点
	if (L == NULL)                        // 内存不足，分配失败
		return false;
	L->next = NULL;                       // 头结点后暂时还没有结点
	return true;
}
