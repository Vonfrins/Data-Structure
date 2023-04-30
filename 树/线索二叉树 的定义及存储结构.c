#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>



// �������
void InOrder(BiTree node)
{
	if (node != NULL)
	{
		InOrder(node->lchild);
		visit(node);
		InOrder(node->rchild);
	}
}



// ���������� �Ĵ洢�ṹ

									//�������������
									typedef struct ThreadNode    // thread �ߣ�����
									{
										ElemType data;
										struct ThreadNode* lchild, * rchild;
										int ltag, rtag;           // ����������־
									}ThreadNode,*ThreadTree;

									// tag = 0 ��ʾָ�� ָ����
									// tag = 1 ��ʾָ�� ��һ��"����"


// ���������� ������һ����������Ĺ��̣�

// ����ȫ�ֱ��� pre��ָ��ǰ���ʽ���ǰ��
ThreadNode* pre = NULL;

// ���������������� T
void CreateInThread(ThreadTree T)
{
	pre = NULL;         // pre��ʼΪ NULL
	if (T != NULL)      // �ǿն���������������
	{
		InThread(T);    // ����������������
		if (pre->rchild == NULL)
			pre->rtag = 1;        // ����������һ�����
	}
}


void visit(ThreadNode* q)
{
	if (q->lchild == NULL)     // ������Ϊ��
	{
		q->lchild = pre;       // ����ǰ������
		q->ltag = 1;
	}
	if (pre!=NULL && pre->rchild==NULL)   // �ýڵ��ǰ����Ϊ�� �� ǰ������ �Һ���Ϊ��
	{
		pre->rchild = q;       // �����������
		pre->rtag = 1;
	}
	pre = q;
}


// ���������������һ�߱���һ��������
void InThread(ThreadTree T)
{
	if (T != NULL)
	{
		InThread(T->lchild);
		visit(T);
		InThread(T->rchild);
	}
}



// �������������� ������ ���

// �ҵ��� P Ϊ���ڵ�������е�һ������������Ľ��
ThreadNode* FirstNode(ThreadNode *p)
{
	// ѭ���ҵ������µĽ�㣨��һ����Ҷ��㣩
	while (p->ltag == 0)
		p = p->lchild;
	return p;
}


// �������������������ҵ���� P �ĺ�̽��
ThreadNode* Nextnode(ThreadNode* p)
{
	// �������������µĽ��
	if (p->rtag == 0)
		return FirstNode(p->rchild);
	else
		return p->rchild;     // rtag=1ֱ�ӷ��غ�̽��
}


// �� �������������� �����������  ����������ʵ�ֵķǵݹ��㷨��
void InOrder(ThreadTree T)
{
	for (ThreadNode* p = FirstNode(T); p != NULL; p = NextNode(p))
		visit(p);
}




// �������������� ������ ǰ��

// �ҵ��� P Ϊ���������У����һ������������Ľ��
ThreadNode* LastNode(ThreadNode* p)
{
	//  ѭ���ҵ������½�㣨��һ����Ҷ��㣩
	while (p->rtag == 0)
		p = p->rchild;
	return p;
}


// �������������������ҵ����P ��ǰ�����
ThreadNode* PreNode(ThreadNode* p)
{
	// �������������½��
	if (p->ltag == 0)
		return LastNode(p->lchild);
	else
		return p->lchild;        // ltag=1 ֱ�ӷ���ǰ������
}


// �������������������� ���� �������
void RevInOrder(ThreadTree T)
{
	for (ThreadNode* p = LastNdoe(T); p != NULL; p = PreNode(p))
		visit(p);
}



//  ǰ�򣬺���ͬ��0 