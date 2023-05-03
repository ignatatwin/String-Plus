#include <string.h>

#include "s21_string.h"

int s21_strcmp(const char *str1, const char *str2) {
  for (; *str1 == *str2; str1++, str2++) {
  }

  return *str1 - *str2;
}

int main() {
  char *str1 = "h4te";
  char *str2 = "hellob";
  printf("my %d\n", s21_strcmp(str1, str2));
  printf("orig %d\n", strcmp(str1, str2));

  return 0;
}