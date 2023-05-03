#include <string.h>  // Для strchr

#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *ach = s21_NULL;
  for (s21_size_t i = 0; i < s21_strlen(str); i++) {
    if ((int)str[i] == c) {
      ach = (char *)&str[i];
      break;
    }
  }
  return ach;
}