/* 
    Saya Cantika Putri Arbiliansyah dengan nama [2103727] mengerjakan 
    Tugas Praktikum 2 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan 
    kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nama[50];
    int tanggal;
    int kode;
}barang;

typedef struct elmt *alamatelmt;

typedef struct elmt
{
    barang kontainer;
    alamatelmt prev;
    alamatelmt next;
} elemen;

typedef struct{
    elemen *first;
    elemen *tail;
}list;

void createList(list *L);
int countElement(list L);
void addFirst(char nama[], int tanggal, int kode, list *L);
void addAfter(elemen* before, char nama[], int tanggal, int kode, list *L);
void addBefore(elemen *after, char nama[], int tanggal, int kode, list *L);
void addLast(char nama[], int tanggal, int kode, list *L);
void delFirst(list *L);
void delAfter(elemen* before, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);
void printRev(list L);
void sort(list *L);
void sortPrev(list *L);
int delEl(elemen *before, list *L, int simpan[]);
void sortlagi(int simpan[], int kiri, int kanan);
void sortt(int jumlah, int simpan[]);