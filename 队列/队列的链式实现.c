#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

// ��ʽ���еĶ���
typedef struct LinkNode              // ������ʽ���еĽ��
{
	ElemType data;
	struct LinkNode* next;

}LinkNode;

typedef struct                      // ����һ����ʽ����
{
	LinkNode* front, * rear;        // ������ʽ���еĶ�ͷ����βָ��
}LinkQueue;



// ��ʼ������ͷ��㣩

// �ж϶����Ƿ�Ϊ��
bool IsEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}

void InitQueue(LinkQueue &Q)    // ��ʼ��
{
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));   // ��ʼʱ��front �� rear ��ָ��ͷ���
	Q.front->next = NULL;                                    
}

void testLinkQueue()
{
	LinkQueue Q;          // ����һ������
	InitQueue(Q);         // ��ʼ������

	// ......��������
}





// ��ʼ�� ������ͷ��㣩

// �ж϶����Ƿ�Ϊ��
bool IsEmpty(LinkQueue Q)
{
	if (Q.front == NULL)
		return true;
	else
		return false;

}


void InitQueue(LinkQueue& Q)           // ��ʼʱ����ͷ����βָ�붼ָ��NULL  
{
	Q.front = NULL;            
	Q.rear = NULL;
}





// ��Ӳ��� ����ͷ��㣩
void EnQueue(LinkQueue& Q, ElemType x)
{
	LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;       // �½����뵽 ��βָ��rearָ���� ֮��
	Q.rear = s;             // �޸Ķ�βָ�� rear
}


// (����ͷ���)
void EnQueue(LinkQueue& Q, ElemType x)
{
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	if (Q.front==NULL)        // �ն����в����һ��Ԫ�أ�����ͷ���Ķ��У���һ��Ԫ�����ʱ��Ҫ���⴦�� 
	{
		Q.front = s;          // �޸Ķ� ͷβָ��
		Q.rear = s;         
	}
	else
	{
		Q.rear->next = s;     // �½����뵽 rear���֮��
		Q.rear = s;           // �޸� rearָ��
	}

}




// ���Ӳ��� ����ͷ��㣩
bool DeQueue(LinkQueue &Q, ElemType &x)
{
	if (Q.front == Q.rear)            // �ն�
		return false;
	LinkNode* p = Q.front->next;
	x = p->data;                           // �ñ���x���ض�ͷԪ��
	Q.front->next = p->next;               // �޸�ͷ���� next ָ��
	if (Q.rear == p)                       // ���˴������һ��������
		Q.rear = Q.front;                  // �޸Ķ�βָ�� 
	free(p);                               // �ͷŽ��ռ�
	return true;
}



// ���Ӳ��� ������ͷ��㣩
bool DeQueue(LinkQueue &Q,ElemType& x)
{
	if (Q.front == NULL)
		return false;
	LinkNode* p=Q.front;            // pָ��˴γ��ӵĽ��
	x = p->data;                    // �ñ���x ���ض�ͷԪ��
	Q.front = p->next;              // �޸� front ָ��
	if (Q.rear == p)                // �˴������һ��������
	{
		Q.front = NULL;             // ��ͷ,βָ��ָ��NULL
		Q.rear = NULL;
	}
	free(p);             // �ͷ�
	
	return true;
}



