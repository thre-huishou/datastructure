#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<malloc.h>
#include<memory.h>
#define MAX 3
typedef int DataType;

typedef struct queueShuzu
{
	DataType * arr;
	int capacity;
	int size;
}queueShuzu;

//��ӡ
void print_s(queueShuzu* ps);
//��ʼ��
void initshuzu(queueShuzu* ps);
//����
queueShuzu* addshuzu(queueShuzu* ps);
//��
void shuzupush(queueShuzu* ps, DataType e);
//ɾ
void shuzupop(queueShuzu* ps);