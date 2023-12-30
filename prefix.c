#include<stdio.h>
    #include<stdlib.h>
    #include "stackHeader.h"
    int power(int a,int n)
    {
        int p;
        //base case
        if(n==0)
            return 1;
        //recurssive case
        p=power(a,n/2);
        if(n%2==0)
            return p*p;
        else
            return p*p*a;
    }
    int eval(int a, int b, char op)
    {
        switch (op)
        {
        case '+': return (a+b);
        case '-': return (a-b);
        case '*': return (a*b);
        case '/': return (a/b);
        case '%': return (a%b);
        case '^': return power(a,b);

        }
    }

    int preeval(char prefix[])
    {
        int size=0;
        struct stack S;
        initialize(&S);
        int i,a,b,val,ans;
        char symbol;

        //getting the size of the expression 
        while(prefix[size]!='\0')
        {
            size++;
        i=size-1;
        while (i>=0)
        {
            symbol=prefix[i];
            i--;
            if(symbol>='0' && symbol<='9')
            {
                push(&S,symbol-'0');
            }
            else
            {
                b=pop(&S);
                a=pop(&S);
                val=eval(b,a,symbol);
                push(&S,val);
                
            }
            printf("%d ",peek(&S));
        }
        ans=peek(&S);
        return ans;
        

    }

    int main()
    {
        char exp[30]="-*-^34^82+/9348";
        int ans;
        // scanf("%s",exp);
        ans=preeval(exp);
        printf("ans is -> %d",ans);
        return 0;
        
    }