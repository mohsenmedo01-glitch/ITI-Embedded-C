#include <stdio.h>
#include <stddef.h>
#include "my_string.h"

int main(void)
{
    /* 1. memchr */
    unsigned char bytes[] = {0x10, 0x20, 0x30, 0x20};
    unsigned char *found = my_memchr(bytes, 0x20, 4);
    printf("1. memchr: %td (expected 1)\n", found ? found - bytes : -1);

    /* 2. memcmp */
    printf("2. memcmp: %d (expected negative)\n", my_memcmp("abcd", "abce", 4));
    printf("   memcmp: %d (expected 0)\n", my_memcmp("abcd", "abce", 3));

    /* 3. memcpy */
    char copy1[6];
    my_memcpy(copy1, "hello", 6);
    printf("3. memcpy: %s (expected hello)\n", copy1);

    /* 4. memmove */
    char move1[] = "abcdef";
    my_memmove(move1 + 2, move1, 3);
    printf("4. memmove: %s (expected ababc f without space)\n", move1);

    /* 5. memset */
    char set1[] = "hello";
    my_memset(set1, '*', 3);
    printf("5. memset: %s (expected ***lo)\n", set1);

    /* 6. strcat */
    char cat1[20] = "hello";
    my_strcat(cat1, " world");
    printf("6. strcat: %s (expected hello world)\n", cat1);

    /* 7. strchr */
    char *p = my_strchr("hello world", 'o');
    printf("7. strchr: %s (expected o world)\n", p ? p : "NULL");

    /* 8. strcmp */
    printf("8. strcmp: %d (expected positive)\n", my_strcmp("abc", "ab"));

    /* 9. strcoll */
    printf("9. strcoll: %d (expected negative)\n", my_strcoll("abc", "abd"));

    /* 10. strcpy */
    char copy2[20];
    my_strcpy(copy2, "embedded");
    printf("10. strcpy: %s (expected embedded)\n", copy2);

    /* 11. strcspn */
    printf("11. strcspn: %zu (expected 5)\n", my_strcspn("hello, world", ", "));

    /* 12. strerror */
    printf("12. strerror: %s\n", my_strerror(0));

    /* 13. strlen */
    printf("13. strlen: %zu (expected 5)\n", my_strlen("hello"));

    /* 14. strncat */
    char cat2[20] = "hello";
    my_strncat(cat2, "barbaz", 3);
    printf("14. strncat: %s (expected hellobar)\n", cat2);

    /* 15. strncmp */
    printf("15. strncmp: %d (expected 0)\n", my_strncmp("hello", "help", 3));

    /* 16. strncpy */
    char copy3[10];
    my_strncpy(copy3, "hello", 7);
    printf("16. strncpy: %s (expected hello)\n", copy3);

    /* 17. strpbrk */
    p = my_strpbrk("hello, world", "wo");
    printf("17. strpbrk: %s (expected o, world)\n", p ? p : "NULL");

    /* 18. strrchr */
    p = my_strrchr("hello world", 'o');
    printf("18. strrchr: %s (expected orld)\n", p ? p : "NULL");

    /* 19. strspn */
    printf("19. strspn: %zu (expected 3)\n", my_strspn("123abc", "0123456789"));

    /* 20. strstr */
    p = my_strstr("the cat sat", "cat");
    printf("20. strstr: %s (expected cat sat)\n", p ? p : "NULL");

    /* 21. strtok */
    char tokens[] = "  one,two;;three ";
    int count = 0;
    p = my_strtok(tokens, ",; ");

    while (p != NULL && count < 10)
    {
        printf("21. strtok: %s\n", p);
        count++;
        p = my_strtok(NULL, ",; ");
    }

    printf("\nAll tests completed.\n");
    return 0;
}
