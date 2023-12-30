#include<stdio.h>
#include"stacheader.h"
int postfixevaluation (postfixexp)
{
    struct stac s;
    initilise(s);
    int i=0;char symb;
    while (postfixexp[i]!)='\0'
    {
        symb=postfix[1];
        i++;
        if (symb>='0'&& symb<='9')
        {
            push(&s,symb-'0');

        }
        else{
            b=pop(&s);
            a=pop(&s);
            value=evaluation (a,b,symb);
            push(&s,value);
        }
    }

}