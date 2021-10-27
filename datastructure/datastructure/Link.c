#define _CRT_SECURE_NO_WARNINGS 1
#include"Link.h"

//β��
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


//βɾ
void LinkStructPopBack(LinkStruct** ps)
{
	if (*ps == NULL)
	{
		printf("��������\n");
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


//ͷ��
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


//ͷɾ
void LinkStructPopFront(LinkStruct** ps)
{
	if (*ps == NULL)
	{
		printf("��������\n");
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


//�½�һ�����
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


//��ӡ����
void print( LinkStruct* ps) 
{
	LinkStruct* tmp = ps;
	if (tmp == NULL)
	{
		printf("��������\n");
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


//��1����д���룬�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ
  