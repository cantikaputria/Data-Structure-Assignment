/* 
    Saya Cantika Putri Arbiliansyah dengan NIM [2103727] mengerjakan 
    UAS No 2 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

//LIBRARY
#include "header.h"

//PROSES
int main ()
{
    //MEMBUAT GRAPH
    graph G;
    createEmpty(&G);

    //POINTER BEGIN DAN END
    simpul *begin;
    simpul *end;

    //DEKLARAIS STRUCK DAN VARIABEL
    int jumlah;
    input x, y;
    input awal, tujuan;

    //MEMINGTA INPUTAN JUMLAH DARI USER
    scanf("%d", &jumlah);
    
    //SELAMA LEBIH KECIL DARI JUMLAH, INPUT GRAPH
    for (int i = 0; i < jumlah; i++)
    {
        scanf(" %c %c", &awal.c, &tujuan.c);

        //MEMASUKKAN INPUTAN KEDALAM GRAPH
        if(findSimpul(awal, G) == NULL)
        {
            addSimpul(awal, &G);
        }
        if(findSimpul(tujuan, G) == NULL)
        {
            addSimpul(tujuan, &G);
        }
    }

    //MEMINGTA INPUTAN AWAL DAN AKHIR
    scanf(" %c %c", &x.c, &y.c);

    //RUN ERROR
    // temp[0] = x.c;
    // jalur *bantu_jalur = findSimpul(x, G)->arc;
    // findJalur(x, y, G, temp, 0);

    //MENAMPILKAN GRAPH
    printGraph(G);

    //KEMBALI KE O
    return 0;
}