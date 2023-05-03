#include <string.h>

#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int res = 0;

  return res;
}

int main() {
    char str1[10] = "234467";
  char str2[10] = "23458";
  printf("my %d\n", s21_memcmp(str1, str2, 5));
  printf("orig %d\n", memcmp(str1, str2, 5));

  return 0;
}