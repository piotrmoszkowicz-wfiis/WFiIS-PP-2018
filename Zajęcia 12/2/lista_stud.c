#include "lista_stud.h"

STUDENT* utworz_element(){
  STUDENT *element;
  char bufor[30 + 1];
  char *imie, *nazwisko;
  printf("Podaj imie:\n");
  gets(bufor);
  imie = malloc((strlen(bufor)+1) * sizeof(char));
  strcpy(imie, bufor);

  printf("Podaj nazwisko:\n");
  gets(bufor);
  nazwisko = malloc((strlen(bufor)+1) * sizeof(char));
  strcpy(nazwisko, bufor);

  element = malloc(sizeof(STUDENT));
  element->next = NULL;
  element->prev = NULL;
  element->dane.imie = imie;
  element->dane.nazwisko = nazwisko;
  return element;
}

void pokaz_osoba(Osoba a){
  printf("Imie: %s Nazwisko: %s\n", a.imie, a.nazwisko);
}

void pokaz_element(STUDENT* stud){
  printf("Prev: %p\n", stud->prev);
  pokaz_osoba(stud->dane);
  printf("Next: %p\n", stud->next);
}

void dodaj_na_poczatek(STUDENT** head, STUDENT* newStudent){
  newStudent->prev = NULL;
  newStudent->next = *head;

  if(*head){
    (*head)->prev = newStudent;
  }

  *head = newStudent;
}

void printList(STUDENT* head){
  STUDENT* wsk = head;

  printf("Lista osob:\n");
  while (wsk)
  {
    pokaz_element(wsk);
    wsk = wsk->next;
  }
  printf("Koniec.\n");
}

void clearList(STUDENT** head){
  STUDENT* wsk = *head;
  while(wsk){
    STUDENT* temp = wsk -> next;
    free(wsk);
    wsk = temp;
  }
  head = NULL;
}

int compareOsoba(Osoba a, Osoba b){
  if(strcmp(a.imie, b.imie) == 0 && strcmp(a.nazwisko, b.nazwisko) == 0){
    return 0;
  }
  return 1;
}

STUDENT* findInList(STUDENT* head, Osoba needleStudent){
  while (head->next && compareOsoba(head->dane, needleStudent))
  {
    head = head->next;
  }

  if (head != NULL && compareOsoba(head->dane, needleStudent) == 0)
  {
    printf("Znalazlem pod adresem: %p: \n", head);
    pokaz_element(head);
    return head;
  }
  else
  {
    printf("Nie znaleziono wartosci\n");
    return NULL;
  }
}

void deleteFromList(STUDENT** head, Osoba needleStudent){
  STUDENT *wsk = *head;

  wsk = findInList(*head, needleStudent);

  if (wsk)
  {
    STUDENT *prevWsk = wsk->prev;
    STUDENT *nextWsk = wsk->next;
    printf("p: %p n: %p", prevWsk, nextWsk);

    if(wsk == *head){
      free(wsk);
      *head = nextWsk;
    }

    prevWsk->next = nextWsk;
    if (nextWsk){
      nextWsk->prev = prevWsk;
    }
    
    free(wsk);
  }
}