#define CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

// ����˳��洢

// ����˳��洢��ʾ����̬���壩

#define MAXLEN 255         // Ԥ������󴮳�Ϊ255
typedef struct
{
	char ch[MAXLEN];       // ÿ�������洢һ���ַ�
	int length;             // ����ʵ�ʳ���
}SString;


// �ѷ���洢��ʾ����̬���壩

typedef struct
{
	char* ch;            // ����������洢���� chָ�򴮵���ʼ��ַ
	int length;
}HString;

HString S;
S.ch = (char*)malloc(MAXLEN * sizeof(char));    // ע�⣺ ʹ�ý��������ֶ� free ��Ƭ�洢�ռ�
S.length = 0; 




//������ʽ�洢

// ÿ�����洢һ���ַ���
typedef struct StringNode
{
	char ch;
	struct StringNode* next;
}StringNode,*String;


// ÿ�����洢����ַ�
typedef struct StringNode
{
	char ch[10];
	struct StringNode* next;
}StringNode,*String;





// �������������þ�����

// 1. ���Ӵ� SubString(&Sub,S,pos,len)  
// ��Sub���ش�S�ĵ�pos���ַ��𣬳���Ϊlen���Ӵ�

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


// 2.�Ƚ��ַ����Ĵ�С StrCompare(S,T)
// �Ƚϲ������� S>T,�򷵻�ֵ >0; �� S<T,�򷵻�ֵ <0;�� S=T,�򷵻�ֵ=0��

int StrCompare(SString S, SString T)
{
	for (int i = 1; i <= S.length && i <= T.length; i++)
	{
		if (S.ch[i] != T.ch[i])
			return S.ch[i] - T.ch[i];
	}
	return S.ch[i] - T.ch[i];       // ɨ����������ַ�����ȣ����ַ������ȸ���Ĵ�����
}



// 3.��λ���� Index(S,T)
// ������ S �д����봮Tֵ��ͬ���Ӵ����򷵻���������S�е�һ�γ��ֳ��ֵ�λ�ã����򷵻�0��

int Index(SString S, SString T)
{
	int i = 1, n = Strlen(S), m = Strlen(T);
	SString sub;          // �����ݴ��Ӵ�
	while (i<=n-m+1)
	{
		SubString(sub, S, i, m)
		if (StrCompare(sub, T) != 0)		
			++i;
		else
			return i;        //�����Ӵ��������е�λ�� 
	}
	return 0;               // S�в�����T��ȵ��Ӵ�
}





