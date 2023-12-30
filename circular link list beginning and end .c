#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *next;
};


struct node * getnode(void)
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    return p;
}



InsBeg(struct node **cstart, int x)
{
    struct node *p;
    p=getnode();
    p->info=x;
    if((*cstart)!=NULL)
    {
        p->next=(*cstart)->next;
        (*cstart)->next=p;

    }
    else
    {
        p->next=p;
        (*cstart)=p;
    }
}


traverse(struct node*cstart)
{
    struct node *p;
    p=cstart->next;
    while(p!=cstart)
    {
        printf("%d--->",p->info);
        p=p->next;
    }
    printf("%d--->",p->info);
}
  InsAfter(struct node *cstart, int val, int x)
{
    struct node *p, *temp;
    p = getnode();
    p->info = x;
    temp = cstart->next;
    while (temp != cstart && temp->info != val)
    {
        temp = temp->next;
    }

    if (temp == cstart)
    {
        printf("Value %d not found in the list\n", val);
    }
    else
    {
        p->next = temp->next;
        temp->next = p;
    }
}




int main()
{
    struct node *cstart;
    cstart=NULL;
    printf("\n Insertion at Begining \n");
    InsBeg(&cstart,10);
    InsBeg(&cstart,20);
    InsBeg(&cstart,30);
    InsBeg(&cstart,40);
    InsBeg(&cstart,50);
    InsBeg(&cstart,60);
    traverse(cstart);
    printf("\n\nInsertion after a given value:\n");
    InsAfter(cstart, 30, 35);
    traverse(cstart);
    return 0;
}