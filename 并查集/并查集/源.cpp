#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int find(int x,int pre[])
{
	/*�ǵݹ�*/
	while (pre[x] != x)
		x = pre[x];
	return x;
}

int join(int x, int y, int pre[])
{
	int m = find(x,pre);
	int n = find(y,pre);
	//�ֱ��ҵ����ߵĸ�
	if (m != n);//��������
	pre[x] = y;//����һ��Ϊ����һ���ĸ���
}
