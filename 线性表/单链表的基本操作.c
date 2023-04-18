// ������� �������

// 1. ��λ�����  ����ͷ��㣩

typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode, * LinkList;


// �ڵ�i��λ�ò���Ԫ��e ����ͷ��㣩
bool ListInsert(LinkList* L, int i, int e)
{
	if (L == NULL)
		return false;
	if (i < 0)
		return false;

	LNode* p;                    // ָ��pָ��ǰɨ�赽�Ľ��
	int j = 0;                   // ��ǰpָ��ڼ������
	p = L;                       // Lָ��ͷ��㣬ͷ����ǵ�0����㣨�������ݣ�

	while (p != NULL && j < i - 1)     // ѭ���ҵ�Ҫ����λ�õ�ǰ������i-1����㣩
	{
		p = p->next;
		j++;
	}
	if (p == NULL)             // iֵ���Ϸ�
		return false;

	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;              // ��s���ӵ�p֮��

	return true;
}




// 2. ָ�����Ĳ������

// (1) ָ�����ĺ�����

typedef struct LNode
{
	int data;
	struct LNode* next;

}LNode, * LinkList;


// ѭ������
bool ListInsert(LinkList& L, int i, int e)
{
	if (L == NULL)
		return false;
	if (i < 0)
		return false;

	LNode* p;
	int j = 0;
	p = L;

	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}

	return InsertNextNode(p, e);


	//  ������: ��p���֮�����Ԫ��e
	bool InsertNextNode(LNode * p, int e)
	{
		if (p == NULL)
			return false;
		LNode* s = (LNode*)malloc(sizeof(LNode));
		if (s == NULL)         // �ڴ����ʧ��
			return false;

		s->data = e;           // �ý��s��������Ԫ��e
		s->next = p->next;
		p->next = s;           // �����s���ӵ�p֮��

		return true;
	}

}



// (2) ָ������ǰ�����

typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode, * LinkList;


// ѭ������
bool ListInsert(LinkList* L, int i, int e)
{
	if (L == NULL)
		return false;
	if (i < 0)
		return false;

	LNode* p;
	int j = 0;
	p = L;

	while (p != NULL && j < i - 1)
	{
		p == p->next;
		j++;
	}

	//  ?
}


// ǰ��ķ��������֣�

// ��һ�־��Ǵ���ͷָ��:

bool InsertPriorNode(LinkList L, LNode* p, int e)  // �����LinkList L��Ϊ����ͷָ��
{
	// ���ϣ�
}

// �ڶ��ַ���

//ǰ�����: ��p���֮ǰ����Ԫ��e

bool InsertPriorNode(LNode* p, int e)
{
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)             // �ڴ����ʧ��
		return false;

	s->next = p->next;
	p->next = s;               // �½��s���ӵ�p��
	s->data = p->data;         // ��p�е�Ԫ�ظ��Ƶ�s�У�����s���p����ԭ����p�Ľ������Ҫ����Ľ�㣩
	p->data = e;               // p��Ԫ�ظ���Ϊe

	return true;

}








// �������ɾ������

// 1. ��λ��ɾ��   (��ͷ���)

typedef struct LNode
{
	int* data;
	struct LNode* next;

}LNode,*LinkList;


bool InitList(LinkList* L)
{
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL)
		return false;
	L->next = NULL;
	return true;
}


bool ListDelete(LinkList* L,int i,int e)
{
	if (i < 1)
		return false;

	LNode* p;
	int j = 0;
	p = L;
	
	while (p!=NULL && j<i-1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL)             // ɾ����iֵ���Ϸ�
		return false;
	
	if (p->next == NULL)       // ��i-1�����֮������������㣨û�н�����ɾ����
		return false;

	LNode* q = p->next;   // �� q ָ��ɾ�����
	e = q->data;          // �� e ���ر�ɾ��Ԫ�ص�ֵ
	p->next = q->next;    // �� *q ������"�Ͽ�"

	free(q);              // �ͷŽ��Ĵ洢�ռ�

	return true;          // ɾ���ɹ�  

}


// 2. ָ������ɾ��

typedef struct LNode
{
	int* data;
	struct LNode* next;
}LNode,*LinkList;


bool InitList(LinkList* L)
{
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL)
		return false;
	L->next = NULL;
	return true;
}


//  ɾ��ָ����� p
bool DeleteNode(LNode* p)
{
	if (p == NULL)
		return false;
	LNode* q = p->next;             // �� q ָ�� *p �ĺ�̽��
	p->data = q->data;              // �ͺ�̽�㽻��������
	p->next = q->next;              // �� *q ������ "�Ͽ�" 

	free(q);          // �ͷź�̽��Ĵ洢�ռ�

	return true;
}


