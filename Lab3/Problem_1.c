#include <stdio.h>
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};

    int i = 0;
    int j = 4;

    while (i < j)
    {
        int temp = arr[i]; //swap
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}