#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"sqstack.h"
void stacknode:: push(linkstack* l, int e)
{
	stacknode* s = (stacknode*)malloc(sizeof(stacknode));//创建一新节点
	s->date= e;//把值赋值给date
	s->next = l->top;//新节点里的指针指向栈顶指针；
	l->top = s;//栈顶指针指向新节点
	l->count++;//数据增加
	
}
void stacknode::pop(linkstack* l)
{
	stacknode* s=NULL;
	s = l->top;
	l->top = l->top->next;
	free(s);
	l->count--;
}
