#pragma once
#include<stdlib.h>
class stacknode
{
public:
	void push(linkstack* l, int e);
	void pop(linkstack* l);
private:
	int date;
	stacknode* next;
};
struct linkstack
{
	stacknode* top;
	int count;
};