// 单链表的 插入操作

// 1. 按位序插入  （带头结点）

typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode, * LinkList;


// 在第i个位置插入元素e （带头结点）
bool ListInsert(LinkList& L, int i, int e)
{
	if (L == NULL)
		return false;
	if (i < 0)
		return false;
	LNode* p;                    // 指针p指向当前扫描到的结点
	int j = 0;                   // 当前p指向第几个结点
	p = L;                       // L指向头结点，头结点是第0个结点（不存数据）
	while (p != NULL && j < i - 1)     // 循环找到要插入位置的前驱（第i-1个结点）
	{
		p = p->next;
		j++;
	}
	if (p == NULL)             // i值不合法
		return false;

	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;              // 将s连接到p之后

	return true;
}




// 指定结点的插入操作

// 1. 指定结点的后插操作

typedef struct LNode
{
	int data;
	struct LNode* next;

}LNode, * LinkList;


// 循环过程
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


	//  后插操作: 在p结点之后插入元素e
	bool InsertNextNode(LNode * p, int e)
	{
		if (p == NULL)
			return false;
		LNode* s = (LNode*)malloc(sizeof(LNode));
		if (s == NULL)         // 内存分配失败
			return false;

		s->data = e;           // 用结点s保存数据元素e
		s->next = p->next;
		p->next = s;           // 将结点s连接到p之后

		return true;
	}

}



// 2. 指定结点的前插操作

typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode, * LinkList;


// 循环过程
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
		p == p->next;
		j++;
	}

	//  ?
}


// 前插的方法有两种：

// 第一种就是传入头指针:

bool InsertPriorNode(LinkList L, LNode* p, int e)  // 加入的LinkList L即为传入头指针
{
	// 综上；
}

// 第二种方法

//前插操作: 在p结点之前插入元素e

bool InsertPriorNode(LNode* p, int e)
{
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)             // 内存分配失败
		return false;

	s->next = p->next;
	p->next = s;               // 新结点s链接到p后
	s->data = p->data;         // 将p中的元素复制到s中，（将s变成p，将原本存p的结点变成需要插入的结点）
	p->data = e;               // p中元素覆盖为e

	return true;

}