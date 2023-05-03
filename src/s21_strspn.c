#include <string.h>

#include "s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t count = 0;
  int flag = 0;
  for (s21_size_t i = 0; i < s21_strlen(str2); i++) {
    for (s21_size_t j = 0; j < s21_strlen(str1); j++) {
      if (str2[i] == str1[j] && !flag) {
        count++;
        flag++;
      }
    }
    flag = 0;
  }
  return count;
}