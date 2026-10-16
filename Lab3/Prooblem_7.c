#include <stdio.h>
// google assistant 
int main() {
    int num = 5;
    int Binary[32] = {0};
    int copy = num;

    for (int i = 0; i < 32; i++) {
        if (copy <= 0) {
            break;
        }
        Binary[32 - i - 1] = copy % 2;
        copy /= 2;
    }

    printf("\nBinary of %d is: ", num);

    for (int i = 0; i < 32; i++) {
        printf("%d", Binary[i]);
    }

    return 0;
}