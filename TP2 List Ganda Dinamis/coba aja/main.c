/* 
    Saya Cantika Putri Arbiliansyah dengan NIM [2103727] mengerjakan 
    Tugas Praktikum 2 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan 
    kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

//LIBRARY
#include "head.h"

int main()
{
    list L;                                                 //deklarasi struct list
    createList(&L);                                         //memanggil prosedur untuk pembuatan list

    //DEKLARASI VARIABEL
    char nama[50];                                          //variabel penampung nama barang
    int tanggal;                                            //variabel penampung tanggal masuk
    int kode;                                               //variabel penampung kode barang
    int i;                                                  //variabel untuk iterasi                             
    
    //PROSES
    do
    {
        scanf("%s", &nama);                                 //meminta inputan nama barang
        if (strcmp(nama, "--stop--") != 0)                  //jika inputannya stop, maka berhenti
        {
            scanf("%d %d", &tanggal, &kode);                //meminta inputan tanggal dan kode dari user
            addLast(nama, tanggal, kode, &L);               //memasukkan semua inputan secara addLast atau ke paling akhir
        }
        
    } while(strcmp(nama, "--stop--") != 0);                 //berhenti hingga inputan stop      

    //PROSES
    sort(&L);                                               //pemanggilan prosedur untuk sorting list
    sortPrev(&L);                                           //pemanggilan prosedur untuk sorting pointer prev
    delEl(&L);                                              //pemanggilan prosedur untuk mengahapus elemen

    //OUTPUT
    printf("==== List Barang ====\n");                      //menampilkan teks ke layar
    printRev(&L);                                           //menampilkan isi list saat ini ke layar
    printf("=====================\n");                      //menampilkan teks ke layar

    return 0;                                               //kembali ke 0
}
