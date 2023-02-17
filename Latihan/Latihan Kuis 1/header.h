#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char food[50];
    int price;
}menu;

//deklarasi pointernya aja, alokasiin di memori bakal ada pointer, tapi belum di deklarasiin
typedef struct elmt* alamatelmt;

typedef struct elmt
{
    menu kontainer;
    alamatelmt next;        //dipake disini, yg atas ga kepake lagi
} elemen;

typedef struct
{   
    //first adalah pointer yg menunjuk ke elemen
    elemen* first;
}list;

void createList(list *L);
int countElement(list L);
void addFirst(char food[], int price, list *L);
void addAfter(elemen* prev, char food[], int price, list *L);
void addLast(char food[], int price, list *L);
void printElement(list L);
void tuker(list *L1, list *L2, char tuker1[50], char tuker2[50]);