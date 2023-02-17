/* 
    Saya Cantika Putri Arbiliansyah dengan NIM [2103727] mengerjakan 
    Tugas Praktikum 1 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan 
    kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

//LIBRARY
#include <stdio.h>
#include <malloc.h>
#include <string.h>

//DEKLARASI STRUCT
typedef struct
{
    char judul[100];                                                              //variabel penampung judul lagu
    char artis[100];                                                              //variabel penampung nama artis
    int urutan;                                                                   //variabel penampung urutan lagu
}lagu;                                                                            //nama struct

//DEKLARASI POINTER untuk alokasi memori
typedef struct elmt* alamatelmt;

//DEKLARASI STRUCT UNTUK PEMBUATAN ELEMEN
typedef struct elmt
{
    lagu kontainer;                                                               //pembuatan kontainer dari data lagu
    alamatelmt next;                                                              //pembuatan pointer next
} elemen;

//DEKLARASI STRUCT untuk pembuatan list
typedef struct
{   
    elemen* first;                                                                //pembuatan pointer first
}list;

//PROSEDUR DAN FUNGSI
void createList(list *L);                                                         //prosedur untuk membuat list
int countElement(list L);                                                         //fungsi untuk menghitung elemen di dalam list
void addFirst(char judul[], char artis[], int urutan, list *L);                   //prosdur untuk menambah list baru di depan
void addAfter(elemen* prev, char judul[], char artis[], int urutan, list *L);     //prosedur untuk menambah list baru di tengah
void addLast(char judul[], char artis[], int urutan, list *L);                    //prosedur untuk menambah list baru di belakang
void delFirst(list *L);                                                           //prosedur untuk menghapus list didepan
void delAfter(elemen* prev, list *L);                                             //prosedur untuk menghapus list ditengah
void delLast(list *L);                                                            //prosedur untuk menghapus list di belakang
void printElement(list L);                                                        //prosedur untuk menampilkan seluruh elemen
void delAll(list *L);                                                             //prosedur untuk menghapus seluruh elemen
void sortList(list *L, char sort[], char ccc[]);                                  //prosedur untuk mengurutkan elemen
void swap(elemen* x, elemen* y);                                                  //prosedur untuk menukar elemen menggunakan pointer