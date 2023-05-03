#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *count = s21_NULL;
  for (s21_size_t i = 0; i < s21_strlen(haystack); i++) {
    for (s21_size_t j = 0; j < s21_strlen(needle); j++) {
      if (haystack[i] == needle[j]) {
        if (s21_memcmp(&haystack[i], needle, s21_strlen(needle)) == 0) {
          count = (char *)&haystack[i];
          break;
        }
      }
    }
  }
  return count;
}