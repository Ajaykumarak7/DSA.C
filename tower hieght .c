#include<stdio.h>
struct complex{
    int feet;
    int inches;

};
int main()
{
    
    struct complex t1;
    struct complex t2;
    struct complex t3;
    struct complex t4;
    scanf("%d %d",&t1.feet,&t1.inches);
        scanf("%d %d",&t2.feet,&t2.inches);
            scanf("%d %d",&t3.feet,&t3.inches);
            int x,y,carry=0;
            x=t1.inches+t2.inches+t3.inches;
            carry=x/12;
            x=x%12;
            y=t1.feet+t2.feet+t3.feet+carry;
            t4.inches=x;
            t4.feet=y;
            printf("%d %d",t4.feet,t4.inches);


    
    
}