#include<stdio.h>
#include<stdlib.h>
#include "stacheader.h"

int prec(char a, char b)
{
    if(a=='^' || a=='*' || a=='/' || a=='%')
    {
        if(b=='^')
            return FALSE;
        else
            return TRUE;
    }
    else
    {
        if(b=='+' || b=='-')
            return TRUE;
        else
            return FALSE;
    }
}
// *********************************
void intfixToPostfix(char infix[])
{
    struct stack S;
    initialize(&S);
    int i=0,j=0;
    char symb,x;
    char postfix[1000];
    

    while(infix[i]!='\0')
    {
        symb=infix[i++];
        if(symb>='a' && symb<='z')
            postfix[j++]=symb;

        else
        {
            while(!isEmpty(&S) && prec(peek(&S),symb))
            {
                x=pop(&S);
                postfix[j++]=x;
            }
            push(&S,symb);
        }
    }
    while (!isEmpty(&S))
    {
        x=pop(&S);
        postfix[j++]=x;
    }
    postfix[j]='\0';
    printf("%s",postfix);
    
}
int main()
{
    char infix[100];
    scanf("%s",&infix);
    intfixToPostfix(infix);
}