#include <stdio.h>

struct zxy
{
  char znak;
  struct zxy *wsk;
};

int main(int argc, char const *argv[])
{
  struct zxy a, b, c;

  a.wsk = &b;
  b.wsk = &c;
  c.wsk = &a;

  (*a.wsk).znak = 'b';
  (*(*a.wsk).wsk).znak = 'c';
  (*(*(*a.wsk).wsk).wsk).znak = 'a';

  printf("Znak A: %c, Znak B: %c, Znak C: %c\n", (*(*b.wsk).wsk).znak, (*(*(*b.wsk).wsk).wsk).znak, (*b.wsk).znak);

  (*c.wsk).znak = 'A';
  (*(*c.wsk).wsk).znak = 'B';
  (*(*(*c.wsk).wsk).wsk).znak = 'C';

  printf("Znak A: %c, Znak B: %c, Znak C: %c\n", (*(*b.wsk).wsk).znak, (*(*(*b.wsk).wsk).wsk).znak, (*b.wsk).znak);

  return 0;
}
