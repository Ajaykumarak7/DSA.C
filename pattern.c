#include<stdio.h>
int main()
{
int n,i,j;
scanf("d",&n);
char k;
for(i=1;i<=n;i++)
{
k='a'+n-i;
for(j=1;j<=i;j++)
{
printf("&c",k);
k++;
}
printf("\n");
}
}
