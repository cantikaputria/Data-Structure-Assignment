/* 
    Saya Cantika Putri Arbiliansyah dengan nama [2103727] mengerjakan 
    Tugas Praktikum 4 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

//LIBRARY
#include <stdio.h>
#include <malloc.h>
#include <string.h>

//ALOKASI ALAMAT SIMPUL
typedef struct smp *alamatsimpul;

//STRUCT SIMPUL
typedef struct smp
{
    char nama[100];                                                         //variabel penampung nama anggota olahraga
    alamatsimpul sibling;                                                   //pointer penanda sibling
    alamatsimpul child;                                                     //pointer penanda child
}simpul;                                                                    //nama struct

//STRUCT TREE
typedef struct
{
    simpul *root;                                                           //pointer penanda root
}tree;                                                                      //nama struct

//PROSEDUR DAN FUNGSI
void makeTree(char nama[], tree *T);                                        //prosedur untuk membuat tree
void addChild(char nama[], simpul *root);                                   //prosedur untuk menambahkan anak pada tree
void delAll(simpul *root);                                                  //prosedur untuk menghapus keseluruhan elemen tree (jika child mempunyai anak)
void delChild(char nama[], simpul *root);                                   //prosedur untuk menghapus child pada tree
simpul* findSimpul(char cari[], simpul *root);                              //fungsi untuk mencari root
void printTreePreOrder(simpul *root, int level);                            //prosedur untuk menampilkan tree secara pre order