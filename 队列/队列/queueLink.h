#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<malloc.h>
#include<assert.h>

typedef int DataType;

typedef struct queueNode
{
	DataType i;
	struct queueNode * next;
}queueNode;

typedef struct queueLink
{
	queueNode* front;
	queueNode* rear;
}queueLink;

//初始化
void initqueue(struct queueLink* ps);
//打印
void print(struct queueLink* ps);
//增加结点
queueNode* addNode(DataType e);
//增
void queuepush(struct queueLink* ps, DataType e);
//删
void queuepop(struct queueLink* ps);
//查

//改