#define _CRT_SECURE_NO_WARNINGS 1
#include"Link.h"




void test()
{
	LinkStruct* head = NULL;
	print(head);
	LinkStructPushBack(&head, 1);
	LinkStructPushBack(&head, 2);
	LinkStructPushBack(&head, 3);
	LinkStructPushBack(&head, 4);
	LinkStructPushBack(&head, 5);
	print(head);
	LinkStructPopBack(&head);
	print(head);
	LinkStructPushFront(&head, 6);
	print(head);
	LinkStructPopFront(&head);
	print(head);
}
int main()
{
	test();
	return 0;
}