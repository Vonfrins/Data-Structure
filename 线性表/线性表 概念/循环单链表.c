#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

// ѭ��������Ķ���

typedef struct LNode
{
	int data;
	struct LNode* next;

}LNode,*LinkList;


// ��ʼ��һ��ѭ��������

bool InitList(LinkList L)
{
	L = (LNode*)malloc(sizeof(LNode));   //����һ��ͷ���
	if (L == NULL)
		return false;     //�ڴ治�����ʧ��

	// ��������ͨ������

	L->next = L;          // ͷ���nextָ��ͷ���

	return true;
}



// �ж�ѭ���������Ƿ�Ϊ�� 
bool Empty(LinkList L)
{
	if (L->next == NULL)
		return true;
	else
		return false;
}


// �жϽ��p�Ƿ�Ϊѭ��������ı�β���
bool isTail(LinkList L, LNode* p)
{
	if (p->next == L)
		return true;
	else
		return false;

}