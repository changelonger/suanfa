#pragma once
#define MAX 1000
#include<stdlib.h>
class StaticLinkList
{
public:
	void CreatList(StaticLinkList space[MAX]);//��ʼ����̬����
	void ListInsert(StaticLinkList l[], int i, int e);
	int MallocSSl(StaticLinkList space[]);
	void FreeSSl(StaticLinkList space[],int k);
	void ListDelete(StaticLinkList space[], int i);
	void SetDate(StaticLinkList space[], int e,int i);
	void DiplayList(StaticLinkList space[]);
private:
	
	int date;
	int cur;
	//�±�Ϊ0Ԫ�ص�cur�������汸�������һ��Ԫ�ص��±ꣻ
	//���һ��Ԫ�ص��α��ǵ�һ������Ԫ�ص��±꣬�൱��ͷ��㣻
};

