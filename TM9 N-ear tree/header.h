/* 
    Saya Cantika Putri Arbiliansyah dengan nama [2103727] mengerjakan 
    mahasiswa Mesin 9 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nama[100];
    int nilai;
} mahasiswa;

extern int first;

typedef struct smp *alamatsimpul;

typedef struct smp
{
    mahasiswa kontainer;
    alamatsimpul sibling;
    alamatsimpul child;
}simpul;

typedef struct
{
    simpul *root;
}tree;

void makeTree(mahasiswa c, tree *T);
void addChild(mahasiswa c, simpul *root);
void delAll(simpul *root);
void delChild(mahasiswa c, simpul *root);
simpul* findSimpul(char cari[], simpul *root);
void printTreePreOrder(simpul *root);
void printTreePostOrder(simpul *root);
void copyTree(simpul *root1, simpul **root2);
int isEqual(simpul *root1, simpul *root2);