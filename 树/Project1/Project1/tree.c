#define _CRT_SECURE_NO_WARNINGS 1
#include"tree.h"


BTnode* CreateBtree()
{
	BTnode* pA = (BTnode*)malloc(sizeof(BTnode));
	BTnode* pB = (BTnode*)malloc(sizeof(BTnode));
	BTnode* pC = (BTnode*)malloc(sizeof(BTnode));
	BTnode* pD = (BTnode*)malloc(sizeof(BTnode));
	BTnode* pE = (BTnode*)malloc(sizeof(BTnode));
	pA->data = 'A';
	pB->data = 'B';
	pC->data = 'C';
	pD->data = 'D';
	pE->data = 'E';

	pA->plchild = pB;
	pA->prchild = pC;
	pB->plchild = pB->prchild = NULL;
	pC->plchild = pD;
	pC->prchild = NULL;
	pD->plchild = NULL;
	pD->prchild = pE;
	pE->plchild = pE->prchild = NULL;
	return pA;
}

void pretraverseBTree(BTnode* pt)
{
	printf("%c", pt->data);
	if (pt->plchild != NULL)
	{
		pretraverseBTree(pt->plchild);
	}
	if (pt->prchild != NULL)
	{
		pretraverseBTree(pt->prchild);
	}
	else
		return;
}

void intraverseBTree(BTnode* pt)
{
	if (pt->plchild != NULL)
	{
		intraverseBTree(pt->plchild);
	}
	printf("%c", pt->data);
	if (pt->prchild != NULL)
	{
		intraverseBTree(pt->prchild);
	}
	else
		return;
}

void posttraverseBTree(BTnode* pt)
{
	if (pt->plchild != NULL)
	{
		posttraverseBTree(pt->plchild);
	}
	if (pt->prchild != NULL)
	{
		posttraverseBTree(pt->prchild);
	}
	printf("%c", pt->data);
	return;
}