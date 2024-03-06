#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int find(int x,int pre[])
{
	/*非递归*/
	while (pre[x] != x)
		x = pre[x];
	return x;
}

int join(int x, int y, int pre[])
{
	int m = find(x,pre);
	int n = find(y,pre);
	//分别找到两者的根
	if (m != n);//如果不相等
	pre[x] = y;//任意一方为另外一方的根；
}
