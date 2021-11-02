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

//��ʼ��
void initqueue(struct queueLink* ps);
//��ӡ
void print(struct queueLink* ps);
//���ӽ��
queueNode* addNode(DataType e);
//��
void queuepush(struct queueLink* ps, DataType e);
//ɾ
void queuepop(struct queueLink* ps);
//��

//��