#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

// 顺序队列的定义
#define MAXSIZE 10       // 定义队列中元素最大个数
typedef struct
{
	ElemType data[MAXSIZE];       // 用静态数组存放队列元素
	int front, rear;              // 定义队头指针和队尾指针
}SqQueue;

void testQueue()
{
	SqQueue Q;          // 声明一个队列（顺序存储）
	//  .......后续操作
}



// 初始化队列
void InitQueue(SqQueue &Q)
{
	Q.front = Q.rear = 0;    // 初始时，队头指针和队尾指针都指向0
}


// 判断队列是否为空
bool QueueEmpty(SqQueue Q)
{
	if (Q.front == Q.rear)  //队空条件
		return true; 
	else
		return false;
}




// 入队操作 (循环队列)
// 注意： 此后操作是以 rear指向队尾元素的下一个位置（下一个因该插入的位置）为基础的

bool QueueEmpty(SqQueue Q)    // 先判断队空
{
	if (Q.rear == Q.front)
		return true;
	else
		return false;
}

bool EnQueue(SqQueue &Q,ElemType i)
{
	if ((Q.rear+1)%MAXSIZE==Q.front)         // 队列已满的条件： 队尾指针的下一个位置是队头
		return false;                  // 队满，无法入队，报错
	Q.data[Q.rear] = i;                // 新元素插入队尾
	Q.rear = (Q.rear + 1) % MAXSIZE;   // 队尾指针+1，取模 (用模运算将存储空间在逻辑上变成“环状”)
	return true;
}



// 出队操作
bool DeQueue(SqQueue &Q, ElemType &i)
{
	if (Q.front==Q.rear)      // 队空，无元素可出队,报错
		return false;
	i = Q.data[Q.front];                       // 用i返回队头指针所指的队头元素
	Q.front = (Q.front + 1) % MAXSIZE;         // 队头指针后移
	return true;
}


// 获得队头元素的值，并用i返回
bool GetHead(SqQueue &Q,int i)
{
	if (Q.front == Q.rear)
		return false;
	i = Q.data[Q.front];
	return true;
}




// 上述算法中，存在一个存储空间被牺牲的现象
// 为了提高利用率 提出两种方法： 1. 增加size变量记录队列长度  2.增加tag = 0/1 来标记最后一次操作是出队/入队


// size方法：（入队成功，size++ ；出对成功，size--）

#define MAXSIZE 10

typedef struct
{
	ElemType data[MAXSIZE];
	int front, rear;
	int size;                // 队列的当前长度
}SqQueue;

// 初始化
void InitQueue(SqQueue &Q)
{
	Q.front = Q.rear = 0;
	Q.size = 0;
}

// 入队
bool EnQueue(SqQueue& Q, int i)
{
	if (Q.size==MAXSIZE)
		return false;
	Q.data[Q.rear] = i;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	Q.size++;
	return true;
}

// 出队
bool DeQueue(SqQueue& Q, int i)
{
	if (Q.size == 0)
		return false;
	i = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	Q.size--;
	return true;
}





// tag方法 ：   (出队成功，tag=0 ； 入队成功，tag=1)

#define MAXSIZE 10

typedef struct
{
	ElemType data[MAXSIZE];
	int front, rear;
	int tag;                    // 最近进行的是插入/删除操作
}SqQueue;


// 队满条件: Q.front==Q.rear && tag=1
// 队空条件: Q.front==Q.rear && tag=0
