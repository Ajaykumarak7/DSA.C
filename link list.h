#include<stdio.h>
#include<stdlib.h>
/***/
struct node
{
    int info;
    struct node *next;
};
/**/

struct node * GetNode()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    return p;
};

void FreeNode(struct Node **list)
{
    free(*list);
}
void InsBeg(struct node **list, int x)
{
    struct node *temp;
    temp=GetNode();
    temp->info=x;
    temp->next=*list;
    *list=temp;
}
/***/
void Traverse (struct node *list)
{
    struct node *t;
    t=list;
    while(t!=NULL)
    {
        printf("\t  %d",t->info);
        t=t->next;
    }
}
/***/
void InsEnd(struct node **list, int x)
{
    struct node *temp,*p;
    temp=*list;
    while (temp->next!=NULL)
        temp=temp->next;
    p=GetNode();
    p->info=x;
    p->next=NULL;

    temp->next=p;
}
/**/
void InsAft(struct node **list, int y, int x)
{
    struct node *temp,*p;
    temp=*list;
    while(temp!=NULL)
    {
        if (temp->info==y)
            break;
        else
            temp=temp->next;
    }
    p=GetNode();
    p->info=x;
    p->next=temp->next;
    temp->next=p;
}
/***/
int DelBeg(struct node **list)
{
    struct node *temp;
    int x;
    temp=*list;
    (*list)=(*list)->next;
    x=temp->info;
    free(temp);
    return x;
}
/**/
int DelEnd(struct node **list)
{
    struct node *p,*q;
    p=*list;
    q=NULL;
    int x;
    while (p->next!=NULL)
    {
        q=p;
        p=p->next;
    }

    q->next=NULL;
    x=p->info;
    free(p);
    return x;
}