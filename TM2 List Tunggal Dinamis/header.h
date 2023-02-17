/* 
    Saya Cantika Putri Arbiliansyah dengan NIM [2103727] mengerjakan 
    Test Mesin 2 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nama[50];
    char jk[50];
    char asal[50];
}buku;

//deklarasi pointernya aja, alokasiin di memori bakal ada pointer, tapi belum di deklarasiin
typedef struct elmt* alamatelmt;

typedef struct elmt
{
    buku kontainer;
    alamatelmt next;        //dipake disini, yg atas ga kepake lagi
} elemen;

typedef struct
{   
    //first adalah pointer yg menunjuk ke elemen
    elemen* first;
}list;

void createList(list *L);
int countElement(list L);
void addFirst(char nama[], char jk[], char asal[], list *L);
void addAfter(elemen* prev, char nama[], char jk[], char asal[], list *L);
void addLast(char nama[], char jk[], char asal[], list *L);
void delFirst(list *L);
void delAfter(elemen* prev, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);