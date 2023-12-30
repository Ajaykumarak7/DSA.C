#include <stdio.h>
#include <math.h>

// Function to check whether a number is Armstrong or not
int isArmstrong(int n)
{
    int sum = 0; 
    int temp = n; 
    int digits = (int) log10(n) + 1; 
    while (temp > 0)
    {
        int rem = temp % 10; 
        sum += pow(rem, digits);
        temp /= 10; 
    }
    return (sum == n);
}
int main()
{
    int num; 
    printf("Enter a number: ");
    scanf("%d", &num);
    if (isArmstrong(num))
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);

    return 0;
}
