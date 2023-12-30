#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

int prec(char a, char b)
{
    if (a == '^' || a == '*' || a == '/' || a == '%')
    {
        if (b == '^')
            return False;
        else
            return True;
    }
    else
    {
        if (b == '+' || b == '-')
            return True;
        else
            return False;
    }
}

int main()
{
    char a = '^';
    char b = '+';
    printf("Result: %d\n", prec(a, b));  
    return 0;
}
