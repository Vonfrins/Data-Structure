#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

// ˳���̬����

// ��̬����ĳ��ȴ�Сһ��ȷ�����Ͳ��ɸı�

#define MAXSIZE 100    //  ����˳������󳤶�
typedef struct
{
	int data[MAXSIZE];      // �þ�̬��"����"�������Ԫ��
	int length;             // ˳���ĵ�ǰ����
}SqList;                    // ˳�������Ͷ��� (��̬ SqList)

// ˳���ľ�̬��ʼ��

void InitList(SqList *L)
{
	L->length = 0;       // ˳���ĳ�ʼ����Ϊ0
}


// ˳���Ķ�̬����

#define InitSize 10      //  ˳���ĳ�ʼ����
typedef struct
{
	int* data;           // ָ��̬���������ָ��
	int MAXSIZE;         // ˳�����������
	int length;          // ˳���ĵ�ǰ����
}SeqList;                // ˳�������Ͷ��� (��̬ SeqList)



// ˳���Ķ�̬��ʼ��

bool InitList(SeqList *L)
{
	//ʹ��malloc��������һƬ�����Ĵ洢�ռ�
	L->data = (int*)malloc(sizeof(int) * InitSize);
	if (L->data == NULL)
		return false;                //�ڴ����ʧ��
	L->length = 0;
	L->MAXSIZE = InitSize;

}

int main()
{
	SeqList L;        // ����һ��˳���L
	InitList(&L);   // ��ʼ��˳��� ����̬�����ڴ�

	return 0;
}