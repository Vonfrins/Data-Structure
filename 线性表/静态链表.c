#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

// 静态链表的代码定义


// 1.写法一

#define MAXSIZE 10         // 静态链表的最大长度
struct Node          // 静态链表的结构类型定义
{
	ElemType data;        // 存储数据元素 
	int next;             // 下一个元素的数组下标  (游标起到指针的作用，但并不是指针！)
};

void testSLinkList()
{
	struct Node a[MAXSIZE];  // a 是一个Node型数组
}


// 2.写法二

#define MAXSIZE 10;
typedef struct 
{
	ElemType data;
	int next;
}SLinkList[MAXSIZE];


void testSLinkList()
{
	SLinkList a;      // a 是一个静态数组
}




// 静态链表的基本操作

// 1. 初始化静态链表


// 2. 查找


// 3. 插入位序为i的结点


// 4. 删除某个结点