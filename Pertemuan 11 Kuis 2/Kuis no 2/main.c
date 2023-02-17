/* 
    Saya Cantika Putri Arbiliansyah dengan nama [2103727] mengerjakan 
    Kuis 2 No 2 untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

//LIBRARY
#include "header.h"

//PROSES
int main() 
{
    //DEKLARASI VARIABEL
    queue Q;                                                                //membuat queue
    createEmpty(&Q);                                                        //membuat queue kosong
    char nama[100];                                                         //variabel penampung nama mahasiswa
    int prioritas = 0;                                                      //variabel penampung prioritas beasiswa
    int semester;                                                           //variabel penampung semester mahasiswa
    int n = 0, m = 0;                                                       //variabel inisialisasi                          

    //PROSES
    scanf("%d", &n);                                                        //meminta inputan jumlah queue dari user
    for (int i = 0; i < n; i++) 
    {
        scanf("%s %d %d", &nama, &prioritas, &semester);                   //meminta inputan data dari user
        addPrioritas(nama, prioritas, semester, &Q);                       //memasukkan data pada queue sesuai prioritas
    }

    scanf("%d", &m);                                                       //meminta inputan jumlah penerima beasiswa

    //OUTPUT
    printQueue(&Q, m, 1);                                                  //memamnggi prosedur pencetak penerima beasiswa sebanyak m
    printQueue(&Q, countElement(Q) + 1, 0);                                //memanggil prosedur pencetak yang belum menerima beasiswa
    return 0;                                                              //kembali ke 0
}