#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int a;
	int b;
	node* next;
}; 
typedef node* list;
list CreatLink();
list Sum(list L1, list L2);
list Mut(list L1, list L2);
void print(list L);
int Compare(int a, int b);
int compare(int a, int b);
int main()
{
	list L1 = CreatLink();
	list L2 = CreatLink();
	list L = NULL;
	L = Mut(L1, L2);
	print(L);
	
	L = Sum(L1, L2);
	print(L);
	return 0;
}
int compare(int a, int b)
{
	if (a > b)
		return 1;
	else if (a < b)
		return -1;
	else
		return 0;
}
list CreatLink()
{
	int n; scanf("%d", &n);
	list l = (list)malloc(sizeof(node));
	l->a = n;
	list front = l;
	for (int i = 0; i < n; i++)
	{
		list p = (list)malloc(sizeof(node));
		int a, b;
		scanf("%d%d", &a,&b);
		p->a = a;
		p->b = b;
		p->next = NULL;
		l->next = p;
		l = p;
	}
	l = front;
	return l;
}
void attach(int a, int b, list* l)
{
	list p = (list)malloc(sizeof(node));
	p->a = a;
	p->b = b;
	p->next = NULL;
	(*l)->next = p;
	(*l) = p;
}
list Sum(list L1, list L2)
{
	list p1 = L1->next;
	list p2 = L2->next;
	list L = (list)malloc(sizeof(node));
	list temp = L;
	while (p1 && p2) 
	{
		switch (compare(p1->b, p2->b)) 
		{
		case 1:
			attach(p1->a, p1->b, &L);
			p1 = p1->next;
			break;
		case -1:
			attach(p2->a, p2->b, &L);
			p2 = p2->next;
			break;
		case 0:
			if (p1->a + p2->a != 0) 
			{
				attach(p2->a + p1->a, p2->b, &L);
			}
			p1 = p1->next;
			p2 = p2->next;
			break;
		}
	}
	while (p1)
	{
		attach(p1->a, p1->b, &L);
		p1 = p1->next;
	}
	while (p2)
	{
		attach(p2->a, p2->b, &L);
		p2 = p2->next;
	}
	return temp;
}

list Mut(list L1, list L2)
{
	list p1 = L1->next;
	list L= (list)malloc(sizeof(node));
	list tmp = L;
	while (p1)
	{
		list p2 = L2->next;
		while (p2)
		{
			list q = (list)malloc(sizeof(node));
			q->a = p1->a * p2->a;
			q->b = p1->b + p2->b;
			q->next = NULL;
			L->next = q;
			L = q;
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	L = tmp->next;
	tmp->a = 0;
	while (L)
	{
		tmp->a += 1;
		L = L->next;
	}
	for (int i = 0; i < tmp->a - 1; i++)
	{
		node* q = tmp->next;
		for (int j = 0; j < tmp->a - 1 - i; j++)
		{
			if (q->b < q->next->b)
			{
				// 交换节点数据
				int m = q->next->a;
				q->next->a = q->a;
				q->a = m;
				m = q->next->b;
				q->next->b = q->b;
				q->b = m;
			}
			q = q->next;
		}
	}
	L = tmp->next;
	while (L->next)
	{
		if (L->b == L->next->b)
		{
			L->a += L->next->a;
			list q = L->next;
			L->next = q->next;
			free(q);
			tmp->a--;
		}
		L = L->next;
	}
	return tmp;
}
void print(list l)
{
	list p = l->next;
	if (p == NULL)
	{
		printf("0 0\n");
		return;
	}
	int flag = 1;
	while (p)
	{
		if (flag == 1)
			flag = 0;
		else if(p->a)
			printf(" ");
		if(p->a)
		printf("%d %d", p->a, p->b);
		p = p->next;
	}
	printf("\n");
	
}

