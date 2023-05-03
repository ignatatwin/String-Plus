#include <stdio.h>
#include <string.h>

#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *symb = (unsigned char *)str;
  char *res = "world";
  s21_size_t i = 0;
  s21_size_t m = 0;
  int k = 0;

  while (i < n) {
    if (symb[i] == c) {
      return ((char *)(res + i));
    }
    i++;
  }

  return s21_NULL;
}

int main() {
  const char str[] = "world";
  char *c;

  c = s21_memchr(str, 'o', 4);
  printf("%s\n", c);

  return 0;
}