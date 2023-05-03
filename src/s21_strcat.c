#include <stdio.h>
#include <string.h>

#include "s21_string.h"

char *s21_strcat(char *dest, const char *src) {
  int i = strlen(dest);
  int j = strlen(src);

  for (int k = 0; k < (i + j); k++) {
    dest[i + k] = src[k];
  }
  return dest;
}

int main() {
  char str1[1024] = "hello";
  char str2[1024] = "world";

  //   strcat(str1, str2);
  //   printf("%s\n", s21_strcat(str1, str2));

  printf("%s\n", s21_strcat(str1, str2));

  return 0;
}
