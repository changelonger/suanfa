#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define MAX 100
#include<stdlib.h>
#include<math.h>
//1、双亲表示
struct PTNode//节点结构
{
	int data;
	int parent;
};
struct PTree//树结构
{
	PTNode nodes[MAX];//节点数组
	int r, n;//根的位置和节点数
};



//2、孩子表示法
struct CTNode//孩子节点
{
	int child;
	CTNode* next;
};
typedef CTNode* ChildPtr;

struct CTBox//表头结构
{
	int data;
	ChildPtr fistchild;
};

struct CTree//树结构
{
	CTBox nodes[MAX];//节点数组
	int r, n;//根位置和节点个数
};


//3、孩子兄弟表示
struct CSNode
{
	int data;
	CSNode* firstchild, * rightsib;
};


//二插树
struct BiTNode
{
	int data;

	BiTNode* lchild, * rchild;
};
typedef BiTNode* BiTree;
//1前序遍历
void PreOrderTraverse(BiTNode* T)
{
	if (T == NULL)
		return;
	printf("%c", T->data);//需要进行的操作
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
	//先执行操作，再访问下面的做孩子
}
///2、中序遍历
void InOrderTraverse(BiTNode* T)
{
	if (T == NULL)
		return;
	InOrderTraverse(T->lchild);
	printf("%c", T->data);//需要进行的操作
	InOrderTraverse(T->rchild);
	//先把左枝找到最下面第一个左孩子访问
	//执行操作
}
//3、后续遍历
void PosOrderTraverse(BiTNode* T)
{
	if (T == NULL);
	return;
	PosOrderTraverse(T->lchild);
	PosOrderTraverse(T->rchild);
	printf("%c", T->data);
}




//按照前序输入二叉树中节点的值一个字符
//#表示空树，构造二叉链表示二叉树
//void CreatBiTree(BiTree* T)
//{
//	char ch;
//	/*scanf("%d", &ch);
//	if (ch == '#')
//		*T = NULL;*/
//	else
//	{
//		*T = (BiTree)malloc(sizeof(BiTNode));
//		/*(*T)->data = ch;*/
//		CreatBiTree(&(*T)->lchild);
//		CreatBiTree(&(*T)->rchild);
//	}
//}


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 线索二叉树
struct BiThrNode
{
    char data;
    BiThrNode* lchild, * rchild;
    int ltag, rtag;
};
typedef BiThrNode* BiThrTree;

// 中序遍历线索化
BiThrTree pre = NULL;

// 设置pre为第一个节点的前驱
void setpre(BiThrTree T)
{
    while (T->lchild)
    {
        T = T->lchild;
    }
    pre = T;
}

void InThreading(BiThrTree p)
{
    if (p)
    {
        InThreading(p->lchild);
        if (!p->lchild) // 没有左孩子
        {
            p->ltag = 1; // 标识符
            p->lchild = pre; // 左孩子的指针指向前驱；
        }
        if (!pre->rchild) // 前驱没有右孩子
        {
            pre->rtag = 1;
            pre->rchild = p; // 后继就是p
        }
        pre = p;
        InThreading(p->rchild);
    }
}

// 线索二叉树的遍历
void InorderTraverseThr(BiThrTree T)
{
    BiThrTree p;
    p = T->lchild; // T是头结点，T->lchild是根节点
    while (p != T) // 当空树或者遍历结束时，p==T;
    {
        while (p->ltag == 0) // ltag==0,循环到第一个节点
            p = p->lchild;
        printf("%c ", p->data);
        while (p->rtag == 1 && p->rchild != T)
        {
            p = p->rchild;
            printf("%c ", p->data);
        }
        p = p->rchild;
    }
}

// 创建固定深度的二叉树
void CreatKTree(int n, BiThrTree* T)
{
    static int cnt = 1;
    if (cnt <= pow(2, n) - 1)
    {
        (*T) = (BiThrTree)malloc(sizeof(BiThrNode));
        if (!(*T)) {
            fprintf(stderr, "Memory allocation error.\n");
            exit(EXIT_FAILURE);
        }

        (*T)->ltag = 0;
        (*T)->rtag = 0;
        scanf(" %c", &((*T)->data));

        cnt++;
        CreatKTree(n, &((*T)->lchild));
        CreatKTree(n, &((*T)->rchild));
    }
}

int main()
{
    BiThrTree h = (BiThrTree)malloc(sizeof(BiThrNode));
    if (!h) {
        fprintf(stderr, "Memory allocation error.\n");
        return EXIT_FAILURE;
    }

    BiThrTree root = h->lchild;
    int n = 0;
    scanf("%d", &n);
    CreatKTree(n, &(h->lchild));

    setpre(root);
    InThreading(root);
    InorderTraverseThr(root);

    // 释放动态分配的内存
    // 在实际应用中，你可能需要更详细的内存管理
    free(h);
    return 0;
}
