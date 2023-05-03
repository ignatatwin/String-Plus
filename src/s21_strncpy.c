#include <stdio.h>
#include <string.h>

#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, size_t n) {
  int k = strlen(src);
  for (int i = 0; i < n; i++) {
    dest[i] = src[i];
  }
  return (char *)dest;
}

int main() {
  char dest[1024] = "hello";
  char src[1024] = "world";

  //   printf("%s\n", strncpy(dest, src, 1));

  printf("%s\n", s21_strncpy(dest, src, 3));
  //   printf("%s\n", dest);
  return 0;
}