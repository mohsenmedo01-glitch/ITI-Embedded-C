#include <stdio.h>

int main() {
    char arr1[] = "mohamed";
    char arr2[] = "mohammed";

    int len1 = 0;
    while (arr1[len1] != '\0') {
        len1++;
    }

    int len2 = 0;
    while (arr2[len2] != '\0') {
        len2++;
    }

    if (len1 != len2) {
        printf("\nThe 2 strings aren't identical");
        return 0;
    }

    int identical = 1;

    for (int i = 0; i < len1; i++) {
        if (arr1[i] != arr2[i]) {
            identical = 0;
            break;
        }
    }

    if (identical != 0) {
        printf("\nThe 2 strings are same");
    } else {
        printf("\nThe 2 strings aren't same");
    }

    return 0;
}