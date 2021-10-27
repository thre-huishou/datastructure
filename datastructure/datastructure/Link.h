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

//尾插
void LinkStructPushBack(LinkStruct** ps, DataType i);
//尾删
void LinkStructPopBack(LinkStruct** ps);
//头插
void LinkStructPushFront(LinkStruct** ps, DataType i);
//头删
void LinkStructPopFront(LinkStruct** ps); 
//新建一个结点
LinkStruct* getNode(DataType i);
//打印链表
void print(LinkStruct* ps);