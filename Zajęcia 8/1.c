#include <stdio.h>

struct wektor3D
{
  float x;
  float y;
  float z;
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
  float skalar = w1->x * w2->x + w1->y * w2->y + w1->z * w2->z;

  printf("Iloczyn skalarny = %f\n", skalar);
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
  scanf("%f %f %f", &(w1.x), &(w1.y), &(w1.z));

  printf("Podaj wspolrzedne wektora 2:\n");
  scanf("%f %f %f", &(w2.x), &(w2.y), &(w2.z));

  wynSum = sumujWektor(w1, w2);
  printf("Sum: x = %f, y = %f, z = %f\n", wynSum.x, wynSum.y, wynSum.z);

  iloczynSkalarny(&w1, &w2);

  iloczynWektorowy(w1, w2, &wynWekt);
  printf("Wekt: x = %f, y = %f, z = %f\n", wynWekt.x, wynWekt.y, wynWekt.z);

  return 0;
}
