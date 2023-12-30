#include<stdio.h>
traverse(int A[], int N)
{
    int i=0;
    for(i=0; i<N; i++)
    {
        printf("%d ",A[i]);
    }
}
void Mergearray(int A[], int N, int B[], int M)
{
    int i=0,j=0,k=0;
    int c[13];
    while (i<N && j<M)
    {
        if (A[i]<B[j]);
        {
        c[k]=A[i];
        i++;
        k++;
        }

        else{
            c[k]=B[j];
            j++;
            k++;
        }
    }
    while(i<N)
    {
        c[k]=A[i]
        i++;k++;
    }
    while(j<M)
    {
        c[k]=B[j];
        j++;k++;
    }
    traverse(c,13);
}
    void main()
    {
        int N=6,M=7;
        int A[]={2,4,6,8,10,12};
        int B[]={1,3,4,5,6,7,8};
        traverse (A,N);
        traverse (B,M);
        Mergearray(A,N,B,M);
    }
