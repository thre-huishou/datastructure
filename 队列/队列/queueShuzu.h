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

//打印
void print_s(queueShuzu* ps);
//初始化
void initshuzu(queueShuzu* ps);
//扩容
queueShuzu* addshuzu(queueShuzu* ps);
//增
void shuzupush(queueShuzu* ps, DataType e);
//删
void shuzupop(queueShuzu* ps);