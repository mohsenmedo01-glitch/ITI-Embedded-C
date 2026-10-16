#include <stdio.h>

int main() {
    char src[] = "Mohamed";
    char dst[8];
    int len = 7;

    for (int i = 0; i < len; i++) {
        dst[i] = src[i];
    }

    dst[len] = '\0';

    printf("Source: %s\n", src);
    printf("Destination: %s\n", dst);

    return 0;
}