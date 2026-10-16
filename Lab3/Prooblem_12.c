#include <stdio.h>

int main() {
    char src[] = "bmw";
    char dst[20] = "aud";

    int srcLen = 0;
    while (src[srcLen] != '\0') {
        srcLen++;
    }

    int dstLen = 0;
    while (dst[dstLen] != '\0') {
        dstLen++;
    }

    if (dstLen < srcLen) {
        printf("\n destination is < than source");
        return 0;
    }

    for (int i = 0; i < srcLen; i++) {
        dst[i] = src[i];
    }

    dst[srcLen] = '\0';

    printf("\nNew Destination: ");

    for (int i = 0; dst[i] != '\0'; i++) {
        printf("%c", dst[i]);
    }

    return 0;
}