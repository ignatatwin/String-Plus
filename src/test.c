#include <stdio.h>
#include <string.h>

//  INSERT ////// NO

//  MEMCHR  ////// YES
//   while ((i < n) && str1 && flag) / зачем str1?

//  MEMCMP /////// YES

// MEMCPY /////// YES

// MEMMOVE //////// YES

//  MEMSET ///// YES

// STRCAT /////// NO

// STRCHR ////// YES

//  STRCMP ////// YES

// STRCPY ////// YES

// STRCSPN  //////
int main() {
  int c = 'o';
  //   size_t n = 5;
  char src[] = "hello";
  char dest[] = "s";

  //   strcspn(src, dest);

  int res = strcspn(src, dest);

  printf("%d\n", res);

  return 0;
}