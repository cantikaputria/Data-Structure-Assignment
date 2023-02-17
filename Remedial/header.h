/* 
    Saya Cantika Putri Arbiliansyah dengan peserta [2103727] mengerjakan 
    Remedial Struktur Data untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

//LIBRARY
#include <stdio.h>
#include <malloc.h>
#include <string.h>

//DEKLARASI STRUCT BARIS
typedef struct
{
    char peserta[100];                         //variabel penampung nama perusahaan
}perusahaan;                                //nama struct

//DEKLARASI STRUCT KOLOM
typedef struct
{
    char bahan[100];                         //variabel penampung kode perusahaan
    int berat;                              //variabel penampung berat;                              ;                         //variabel penampung jenis obat
}obat;

//ALAMAT KOLOM
typedef struct eklm *alamatekolom;

//ELEMEN KOLOM
typedef struct eklm{
    obat kontainer_kol;
    alamatekolom next_kol;
}eKolom;

//ALAMAT BARIS
typedef struct ebr *alamatebaris;

//ELEMEN BARIS
typedef struct ebr{
    perusahaan kontainer;
    eKolom *col;
    alamatebaris next;
}eBaris;

//LIST
typedef struct{
    eBaris *first;
}list;

//PROSEDUR DAN FUNGSI
void createList(list *L);                                           //prosedur membuat list
int countElementB(list L);                                          //fungsi menghitung jmlh elemen baris
int countElementK(eBaris L);                                        //fungsi menghitung jmlh elemen kolom
void addFirstB(char peserta[], list *L);                 //prosedur menamba elemen awal baris
void addFirstK(char bahan[], int berat, eBaris *L);                           //prosedur menamba elemen awal kolom
void addAfterB(eBaris* prev, char peserta[]);            //prosedur menambah elemen tengah baris
void addAfterK(eKolom* prev, char bahan[], int berat);                        //prosedur menambah elemen tengah kolom
void addLastB(char peserta[], list *L);                  //prosedur menambah elemen akhir baris
void addLastK(char bahan[], int berat, eBaris *L);                            //prosedur menambah elemen akhir kolom
void delFirstB(list *L);                                            //prosedur menghapus elemen awal baris
void delFirstK(eBaris *L);                                          //prosedur menghapus elemen awal kolom
void delAfterB(eBaris* prev);                                       //prosedur menghapus elemen tengah baris
void delAfterK(eKolom* prev);                                       //prosedur menghapus elemen tengah kolom
void delLastB(list *L);                                             //prosedur menghapus elemen akhir baris
void delLastK(eBaris *L);                                           //prosedur menghapus elemen akhir kolom
void delAllK(eBaris *L);                                            //prosedur menghapus semua elemen kolom
void delAllB(list *L);                                              //prosedur menghapus semua elemen baris
void printElement(list L);                                          //prosedur menampilkan isi elemen
eBaris* get(char peserta[], list L);                                  //prosedur menandai alamat baris
eKolom* get2(eBaris *L;                               //prosedur menandai alamat kolom
void proses(eBaris *L, int berat);         //prosedur proses pemindahan