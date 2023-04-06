#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//  ˳��ջ�Ķ���

#define MAXSIZE 10      // ����ջ��Ԫ�ص�������
typedef struct
{
	ElemType data[MAXSIZE];      // ��̬������ջ��Ԫ��
	int top;         // ջ��ָ��
}SqStack;

// ��ʼ��ջ
void InitStack(SqStack &S)
{
	S.top = -1;     // ��ʼ��ջ��ָ��  (��ʱ�����ջ��ָ��ָ�����ջ��Ԫ�أ�)
}


// �жϿ�ջ
bool StackEmpty(SqStack& S)
{
	if (S.top == -1)      // ջ��
		return false;
	else                  // �ǿ�
		return true;
}

void testStack()
{
	SqStack S;      // ����һ��˳��ջ������ռ䣩
	InitStack(S);
	// ��������
}




// ��ջ���� �����ơ����롱��

//��Ԫ����ջ
bool Push(SqStack& S, ElemType x)
{
	if (S.top != MAXSIZE - 1)          // ջ�����޷���ջ������
		return false;
	S.top = S.top + 1;       // ָ����+1
	S.data[S.top] = x;       // ��Ԫ����ջ
		return true;
}

// 47,48���д���ȼ���  S.data[++S.top]=x;




// ��ջ����  �����ơ�ɾ������

bool Pop(SqStack &S, ElemType &x)
{
	if (S.top == -1)       // ջ�գ���Ԫ�ؿ�ɾ��������
		return false; 
	x = S.data[S.top];     // ջ��Ԫ���ȳ�ջ
	S.top = S.top - 1;     // ָ���ټ�1
	return true;
}


// 63,64���д���ȼ���   x=S.data[S.top--];




// ��ջ��Ԫ�ز���  (�����ڳ�ջ����)
bool GetTop(SqStack &S, ElemType &x)
{
	if (S.top == -1)
		return false;
	x = S.data[S.top];             // x��¼ջ��Ԫ��, ע��˴������ջ������Ψһ���𣨳�ջ������"--"��
	return true;
}





// ����ջ (����ջ����ͬһ���洢�ռ�)

#define MAXSIZE 10

typedef struct
{
	ElemType data[MAXSIZE];   // ��̬������ջ��Ԫ��
	int top0;        // 0��ջջ��ָ��
	int top1;        // 1��ջջ��ָ��
}ShqStack;   //ע��˴���˳��ջ���˸�'h'


// ��ʼ��ջ
void InitStack(SqStack &S)
{
	S.top0 = -1;          // ��ʼ������ջ��ָ��
	S.top1 = MAXSIZE;
}

// ����ջ��ջ������Ϊ top0 + 1= top1;






