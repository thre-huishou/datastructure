#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<malloc.h>
#include<errno.h>

#define N 6

typedef struct cyclequeue
{
	int* arr;
	int front;
	int rear;
}cyclequeue;

//��ʼ��
void initqueue(cyclequeue * ps);

void print(cyclequeue * ps);

//��
void queuepush(cyclequeue * ps, int e);
//ɾ
void queuepop(cyclequeue * ps);
