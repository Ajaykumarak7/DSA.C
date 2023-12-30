#include<stdio.h>
void main()
{
int n,x,i,num=1,f=1;
float s=0.0;
printf("enter no of terms,value of x");
scanf ("%d %d",&n,&x);
for ( i=1; i<n;i++)
{
f=f*i;
num=num*x;
s=s+num/f;
}
printf("sum=%d",&s);

}
