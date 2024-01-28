#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"Node.h"
#include<stdlib.h> 
int main()
{
	Node*p= (Node*)malloc(sizeof(Node*));
	 int n; scanf("%d", &n);
	 p->CreateList(&p, n);
	 p->DisplayList(&p, n);
	 printf("\n%d", p->ListLenth(p));
	return 0;
}