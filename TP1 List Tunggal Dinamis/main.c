/* 
    Saya Cantika Putri Arbiliansyah dengan NIM [2103727] mengerjakan 
    Tugas Praktikum 1 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan 
    kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

//LIBRARY
#include "header.h"

int main()
{
    list L;                                                 //deklarasi struct list
    createList(&L);                                         //memanggil prosedur untuk pembuatan list

    //DEKLARASI VARIABEL
    char judul[100];                                        //variabel penampung judul lagu
    char artis[100];                                        //variabel penampung artis atau penyanyinya
    int urutan;                                             //variabel penampung urutan lagu
    char sort[100];                                         //variabel penampung sorting berdasarkan urutan lagu atau judul
    char ccc[100];                                          //variabel penampung sorting ascending atau descending

    //PROSES
    do
    {
        scanf("%s", &judul);                                //meminta inputan judul lagu ke user
        if (strcmp(judul, "-") != 0)                        //jika inputannya "-", maka berhenti
        {
            scanf("%s %d", &artis, &urutan);                //meminta inputan artis dan urutan dari user
            addLast(judul, artis, urutan, &L);              //memasukkan semua inputan secara addLast atau ke paling akhir
        }
        
    } while(strcmp(judul, "-") != 0);                       //jika inputannya "-", maka berhenti

    scanf("%s %s", &sort, &ccc);                            //meminta inputan penentu sorting dari user
    sortList(&L, sort, ccc);                                //pemanggilan prosedur untuk sorting list
    
    //OUTPUT
    printElement(L);                                        //menampilkan isi list ke layae

    return 0;                                               //kembali ke 0
}