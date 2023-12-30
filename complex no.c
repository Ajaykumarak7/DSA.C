#include <stdio.h>
struct complex
{
    float real; 
    float imag;
};
struct complex add(struct complex c1, struct complex c2)
{
    struct complex c3; 
    c3.real = c1.real + c2.real; 
    c3.imag = c1.imag + c2.imag; 
    return c3; 
}
int main()
{
    struct complex c1, c2, c3; 
    printf("Enter the first complex number (real and imaginary): ");
    scanf("%f %f", &c1.real, &c1.imag); 
    printf("Enter the second complex number (real and imaginary): ");
    scanf("%f %f", &c2.real, &c2.imag); 
    c3 = add(c1, c2); 
    printf("The sum of the two complex numbers is: %.2f + %.2fi\n", c3.real, c3.imag);
    return 0; 
}
