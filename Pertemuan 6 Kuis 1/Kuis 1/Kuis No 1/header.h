/* 
    Saya Cantika Putri Arbiliansyah dengan jenis [2103727] mengerjakan 
    Kuis 1 No 1 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan 
    kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

//LIBRARY
#include <stdio.h>
#include <malloc.h>
#include <string.h>

//DEKLARASI STRUCK
typedef struct
{
    char jenis[50];                                     //variabel penampung jenis produk
    char nama[50];                                      //variabel penampung nama produk
    int harga;                                          //variabel penampung harga produk
}perusahaan;

typedef struct elmt* alamatelmt;

//DEKLARASI STRUCT UNTUK PEMBUATAN ELEMEN
typedef struct elmt
{
    perusahaan kontainer;                               //pembuatan kontainer
    alamatelmt next;                                    //pembuatan pointer next
} elemen;

//DEKLARASI STRUCT untuk pembuatan list
typedef struct
{   
    elemen* first;                                      //pembuatan pointer first
}list;

//PROSEDUR DAN FUNGSI
void createList(list *L);                                                       //prosedur untuk membuat list                             
int countElement(list L);                                                       //fungsi untuk menghitung elemen di dalam list
void addFirst(char jenis[], char nama[], int harga, list *L);                   //prosdur untuk menambah list baru di depan
int emptyElement(list L);                                                       //fungsi menghitung elemen kosong
void addAfter(elemen* prev, char jenis[], char nama[], int harga, list *L);     //prosedur untuk menambah list baru di tengah
void addLast(char jenis[], char nama[], int harga, list *L);                    //prosedur untuk menambah list baru di belakang
void printElement(list L);                                                      //prosedur untuk menampilkan seluruh elemen
void tuker(list *L1, list *L2, char perusahaan[], char jenis_swap[]);           //prosedur untuk menukar elemen