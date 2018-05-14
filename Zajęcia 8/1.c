#include <stdio.h>

struct wektor3D
{
  int x;
  int y;
  int z;
};

struct wektor3D sumujWektor(struct wektor3D w1, struct wektor3D w2)
{
  struct wektor3D sum;
  sum.x = w1.x + w2.x;
  sum.y = w1.y + w2.y;
  sum.z = w1.z + w2.z;

  return sum;
}

void iloczynSkalarny(struct wektor3D *w1, struct wektor3D *w2)
{
  int skalar = w1->x * w2->x + w1->y * w2->y + w1->z * w2->z;

  printf("Iloczyn skalarny = %d\n", skalar);
}

void iloczynWektorowy(struct wektor3D w1, struct wektor3D w2, struct wektor3D *wyn)
{
  wyn->x = (w1.y * w2.z) - (w1.z * w2.y);
  wyn->y = (w1.z * w2.x) - (w1.x * w2.z);
  wyn->z = (w1.x * w2.y) - (w1.y * w2.x);
}

int main(int argc, char const *argv[])
{
  struct wektor3D w1, w2, wynSum, wynWekt;

  printf("Podaj wspolrzedne wektora 1:\n");
  scanf("%d %d %d", &(w1.x), &(w1.y), &(w1.z));

  printf("Podaj wspolrzedne wektora 2:\n");
  scanf("%d %d %d", &(w2.x), &(w2.y), &(w2.z));

  wynSum = sumujWektor(w1, w2);
  printf("Sum: x = %d, y = %d, z = %d\n", wynSum.x, wynSum.y, wynSum.z);

  iloczynSkalarny(&w1, &w2);

  iloczynWektorowy(w1, w2, &wynWekt);
  printf("Wekt: x = %d, y = %d, z = %d\n", wynWekt.x, wynWekt.y, wynWekt.z);

  return 0;
}
