#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"Sqstack.h"
int SqStack::Push(SqStack* s, int e)
{
	if (s->top = MAX - 1)
		return 0;	
	s->top++;
	s->date[s->top] = e;
	return 1;
}
void SqStack::Pop(SqStack* s)
{
	s->top--;
}