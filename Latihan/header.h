#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char string[10];
}sederhana;

//deklarasi pointernya aja, alokasiin di memori bakal ada pointer, tapi belum di deklarasiin
typedef struct elmt* alamatelmt;

typedef struct elmt
{
    sederhana kontainer;
    alamatelmt next;        //dipake disini, yg atas ga kepake lagi
} elemen;

typedef struct
{   
    //first adalah pointer yg menunjuk ke elemen
    elemen* first;
}list;

void createList(list *L);
int countElement(list L);
void addFirst(sederhana input, list *L);
// void addAfter(elemen* prev, char string[], list *L);
// void addLast(char string[], list *L);
void delFirst(list *L);
void delAfter(elemen* prev, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);