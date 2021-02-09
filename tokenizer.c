#include <stdio.h>

int main()
{
  char str[100];
  printf("Hello please enter a string!: ");
  gets(str);

  printf("$ ");
  puts(str);

  return 0;
}
