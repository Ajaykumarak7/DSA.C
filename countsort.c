#include<stdio.h>
#include<stdlib.h>  
int countsort (int *a,int n,int k)
{
    int *c=(int*)calloc (sizeof(int),(k+1));
    int *c=(int*)malloc (sizeof(int),*n);
    for(int i=0;i<n-1;i++)
    {
    c[i]=c[a[i]]+1;

    }
    for(int i=1;i<k;i++)
    {
        c[i]=c[i]+c[i-1];
    }
    for(int i=n-1;i>0;i--)
    {
        ans[c[a[i]]-1]=a[i];
        c[a[i]]=c[a[i]]-1;
    }
    return ans;
}


int main ()
{
    int n,i,a[100];
    printf("enter the size of array ");
    scanf ("&d", &n);
    printf("enter the element of the array");
    for(i=0;i<n;i++)
    {
        scanf( "%d",&a[i]);
    }
    printf("array before sorting is");
    for(i=0;i<n;i++)
{
    printf("\n%d\n",a[i]);
}
countsort(a,0,n-1);
printf("sorted array is");
for(i=0;i<n;i++)
{
    printf("\n%d\n",a[i]);
}
return 0;

}