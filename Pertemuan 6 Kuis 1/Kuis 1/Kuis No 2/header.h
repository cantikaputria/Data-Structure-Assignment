/* 
    Saya Cantika Putri Arbiliansyah dengan NIM [2103727] mengerjakan 
    Kuis 1 No 2 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan 
    kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

//LIBRARY
#include <stdio.h>
#include <malloc.h>
#include <string.h>

//DEKLARASI STRUCK
typedef struct
{
    int id;                                     //variabel penampung id karyawan
    char nama[50];                              //variabel penampung nama karyawan
    char bagian[100];                           //variabel penampung bagian karyawan
}karyawan;

//DEKLARASI STRUCT UNTUK PEMBUATAN ELEMEN
typedef struct
{
    karyawan kontainer;                        //pembuatan kontainer dari data karyawan
    int prev;                                  //pembuatan pointer prev
    int next;                                  //pembuatan pointer next
}elemen;

//DEKLARASI STRUCT untuk pembuatan list
typedef struct
{
    int first;                                 //pembuatan pointer first
    int tail;                                  //pembuatan pointer tail                 
    elemen data[10];                           //pembuatan data
}list;

//PROSEDUR DAN FUNGSI
void createList(list *L);                                                           //prosedur untuk membuat list
int countElement(list L);                                                           //fungsi untuk menghitung elemen di dalam list
int emptyElement(list L);                                                           //fungsi menghitung elemen kosong
void addFirst(int id, char nama[], char bagian[], list *L);                         //prosedur untuk menambah list baru di depan
void addAfter(int before, int id, char nama[], char bagian[], list *L);             //prosedur untuk menambah list baru di tengah
void addLast(int id, char nama[], char bagian[], list *L);                          //prosedur untuk menambah list di belakang
void printElement(list L);                                                          //prosedur untuk menampilkan seluruh elemen
void tukar(list *L1, list *L2);                                                     //prosedur untuk menukar elemen