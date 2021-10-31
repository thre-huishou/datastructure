#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
//不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

//暴力求解法
void reverseString(char* s, int sSize) {
	if (s == NULL)
	{
		return;
	}
	char tmp = 0;
	int left = 0, right = sSize - 1;
	while (left < right)
	{
		tmp = s[left];
		s[left] = s[right];
		s[right] = tmp;
		left++;
		right--;
	}

}

//给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
//双指针法
char * reverseWords(char * s) {
	//双指针
	int first = 0, second = 0;
	while (s[second] != '\0')
	{
		while (s[second] != ' '&&s[second] != '\0')
		{
			second++;
		}
		int right = second - 1, left = first;
		while (left < right)
		{
			char tmp = s[left];
			s[left] = s[right];
			s[right] = tmp;
			right--;
			left++;

		}
		if (s[second] == '\0')
		{
			return s;
		}
		else
			first = ++second;
	}
	return s;
}
//给定一个头结点为 head 的非空单链表，返回链表的中间结点。

//如果有两个中间结点，则返回第二个中间结点。
//硬算
struct ListNode* middleNode(struct ListNode* head) {
	struct ListNode* tail = head;//计算链表元素个数
	int i = 1;
	while (tail->next != NULL)
	{
		i++;
		tail = tail->next;
	}
	if (i % 2 == 0)
	{
		i = i / 2 + 1;
	}
	else
	{
		i = (i + 1) / 2;;
	}
	int j = 1;
	tail = head;
	for (j = 1; j < i; j++)
	{
		tail = tail->next;
	}
	head = tail;
	return head;
}
//快慢指针
struct ListNode* middleNode(struct ListNode* head) {
	struct ListNode* fast = head, *slow = head;
	while (fast->next != NULL)
	{
		if (fast->next->next != NULL)
		{
			fast = fast->next->next;
		}
		else
		{
			fast = fast->next;
		}
		slow = slow->next;
	}
	head = slow;
	return head;
}

//给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
//进阶：你能尝试使用一趟扫描实现吗？
//先计算链表个数找到目标元素，删除在返回
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	struct ListNode* tail = head;
	struct ListNode* prev = head;
	int len = 1;
	while (tail->next != NULL)
	{
		tail = tail->next;
		len++;
	}
	len = len - n + 1;
	tail = head;
	int i = 1;
	while (i < len)
	{
		prev = tail;
		tail = tail->next;
		i++;
	}
	if (i == 1)
	{
		head = tail->next;
	}
	else
	{
		prev->next = tail->next;
		free(tail);
		tail = NULL;
	}
	return head;
}

//快慢指针，快的先走n步
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	struct ListNode* fast = head, *slow = head;
	struct ListNode* prev = slow;
	while (--n)
	{
		fast = fast->next;
	}
	while (fast->next != NULL)
	{
		fast = fast->next;
		prev = slow;
		slow = slow->next;
	}
	if (prev == slow)
	{
		head = slow->next;
		free(slow);
		slow = NULL;
	}
	else
	{
		prev->next = slow->next;
		free(slow);
		slow = NULL;
	}
	return head;

}




int main()
{
	char s[]="Let's take LeetCode contest";
	reverseWords(s);
	printf("%s\n", s);
	return 0;
}