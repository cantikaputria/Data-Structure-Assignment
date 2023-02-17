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
    char nama[50];                                        //variabel penampung nama lagu
    int tanggal;                                        //variabel penampung tanggal atau penyanyinya
    int kode;                                             //variabel penampung kode lagu
    int i;
    

    //PROSES
    do
    {
        scanf("%s", &nama);                                //meminta inputan nama lagu ke user
        if (strcmp(nama, "--stop--") != 0)                        //jika inputannya "-", maka berhenti
        {
            scanf("%d %d", &tanggal, &kode);                //meminta inputan tanggal dan kode dari user
            addLast(nama, tanggal, kode, &L);              //memasukkan semua inputan secara addLast atau ke paling akhir
        }
        
    } while(strcmp(nama, "--stop--") != 0);                

    sort(&L);                                //pemanggilan prosedur untuk sorting list
    sortPrev(&L);

    int simpan[countElement(L)];                                         //jika inputannya "-", maka berhenti
    int jumlah = delEl(L.first, &L, simpan);
    // sortlagi(simpan, 0, jumlah);
    sortt(jumlah, simpan);
    for ( i = 0; i < jumlah; i++)
    {
        printf("%d telah dihapus.\n", simpan[i]);
    }
    
    printf("==== List Barang ====\n");
    printRev(L);                                        //menampilkan isi list ke layae
    printf("=====================\n");

    return 0;                                               //kembali ke 0
}
