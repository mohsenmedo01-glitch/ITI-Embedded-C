#include <stdio.h>
#include <string.h>

int main() {
    int arr[] = {0, 55, 7, 2, 0, 55, 7};
    int len = sizeof(arr) / sizeof(arr[0]);

    int foundElements[999];
    memset(foundElements, -1, sizeof(foundElements));

    for (int i = 0; i < len; i++) {
        int previouslyFound = 0;

        for (int j = 0; j < len; j++) {
            if (foundElements[j] == -1) {
                foundElements[j] = arr[i];
                break;
            }

            if (arr[i] == foundElements[j]) {
                previouslyFound = 1;
                break;
            }
        }

        if (previouslyFound == 0) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}