#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

// ˳����еĶ���
#define MAXSIZE 10       // ���������Ԫ��������
typedef struct
{
	ElemType data[MAXSIZE];       // �þ�̬�����Ŷ���Ԫ��
	int front, rear;              // �����ͷָ��Ͷ�βָ��
}SqQueue;

void testQueue()
{
	SqQueue Q;          // ����һ�����У�˳��洢��
	//  .......��������
}



// ��ʼ������
void InitQueue(SqQueue &Q)
{
	Q.front = Q.rear = 0;    // ��ʼʱ����ͷָ��Ͷ�βָ�붼ָ��0
}


// �ж϶����Ƿ�Ϊ��
bool QueueEmpty(SqQueue Q)
{
	if (Q.front == Q.rear)  //�ӿ�����
		return true; 
	else
		return false;
}




// ��Ӳ��� (ѭ������)
// ע�⣺ �˺�������� rearָ���βԪ�ص���һ��λ�ã���һ����ò����λ�ã�Ϊ������

bool QueueEmpty(SqQueue Q)    // ���ж϶ӿ�
{
	if (Q.rear == Q.front)
		return true;
	else
		return false;
}

bool EnQueue(SqQueue &Q,ElemType i)
{
	if ((Q.rear+1)%MAXSIZE==Q.front)         // ���������������� ��βָ�����һ��λ���Ƕ�ͷ
		return false;                  // �������޷���ӣ�����
	Q.data[Q.rear] = i;                // ��Ԫ�ز����β
	Q.rear = (Q.rear + 1) % MAXSIZE;   // ��βָ��+1��ȡģ (��ģ���㽫�洢�ռ����߼��ϱ�ɡ���״��)
	return true;
}



// ���Ӳ���
bool DeQueue(SqQueue &Q, ElemType &i)
{
	if (Q.front==Q.rear)      // �ӿգ���Ԫ�ؿɳ���,����
		return false;
	i = Q.data[Q.front];                       // ��i���ض�ͷָ����ָ�Ķ�ͷԪ��
	Q.front = (Q.front + 1) % MAXSIZE;         // ��ͷָ�����
	return true;
}


// ��ö�ͷԪ�ص�ֵ������i����
bool GetHead(SqQueue &Q,int i)
{
	if (Q.front == Q.rear)
		return false;
	i = Q.data[Q.front];
	return true;
}




// �����㷨�У�����һ���洢�ռ䱻����������
// Ϊ����������� ������ַ����� 1. ����size������¼���г���  2.����tag = 0/1 ��������һ�β����ǳ���/���


// size����������ӳɹ���size++ �����Գɹ���size--��

#define MAXSIZE 10

typedef struct
{
	ElemType data[MAXSIZE];
	int front, rear;
	int size;                // ���еĵ�ǰ����
}SqQueue;

// ��ʼ��
void InitQueue(SqQueue &Q)
{
	Q.front = Q.rear = 0;
	Q.size = 0;
}

// ���
bool EnQueue(SqQueue& Q, int i)
{
	if (Q.size==MAXSIZE)
		return false;
	Q.data[Q.rear] = i;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	Q.size++;
	return true;
}

// ����
bool DeQueue(SqQueue& Q, int i)
{
	if (Q.size == 0)
		return false;
	i = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	Q.size--;
	return true;
}





// tag���� ��   (���ӳɹ���tag=0 �� ��ӳɹ���tag=1)

#define MAXSIZE 10

typedef struct
{
	ElemType data[MAXSIZE];
	int front, rear;
	int tag;                    // ������е��ǲ���/ɾ������
}SqQueue;


// ��������: Q.front==Q.rear && tag=1
// �ӿ�����: Q.front==Q.rear && tag=0
