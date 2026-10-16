#include <stdio.h>
#include <string.h>

int main() {
    char arr[] = "here we go";
    int len = strlen(arr);

    int words = 1;

    if (len == 0) {
        words = 0;
    }

    for (int i = 0; i < len; i++) {
        if (arr[i] == ' ') {
            words++;
        }
    }

    printf("\nNumber of words is: %d\n", words);

    return 0;
}