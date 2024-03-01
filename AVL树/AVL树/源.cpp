#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//定义树的结构
typedef struct BiTNode
{
	int height;
	int data;
	BiTNode* lchild, * rchild;
}*BiTree;

//定义获取树高
int getheight(BiTree T)
{
	if (T == NULL)
		return 0;
	else
		return T->height;
}

//获得最大值
int max(int a, int b)
{
	return (a > b) ? a : b;
}

//定义左旋函数
void leftRotate(BiTree* T)
{
	BiTree R = (*T)->rchild;//新根节点是旧根结点的右子树
	(*T)->rchild = R->lchild;//新根节点的左子树（如果存在）是旧根结点的右子树
	R->lchild = (*T);//旧结点是新根节点的左子树
	//更新树高
	(*T)->height = 1 + max(getheight((*T)->lchild), getheight((*T)->rchild));
	R->height = 1 + max(getheight(R->lchild), getheight(R->rchild));
	*T = R;//重新让T指向新根结点
}

//定义右旋函数
void RightRotate(BiTree* T)
{
	BiTree L = (*T)->lchild;//新根节点是旧跟节点的左子树
	(*T)->lchild = L->rchild;//新根节点的右子树（如果存在）是旧结点的左子树
	L->rchild = (*T);//旧根节点是新根节点的右孩子
	(*T)->height = 1 + max(getheight((*T)->lchild), getheight((*T)->rchild));
	L->height = 1 + max(getheight(L->lchild), getheight(L->rchild));
	*T = L;//重新让T指向新根节点
}

//得到bf值
int getbf(BiTree T)
{
	return getheight(T->lchild) - getheight(T->rchild);
}

//四种失衡的平衡处理
void Balance(BiTree* T)
{
	//1、LL型
	if (getbf(*T) > 1 && getbf((*T)->lchild) > 0)
	{
		RightRotate(T);
	}
	//2、RR型
	else if (getbf(*T) < -1 && getbf((*T)->rchild) < 0)
		leftRotate(T);
	//3、LR型
	else if (getbf(*T) > 1 && getbf((*T)->lchild) < 0)
	{
		leftRotate(&(*T)->lchild);
		RightRotate(T);
	}

	//4、RR型
	else if (getbf(*T) < -1 && getbf((*T)->rchild) > 0)
	{
		RightRotate(&(*T)->rchild);
		leftRotate(T);
	}
}

//创建新的结点
BiTree Creatnode(int key)
{
	BiTree T = (BiTree)malloc(sizeof(BiTNode));
	T->height = 1;
	T->data = key;
	T->lchild = NULL;
	T->rchild = NULL;
	return T;
}

//AVL树的插入造作
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
		printf("%d已经存在了\n", key);
		return;
	}
	(*T)->height= 1 + max(getheight((*T)->lchild), getheight((*T)->rchild));
	//平衡处理
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
			s = s->rchild;//q是s的直接前继
		}
		(*T)->data = s->data;//把删除节点的数据变为它的前继的数据
		//以下情况是T的左子树没有右子树
		//此时，q和T相等,少见
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
		printf("删除失败\n");
	else if (key < (*T)->data)
		DeleteAVL(&(*T)->lchild, key);
	else if (key > (*T)->data)
		DeleteAVL(&(*T)->rchild, key);
	else
		Del(T);
	(*T)->height=1+ max(getheight((*T)->lchild), getheight((*T)->rchild));
}

//前序遍历
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

//中序遍历
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

//主函数
int main()
{
	BiTree T = NULL;
	int arr[11] = { 3,2,1,4,5,6,7,10,9,8,11 };
	for (int i = 0; i < 11; i++)
	{
		InsertAVL(&T, arr[i]);
		
	}
	printf("前序遍历结果是：\n");
	pre(T);
	printf("\n中序遍历结果是：\n");
	mid(T);
	DeleteAVL(&T, 7);
	printf("\n前序遍历结果是：\n");
	pre(T);
	printf("\n中序遍历结果是：\n");
	mid(T);
	return 0;
}