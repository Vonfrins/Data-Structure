#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

// ��̬����Ĵ��붨��


// 1.д��һ

#define MAXSIZE 10         // ��̬�������󳤶�
struct Node          // ��̬����Ľṹ���Ͷ���
{
	ElemType data;        // �洢����Ԫ�� 
	int next;             // ��һ��Ԫ�ص������±�  (�α���ָ������ã���������ָ�룡)
};

void testSLinkList()
{
	struct Node a[MAXSIZE];  // a ��һ��Node������
}


// 2.д����

#define MAXSIZE 10;
typedef struct 
{
	ElemType data;
	int next;
}SLinkList[MAXSIZE];


void testSLinkList()
{
	SLinkList a;      // a ��һ����̬����
}




// ��̬����Ļ�������

// 1. ��ʼ����̬����


// 2. ����


// 3. ����λ��Ϊi�Ľ��


// 4. ɾ��ĳ�����