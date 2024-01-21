#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"Node.h"
#include<stdlib.h> 
int main()
{
	Node Linklist;
	Node** l = (Node**)malloc(sizeof(Node**));
	int* e =(int*) malloc(sizeof(int*));
	int n; scanf("%d", &n);
	Linklist.CreateList(l, n);
	Linklist.GetElem(*l, n -1, e);
	printf("%d\n", *e);
	Linklist.DisplayList(l, n);
	return 0;
}