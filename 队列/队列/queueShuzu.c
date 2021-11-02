#define _CRT_SECURE_NO_WARNINGS 1
#include"queueShuzu.h"

void initshuzu(queueShuzu* ps)
{
	ps->arr = (DataType*)malloc(sizeof(DataType)*MAX);
	if (ps->arr == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}
	ps->capacity = MAX;
	ps->size = 0;
	memset(ps->arr,0,sizeof(DataType)*MAX);
}

void print_s(queueShuzu* ps)
{
	if (ps->size == 0)
	{
		printf("¿Õ¶Ó£¡\n");
	}
	else
	{
		int i = 0;
		for (i = 0; i < ps->size; i++)
		{
			printf("%d->", ps->arr[i]);
		}
		printf("\n");
	}

}
queueShuzu* addshuzu(queueShuzu* ps)
{
	ps->capacity = ps->capacity + MAX;
	DataType* tmp = (DataType*)realloc(ps->arr,sizeof(DataType)*ps->capacity);
	if (tmp == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}
	ps->arr = tmp;
}

void shuzupush(queueShuzu* ps, DataType e)
{
	if (ps->size == ps->capacity)
	{
		printf("ÄÚ´æ²»¹»£¡\n");
		addshuzu(ps);
	}
		int i = 0;
		for (i = ps->size-1; i>=0; i--)
		{
			ps->arr[i + 1] = ps->arr[i];
		}
		ps->arr[0] = e;
		ps->size++;

}

void shuzupop(queueShuzu* ps)
{
	ps->size--;
}