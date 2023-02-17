/* 
    Saya Cantika Putri Arbiliansyah dengan harga [2103727] mengerjakan 
    Tugas Praktikum 3 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

//LIBRARY
#include "header.h"

//PROSES UTAMA
int main ()
{   
    //DEKLARASI VARIABEL
    stack SManis, SPedas, SAll;                     //pembuatan stack penamppung keseluruhan, stack penampung makanan pedas, dan stack penampung makanan manis (kayak aku)
    int harga;                                      //variabel penampung harga makanan
    char nama[50];                                  //variabel penampung nama makanan
    int kalori;                                     //variabel penampung kalori makanan
    int n, i;                                       //inisialisasi

    //MEMBUAT STACK KOSONG
    createEmpty(&SPedas);                           //stack penampung makanan pedas
    createEmpty(&SManis);                           //stack penampung makanan manis
    createEmpty(&SAll);                             //stack penampung seluruh makanan

    //PROSES
    scanf("%d", &n);                                //meminta inputan jumlah makanan dari user
    for ( i = 0; i < n; i++)
    {
        scanf("%d %s %d", &harga, &nama, &kalori);  //meminta inputan harga, nama, dan kalori makanan dari user
        push(harga, nama, kalori, &SAll);           //memasukkan ke dalam stack all
    }

    pushCek(&SAll, &SPedas, &SManis);               //memasukkan makanan ke dalam stack tertentu sesuai syarat       

    //OUTPUT
    printStack1(SPedas);                            //menampilkan isi stack makanan pedas
    printStack2(SManis);                            //menampilkan isi stack makanan manis

    return 0;                                       //kembali ke 0
}
