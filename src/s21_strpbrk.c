#include <stdio.h>
#include <string.h>

#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *first = (char *)str1;
  char *second = (char *)str2;

  int l = strlen(second);
  char *res;
  int work = 1;

  while (work == 1) {
    for (int i = 0; i < l; i++) {
      if (*first == second[i]) {
        work = 0;
        res = first;
      }
    }
    first++;
  }

  return (char *)res;
}

int main() {
  char *str1 = "fijqhwgpe";
  char *str2 = "wkg";

  printf("my %s\n", s21_strpbrk(str1, str2));
  printf("orig %s\n", strpbrk(str1, str2));
  return 0;
}