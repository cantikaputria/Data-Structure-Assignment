/* 
    Saya Cantika Putri Arbiliansyah dengan nama [2103727] mengerjakan 
    Test Mesin 5 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
 char label[50];
 char kode[50];
}mahasiswa;

typedef struct{
 char barang[50];
}matKul;

typedef struct eklm *alamatekolom;

typedef struct eklm{
 matKul kontainer_kol;
 alamatekolom next_kol;
}eKolom;

typedef struct ebr *alamatebaris;

typedef struct ebr{
 mahasiswa kontainer;
 eKolom *col;
 alamatebaris next;
}eBaris;

typedef struct{
 eBaris *first;
}list;

void createList(list *L);
int countElementB(list L);
int countElementK(eBaris L);
void addFirstB(char label[], char kode[], list *L);
void addFirstK(char barang[], eBaris *L);
void addAfterB(eBaris* prev, char label[], char kode[]);
void addAfterK(eKolom* prev, char barang[]);
void addLastB(char label[], char kode[], list *L);
void addLastK(char barang[], eBaris *L);
void delFirstB(list *L);
void delFirstK(eBaris *L);
void delAfterB(eBaris* prev);
void delAfterK(eKolom* prev);
void delLastB(list *L);
void delLastK(eBaris *L);
void delAllK(eBaris *L);
void delAllB(list *L);
void printElement(list L);
eBaris* get(char kode[], list L);