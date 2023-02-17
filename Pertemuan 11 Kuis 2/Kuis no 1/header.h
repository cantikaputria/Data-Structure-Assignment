/* 
    Saya Cantika Putri Arbiliansyah dengan nim [2103727] mengerjakan 
    Tugas Kuis 2 No 1 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

//LIBRARY
#include <stdio.h>
#include <malloc.h>
#include <string.h>

//DEKLARASI STRUCT
typedef struct
{
    char nama[50];                                                          //variabel penampung nama paket
    char counter[50];                                                       //variabel penampung counter paket
    char daerah[50];                                                        //variabel penampung daerah paket
}paket;

//DEKLARASI STRUCT
typedef struct
{   
    int top;                                                               //penanda atas stack
    paket data[50];                                                        //deklarasi jumlah elemen stack
}stack;

//DEKLARASI FUNGSI DAN PROSEDUR
void createEmpty(stack *S);                                                 //prosedur untuk membuat stack kosong
int isEmpty(stack S);                                                       //fungsi untuk mengecek apakah stack kosong atau tidak
int isFull(stack S);                                                        //fungsi untu mengecek apakah stack penuh
void push(char nama[], char counter[], char daerah[], stack *S);            //prosedur untuk memasukkan data ke dalam stack
void pop(stack *S);                                                         //prosedur untuk menghapus data dari stack     
void printStack(stack S, int flag);                                         //prosedur untuk menampilkan isi stack
int cariDaerah(stack *S1, stack *S2, char cari[][50], int n);               //prosedur untuk mencari daerah sesuai
void popPush(stack *S1, stack *S2);                                         //prosedur untuk memindahkan elemen