#include<stdio.h>
void main()
{
    int num1,num2,num3;
    printf("Enter the value\n");
    scanf("%d%d%d",&num1,&num2,&num3);
    if(num1>num2)
    {
        if(num1>num3)
        printf("%d is the greatest\n",num1);
        else
        printf("%d is the greatest\n",num3);

    }
    else
    {
        if(num2>num3)
        printf("%d is the greatest number", num2);
        else
        printf("%d is the greastest number",num3);
    }
}
