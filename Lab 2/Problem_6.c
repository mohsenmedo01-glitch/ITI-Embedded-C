// ai assistant , i tried many times 
#include <stdio.h>
int main()
{
for (int x = 0; x <= 10; x++)
{
    int prime = 1;

    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
        {
            //printf("%d is not prime\n", x);
            prime = 0;
            break;
        }
    }

    if (prime && x > 1)
    {
        printf("%d ", x);
    }
}
}