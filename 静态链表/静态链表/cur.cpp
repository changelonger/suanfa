#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"cur.h"
void StaticLinkList:: CreatList(StaticLinkList space[MAX])
{
	int i;
	for (i = 0; i < MAX - 1; i++)
	{
		space[i].cur = i + 1;
	}
	space[MAX - 1].cur = 0;
}
int StaticLinkList::MallocSSl(StaticLinkList space[])
{
	int i = space[0].cur;//�ҵ����������һ��Ԫ�ص��±�
	if (space[0].cur)
		space[0].cur = space[i].cur;//�ѵ�һ��Ԫ�ص��α��ɱ�������ڶ���Ԫ�ص��±ꣻ
	return i;
	
}
void StaticLinkList::ListInsert(StaticLinkList space[], int i, int e)
{
	int j, k, l;
	k = MAX - 1;//k�������±꣬��Ϊ�����α���1
	j = MallocSSl(space);//�ҵ����������һ��Ԫ�ص��±�
	space[j].date = e;//�������Ԫ�ظ�ֵ
	for (l = 1; l < i; l++)
	{
		k = space[k].cur;//���α�1��ʼ���ҵ���Ҫ�����λ�ã����ƽڵ㣬ÿ�ζ�ָ����һ����
	}
	space[j].cur = space[k].cur;//����Ҫ�����λ��֮ǰ���α����Ԫ�ص��α꣬����Ԫ��ָ��ǰ��Ԫ����ָ���λ��
	//
	space[k].cur = j;//ǰ���Ԫ��ָ����Ԫ�أ�
	space[0].date++;

}
void StaticLinkList::FreeSSl(StaticLinkList space[],int k)
{
	space[k].cur = space[0].cur;//��һ��Ԫ����ָ���λ�ø�Ҫɾ����Ԫ��
	space[0].cur = k;//��һ��Ԫ�ص�ָ��Ҫɾ����Ԫ��
	//��������Ŀ���ǰѱ�������ĵ�һ����ɾ����Ԫ�ء�
}
void StaticLinkList::ListDelete(StaticLinkList space[], int i)
{
	int j, k;
	k = MAX - 1;
	for (j = 1; j <= i - 1; j++)
	{
		k = space[k].cur;
	}//k��Ҫɾ����Ԫ�ص�ǰһ��Ԫ��
	j = space[k].cur;//Ҫɾ����Ԫ�ص��±�
	space[k].cur = space[j].cur;//Ҫɾ����Ԫ�ص�cur�����Ǻ���Ԫ�ص��±����ǰ��Ԫ�ص�cur��
	FreeSSl(space, j);//�ͷ�j��
	space[0].date--;
}
void StaticLinkList::SetDate(StaticLinkList space[], int e,int i)
{
	space[i].date = e;
	space[0].date++;
}
void StaticLinkList::DiplayList(StaticLinkList space[])
{
	int i = MAX - 1; int j = 0;
	while(j<space[0].date)
	{
		printf("%d %d\n", space[i].date, space[i].cur);
		i = space[i].cur; 
		j++;
	}
}