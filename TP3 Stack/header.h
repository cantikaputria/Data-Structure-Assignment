/* 
    Saya Cantika Putri Arbiliansyah dengan harga [2103727] mengerjakan 
    Tugas Praktikum 3 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

//LIBRARY
#include <stdio.h>
#include <malloc.h>
#include <string.h>

//DEKLARASI STRUCT
typedef struct
{
    int harga;                                                          //variabel penampung harga makanan
    char nama[50];                                                      //variabel penampung nama makanan
    int kalori;                                                         //variabel penampung kalori makanan
}rumahMakan;

//STRUCT POINTER PENGHUBUNG
typedef struct elmt *alamatelmt;

//ELEMEN STACK
typedef struct elmt
{
    rumahMakan kontainer;                                               //pembuatan kontainer stack
    alamatelmt next;                                                    //pembuatan pointer next
}elemen;

//STACK
typedef struct 
{
    elemen* top;                                                        //pembuatan pointer top
}stack;

//DEKLARASI FUNGSI DAN PROSEDUR
void createEmpty(stack *S);                                             //prosedur untuk membuat stack kosong
int isEmpty(stack S);                                                   //fungsi untuk mengecek apakah stack kosong atau tidak
int countElement(stack S);                                              //fungsi untuk menghitung elemen stack
void push(int harga, char nama[], int kalori, stack *S);                //prosedur untuk memasukkan data ke dalam stack
void pop(stack *S);                                                     //prosedur untuk menghapus data dari stack
void printStack1(stack S);                                              //prosedur untuk menampilkan isi stack
void printStack2(stack S);                                              //prosedur untuk menampilkan isi stack
void pushCek(stack *SX, stack *SY, stack *SZ);                          //prosedur untuk mengecek dan memasukkan ke stack yang sesuai
int countAscii(char str[]);                                             //fungsi untuk menghitung nilai ascii