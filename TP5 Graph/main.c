/* 
    Saya Cantika Putri Arbiliansyah dengan nama [2103727] mengerjakan 
    Tugas Praktikum 5 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

//LIBRARY
#include "header.h"

//PROSES
int main ()
{
    //MEMBUAT GRAPH
    graph G;                                                    //variabel untuk membuat graph
    createEmpty(&G);                                            //panggil prosedur untuk membuat graph kosong

    //POINTER
    simpul *begin;                                              //pointer untuk simpul awal
    simpul *end;                                                //pointer untuk simpul tujuan

    //DEKLARASI VARIABEL    
    input awal, tujuan;                                         //struct untuk posisi awal dan tujuan 
    int jumlah;                                                 //variabel penampung jumlah inputan
    int bobot;                                                  //variabel penampung bobot jalur

    scanf("%d", &jumlah);                                       //meminta inputan jumlah simpul dari user

    //PROSES
    for (int i = 0; i < jumlah; i++)                            //loop sebanyak jumlah simpul dari inputan user
    {
        scanf(" %c %c %d", &awal.c, &tujuan.c, &bobot);         //meminta inputan posisi awal dan tujuan serta bobot jalurnya

        if(findSimpul(awal, G) == NULL)                         //jika simpul awal yg diinput belum ada
        {
            addSimpul(awal, &G);                                //masukkan simpul ke graph
        }
        if(findSimpul(tujuan, G) == NULL)                       //jika simpul akhir yg diinput belum ada
        {
            addSimpul(tujuan, &G);                              //masukkan simpul ke graph
        }

        begin = findSimpul(awal, G);                            //tandai simpul awal dengan pointer begin
        end = findSimpul(tujuan, G);                            //tandai simpul tujua dengan pointer end

        if((begin != NULL) && (end != NULL))                    //jika dua-duanya belum ada
        {
            addJalur(begin, end, bobot);                        //maka tambahkan jalur diantara simpul awal dan tujuan
        }
    }

    //DEKLARASI VARIABLE
    input x, y;                                                 //deklarasi stuct posisi techi dan ibunya
    int totbot = 0;                                             //variabel penghitung total bobot
    char temp[50];                                              //variabel penampung sementara jalur yg dilalui 
    scanf(" %c %c", &x.c, &y.c);                                //meminta inputan posisi techi dan ibunya dari user

    //CARI JALUR
    findJalur(x, y, G, totbot, temp, 0);                        //panggil prosedur untuk mencari jalurnya

    return 0;                                                   //kembali ke 0
}