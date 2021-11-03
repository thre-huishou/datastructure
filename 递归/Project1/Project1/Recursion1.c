#define _CRT_SECURE_NO_WARNINGS 1
#include"Recursion1.h"

int myadd(int n)
{
	if (n > 1)
	{
		return n + myadd(n - 1);
	}
	else {
		return 1;
	}
}

int jiecheng(int n)
{
	if (n > 1)
	{
		return n * jiecheng(n - 1);
	}
	else
	{
		return 1;
	}
	
}