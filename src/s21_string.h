#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <stdio.h>

#define s21_NULL ((void *)0)

typedef unsigned long s21_size_t;

void *s21_memchr(const void *str, int c, s21_size_t n);             // NO
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);   // ok
void *s21_memcpy(void *dest, const void *src, s21_size_t n);        // ok
void *s21_memmove(void *dest, const void *src, s21_size_t n);       // NO
void *s21_memset(void *str, int c, s21_size_t n);                   // ok
char *s21_strcat(char *dest, const char *src);                      // ok
char *s21_strncat(char *dest, const char *src, s21_size_t n);       // ok
char *s21_strchr(const char *str, int c);                           // ok
int s21_strcmp(const char *str1, const char *str2);                 // ok
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);  // ok
char *s21_strcpy(char *dest, const char *src);                      // ok
char *s21_strncpy(char *dest, const char *src, s21_size_t n);       // ok
s21_size_t s21_strcspn(const char *str1, const char *str2);         // ok
char *s21_strerror(int errnum);                                     // ok
s21_size_t s21_strlen(const char *str);                             // ok
char *s21_strpbrk(const char *str1, const char *str2);              // ok
char *s21_strrchr(const char *str, int c);                          // ok
s21_size_t s21_strspn(const char *str1, const char *str2);          // ok
char *s21_strstr(const char *haystack, const char *needle);         // ok
char *s21_strtok(char *str, const char *delim);                     // NO

#endif  // SRC_S21_STRING_H_