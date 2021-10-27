#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<memory.h>
#include<errno.h>
#include<malloc.h>
#include<string.h>

typedef int DataType;


typedef struct LinkStruct
{
	DataType e;
	struct LinkStruct * next;
}LinkStruct;

//β��
void LinkStructPushBack(LinkStruct** ps, DataType i);
//βɾ
void LinkStructPopBack(LinkStruct** ps);
//ͷ��
void LinkStructPushFront(LinkStruct** ps, DataType i);
//ͷɾ
void LinkStructPopFront(LinkStruct** ps); 
//�½�һ�����
LinkStruct* getNode(DataType i);
//��ӡ����
void print(LinkStruct* ps);