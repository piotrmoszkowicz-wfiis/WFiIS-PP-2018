#include "lista_stud.h"

int main(int argc, char const *argv[])
{
  STUDENT* nowyStudent;
  STUDENT* head = NULL;

  nowyStudent = utworz_element();
  dodaj_na_poczatek(&head, nowyStudent);
  nowyStudent = utworz_element();
  dodaj_na_poczatek(&head, nowyStudent);
  printList(head);

  Osoba needleStudent = {"Piotr", "Moszkowicz"};

  deleteFromList(&head, needleStudent);

  printf("\n\n\n\n");

  printList(head);

  return 0;
}
