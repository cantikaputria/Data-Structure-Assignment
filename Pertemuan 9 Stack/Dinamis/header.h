//LIBRARY
#include <stdio.h>
#include <malloc.h>
#include <string.h>

//DEKLARASI STRUCT
typedef struct
{
    char nim[10];
    char nama[50];
    float nilai;
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
void push(char nim[], char nama[], float nilai, stack *S);
void pop(stack *S);
void printStack(stack S);