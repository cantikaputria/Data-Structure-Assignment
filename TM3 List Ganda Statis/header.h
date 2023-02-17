
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nama[50];
    char tgl[50];
    char jumlah[50];
}zoo;

//deklarasi pointernya aja, alokasiin di memori bakal ada pointer, tapi belum di deklarasiin

typedef struct
{
    zoo kontainer;
    int prev;
    int next;
}elemen;

typedef struct
{
    int first;
    int tail;
    elemen data[7];
}list;

void createList(list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(char nama[], char tgl[], char jumlah[], list *L);
void addAfter(int before, char nama[], char tgl[], char jumlah[], list *L);
void addLast(char nama[], char tgl[], char jumlah[], list *L);
void delFirst(list *L);
void delAfter(int before, list *L);
void delLast(list *L);
void printElement(list L);
void printRev(list L);
void delAll(list *L);
