#include <stdio.h>
#include <string.h>

//DATA DIBUNGKUS MENJADI NILAI MATKUL
typedef struct
{
    char nim[10];
    char nama[50];
    char nilai[2];
}nilaiMatKul;

//PEMBUATAN ELEMEN BERISI STRUCK NILAI MATKUL DAN POINTER
typedef struct
{
    nilaiMatKul kontainer;
    int next;
}elemen;

//PEMBUATAN LIST BERISIKAN ELEMEN
typedef struct
{
    int first;
    elemen data[10];
}list;

//PROSEDUR
void createList(list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(char nim[], char nama[], char nilai[], list *L);
void addAfter(int prev, char nim[], char nama[], char nilai[], list *L);
void addLast(char nim[], char nama[], char nilai[], list *L);
void delFirst(list *L);
void delAfter(int prev, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);