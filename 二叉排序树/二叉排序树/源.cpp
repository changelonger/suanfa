#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct BiTNode
{
	int data;
	BiTNode* lchild, * rchild;

};
typedef BiTNode* BiTree;
//二叉树查找
int SrearchBST(BiTree T, int key, BiTree f, BiTree* p)
{
	if (!T)
	{
		*p = f;
		return 0;
	}
	else if (key == T->data)
	{
		*p = T;
		return 1;
	}
	else if (key < T->data)
		return SrearchBST(T->lchild,key, T, p);
	else
		return SrearchBST(T->rchild,key, T, p);
	
}

//二叉树插入
int InsertBST(BiTree* T, int key)
{
	BiTree p, s;
	if (!SrearchBST(*T, key, NULL, &p))
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if (!p)
			*T = s;
		else if (key < p->data)
			p->lchild = s;
		else
			p->rchild = s;
		return 1;
	}
	return 0;
}
void b(BiTree T)//中序遍历
{
	if (T)
	{
		b(T->lchild);
		printf("%d ", T->data);
		b(T->rchild);
	}
}

//int main()
//{
//	int i = 0;
//	int a[12] = {62,88,58,47,35,73,51,99,37,93,90,96};
//	BiTree T = NULL;
//	for (i = 0; i < 12; i++)
//	{
//		InsertBST(&T, a[i]);
//	}
//	InsertBST(&T, 95);
//	b(T);
//	return 0;
//}
int Delete(BiTree* p)
{
	BiTree q, s;
	if ((*p)->lchild == NULL)
	{
		q = (*p); *p = (*p)->rchild; free(q);
	}
	else if ((*p)->rchild == NULL)
	{
		q = (*p); *p = (*p)->lchild; free(q);
	}
	else
	{
		q = *p;
		s = (*p)->lchild;
		while (s->rchild)
		{
			q=s; s = s->rchild;
		}
		(*p)->data = s->data;
		if (q != *p)
			q->rchild = s->lchild;//q的右孩子是s;
		else
			q->lchild = s->lchild;//q的左孩子是s;
		free(s);
	}
	return 1;
}
int DeleteBST(BiTree* T, int key)
{
	if (!*T)
		return 0;
	else if (key < (*T)->data)
		DeleteBST(&(*T)->lchild, key);
	else if (key > (*T)->data)
		DeleteBST(&(*T)->rchild, key);
	else
		return Delete(T);
}
//int main()
//{
//	BiTree T = NULL;
//	int a[16] = { 62,58,88,47,73,99,35,51,93,29,36,49,56,36,48,50 };
//	for (int i = 0; i < 16; i++)
//	{
//		InsertBST(&T, a[i]);
//	}
//	DeleteBST(&T, 47);
//	b(T);
//	return 0;
//}