/* 
    Saya Cantika Putri Arbiliansyah dengan NIM [2103727] mengerjakan 
    Test Mesin 1 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    char nama[50];
    char level[10];
    char asal[50];
}game;

typedef struct
{
    game kontainer;
    int next;
}elemen;

typedef struct
{
    int first;
    elemen data[5];
}list;

void createList(list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(char nama[], char level[], char asal[], list *L);
void addAfter(int prev, char nama[], char level[], char asal[], list *L);
void addLast(char nama[], char level[], char asal[], list *L);
void delFirst(list *L);
void delAfter(int prev, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);