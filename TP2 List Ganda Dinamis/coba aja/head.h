/* 
    Saya Cantika Putri Arbiliansyah dengan nama [2103727] mengerjakan 
    Tugas Praktikum 2 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan 
    kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

//LIBRARY
#include <stdio.h>
#include <malloc.h>
#include <string.h>

//STRUCT
typedef struct
{
    char nama[50];                                                              //variabel penampung nama barang
    int tanggal;                                                                //variabel penampung tanggal masuk barang
    int kode;                                                                   //variabel penampung kode barang
}barang;

typedef struct elmt *alamatelmt;

typedef struct elmt
{
    barang kontainer;                                                           //pembuatan struct menjadi satu kontainer
    alamatelmt prev;                                                            //deklarasi pointer prev
    alamatelmt next;                                                            //deklarasi pointer next
} elemen;

typedef struct{
    elemen *first;                                                              //pembuatan pointer first   
    elemen *tail;                                                               //pembuatan pointer tail
}list;

//PROSEDUR DAN FUNGSI
void createList(list *L);                                                       //prosedur untuk membuat list
int countElement(list L);                                                       //fungsi untuk menghitung jumlah elemen di dalam list
void addFirst(char nama[], int tanggal, int kode, list *L);                     //prosedur menambah list di depan
void addAfter(elemen* before, char nama[], int tanggal, int kode, list *L);     //prosedur menambah list di tengah atau yang diinginkan
void addLast(char nama[], int tanggal, int kode, list *L);                      //prosedur menambah list di belakang
void delFirst(list *L);                                                         //prosedur menghapus list di depan
void delAfter(elemen* before, list *L);                                         //prosedur menghapus list di tengah atau yg diinginkan
void printRev(list *L);                                                         //prosedur menampilkan output dengan reverse
void sort(list *L);                                                             //prosedur untuk sorting list berdasarkan kode di pointer next
void sortPrev(list *L);                                                         //prosedur untuk sorting list berdasarkan kode di pointer prev
int delEl(list *L);                                                             //fungsi untuk menghapus elemen sesuai pertintah
void sortt(int jumlah, int simpan[]);                                           //prosedur untuk sorting kode yg dihapus