#include <stdio.h>
#include <string.h>

#include "s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
  int k = strlen(src);
  for (int i = 0; i < k; i++) {
    dest[i] = src[i];
  }
  return (char *)dest;
}

int main() {
  char dest[1024] = "hello";
  char src[1024] = "world";

  printf("%s\n", s21_strcpy(dest, src));
  printf("%s\n", dest);
  return 0;
}