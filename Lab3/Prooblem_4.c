#include <stdio.h>

int main() {
    int arr[] = {100,56,8,4,0,14};
    int len = sizeof(arr) / sizeof(arr[0]);

    int max = 0;
    int min = 999;

    for (int i = 0; i < len; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }

        if (arr[i] < min) {
            min = arr[i];
        }
    }

    printf("\nSmallest Number: %d, Biggest Number: %d\n", min, max);

    return 0;
}