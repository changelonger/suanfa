#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"sqstack.h"
void stacknode:: push(linkstack* l, int e)
{
	stacknode* s = (stacknode*)malloc(sizeof(stacknode));//����һ�½ڵ�
	s->date= e;//��ֵ��ֵ��date
	s->next = l->top;//�½ڵ����ָ��ָ��ջ��ָ�룻
	l->top = s;//ջ��ָ��ָ���½ڵ�
	l->count++;//��������
	
}
void stacknode::pop(linkstack* l)
{
	stacknode* s=NULL;
	s = l->top;
	l->top = l->top->next;
	free(s);
	l->count--;
}
