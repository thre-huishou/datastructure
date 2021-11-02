#define _CRT_SECURE_NO_WARNINGS 1
#include"cyclequeue.h"

void initqueue(cyclequeue * ps)
{
	ps->arr = (int*)malloc(sizeof(int)*N);
	if (ps->arr == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}
	ps->front = 0;
	ps->rear = 0;

}

void print(cyclequeue * ps) 
{
	assert(ps != NULL);
	if (ps->front == ps->rear)
	{
		printf("¿Õ¶Ó£¡£¡\n");
		return;
	}
	int i = ps->front;
	while (i != ps->rear)
	{
		printf("%d<-", ps->arr[i]);
		if (i < N-1)
		{
			i++;
		}
		else
		{
			i = (i + 1) % N;
		}
	}
	printf("\n");
}

void queuepush(cyclequeue * ps, int e)
{
	if ((ps->rear + 1) % N == ps->front)
	{
		printf("¶ÓÂú£¡£¡\n");
		return;
	}
	else
	{
		ps->arr[ps->rear] = e;
		if (ps->rear < N-1)
		{
			ps->rear++;
		}
		else
		{
			ps->rear = (ps->rear + 1) % N;
		}
	}
}

void queuepop(cyclequeue * ps)
{
	if (ps->front == ps->rear)
	{
		printf("¿Õ¶Ó£¡");
		return;
	}
	if (ps->front < N - 1)
	{
		ps->front++;
	}
	else
	{
		ps->front = (ps->front + 1) % N;
	}

}