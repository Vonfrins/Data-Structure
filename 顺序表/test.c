#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

#define InitSize 10

typedef struct 
{
	int *data;
	int length;
	int MAXSIZE;
}SeqList;


bool InitList(SeqList &L)
{
	L->data = (int*)malloc(sizeof(int) * InitSize);
	if (L->data == NULL)
		return false;
	L->length = 0;
	L->MAXSIZE = InitSize;

	return true;
}


bool ListInsert(SeqList &L, int i, int e)
{
	if (i<1 || i>L->length + 1)
		return false;
	if (L->length >= L->MAXSIZE)
		return false;

	for (int j = L->length; j >=i; j--)
	{
		L->data[j] = L->data[j-1];
	}
	L->data[i-1] = e;
	L ->length++;

	return true;
}


bool ListDelete(SeqList &L, int i, int e)
{
	if (i<i || i>L->length + 1)
		return false;

	e=L->data[i - 1];
	for (int j=i;j<L->length;j++)
	{
		L->data[j-1] = L->data[j];
	}
	L->length--;

	return true;
}


int LocateElem(SeqList& L, int e)
{
	for (int i = 0; i < L->length; i++)
	{
		if (L->data[i] == e)
			return i + 1;
	}
	return 0;
}



int GetElem(SeqList& L, int i)
{
	if (i<1 || i>L->length + 1)
		return 0;
	return L->data[i-1];

}
