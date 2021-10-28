#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//输入两个链表，找到两个链表相交的起始结点;另判断两个链表是否相交只需要判断最后元素是否相等。
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

//先跑差值数的结点使两结点同步
struct ListNode *getIntersectionNode(struct ListNode * headA, struct ListNode * headB)
{
	ListNode* curA = headA;
	int la = 0;
	while (curA)//求长度
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

//给定一个链表，判断是否有环；
//设置快慢指针，一个走两一个走1，能够追上，就判断是环。 
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