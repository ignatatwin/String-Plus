#include <stdio.h>
#include <string.h>

#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, size_t n) {
  int i = strlen(dest);
  int j = strlen(src);

  for (int k = 0; k < n; k++) {
    dest[i + k] = src[k];
  }
  return dest;
}

int main() {
  char str1[1024] = "hello";
  char str2[1024] = "world";

  //   printf("%s\n", strncat(str1, str2, 3));

  printf("%s\n", s21_strncat(str1, str2, 4));

  return 0;
}
