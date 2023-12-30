#include<stdio.h>
struct triplet{
    int x,y,gcd;
}ans,IntAns;
typedef struct triplet triplet;

triplet EE(int a,int b)
{
    if(b==0)
    {
        ans.x=1;
        ans.y=0;
        ans.gcd=a;
        return ans;
    }
    else
    {
        IntAns=EE(b,a%b);
        ans.x=IntAns.y;
        ans.y=IntAns.x-(a/b)*IntAns.y;
        ans.gcd=IntAns.gcd;
        return ans;
    }
}


int multiplicativemoduloinverse(int a,int m)
{
    triplet ans=EE(a,m);
    return (ans.x%m+m)%m;
}

int main()
{

    int x,y,p;
    triplet z;
    p=multiplicativemoduloinverse(14,5);

    printf("%d",p); 

    scanf("%d%d",&x,&y);
    z=EE(x,y);
    printf("%d       %d         %d      ",z.x,z.y,z.gcd);
}