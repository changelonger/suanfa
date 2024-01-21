#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"cur.h"
int main()
{
	StaticLinkList L[MAX];
	L->CreatList(L);
	int n = 0; scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		L[i].SetDate(L, i, i);
	}
	L->DiplayList(L);
	return 0;
}