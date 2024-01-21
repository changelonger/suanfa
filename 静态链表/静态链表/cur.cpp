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
	int i = space[0].cur;//找到备用链表第一个元素的下标
	if (space[0].cur)
		space[0].cur = space[i].cur;//把第一个元素的游标变成备用链表第二个元素的下标；
	return i;
	
}
void StaticLinkList::ListInsert(StaticLinkList space[], int i, int e)
{
	int j, k, l;
	k = MAX - 1;//k是最大的下标，因为它的游标是1
	j = MallocSSl(space);//找到备用链表第一个元素的下标
	space[j].date = e;//给这个新元素赋值
	for (l = 1; l < i; l++)
	{
		k = space[k].cur;//从游标1开始。找到想要插入的位置，类似节点，每次都指向下一个。
	}
	space[j].cur = space[k].cur;//把想要插入的位置之前的游标给新元素的游标，让新元素指向前面元素所指向的位置
	//
	space[k].cur = j;//前面的元素指向新元素；
	space[0].date++;

}
void StaticLinkList::FreeSSl(StaticLinkList space[],int k)
{
	space[k].cur = space[0].cur;//第一个元素所指向的位置给要删除的元素
	space[0].cur = k;//第一个元素的指向要删除的元素
	//这样做的目的是把备用链表的第一个是删除的元素。
}
void StaticLinkList::ListDelete(StaticLinkList space[], int i)
{
	int j, k;
	k = MAX - 1;
	for (j = 1; j <= i - 1; j++)
	{
		k = space[k].cur;
	}//k是要删除的元素的前一个元素
	j = space[k].cur;//要删除的元素的下标
	space[k].cur = space[j].cur;//要删除的元素的cur，就是后面元素的下标给他前面元素的cur；
	FreeSSl(space, j);//释放j；
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