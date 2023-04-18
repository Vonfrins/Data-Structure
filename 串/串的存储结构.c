#define CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

// 串的顺序存储

// 定长顺序存储表示（静态定义）

#define MAXLEN 255         // 预定义最大串长为255
typedef struct
{
	char ch[MAXLEN];       // 每个分量存储一个字符
	int length;             // 串的实际长度
}SString;


// 堆分配存储表示（动态定义）

typedef struct
{
	char* ch;            // 按串长分配存储区， ch指向串的起始地址
	int length;
}HString;

HString S;
S.ch = (char*)malloc(MAXLEN * sizeof(char));    // 注意： 使用结束后需手动 free 该片存储空间
S.length = 0; 




//串的链式存储

// 每个结点存储一个字符：
typedef struct StringNode
{
	char ch;
	struct StringNode* next;
}StringNode,*String;


// 每个结点存储多个字符
typedef struct StringNode
{
	char ch[10];
	struct StringNode* next;
}StringNode,*String;





// 基本操作（常用举例）

// 1. 求子串 SubString(&Sub,S,pos,len)  
// 用Sub返回串S的第pos个字符起，长度为len的子串

#define MAXLEN 255
typedef struct
{
	char ch[MAXLEN];
	int length;
}SString;


bool SubString(SString& Sub, SString S, int pos, int len)
{
	if (pos + len - 1 > S.length)
		return false;
	for (int i = pos; i < pos + len; i++)
		Sub.ch[i-pos+1] = S.ch[i];
	Sub.length = len;
	return true;
}


// 2.比较字符串的大小 StrCompare(S,T)
// 比较操作，若 S>T,则返回值 >0; 若 S<T,则返回值 <0;若 S=T,则返回值=0；

int StrCompare(SString S, SString T)
{
	for (int i = 1; i <= S.length && i <= T.length; i++)
	{
		if (S.ch[i] != T.ch[i])
			return S.ch[i] - T.ch[i];
	}
	return S.ch[i] - T.ch[i];       // 扫描过的所有字符都相等，则字符串长度更大的串更大
}



// 3.定位操作 Index(S,T)
// 若主串 S 中存在与串T值相同的子串，则返回它在主串S中第一次出现出现的位置；否则返回0；

int Index(SString S, SString T)
{
	int i = 1, n = Strlen(S), m = Strlen(T);
	SString sub;          // 用于暂存子串
	while (i<=n-m+1)
	{
		SubString(sub, S, i, m)
		if (StrCompare(sub, T) != 0)		
			++i;
		else
			return i;        //返回子串在主串中的位置 
	}
	return 0;               // S中不存与T相等的子串
}





