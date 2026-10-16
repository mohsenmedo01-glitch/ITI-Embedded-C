#include <stdio.h>

int main() {
    int arr[] = {6, 4, 6, 0, 7, 4};
    int len = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < len - 1; i++) {
        int swapped = 0;

        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = 1;
            }
        }

        if (swapped == 0) {
            break;
        }
    }

    printf("\nArray After Sorting (Descending): ");

    for (int i = 0; i < len; i++) {
        printf(" %d", arr[i]);
    }

    return 0;
}