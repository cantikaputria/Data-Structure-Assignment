//LIBRARY
#include "header.h"

int main ()
{   
    //PEMBUATA LIST
    list L1;                                //deklarasi struct list perusahaan1
    createList(&L1);                        //memanggil prosedur untuk pembuatan list

    list L2;                                //deklarasi struct list perusahaan2
    createList(&L2);                        //memanggil prosedur untuk pembuatan list

    //DEKLARASI VARIABEL
    char bagian[100], nama[50];             //variabel penampung nama dan bagian karyawan
    int id;                                 //variabel penampung id karyawan
    int n, i;                               //variabel iterasi
    
    //PROSES
    scanf("%d", &n);                                //meminta inputan jumlah data dari user

    //LIST PERTAMA
    for ( i = 0; i < n; i++)
    {
        scanf("%d %s %s", &id, &nama, &bagian);     //meminta inputan dari user
        addLast(id, nama, bagian, &L1);             //memasukkan semua inputan secara addLast atau ke paling akhir
    }

    //LIST KEDUA
    for ( i = 0; i < n; i++)
    {
       scanf("%d %s %s", &id, &nama, &bagian);      //meminta inputan dari user
       addLast(id, nama, bagian, &L2);              //memasukkan semua inputan secara addLast atau ke paling akhir
    }

    //PENUKARAN
    tukar(&L1, &L2);                                //pemanggilan prosedur untuk menukar data

    //OUTPUT
    printElement(L1);                               //menampilkan list1 ke layar
    printElement(L2);                               //menampilkan list2 ke layar

    return 0;                                       //kembali ke 0
}