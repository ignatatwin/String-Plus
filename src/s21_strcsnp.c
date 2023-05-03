#include <stdio.h>
#include <string.h>

#include "s21_string.h"

size_t s21_strcspn(const char *str1, const char *str2) {
  int res = 0;
  int k = strlen(str1);
  int l = strlen(str2);

  for (int i = 0; i < k; i++) {    // str1
    for (int j = 0; j < l; j++) {  // str2
      if (str1[i] != str2[j]) {
        res++;
      } else {
        i = k;
        j = l;
      }
    }
  }

  return res / l;
}

int main() {
  char str[1024] = "sfvd";
  char sym[1024] = "edfvrvwgrf1";

  int res1 = strcspn(str, sym);
  printf("orig %d\n", res1);

  int res = s21_strcspn(str, sym);
  printf("my %d\n", res);

  return 0;
}