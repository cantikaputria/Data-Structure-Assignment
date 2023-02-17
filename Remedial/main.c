/* 
    Saya Cantika Putri Arbiliansyah dengan nama [2103727] mengerjakan 
    Remedial Struktur Data untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

//LIBRARY
#include "header.h"

int main()
{   
    //DEKLARASI VARIABEL
    list L;                                         //deklarasi list
    createList(&L);                                 //pemanggilan prosedur pembuatan list

    char peserta[100];
    char bahan[100];
    int berat;
    int jumlahP, jumlahB;
    int i = 0, j = 0;

    // eBaris *baris;

    scanf("%d", &jumlahP);

    for ( i = 0; i < jumlahP; i++)
    {
        scanf("%s", peserta);                       //meminta inputan kode dan nama perusahaan
        addLastB(peserta, &L);                  //memasukkan ke list secara addlast

        scanf("%d", &jumlahP);

        baris = get(peserta, L);                       //mengambil alamat baris

        for ( j = 0; j < jumlahB; j++)
        {
            scanf("%s %d", &bahan, &berat);
        }
    }
    
    printElement(L);                                //menampilkan output ke layar

    return 0;                                       //kembali ke o
}