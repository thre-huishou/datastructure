#define _CRT_SECURE_NO_WARNINGS 1
#include"Recursion2.h"
//��ŵ��

void hannuota(int n, char ch1, char ch2, char ch3)
{
	if (n != 1)
	{
		hannuota(n - 1, ch1, ch3, ch2);
		printf("��%c��%d��%c\n",ch1, n,ch3);
		hannuota(n - 1, ch2, ch1, ch3);
	}
	else
	{
		printf("��%c��%d��%c\n",ch1, n,ch3);
	}

}