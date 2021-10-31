#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//��дһ���������������ǽ�������ַ�����ת�����������ַ������ַ����� s ����ʽ������
//��Ҫ�����������������Ŀռ䣬�����ԭ���޸��������顢ʹ�� O(1) �Ķ���ռ�����һ���⡣

//������ⷨ
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

//����һ���ַ���������Ҫ��ת�ַ�����ÿ�����ʵ��ַ�˳��ͬʱ�Ա����ո�͵��ʵĳ�ʼ˳��
//˫ָ�뷨
char * reverseWords(char * s) {
	//˫ָ��
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
//����һ��ͷ���Ϊ head �ķǿյ���������������м��㡣

//����������м��㣬�򷵻صڶ����м��㡣
//Ӳ��
struct ListNode* middleNode(struct ListNode* head) {
	struct ListNode* tail = head;//��������Ԫ�ظ���
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
//����ָ��
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

//����һ������ɾ������ĵ����� n ����㣬���ҷ��������ͷ��㡣
//���ף����ܳ���ʹ��һ��ɨ��ʵ����
//�ȼ�����������ҵ�Ŀ��Ԫ�أ�ɾ���ڷ���
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

//����ָ�룬�������n��
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