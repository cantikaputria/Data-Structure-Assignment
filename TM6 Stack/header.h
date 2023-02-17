/* 
    Saya Cantika Putri Arbiliansyah dengan nama [2103727] mengerjakan 
    Test Mesin 6 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/


//LIBRARY
#include <stdio.h>
#include <malloc.h>
#include <string.h>

//DEKLARASI STRUCT
typedef struct
{
    char nama[50];
    char harga[50];
}nilaiMatKul;

//DEKLARASI STRUCT
typedef struct elmt *alamatelmt;
typedef struct elmt
{
    nilaiMatKul kontainer;
    alamatelmt next;
}elemen;

typedef struct 
{
    elemen* top;
}stack;

//DEKLARASI FUNGSI DAN PROSEDUR
void createEmpty(stack *S);
int isEmpty(stack S); //ganti
int countElement(stack S); //ganti
void push(char nama[], char harga[], stack *S);
void pop(stack *S);
void printStack1(stack S);
void printStack2(stack S);
void popTuker(stack *SX, stack *SY);