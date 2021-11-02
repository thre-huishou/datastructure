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

//³õÊ¼»¯
void initqueue(cyclequeue * ps);

void print(cyclequeue * ps);

//Ôö
void queuepush(cyclequeue * ps, int e);
//É¾
void queuepop(cyclequeue * ps);
