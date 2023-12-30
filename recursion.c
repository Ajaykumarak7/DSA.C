int power (int a,int b); // add a semicolon here
if(b=0) // use == instead of =
{
    return 1;
}
else
{
    int p= power(a,b);
    if(b%2==0)
    {
        return p*p;
    }
    else
    {
        return p*p*a;
    }
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int result = power(a,b); // store the result in a variable
    printf("%d\n", result); // print the result
    return 0;
}
