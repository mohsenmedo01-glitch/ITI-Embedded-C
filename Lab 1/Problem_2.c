#include <stdio.h>
int main(void)
{
    int x1;
    int x2;
    printf("enter first number\n");
    scanf("%d", &x1);
    printf("enter second number\n");
    scanf("%d", &x2);
    if (x1 == 0 || x2 == 0) // test
    {
        printf("Division by zero is not allowed.\n");
        return 0;
    }
    if (x1 % x2 == 0 || x2 % x1 == 0)
    {
        printf("%d is a multiple of %d\n", x1, x2);
    }
    else
    {
        printf("%d is not a multiple of %d\n", x1, x2);
    }

    return 0;
}