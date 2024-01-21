#pragma once
#define MAX 1000
#include<stdlib.h>
class StaticLinkList
{
public:
	void CreatList(StaticLinkList space[MAX]);//初始化静态链表；
	void ListInsert(StaticLinkList l[], int i, int e);
	int MallocSSl(StaticLinkList space[]);
	void FreeSSl(StaticLinkList space[],int k);
	void ListDelete(StaticLinkList space[], int i);
	void SetDate(StaticLinkList space[], int e,int i);
	void DiplayList(StaticLinkList space[]);
private:
	
	int date;
	int cur;
	//下标为0元素的cur用来储存备用链表第一个元素的下标；
	//最后一个元素的游标是第一个插入元素的下标，相当于头结点；
};

