/* 
    Saya Cantika Putri Arbiliansyah dengan nim [2103727] mengerjakan 
    Tugas Kuis 2 No 1 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

//LIBRARY
#include "header.h"

//PROSES UTAMA
int main()
{
    //DELARASI VARIABEL
    stack SAll[50], SDaerah[50];                            //membuat stack keseluruhan dan stack daerah
    char nama[50], counter[50], daerah[50];                 //membuat variabel penampung data elemen
    int n = 0, m = 0;                                       //insialisasi variabel                           

    //INPUTAN USER
    scanf("%d", &n);                                        //meminta inputan jumlah elemen stack
    for (int i = 0; i < n; i++) 
    {
        createEmpty(&SAll[i]);                              //membuat stack keseluruhan
        scanf("%s %s %s", &nama, &counter, &daerah);        //meminta inputan data elemen stack
        push(nama, counter, daerah, &SAll[i]);              //memasukkan elemen pada stack keseluruhan
    }

    //INPUTANN USER
    scanf("%d", &m);                                        //meminta jumlah daerah yang difilter
    char ambil[m][50];                                      //menampung nama daerah
    for (int i = 0; i < m; i++) 
    {
        scanf("%s", &ambil[i]);                             //meminta inputan nama daerah
        createEmpty(&SDaerah[i]);                           //membuat stack daerah
    }

    //PROSES
    for (int i = 0; i < m; i++)
    {
        int idx = cariDaerah(&SAll[i], &SDaerah[i], ambil, m);          //mencari daerah yang sesuai

        printf("stack %s:\n", ambil[i]);                                //menampilkan stack daerah ke layar
        printStack(SDaerah[i], 1);                                      //menampilkan isi stack daerah
        printf("\n");
    }

    return 0;
}