#pragma once
#include<stdlib.h> 
class Node
{
public:
	int GetElem(Node* l, int i, int* e);//找到第i个元素并且返回
	int ListInsert(Node** l, int i, int e);//插入;
	int ListDelete(Node** l, int i, int* e);//删除某个元素；
	void CreateList(Node** l, int n);//建立整个链表
	void ClearList(Node** l);//删除整个链表；
	void DisplayList(Node**l,int n);//展示整个链表；
private:
	int date;//数据
	Node* next;//下一个的地址
};