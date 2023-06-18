#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

typedef struct DNode
{
	int data;
	struct DNode* prior, * next;

}DNode,*DLinkList;


//  ˫����Ĳ������


// ��p���֮�����s���
bool InsertNextDNode(DNode* p, DNode* s)
{
	if (p = NULL || s = NULL)        // �Ƿ�����
		return false;
	s->next = p->next;
	
	if (p->next != NULL)            // ���p����к�̽��
		p->next->prior = s;

	s->prior = p;
	p->next = s;

	return true;
}




//  ˫�����ɾ������


//ɾ��p���ĺ�̽��
bool DeleteNextDNode(DNode* p)
{
	if (p == NULL)
		return false;
	DNode* q = p->next;          // �ҵ� p �ĺ�̽�� q
	if (q == NULL)
		return false;            // p û�к��

	p->next = q->next;
	if (q->next != NULL)         // q ��㲻�����һ�����
		q->next->prior = p;

	free(q);             // �ͷŽ��ռ�

	return true; 
		
}




// ˫���������

void DestroyList(DLinkList *L)
{
	// ѭ���ͷŸ������ݽ��
	while (L->next != NULL)
		DeleteNextDNode(L);
	free(L);                        // �ͷ�ͷ���
	L = NULL;                       // ͷָ��ָ��NULL

}





// ˫����ı���

// �������

while (p != NULL)
{
	// �Խ��p ������Ӧ����
	p = p->next;
}


// ǰ�����

  // 1.����ͷ���
while (p != NULL)
{
	// �Խ��p������Ӧ����
	p = p->prior;
}

  // 2. ����ͷ���
while (p->prior != NULL)
{
	// �Խ��p������Ӧ����
	p = p->prior;
}






