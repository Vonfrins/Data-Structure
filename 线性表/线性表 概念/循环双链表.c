#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

// ѭ��˫����Ķ���

typedef struct DNode
{
	int data;
	struct DNode* next, * prior;
}DNode,*DLinkList;


//  ��ʼ��һ���յ�ѭ��˫����
bool InitDLinkList(DLinkList L)
{
	L = (DNode*)malloc(sizeof(DNode));       // ����һ��ͷ���
	if (L == NULL)            // �ڴ治�㣬����ʧ��
		return false;

	L->next = L;      //ͷ����nextָ��ͷ���
	L->prior = L;     //ͷ����priorָ��ͷ���

	return true;

}

void testDLinkList()
{
	DLinkList L;
	InitDLinkList(L);

}



// �ж�ѭ��˫�����Ƿ�Ϊ��
bool Empty(DLinkList L)
{
	if (L->next = L)
		return true;
	else
		return false;
}


// �жϽ��p�Ƿ�Ϊѭ��˫����ı�β���
bool isTail(DLinkList L, DNode*p)
{
	if (p->next = L)
		return true;
	else
		return false;

}




// ѭ��˫����Ĳ���


// �������

// ��p���֮�����s���
bool InsertNextNode(DNode* p, DNode* s)
{
	s->next = p->next;
	p->next->prior = s;
	s->prior = p;
	p->next = s;
}


// ɾ������

// ɾ�� p �ĺ�̽�� q
bool DeleteNextNode(DNode *p,DNode *q)
{
	p->next=q->next;
	q->next->prior = p;
	free(q);

}
