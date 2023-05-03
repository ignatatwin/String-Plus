#include <string.h>  //Для memmove

#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  unsigned char *src = 0;
}

int main(void) {
  // Исходный массив данных
  unsigned char src[] = "1234567890";

  // Вывод массива src на консоль
  printf("src old: %s\n", src);

  // Копируем 3 байт
  memmove(&src[4], &src[3], 3);

  // Вывод массива src на консоль
  printf("src new: %s\n", src);

  return 0;
}