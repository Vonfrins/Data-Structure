#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

// ������ ��˳��洢
 
// ע�⣺ֻ�ʺϴ洢 ��ȫ������

#define MAXSIZE[100]
struct TreeNode
{ 
	ElemType data;   // ����д洢������Ԫ��
	bool isEmpty;    // ����Ƿ�Ϊ��
};


// ��ʼ��
TreeNode t[MAXSIZE];   // ����һ������ΪMAXSIZE������t�����մ������£��������ҵ�˳�����δ洢��ȫ�������еĸ����ڵ�
for (int i = 0; i < MAXSIZE; i++)
{
	t[i].isEmpty = true;    // ��ʼ��ʱ���н����Ϊ��
}



// ������ ����ʽ�洢

struct ElemType
{
	int val;
};

typedef struct BiTNode
{
	ElemType data;       // ������
	struct BiTNode* lchild, * rchild;        // ���Һ���ָ��
}BiTNode,*BiTree;


// ����һ�ÿ���
BiTree root = NULL;

// ��������
root = (BiTNode*)malloc(sizeof(BiTNode));
root->data = { 1 };
root->lchild = NULL;      // ��ʼ���ڵ�����Һ��Ӷ�Ϊ��
root->rchild = NULL;

// �����½��
BiTNode* p = (BiTNode*)malloc(sizeof(BiTNode));
p->data = { 2 };
p->lchild = NULL;
p->rchild = NULL;
root->lchild = p;        // ��Ϊ����������



// ����һ�ö�����  (����ǰ���������)
BiTree createBinaryTree()
{
	int data;
	printf("������ڵ��ֵ��-1��ʾ�ڵ�Ϊ�գ���\n");
	scanf("%d", &data);

	if (data == -1)
	{
		return NULL;
	}

	BiTree node = (BiTNode*)malloc(sizeof(BiTNode));
	node->data = data;
	node->lchild = createBinaryTree();
	node->rchild = createBinaryTree();
	return node;
}





// �����ڶ��������ж��������Һ���ָ�룬���Զ�����Ѱ��� p �����Һ��ӷǳ���
// ���ǣ�����Ѱ�� p�ĸ���� ȴֻ�ܴӸ���㿪ʼ�������ǳ����ӣ�

// Ϊ���������������ˣ�

// ��������
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode* lchild, * rchild;
	struct BiTNode* parent;             // ��ԭ�еĶ�������ϣ����Ӹ��ڵ�ָ��
}BiTNode,*BiTree;


