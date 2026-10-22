#ifndef MY_STRING_H
#define MY_STRING_H

#include <stddef.h>

void *my_memchr(const void *s, int c, size_t n);
int my_memcmp(const void *s1, const void *s2, size_t n);
void *my_memcpy(void *restrict dest, const void *restrict src, size_t n);
void *my_memmove(void *dest, const void *src, size_t n);
void *my_memset(void *s, int c, size_t n);

char *my_strcat(char *restrict dest, const char *restrict src);
char *my_strchr(const char *s, int c);
int my_strcmp(const char *s1, const char *s2);
int my_strcoll(const char *s1, const char *s2);
char *my_strcpy(char *restrict dest, const char *restrict src);
size_t my_strcspn(const char *s, const char *reject);
char *my_strerror(int errnum);
size_t my_strlen(const char *s);
char *my_strncat(char *restrict dest, const char *restrict src, size_t n);
int my_strncmp(const char *s1, const char *s2, size_t n);
char *my_strncpy(char *restrict dest, const char *restrict src, size_t n);
char *my_strpbrk(const char *s, const char *accept);
char *my_strrchr(const char *s, int c);
size_t my_strspn(const char *s, const char *accept);
char *my_strstr(const char *haystack, const char *needle);
char *my_strtok(char *restrict str, const char *restrict delim);

#endif
