#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Osoba
{
  char *imie;
  char *nazwisko;
} Osoba;

typedef struct Stud
{
  Osoba dane;
  struct Stud *next;
  struct Stud *prev;
} STUDENT;

STUDENT* utworz_element();
void pokaz_osoba(Osoba a);
void pokaz_element(STUDENT* stud);
void dodaj_na_poczatek(STUDENT** head, STUDENT* newStudent);
void printList(STUDENT* head);
int compareOsoba(Osoba a, Osoba b);
void clearList(STUDENT** head);
STUDENT* findInList(STUDENT*head, Osoba needleStudent);
void deleteFromList(STUDENT** head, Osoba needleStudent);

#endif