/* 
    Saya Cantika Putri Arbiliansyah dengan NIM [2103727] mengerjakan 
    UAS No 1 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

//LIBRARY
#include <stdio.h>
#include <malloc.h>

//STRUCT
typedef struct
{
    int ortu, pembagi, hasil;
}input;

//ALOKASI MEMORI ALAMAT SIMPUL
typedef struct smp *alamatsimpul;
typedef struct smp

//SIMPUL BINARY TREE
{
    input kontainer;                                     //kontainer data
    alamatsimpul right;                                 //pointer to right
    alamatsimpul left;                                  //pointer to left
}simpul;                                                //nama struct

//BINARY TREE
typedef struct
{
    simpul* root;                                       //pointer to root
}tree;

//PROSEDUR DAN FUNGSI
void makeTree(input c, tree *T);                         //prosedur untuk membuat pohon    
void addRight(input c, simpul *root);                  //prosedur untuk menambahkan child di kanan
void addLeft(input c, simpul *root);                   //prosedur untuk menambahkan child di kiri  
void printTreeInOrder(simpul *root);                    //prosedur untuk menampilkan tree secara in order
void addData(input c, int hasil, simpul *root);