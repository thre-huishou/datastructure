#define _CRT_SECURE_NO_WARNINGS 1
#include"cyclequeue.h"


int main()
{
	cyclequeue s;
	initqueue(&s);
	print(&s);
	queuepush(&s, 1);
	print(&s);
	queuepush(&s, 2);
	print(&s);
	queuepush(&s, 3);
	print(&s);
	queuepush(&s, 4);
	print(&s);
	queuepush(&s, 5);
	print(&s);
	queuepush(&s, 6);
	print(&s);
	queuepop(&s);
	print(&s);
	queuepop(&s);
	print(&s);
	queuepop(&s);
	print(&s);
	queuepop(&s);
	print(&s);
	queuepush(&s, 6);
	print(&s);
	queuepush(&s, 5);
	print(&s);
}