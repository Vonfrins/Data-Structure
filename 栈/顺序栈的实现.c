#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//  顺序栈的定义

#define MAXSIZE 10      // 定义栈中元素的最大个数
typedef struct
{
	ElemType data[MAXSIZE];      // 静态数组存放栈中元素
	int top;         // 栈顶指针
}SqStack;

// 初始化栈
void InitStack(SqStack &S)
{
	S.top = -1;     // 初始化栈顶指针  (此时定义的栈顶指针指向的是栈顶元素！)
}


// 判断空栈
bool StackEmpty(SqStack& S)
{
	if (S.top == -1)      // 栈空
		return false;
	else                  // 非空
		return true;
}

void testStack()
{
	SqStack S;      // 声明一个顺序栈（分配空间）
	InitStack(S);
	// 后续操作
}




// 进栈操作 （类似“插入”）

//新元素入栈
bool Push(SqStack& S, ElemType x)
{
	if (S.top != MAXSIZE - 1)          // 栈满，无法入栈，报错
		return false;
	S.top = S.top + 1;       // 指针先+1
	S.data[S.top] = x;       // 新元素入栈
		return true;
}

// 47,48两行代码等价于  S.data[++S.top]=x;




// 出栈操作  （类似“删除”）

bool Pop(SqStack &S, ElemType &x)
{
	if (S.top == -1)       // 栈空，无元素可删除，报错
		return false; 
	x = S.data[S.top];     // 栈顶元素先出栈
	S.top = S.top - 1;     // 指针再减1
	return true;
}


// 63,64两行代码等价于   x=S.data[S.top--];




// 读栈顶元素操作  (类似于出栈操作)
bool GetTop(SqStack &S, ElemType &x)
{
	if (S.top == -1)
		return false;
	x = S.data[S.top];             // x记录栈顶元素, 注意此处是与出栈操作的唯一区别（出栈操作有"--"）
	return true;
}





// 共享栈 (两个栈共享同一个存储空间)

#define MAXSIZE 10

typedef struct
{
	ElemType data[MAXSIZE];   // 静态数组存放栈中元素
	int top0;        // 0号栈栈顶指针
	int top1;        // 1号栈栈顶指针
}ShqStack;   //注意此处比顺序栈多了个'h'


// 初始化栈
void InitStack(SqStack &S)
{
	S.top0 = -1;          // 初始化两个栈顶指针
	S.top1 = MAXSIZE;
}

// 共享栈的栈满条件为 top0 + 1= top1;






