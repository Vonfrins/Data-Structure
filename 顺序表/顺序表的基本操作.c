#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>


// ˳���Ļ�������



// ˳���Ĳ������

#define InitSize 10

typedef struct
{
	int* data;
	int length;
	int MAXSIZE;

}SeqList;


bool InitList(SeqList* L)
{
	L->data = (int*)malloc(sizeof(int) * InitSize);
	if (L->data == NULL)
		return false;

	L->length = 0;
	L->MAXSIZE = InitSize;


}



bool ListIsert(SeqList* L,int i,int e)        // �����i��ָ˳����е�i��Ԫ��
{
	if (i<1 || i>L->length + 1)       
		return false;                // ����λ�ò��Ϸ�

	if (L->length >= L->MAXSIZE)
		return false;                // ˳����Ѵ������޿�λ�ɹ�����
	for (int j=L->length;j>=i;j--)
	{
		L->data[j] = L->data[j-1];   // ������Ԫ�غ����Ԫ��ȫ������
	}
	L->data[i-1] = e;                // ����Ԫ�ز��뵽�ճ�����λ��
	L->length++;                     // ˳���������1

	return true;

}






// ˳����ɾ������

#define InitSize 10

typedef struct
{
	int* data;
	int length;
	int MAXSIZE;

}SeqList;


bool InitList(SeqList* L)
{
	L->data = (int*)malloc(InitSize * sizeof(int));
	if (L->data == NULL)
		return false;
	L->length = 0;
	L->MAXSIZE = InitSize;

}

// ɾ������

bool ListDelete(SeqList* L,int i)
{
	if (i<1 || i>L->length + 1)
		return false;                         // ɾ��λ�ò��Ϸ�

	for (int j = i; j < L->length; j++)
	{
		L->data[j-1] = L->data[j];            // ����ɾ��Ԫ�غ��������Ԫ��ǰ��
	}
	L->length--;                              // ˳����ȼ�1

	return true;
}








// ˳���Ĳ���


#define InitSize 10

typedef struct
{
	int* data;
	int length;
	int MAXSIZE;

}SeqList;

bool InitList(SeqList* L)
{
	L->data = (int*)malloc(sizeof(int) * InitSize);
	if (L->data == NULL)
		return false;

	L->length = 0;
	L->MAXSIZE = InitSize;

}


// ��ֵ����

//��˳���L�в��ҵ�һ��Ԫ��ֵ����e��Ԫ�أ���������λ��
int LocateElem(SeqList* L, int e)
{
	for (int i = 0; i < L->length; i++)
	{
		if (L->data[i] == e)
			return i + 1;            // �����±�Ϊi��Ԫ��ֵ����e ��������λ�� i+1
	}
	return 0;                        // �˳�ѭ����˵��δ�ҵ�Ԫ��

}



// ��λ����

ElemType GetElem(SeqList* L, int i)
{
	if (i<1 || i>L->length)
		return 0;                     // ����λ�ò��Ϸ�
	return L->data[i-1];      // ���ص�i��λ���ϵ�Ԫ��ֵ
}


