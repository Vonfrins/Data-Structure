#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

// 顺序表静态分配

// 静态分配的长度大小一旦确定，就不可改变

#define MAXSIZE 100    //  定义顺序表的最大长度
typedef struct
{
	int data[MAXSIZE];      // 用静态的"数组"存放数据元素
	int length;             // 顺序表的当前长度
}SqList;                    // 顺序表的类型定义 (静态 SqList)

// 顺序表的静态初始化

void InitList(SqList *L)
{
	L->length = 0;       // 顺序表的初始长度为0
}


// 顺序表的动态分配

#define InitSize 10      //  顺序表的初始长度
typedef struct
{
	int* data;           // 指向动态分配数组的指针
	int MAXSIZE;         // 顺序表的最大容量
	int length;          // 顺序表的当前长度
}SeqList;                // 顺序表的类型定义 (动态 SeqList)



// 顺序表的动态初始化

bool InitList(SeqList *L)
{
	//使用malloc函数申请一片连续的存储空间
	L->data = (int*)malloc(sizeof(int) * InitSize);
	if (L->data == NULL)
		return false;                //内存分配失败
	L->length = 0;
	L->MAXSIZE = InitSize;

}

int main()
{
	SeqList L;        // 声明一个顺序表L
	InitList(&L);   // 初始化顺序表， 并动态分配内存

	return 0;
}