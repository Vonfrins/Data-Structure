#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>


// ���붨�壺

struct LNode               // ���嵥����������
{
	int data;                      // (������)  ÿ�������һ������Ԫ��
	struct LNode* next;            // (ָ����)  ָ��ָ����һ�����

}LNode,*LinkList;

struct LNode* p = (struct LNode*)malloc(sizeof(struct LNode));   // ����һ���µĽ�㣺���ڴ�ռ�������һ���������ռ䣬����ָ��pָ��������


typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode, * LinkList;



//  ������ĳ�ʼ��

// 1. ����ͷ���

typedef struct LNode
{
	int data;
	struct LNode* next;

}LNode, * LinkList;

// ��ʼ��һ���յĵ�����
bool InitList(LinkList* L)
{
	L = NULL;          // �ձ���ʱ��û���κν��
	return true;
}

void test()
{
	LinkList L;   //����һ��ָ�������ָ��
	InitList(L);  //��ʼ��һ���ձ�

}


// 2.��ͷ�ڵ� ������ʹ�ô�ͷ��㣩

typedef struct LNode
{
	int data;
	struct LNode* next;

}LNode, * LinkList;


// �жϵ������Ƿ�Ϊ��
bool Empty(LinkList L)
{
	if (L->next == NULL)
		return true;
	else
		return false;

}

// ��ʼ��һ��������
bool InitList(LinkList* L)
{
	L = (LNode*)malloc(sizeof(LNode));      // ����һ��ͷ���
	if (L == NULL)                        // �ڴ治�㣬����ʧ��
		return false;
	L->next = NULL;                       // ͷ������ʱ��û�н��
	return true;
}
