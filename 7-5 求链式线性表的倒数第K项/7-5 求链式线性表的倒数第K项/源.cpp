#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    node* next;
};
int main()
{
    int k; scanf("%d", &k);
    node* l = (node*)malloc(sizeof(node));
    node* p = l;
    l->data = 0;

    while (1)
    {
        int a = 0;
        scanf("%d", &a);
        if (a < 0)
            break;
        else
        {
            // Ϊ�½ڵ�����ڴ沢�������ӵ�����
            node* q = (struct node*)malloc(sizeof(struct node));
            q->data = a;
            q->next = NULL;
            p->next = q;  // ���½ڵ����ӵ�����
            p = q;  // ��ָ���Ƶ��½ڵ�
            l->data++;  // ���½ڵ���
            
        }
       /* p->data = a;
        node* q = (node*)malloc(sizeof(node));
        q = p->next;
        p = q;
        l->data++;*////����˼·
    }
    int i = 0;
    p = l->next;
    if (i > l->data - k)
    {
        printf("null");
    }
    else if (i == l->data - k)
        printf("%d", p->data);
    else
    {
        while (i < l->data - k)
        {
            p = p->next;
            i++;
        }
        printf("%d", p->data);
    }
    
    return 0;
}