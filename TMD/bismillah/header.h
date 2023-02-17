/* 
    Saya Cantika Putri Arbiliansyah dengan nim [2103727] mengerjakan 
    Tugas Masa Depan Struktur Data untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

//LIBRARY
#include <stdio.h>
#include <malloc.h>
#include <string.h>

//STRUCT
typedef struct
{
    char nama[201];                                                                                         //variabel penampung nama mie
    char nilaiJual[201];                                                                                    //variabel penampung nilai jual mie (string)
    char jmlhKom[201];                                                                                      //variabel penampung jumlah komponen mie (string)
    char komponen[100][201];                                                                                //variabel penampung list komponen mie
    int level;                                                                                              //variabel penampung level child
    int simpan;                                                                                             //variabel penyimpan jumlah komponen mie (integer)
    int nilaiJual2;                                                                                         //variabel penampung nilai jual mie (integer)
} mie;

//VARIABEL GLOBAL
extern int jumlahKom2;                                                                                      //variabel penampung jumlah komponen mie (integer)
extern int maxPanjang[100];                                                                                 //variabel penampung panjang string

//SIMPUL
typedef struct smp *alamatsimpul;                                                                           //pointer alamat simpul
typedef struct smp
{
    mie kontainer;                                                                                          //kontainer struct mie
    alamatsimpul sibling;                                                                                   //pointer penanda sibling
    alamatsimpul child;                                                                                     //pointer penanda child
}simpul;

//TREE
typedef struct
{
    simpul *root;                                                                                           //pointer root tree
}tree;

//PROSEDUR DAN FUNGSI
void makeTree(mie c, tree *T);                                                                              //prosedur untuk membuat tree
void addChild(mie c, simpul *root);                                                                         //prosedur untuk menambahkan child dari tree
void delAll(simpul *root);                                                                                  //prosedur untuk menghapus child tree
void delChild(mie c, simpul *root);                                                                         //prosedur untuk menghapus keseluruhan tree
simpul* findSimpul(char cari[], simpul *root);                                                              //fungsi untuk mencari simpul ree
void printTreePreOrder(simpul *root, int *panjangStr, int temp[]);                                          //prosedur untuk menampilkan tree secara pre-order
void pisah(mie c, char str[], char temp1[], char temp2[], char temp3[], char temp4[], int *jumlah);         //prosedur untuk memisahkan inputan
void cariMaxLen(simpul *root, int level, int temp[]);                                                       //prosedur untuk mencari panjang maksimal
void hapus_jual(simpul *root, int batasJual);                                                               //prosedur untuk menghapus child yang kurang dari batas jual