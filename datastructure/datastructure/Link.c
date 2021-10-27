#define _CRT_SECURE_NO_WARNINGS 1
#include"Link.h"

//尾插
void LinkStructPushBack(LinkStruct** ps, DataType i)
{
	LinkStruct* tail = *ps;
	LinkStruct* tmp = getNode(i);
	if (*ps == NULL)
	{
		*ps = tmp;
	}
	else
	{
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = tmp;
	}
}


//尾删
void LinkStructPopBack(LinkStruct** ps)
{
	if (*ps == NULL)
	{
		printf("空链表！！\n");
	}
	else
	{
		LinkStruct* prev = NULL;
		LinkStruct* tail = *ps;
		if ((*ps)->next == NULL)
		{
			free((*ps));
			*ps = NULL;
		}
		else
		{
			while (tail->next != NULL)
			{
				prev = tail;
				tail = tail->next;
			}
			free(tail);
			prev->next = NULL;
		}


	}
}


//头插
void LinkStructPushFront(LinkStruct** ps, DataType i)
{
	LinkStruct* tmp = getNode(i);
	if (*ps == NULL)
	{
		*ps = tmp;
	}
	else
	{
		tmp->next = *ps;
		(*ps) = tmp;
	}
}


//头删
void LinkStructPopFront(LinkStruct** ps)
{
	if (*ps == NULL)
	{
		printf("空链表！！\n");
		return;
	}
	else if((*ps)->next==NULL)
	{
		free(*ps);
		(*ps) = NULL;
	}
	else
	{
		LinkStruct * tmp = (*ps)->next;
		free(*ps);
		*ps = NULL;
		*ps = tmp;

	}
}


//新建一个结点
LinkStruct* getNode(DataType i)
{
	LinkStruct * tmp = (LinkStruct*)malloc(sizeof(LinkStruct));
	if (tmp == NULL)
	{
		printf("%s", strerror(errno));
		return 0;
	}
	tmp->e = i;
	tmp->next = NULL;
	return tmp;
}


//打印链表
void print( LinkStruct* ps) 
{
	LinkStruct* tmp = ps;
	if (tmp == NULL)
	{
		printf("空链表！！\n");
	}
	else
	{
		while (tmp->next != NULL)
		{
			printf("%d->", tmp->e);
			tmp = tmp->next;
		}
		printf("%d->NULL\n", tmp->e);
	}
}


//题1：编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
  