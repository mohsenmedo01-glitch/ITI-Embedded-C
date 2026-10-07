#include <stdio.h>
int main(void)
{
    int x;
    printf("enter a number\n");
    scanf("%d", &x);
    for (int i=1;i<=100;i++)
    {
        if(i%x==0)
        {
            printf("%d ",i);
        }

    }

    return 0;
}