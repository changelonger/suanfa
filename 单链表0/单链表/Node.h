#pragma once
#include<stdlib.h> 
class Node
{
public:
	int ListLenth(Node*p0);
	int GetElem(Node* l, int i, int* e);//�ҵ���i��Ԫ�ز��ҷ���
	void ListInsert(Node** l, int i, int e);//����;
	void ListDelete(Node** l, int i);//ɾ��ĳ��Ԫ�أ�
	void CreateList(Node** l, int n);//������������
	void ClearList(Node** l);//ɾ����������
	void DisplayList(Node**l,int n);//չʾ��������
private:
	int date;//����
	Node* next;//��һ���ĵ�ַ
};