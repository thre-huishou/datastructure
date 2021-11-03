#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<malloc.h>
#include<stdio.h>

typedef struct BTnode
{
	char data;
	struct BTnode * plchild;
	struct BTnode * prchild;
}BTnode;


BTnode* CreateBtree();
void pretraverseBTree(BTnode* pt);

void intraverseBTree(BTnode* pt);

void posttraverseBTree(BTnode* pt);