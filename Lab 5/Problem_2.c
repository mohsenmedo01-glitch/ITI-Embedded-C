#include <stdio.h>
struct complex
{
    float real;
    float imaginary;
};

int main()
{
    struct complex c1;
    struct complex c2;
    struct complex sum;
    struct complex multiply;

    printf("Enter real and imaginary parts of first number: ");
    scanf("%f %f", &c1.real, &c1.imaginary);

    printf("Enter real and imaginary parts of second number: ");
    scanf("%f %f", &c2.real, &c2.imaginary);
    sum.real = c1.real + c2.real;
    sum.imaginary = c1.imaginary + c2.imaginary;
    multiply.real =(c1.real * c2.real) - (c1.imaginary * c2.imaginary);

    multiply.imaginary =(c1.real * c2.imaginary) + (c1.imaginary * c2.real);
    printf("\nSum = %.2f + %.2fi\n",sum.real, sum.imaginary);
    printf("Multiplication = %.2f + %.2fi\n",multiply.real, multiply.imaginary);
    return 0;
}