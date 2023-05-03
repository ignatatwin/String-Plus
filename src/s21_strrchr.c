#include <stdio.h>
#include <string.h>

#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *res = (char *)str;
  int k = strlen(str);

  for (int i = k; i > 0; i--) {
    if (res[i] == c) {
      res = &res[i];
    } else {
      res = "(null)";
    }
  }

  return res;
}

int main() {
  const char *str = "helmlo";
  int c = 107;

  printf("%s\n", strrchr(str, c));
  printf("%s\n", s21_strrchr(str, c));

  return 0;
}