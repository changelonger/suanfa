#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//�������Ľṹ
typedef struct BiTNode
{
	int height;
	int data;
	BiTNode* lchild, * rchild;
}*BiTree;

//�����ȡ����
int getheight(BiTree T)
{
	if (T == NULL)
		return 0;
	else
		return T->height;
}

//������ֵ
int max(int a, int b)
{
	return (a > b) ? a : b;
}

//������������
void leftRotate(BiTree* T)
{
	BiTree R = (*T)->rchild;//�¸��ڵ��Ǿɸ�����������
	(*T)->rchild = R->lchild;//�¸��ڵ����������������ڣ��Ǿɸ�����������
	R->lchild = (*T);//�ɽ�����¸��ڵ��������
	//��������
	(*T)->height = 1 + max(getheight((*T)->lchild), getheight((*T)->rchild));
	R->height = 1 + max(getheight(R->lchild), getheight(R->rchild));
	*T = R;//������Tָ���¸����
}

//������������
void RightRotate(BiTree* T)
{
	BiTree L = (*T)->lchild;//�¸��ڵ��Ǿɸ��ڵ��������
	(*T)->lchild = L->rchild;//�¸��ڵ����������������ڣ��Ǿɽ���������
	L->rchild = (*T);//�ɸ��ڵ����¸��ڵ���Һ���
	(*T)->height = 1 + max(getheight((*T)->lchild), getheight((*T)->rchild));
	L->height = 1 + max(getheight(L->lchild), getheight(L->rchild));
	*T = L;//������Tָ���¸��ڵ�
}

//�õ�bfֵ
int getbf(BiTree T)
{
	return getheight(T->lchild) - getheight(T->rchild);
}

//����ʧ���ƽ�⴦��
void Balance(BiTree* T)
{
	//1��LL��
	if (getbf(*T) > 1 && getbf((*T)->lchild) > 0)
	{
		RightRotate(T);
	}
	//2��RR��
	else if (getbf(*T) < -1 && getbf((*T)->rchild) < 0)
		leftRotate(T);
	//3��LR��
	else if (getbf(*T) > 1 && getbf((*T)->lchild) < 0)
	{
		leftRotate(&(*T)->lchild);
		RightRotate(T);
	}

	//4��RR��
	else if (getbf(*T) < -1 && getbf((*T)->rchild) > 0)
	{
		RightRotate(&(*T)->rchild);
		leftRotate(T);
	}
}

//�����µĽ��
BiTree Creatnode(int key)
{
	BiTree T = (BiTree)malloc(sizeof(BiTNode));
	T->height = 1;
	T->data = key;
	T->lchild = NULL;
	T->rchild = NULL;
	return T;
}

//AVL���Ĳ�������
void InsertAVL(BiTree* T, int key)
{
	if ((*T) == NULL)
	{
		(*T) = Creatnode(key);
		return;
	}
	else if ((*T)->data > key)
		 InsertAVL(&(*T)->lchild, key);
	else if ((*T)->data < key)
		 InsertAVL(&(*T)->rchild, key);
	else
	{
		printf("%d�Ѿ�������\n", key);
		return;
	}
	(*T)->height= 1 + max(getheight((*T)->lchild), getheight((*T)->rchild));
	//ƽ�⴦��
	Balance(T);
}

void Del(BiTree*T)
{
	if ((*T)->lchild == NULL)
	{
		BiTree q = *T;
		(*T) = (*T)->rchild;
		free(q);
	}
	else if ((*T)->rchild == NULL)
	{
		BiTree* q = T;
		(*T) = (*T)->lchild;
		free(q);
	}
	else
	{
		BiTree s = (*T)->lchild;
		BiTree q = (*T);
		while (s->rchild)
		{
			q = s;
			s = s->rchild;//q��s��ֱ��ǰ��
		}
		(*T)->data = s->data;//��ɾ���ڵ�����ݱ�Ϊ����ǰ�̵�����
		//���������T��������û��������
		//��ʱ��q��T���,�ټ�
		if (q != *T)
			q->rchild = s->lchild;
		else
			q->lchild = s->lchild;
		free(s);
	}
}
void DeleteAVL(BiTree* T,int key)
{
	if (*T == NULL)
		printf("ɾ��ʧ��\n");
	else if (key < (*T)->data)
		DeleteAVL(&(*T)->lchild, key);
	else if (key > (*T)->data)
		DeleteAVL(&(*T)->rchild, key);
	else
		Del(T);
	(*T)->height=1+ max(getheight((*T)->lchild), getheight((*T)->rchild));
}

//ǰ�����
void pre(BiTree T)
{
	if (T)
	{
		printf("%d ", T->data);
		pre(T->lchild);
		pre(T->rchild);
	}
	else
		return;
}

//�������
void mid(BiTree T)
{
	if (T)
	{
		mid(T->lchild);
		printf("%d ", T->data);
		mid(T->rchild);
	}
	else
		return;
}

//������
int main()
{
	BiTree T = NULL;
	int arr[11] = { 3,2,1,4,5,6,7,10,9,8,11 };
	for (int i = 0; i < 11; i++)
	{
		InsertAVL(&T, arr[i]);
		
	}
	printf("ǰ���������ǣ�\n");
	pre(T);
	printf("\n�����������ǣ�\n");
	mid(T);
	DeleteAVL(&T, 7);
	printf("\nǰ���������ǣ�\n");
	pre(T);
	printf("\n�����������ǣ�\n");
	mid(T);
	return 0;
}