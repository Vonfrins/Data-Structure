#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

typedef struct DNode
{
	int data;
	struct DNode* prior, * next;

}DNode,*DLinkList;


//  双链表的插入操作


// 在p结点之后插入s结点
bool InsertNextDNode(DNode* p, DNode* s)
{
	if (p = NULL || s = NULL)        // 非法参数
		return false;
	s->next = p->next;
	
	if (p->next != NULL)            // 如果p结点有后继结点
		p->next->prior = s;

	s->prior = p;
	p->next = s;

	return true;
}




//  双链表的删除操作


//删除p结点的后继结点
bool DeleteNextDNode(DNode* p)
{
	if (p == NULL)
		return false;
	DNode* q = p->next;          // 找到 p 的后继结点 q
	if (q == NULL)
		return false;            // p 没有后继

	p->next = q->next;
	if (q->next != NULL)         // q 结点不是最后一个结点
		q->next->prior = p;

	free(q);             // 释放结点空间

	return true; 
		
}




// 双链表的销毁

void DestroyList(DLinkList *L)
{
	// 循环释放各个数据结点
	while (L->next != NULL)
		DeleteNextDNode(L);
	free(L);                        // 释放头结点
	L = NULL;                       // 头指针指向NULL

}





// 双链表的遍历

// 后向遍历

while (p != NULL)
{
	// 对结点p 进行相应操作
	p = p->next;
}


// 前向遍历

  // 1.包含头结点
while (p != NULL)
{
	// 对结点p进行相应操作
	p = p->prior;
}

  // 2. 跳过头结点
while (p->prior != NULL)
{
	// 对结点p进行相应操作
	p = p->prior;
}






