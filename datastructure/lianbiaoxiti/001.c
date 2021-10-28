#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//�������������ҵ����������ཻ����ʼ���;���ж����������Ƿ��ֻཻ��Ҫ�ж����Ԫ���Ƿ���ȡ�
struct ListNode *getIntersectionNode(struct ListNode * headA, struct ListNode * headB)
{
	assert(headA == NULL);
	assert(headB == NULL);
	struct ListNode* tmpA = headA;
	struct ListNode* tmpB = headB;
	while (tmpA != NULL)
	{
		while (tmpB != tmpA && tmpB != NULL)
		{
			tmpB = tmpB->next;
		}
		if (tmpB == tmpA)
		{
			return tmpA->DATA;
		}
		tmpA = tmpA->next;
		tmpB = headB;
	}
	return  null;
}

//���ܲ�ֵ���Ľ��ʹ�����ͬ��
struct ListNode *getIntersectionNode(struct ListNode * headA, struct ListNode * headB)
{
	ListNode* curA = headA;
	int la = 0;
	while (curA)//�󳤶�
	{
		++la;
		curA = curA->next;
	}
	ListNode* curB = headB;
	int lb = 0;
	while (curB)
	{
		++lb;
		curB = curB->next;
	}
	ListNode* longList = headA;
	ListNode* shortList = headB;
	if (la < lb)
	{
		longList = headB;
		shortList = headA;
	}
	int gap = abs(la - lb);
	while (gap--)
	{
		longList = longList->next;
	}
	while (longList)
	{
		if (longList == shortList)
		{
			return longList;
		}
		longList = longList->next;
		shortList = shortList->next;
	}
	return null;
}

//����һ�������ж��Ƿ��л���
//���ÿ���ָ�룬һ������һ����1���ܹ�׷�ϣ����ж��ǻ��� 
struct listnode *setectcycle(struct listnode * head)
{
	struct lisnode* slow, *fast;
	slow = fast = head;
	while (fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
		{
			break;
		}
	}
	if (fast ==NULL||fast->next==NULL)
	{
		return NULL;
	}
	struct listnode* meet = fast;
	while (head != meet)
	{
		head = head->next;
		meet = meet->next; 
	}
	return meet;
}