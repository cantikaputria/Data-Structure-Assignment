/* 
    Saya Cantika Putri Arbiliansyah dengan nama [2103727] mengerjakan 
    Tugas Praktikum 5 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

//LIBRARY
#include <stdio.h>
#include <string.h>
#include <malloc.h>

//STRUCT
typedef struct smp *alamatsimpul;
typedef struct jlr *alamatjalur;

//STRUCT PENAMPUNG DATA INPUT
typedef struct
{
    char c;
} input;

//SIMPUL
typedef struct smp
{
    input kontainer;
    alamatsimpul next;
    alamatjalur arc;
}simpul;

//JALUR
typedef struct jlr
{
    int bobot;
    alamatjalur next_jalur;
    simpul *tujuan;
}jalur;

//GRAPH
typedef struct
{
    simpul* first;
}graph;

//PROSEDUR DAN FUNGSI
void createEmpty(graph *G);                                                                         //prosedur untuk membuat graph
void addSimpul(input c, graph *G);                                                                  //prosedur untuk menambahkan simpul
void addJalur(simpul *awal, simpul *tujuan, int beban);                                             //prosedur untuk menambahkan jalur
simpul* findSimpul(input c, graph G);                                                               //fungsi untuk mencari simpul
void findJalur(input awal, input akhir, graph G, int totbot, char temp[], int i);                   //prosedur untuk mencari jalur