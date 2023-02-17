/* 
    Saya Cantika Putri Arbiliansyah dengan nama [2103727] mengerjakan 
    Tugas Praktikum 5 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/
#include <stdio.h>
#include <malloc.h>

typedef struct smp *alamatsimpul;
typedef struct jlr *alamatjalur;

typedef struct {
    char c;
    int visited;
} data;

typedef struct smp
{
    char kontainer;
    alamatsimpul next;
    alamatjalur arc;
}simpul;

typedef struct jlr
{
    int kontainer_jalur;
    alamatjalur next_jalur;
    simpul *tujuan;
}jalur;

typedef struct
{
    simpul* first;
}graph;

void createEmpty(graph *G);
void addSimpul(int c, graph *G);
void addJalur(simpul *awal, simpul *tujuan, int beban);
simpul* findSimpul(int c, graph G);
void delJalur(int ctujuan, simpul *awal);
void delAll(simpul *awal);
void delSimpul(int c, graph *G);
void printGraph(graph G);
