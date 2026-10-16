#include <stdio.h>

int main() {
    char arr[] = "Hola world";

    int i = 0;

    while (arr[i] != '\0') {
        i++;
    }

    printf("\nString len: %d\n", i);

    return 0;
}