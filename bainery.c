#include<stdio.h>
#include<stdlib.h>
#define stacsize 100
#define true 1
#define false 0
struct stac{
    int item [stacsize];
    int top;

};

void initialisation(struct stac *s){
s->top=1;
}
int isempty (struct stac *s){
    if(s->top==-1){
        return true ;
    }
    else{
        return false;
    }
}
int push(struct stac *s,int n){
    if(s->top==stacsize-1){
        printf("\n stac ovrflow");

    }
    else{
        s->top++;
        s->item[s->top]=n;
        return n;
    }
}
int pop(struct stac *s){
    if (s->top==-1){
        printf("stack underflow");
    }
    else{
        int y=s.item[s->top];
        s.top--;
        return y;


    }
}
int stactop(struct stac s){
    return s->item[s->top];
}
int main()

{
    struct stac *s;
    initialisation();
    printf("%d\n",push(&s,5));
     printf("%d\n",push(6));
      printf("%d\n",push(7));
       printf("%d\n",push(8));
        printf("%d\n",pop());
         printf("%d\n",pop());
          printf("%d\n",push(9));
           printf("%d\n",stactop());
}

