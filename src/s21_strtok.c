#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  char *istrr = s21_NULL;
  s21_size_t k = 0;
  if (str != s21_NULL) {
    for (s21_size_t i = 0; i < s21_strlen(str); i++) {
      if (str[i] != (char)delim) {
        istrr[k] = str[i];
        k++;
      } else
        break;
    }
  }
  return istrr;
}

#include <string.h>  // Для strtok
int main(void) {
  // Массив со строкой для поиска
  char str[] = "test1/test2/test3/test4";
  // Набор символов, которые должны входить в искомый сегмент
  char sep[] = "/";
  // Переменная, в которую будут заноситься начальные адреса частей
  // строки str
  char *istr = s21_NULL;
  char *istr1 = s21_NULL;

  printf("Исходная строка: %s\n", str);
  printf("Результат разбиения:\n");
  // Выделение первой части строки
  istr = strtok(str, sep);

  // Выделение последующих частей
  while (istr != NULL) {
    // Вывод очередной выделенной части
    printf("%s\n", istr);
    // Выделение очередной части строки
    istr = strtok(NULL, sep);
  }
  istr1 = s21_strtok(str, sep);
  while (istr1 != NULL) {
    // Вывод очередной выделенной части
    printf("%s\n", istr1);
    // Выделение очередной части строки
    istr1 = s21_strtok(NULL, sep);
  }

  return 0;
}