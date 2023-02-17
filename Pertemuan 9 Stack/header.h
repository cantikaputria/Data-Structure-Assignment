//LIBRARY
#include <stdio.h>
#include <string.h>

//DEKLARASI STRUCT
typedef struct
{
    char nim[10];
    char nama[50];
    float nilai;
}nilaiMatKul;

//DEKLARASI STRUCT
typedef struct
{
    int top;
    nilaiMatKul data[10];
}stack;

//DEKLARASI FUNGSI DAN PROSEDUR
void createEmpty(stack *S);
int isEmpty(stack S); //ganti
int isFull(stack S); //ganti
void push(char nim[], char nama[], float nilai, stack *S);
void pop(stack *S);
int pop2(stack *S);
void printStack(stack S);