#include <stdio.h>
#include <string.h>

//DEKLARASI ELEMEN
typedef struct
{
    int x;
}input;

typedef struct
{
    input kontainer;
    int next;
}elemen;

typedef struct
{
    int first;
    elemen data[10];
}list;

void addFirst(int x, list *L);
void printElement(list L);
void createList(list *L);
int countElement(list L);
int emptyElement(list L);
