#define _CRT_SECURE_NO_WARNINGS 1
#include"tree.h"

int main()
{
	BTnode* pt = CreateBtree();
	//pretraverseBTree(pt);
	//intraverseBTree(pt);
	posttraverseBTree(pt);
	return 0;
}