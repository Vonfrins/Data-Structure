#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

// ˫����Ķ���

typedef struct DNode
{
	int data;                          // ����������
	struct DNode* prior, * next;       // ����ǰ���ͺ�̽��ָ��

}DNode,*DLinkList;

// "D" ��ʾ double

// DLinkList ǿ��һ������
// DNode *   ǿ��һ�����



// ��ʼ��˫����

typedef struct DNode
{
	int data;
	struct DNode* prior, * next;

}DNode,*DLinkList;

bool InitList(DLinkList *L)
{
	L = (DNode*)malloc(sizeof(DNode));    // ����һ��ͷ���
	if (L == NULL)
		return false;
	L->prior = NULL;             // ͷ����ǰ�� prior ��Զָ�� NULL
	L->next = NULL;              // ͷ������ʱ�޽��

	return true;
}


// �ж�˫�����Ƿ�Ϊ�գ���ͷ��㣩
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