#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  int size = 0;
  while (str[size] != '\0') {
    size++;
  }
  return size;
}