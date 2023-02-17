/* 
    Saya Cantika Putri Arbiliansyah dengan nama [2103727] mengerjakan 
    Test Mesin 4 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nama[50];
    char nim[50];
    char golDar[50];
}data;

typedef struct elmt *alamatelmt;

typedef struct elmt
{
    data kontainer;
    alamatelmt prev;
    alamatelmt next;
} elemen;

typedef struct{
    elemen *first;
    elemen *tail;
}list;

void createList(list *L);
int countElement(list L);
void addFirst(char nama[], char nim[], char golDar[], list *L);
void addAfter(elemen* before, char nama[], char nim[], char golDar[], list *L);
void addBefore(elemen *after, char nama[], char nim[], char golDar[], list *L);
void addLast(char nama[], char nim[], char golDar[], list *L);
void delFirst(list *L);
void delAfter(elemen* before, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);
void printRev(list L);