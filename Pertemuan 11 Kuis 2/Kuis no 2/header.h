/* 
    Saya Cantika Putri Arbiliansyah dengan nama [2103727] mengerjakan 
    Kuis 2 No 2 untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

//LIBRARY
#include <stdio.h>
#include <string.h>
#include <malloc.h>

//DEKLARASI STRUCT
typedef struct 
{
    char nama[50];                                                              //variabel penampung nama mahasiswa
    int prioritas;                                                              //variabel penampung prioritas mahasiswa
    int semester;                                                               //variabel penampung semester mahasiswa
} beasiswa;

//ALAMAT ELEMENR
typedef struct elm *alamatelmt;                                                 //alokasi memori 

//ELEMEN
typedef struct elm
{
    beasiswa kontainer;                                                         //pembuatan kontainer struct beasiswa
    alamatelmt next;                                                            //pembuatan pointer next
} elemen;

//DEKLARASI QUEUE
typedef struct 
{
    elemen *first;                                                              //pointer first queue
    elemen *last;                                                               //pointer last queue
} queue;

//DEKLARASI FUNGSI DAN PROSEDUR
void createEmpty(queue *Q);                                                         //prosedur untuk membuat queue
int isEmpty(queue Q);                                                               //prosedur untuk mengecek isi queue 
int countElement(queue Q);                                                          //prosedur untuk menghitung elemen queue
void add(char nama[], int priotitas, int semester, queue *Q);                       //prosedur untuk menambahkan elemen ke queue
void addPrioritas(char nama[], int priotitas, int semester, queue *Q);              //prosedur untuk menambah elemen ke queue sesuai prioritas
void del(queue *Q1);                                                                //prosedur menghapus elemen dalam queue
void printQueue(queue *Q, int n, int Queue);                                        //prosedur mencetak elemen queuu