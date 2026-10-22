#include "my_string.h"

#include <errno.h>
#include <stdint.h>

typedef unsigned char UC;

/* 1. memchr */
void *my_memchr(const void *s, int c, size_t n)
{
    const UC *ptr = s;
    UC chr = (UC)c;

    for (size_t i = 0; i < n; i++)
    {
        if (ptr[i] == chr)
        {
            return (void *)(ptr + i);
        }
    }

    return NULL;
}

/* 2. memcmp */
int my_memcmp(const void *s1, const void *s2, size_t n)
{
    const UC *first = s1;
    const UC *second = s2;

    for (size_t i = 0; i < n; i++)
    {
        if (first[i] != second[i])
        {
            return (first[i] > second[i]) ? 1 : -1;
        }
    }

    return 0;
}

/* 3. memcpy: source and destination must not overlap */
void *my_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
    UC *dest_c = dest;
    const UC *src_c = src;

    for (size_t i = 0; i < n; i++)
    {
        dest_c[i] = src_c[i];
    }

    return dest;
}

/* 4. memmove: supports overlapping memory regions */
void *my_memmove(void *dest, const void *src, size_t n)
{
    UC *dest_c = dest;
    const UC *src_c = src;

    if (n == 0 || dest == src)
    {
        return dest;
    }

    uintptr_t d = (uintptr_t)dest_c;
    uintptr_t s = (uintptr_t)src_c;

    if (d < s || d - s >= n)
    {
        for (size_t i = 0; i < n; i++)
        {
            dest_c[i] = src_c[i];
        }
    }
    else
    {
        for (size_t i = n; i > 0; i--)
        {
            dest_c[i - 1] = src_c[i - 1];
        }
    }

    return dest;
}

/* 5. memset */
void *my_memset(void *s, int c, size_t n)
{
    UC *ptr = s;
    UC value = (UC)c;

    for (size_t i = 0; i < n; i++)
    {
        ptr[i] = value;
    }

    return s;
}

/* 6. strcat */
char *my_strcat(char *restrict dest, const char *restrict src)
{
    char *return_ptr = dest;

    while (*dest != '\\0')
    {
        dest++;
    }

    while ((*dest++ = *src++) != '\\0')
    {
    }

    return return_ptr;
}

/* 7. strchr */
char *my_strchr(const char *s, int c)
{
    unsigned char chr = (unsigned char)c;

    while (1)
    {
        if ((unsigned char)*s == chr)
        {
            return (char *)s;
        }

        if (*s == '\\0')
        {
            return NULL;
        }

        s++;
    }
}

/* 8. strcmp */
int my_strcmp(const char *s1, const char *s2)
{
    while (*s1 != '\\0' &&
           (unsigned char)*s1 == (unsigned char)*s2)
    {
        s1++;
        s2++;
    }

    unsigned char first = (unsigned char)*s1;
    unsigned char second = (unsigned char)*s2;

    return (first > second) - (first < second);
}

/* 9. strcoll: this basic implementation uses strcmp ordering */
int my_strcoll(const char *s1, const char *s2)
{
    return my_strcmp(s1, s2);
}

/* 10. strcpy */
char *my_strcpy(char *restrict dest, const char *restrict src)
{
    char *return_ptr = dest;

    while ((*dest++ = *src++) != '\\0')
    {
    }

    return return_ptr;
}

/* 11. strcspn */
size_t my_strcspn(const char *s, const char *reject)
{
    size_t count = 0;

    while (*s != '\\0')
    {
        const char *r = reject;

        while (*r != '\\0' && *r != *s)
        {
            r++;
        }

        if (*r != '\\0')
        {
            break;
        }

        count++;
        s++;
    }

    return count;
}

/* 12. strerror: simplified messages for common errors */
char *my_strerror(int errnum)
{
    switch (errnum)
    {
        case 0:
            return "No error";
#ifdef EDOM
        case EDOM:
            return "Domain error";
#endif
#ifdef ERANGE
        case ERANGE:
            return "Result out of range";
#endif
#ifdef EILSEQ
        case EILSEQ:
            return "Illegal byte sequence";
#endif
        default:
            return "Unknown error";
    }
}

/* 13. strlen */
size_t my_strlen(const char *s)
{
    size_t count = 0;

    while (s[count] != '\\0')
    {
        count++;
    }

    return count;
}

/* 15. strncmp */
int my_strncmp(const char *s1, const char *s2, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        unsigned char first = (unsigned char)s1[i];
        unsigned char second = (unsigned char)s2[i];

        if (first != second)
        {
            return (first > second) ? 1 : -1;
        }

        if (first == '\\0')
        {
            return 0;
        }
    }

    return 0;
}

/* 16. strncpy */
char *my_strncpy(char *restrict dest, const char *restrict src, size_t n)
{
    char *return_ptr = dest;
    size_t i = 0;

    while (i < n && src[i] != '\\0')
    {
        dest[i] = src[i];
        i++;
    }

    while (i < n)
    {
        dest[i] = '\\0';
        i++;
    }

    return return_ptr;
}

/* 17. strpbrk */
char *my_strpbrk(const char *s, const char *accept)
{
    while (*s != '\\0')
    {
        const char *a = accept;

        while (*a != '\\0' && *a != *s)
        {
            a++;
        }

        if (*a != '\\0')
        {
            return (char *)s;
        }

        s++;
    }

    return NULL;
}

/* 18. strrchr */
char *my_strrchr(const char *s, int c)
{
    unsigned char chr = (unsigned char)c;
    const char *last = NULL;

    while (1)
    {
        if ((unsigned char)*s == chr)
        {
            last = s;
        }

        if (*s == '\\0')
        {
            break;
        }

        s++;
    }

    return (char *)last;
}

/* 19. strspn */
size_t my_strspn(const char *s, const char *accept)
{
    size_t count = 0;

    while (*s != '\\0')
    {
        const char *a = accept;

        while (*a != '\\0' && *a != *s)
        {
            a++;
        }

        if (*a == '\\0')
        {
            break;
        }

        count++;
        s++;
    }

    return count;
}

/* 20. strstr */
char *my_strstr(const char *haystack, const char *needle)
{
    if (*needle == '\\0')
    {
        return (char *)haystack;
    }

    while (*haystack != '\\0')
    {
        const char *h = haystack;
        const char *n = needle;

        while (*h != '\\0' && *n != '\\0' && *h == *n)
        {
            h++;
            n++;
        }

        if (*n == '\\0')
        {
            return (char *)haystack;
        }

        haystack++;
    }

    return NULL;
}

