#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define MAX 100
#include<stdlib.h>
#include<math.h>
//1��˫�ױ�ʾ
struct PTNode//�ڵ�ṹ
{
	int data;
	int parent;
};
struct PTree//���ṹ
{
	PTNode nodes[MAX];//�ڵ�����
	int r, n;//����λ�úͽڵ���
};



//2�����ӱ�ʾ��
struct CTNode//���ӽڵ�
{
	int child;
	CTNode* next;
};
typedef CTNode* ChildPtr;

struct CTBox//��ͷ�ṹ
{
	int data;
	ChildPtr fistchild;
};

struct CTree//���ṹ
{
	CTBox nodes[MAX];//�ڵ�����
	int r, n;//��λ�úͽڵ����
};


//3�������ֵܱ�ʾ
struct CSNode
{
	int data;
	CSNode* firstchild, * rightsib;
};


//������
struct BiTNode
{
	int data;

	BiTNode* lchild, * rchild;
};
typedef BiTNode* BiTree;
//1ǰ�����
void PreOrderTraverse(BiTNode* T)
{
	if (T == NULL)
		return;
	printf("%c", T->data);//��Ҫ���еĲ���
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
	//��ִ�в������ٷ��������������
}
///2���������
void InOrderTraverse(BiTNode* T)
{
	if (T == NULL)
		return;
	InOrderTraverse(T->lchild);
	printf("%c", T->data);//��Ҫ���еĲ���
	InOrderTraverse(T->rchild);
	//�Ȱ���֦�ҵ��������һ�����ӷ���
	//ִ�в���
}
//3����������
void PosOrderTraverse(BiTNode* T)
{
	if (T == NULL);
	return;
	PosOrderTraverse(T->lchild);
	PosOrderTraverse(T->rchild);
	printf("%c", T->data);
}




//����ǰ������������нڵ��ֵһ���ַ�
//#��ʾ�����������������ʾ������
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

// ����������
struct BiThrNode
{
    char data;
    BiThrNode* lchild, * rchild;
    int ltag, rtag;
};
typedef BiThrNode* BiThrTree;

// �������������
BiThrTree pre = NULL;

// ����preΪ��һ���ڵ��ǰ��
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
        if (!p->lchild) // û������
        {
            p->ltag = 1; // ��ʶ��
            p->lchild = pre; // ���ӵ�ָ��ָ��ǰ����
        }
        if (!pre->rchild) // ǰ��û���Һ���
        {
            pre->rtag = 1;
            pre->rchild = p; // ��̾���p
        }
        pre = p;
        InThreading(p->rchild);
    }
}

// �����������ı���
void InorderTraverseThr(BiThrTree T)
{
    BiThrTree p;
    p = T->lchild; // T��ͷ��㣬T->lchild�Ǹ��ڵ�
    while (p != T) // ���������߱�������ʱ��p==T;
    {
        while (p->ltag == 0) // ltag==0,ѭ������һ���ڵ�
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

// �����̶���ȵĶ�����
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

    // �ͷŶ�̬������ڴ�
    // ��ʵ��Ӧ���У��������Ҫ����ϸ���ڴ����
    free(h);
    return 0;
}
