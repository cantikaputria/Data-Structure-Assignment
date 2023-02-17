/* 
    Saya Cantika Putri Arbiliansyah dengan NIM [2103727] mengerjakan 
    UAS No 2 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

//LIBRARY
#include <stdio.h>
#include <malloc.h>
#include <string.h>

//ALOKASI MEMORI
typedef struct smp *alamatsimpul;
typedef struct jlr *alamatjalur;

//PEMANMPUNG DATA
typedef struct
{
    char c;                                     //variabel penampung karakter
}input;

//SIMPUL 
typedef struct smp
{
    input kontainer;                             //kontainer data
    alamatsimpul next;                          //pointer next simpul
    alamatjalur arc;                            //pointer jalur
}simpul;

//JALUR
typedef struct jlr
{
    int kontainer_jalur;                                          //niali kontainer jalur      
    alamatjalur next_jalur;                                       //pointer next jalur
    simpul *tujuan;                                               //pointer tujuan
}jalur;

//GRAPH
typedef struct
{
    simpul* first;                                                 //pointer node first
}graph; 

//PROSEDUR DAN FUNGSI
void createEmpty(graph *G);                                        //prosedur untuk membuat graph
void addSimpul(input c, graph *G);                                   //prosedur untuk menambahkan simpul
void addJalur(simpul *awal, simpul *tujuan, int beban);            //prosedur untuk menambahkan jalur
simpul* findSimpul(input c, graph G);                                //fungsi untuk mencari simpul
void printGraph(graph G);                                          //prosedur untuk menampilkan graph
simpul* findJalur(input awal, input akhir, graph G, char temp[], int i); //prosedur untuk mencari jalur