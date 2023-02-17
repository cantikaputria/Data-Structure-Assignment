//LIBARARY
#include "header.h"

int main ()
{
    //PEMBUATAN LIST
    list L1;                                //deklarasi struct list perusahaan1
    createList(&L1);                        //memanggil prosedur untuk pembuatan list

    list L2;                                //deklarasi struct list perusahaan2
    createList(&L2);                        //memanggil prosedur untuk pembuatan list

    //DEKLARASI VARIABEL
    char jenis[50], nama[50];               //menampung variabel
    int harga;                              //menampung variabel
    int n, i;                               //iterasi
    char perusahaan[50], jenis_swap[50];    //menampung variabel
    
    //MEMINTA INPUTAN USER
    scanf("%d", &n);

    //MEMINTA INPUTAN LIST PERTAMA
    for ( i = 0; i < n; i++)
    {
        scanf("%s %s %d", &jenis, &nama, &harga);   //meminta inputan user
        addLast(jenis, nama, harga, &L1);           //memasukkan ke list secara addlast
    }

    //MEMINTA INPUTAN LIST KEDUA
    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        scanf("%s %s %d", &jenis, &nama, &harga);  //meminta inputan user
        addLast(jenis, nama, harga, &L2);
    }

    //MEMINTA INPUTAN SWAP
    scanf("%s %s", &perusahaan, &jenis_swap);   //meminta inputan user
    tuker(&L1, &L2, perusahaan, jenis_swap);    //menukar elemen

    //MNAMPILKAN ELEMEN KE LAYAR
    printElement(L1);
    printElement(L2);

    //KEMBALI KE O
    return 0;
}