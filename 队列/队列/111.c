#define _CRT_SECURE_NO_WARNINGS 1
//#include"queueLink.h"
#include"queueShuzu.h"

int main()
{
	//链表队
	//struct queueLink s ;
	//initqueue(&s);
	//print(&s);
	//queuepush(&s, 1);
	//queuepush(&s, 2);
	//queuepush(&s, 3);
	//queuepush(&s, 4);
	//print(&s);
	//queuepop(&s);
	//queuepop(&s);
	//print(&s);

	//数组队
	queueShuzu s;
	initshuzu(&s);
	print_s(&s);
	shuzupush(&s, 1);
	shuzupush(&s, 2);
	shuzupush(&s, 3);
	shuzupush(&s, 4);
	print_s(&s);
	shuzupop(&s);
	shuzupop(&s);
	print_s(&s);
	return 0;
}