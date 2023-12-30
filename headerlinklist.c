#include<stdio.h>
#include<stdlib.h>
struct node{
int info;
struct node *next;};
struct head{
int info,max,min;
struct node *next;
};
struct node *getnode(){
struct node *p;
p=(struct node*)malloc(sizeof(struct node));
return p;
};

struct head *gethead(){
struct head *p;
p=(struct head*)malloc(sizeof(struct head));
return p;
};


void createhead(struct head **head){
struct head *p;
p=gethead();
p->info=0;
p->max=-89454;
p->min=85349;
p->next=NULL;
*head=p;
}
void insbeg(struct head **head,int x){
struct node *p,*q;
p=getnode();


p->info=x;
p->next=(*head)->next;
(*head)->next=p;
(*head)->info+=1;
if((*head)->max<x){
    (*head)->max=x;
}
if((*head)->min>x){
    (*head)->min=x;
}


}
void traverse(struct head *head){
struct node *p=head->next;
while(p!=NULL){
    printf("%d->> ",p->info);
p=p->next;
}
printf("\n\n%d\n\n",head->info);
printf("%d\n\n",head->max);
printf("%d\n\n",head->min);}
int main(){
struct head *head;
createhead(&head);
insbeg(&head,100);
insbeg(&head,200);
insbeg(&head,300);
insbeg(&head,400);
insbeg(&head,500);
traverse(head);

}