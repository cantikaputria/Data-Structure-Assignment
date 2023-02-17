/* 
    Saya Cantika Putri Arbiliansyah dengan nama [2103727] mengerjakan 
    Test Mesin 7 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
    char nama[50];
    char rating[50];
}nilaiMatKul;

typedef struct elm *alamatelmt;

typedef struct elm{
    nilaiMatKul kontainer;
    alamatelmt next;
}elemen;

typedef struct{
    elemen *first;
    elemen *last;
}queue;

void createEmpty(queue *Q);
int isEmpty(queue Q);
int countElement(queue Q);
void add(char nama[], char rating[], queue *Q);
void addPriority(char nama[], char rating[], int priority, queue *Q);
void del(queue *QA, queue *QB);
void printQueue1(queue Q);
void printQueue2(queue Q);