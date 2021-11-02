#define _CRT_SECURE_NO_WARNINGS 1
#include"queueLink.h"

void initqueue(struct queueLink* ps)
{
	ps->rear = (queueNode*)malloc(sizeof(queueNode));
	if (ps->rear == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}
	ps->rear->next = NULL;
	ps->front = ps->rear;
}

void print(struct queueLink* ps)
{
	assert(ps != NULL);
	if (ps->front == ps->rear)
	{
		printf("¿Õ¶Ó!\n");
		return;
	}
	else
	{
		queueNode* tmp = ps->front;
		while (tmp->next != NULL)
		{
			printf("%d->", tmp->i);
			tmp = tmp->next;
		}
		printf("NULL\n");
	}
}

queueNode* addNode(DataType e)
{
	queueNode* newNode = (queueNode*)malloc(sizeof(queueNode));
	if (newNode == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}
	newNode->i = e;
	newNode->next = NULL;
	return newNode;
}

void queuepush(struct queueLink* ps, DataType e)
{
	queueNode* newNode = addNode(e);
	if (ps->front == ps->rear)
	{
		ps->front = newNode;
		newNode->next = ps->rear;
	}
	else
	{
		queueNode* tail = ps->front;
		while (tail->next != ps->rear)
		{
			tail = tail->next;
		}
		tail->next = newNode;
		newNode->next = ps->rear;
	}
}

void queuepop(struct queueLink* ps)
{
	if (ps == NULL)
	{
		printf("¿Õ¶Ó£¡\n");
		return;
	}
	else
	{
		queueNode* tmp = ps->front;
		ps->front = ps->front->next;
		free(tmp);
		tmp = NULL;
	}
}