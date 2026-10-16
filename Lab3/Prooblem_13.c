#include <stdio.h>

int main() {
    char arr[] = "Hello World";

    int len = 0;

    while (arr[len] != '\0') {
        len++;
    }

    for (int i = 0; i < len; i++) {
        if (arr[i] >= 65 && arr[i] <= 90) {
            // Uppercase to lowercase
            arr[i] += 32;
        } else if (arr[i] >= 97 && arr[i] <= 122) {
            // Lowercase to uppercase
            arr[i] -= 32;
        }
    }

    printf("\nAfter Case Swap: ");

    for (int i = 0; i <= len; i++) {
        printf("%c", arr[i]);
    }

    return 0;
}