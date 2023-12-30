#include<stdio.h>
int main ()
{
int A[10];
int B[5] [4];
int c[5] [4] [3];
int i=4,j=3,k=2;
int x;

x=i-0;
printf("%u",&A[i]);
x=i-0;
printf("\n\n%u",&A+x);

//2d
x=(i-0)*(3-0+1)+(j-0);
printf("\n\n\n%u",&B[i][j]);
printf("\n\n%u",B[0]+x);
//3d
x=(i-0)*(4-0+1)*(3-0+1)+(j-0)*(2-1)+(2-0);
printf("\n\n\n%u",&C[i][j][k]);
printf("\n\n%u",B[0]+x);
}
