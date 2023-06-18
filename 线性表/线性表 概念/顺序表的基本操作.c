#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>


// 顺序表的基本操作



// 顺序表的插入操作

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



bool ListIsert(SeqList* L,int i,int e)        // 这里的i是指顺序表中第i个元素
{
	if (i<1 || i>L->length + 1)       
		return false;                // 插入位置不合法

	if (L->length >= L->MAXSIZE)
		return false;                // 顺序表已存满，无空位可供插入
	for (int j=L->length;j>=i;j--)
	{
		L->data[j] = L->data[j-1];   // 将插入元素后面的元素全部右移
	}
	L->data[i-1] = e;                // 将新元素插入到空出来的位置
	L->length++;                     // 顺序表长度增加1

	return true;

}






// 顺序表的删除操作

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

// 删除操作

bool ListDelete(SeqList* L,int i)
{
	if (i<1 || i>L->length + 1)
		return false;                         // 删除位置不合法

	for (int j = i; j < L->length; j++)
	{
		L->data[j-1] = L->data[j];            // 将被删除元素后面的所有元素前移
	}
	L->length--;                              // 顺序表长度减1

	return true;
}








// 顺序表的查找


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


// 按值查找

//在顺序表L中查找第一个元素值等于e的元素，并返回其位序
int LocateElem(SeqList* L, int e)
{
	for (int i = 0; i < L->length; i++)
	{
		if (L->data[i] == e)
			return i + 1;            // 数组下表为i的元素值等于e ，返回其位序 i+1
	}
	return 0;                        // 退出循环，说明未找到元素

}



// 按位查找

ElemType GetElem(SeqList* L, int i)
{
	if (i<1 || i>L->length)
		return 0;                     // 查找位置不合法
	return L->data[i-1];      // 返回第i个位置上的元素值
}


