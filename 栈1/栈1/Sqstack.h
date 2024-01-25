#pragma once
#define MAX 20
#define OK 1
#define TRUE 1
#define FALSE 0
#define ERROR 0
class SqStack
{
public:
	int Push(SqStack* s, int e);
	void Pop(SqStack* s);
private:
	int date[MAX];
	int top;
};
