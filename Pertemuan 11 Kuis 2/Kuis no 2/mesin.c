/* 
    Saya Cantika Putri Arbiliansyah dengan nama [2103727] mengerjakan 
    Kuis 2 No 2 untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

//DEKLARASI VARIABEL
#include "header.h"

//PROSEDUR UNTUK MEMBUAT QUEUE
void createEmpty(queue *Q) 
{
    (*Q).first = NULL;                      //pointer pendanda elemen pertama queue
    (*Q).last = NULL;                       //pointer pendanda elemen terakir queue
}

//PROSEDUR UNTUK MENGECEK ISI QUEUE
int isEmpty(queue Q) 
{
    int hasil = 0;                                                  //inisialiasi
    if(Q.first == NULL)                                             //jika elemen pertama null maka kosong
    {
        hasil = 1;                                                  //tandai hasil sama dengan 1
    }
    return hasil;                                                   //kembalikan nilai hasi
}

//PROSEDUR UNTUK MENGUITUNG ELEMEN QUEUE
int countElement(queue Q) 
{
    int hasil = 0;                                                  //inisialiasi
    if(Q.first != NULL)                                             //jika elemen pertama bukan null
    {
        elemen *bantu;                                              //buat pointer bantu
        bantu = Q.first;                                            //bantu menunjuk pada first
        while(bantu != NULL)                                        //selama bantu bukan null
        {
            hasil++;                                                //hasil terus bertambah
            bantu = bantu->next;                                    //maju terus hingga elemen akhir
        }
    }
    return hasil;                                                   //mengembalikan nilai hasil
}

//PROSEDUR UNTUK MENAMBAHKAN ELEMEN QUEUE
void add(char nama[], int prioritas, int semester, queue *Q) 
{
    elemen *baru;                                           //membuat pointer baru
    baru = (elemen*)malloc(sizeof(elemen));                 //alokasi memori

    //memasukkan data elemen
    strcpy(baru->kontainer.nama, nama);                     
    baru->kontainer.prioritas = prioritas;
    baru->kontainer.semester = semester;

    baru->next = NULL;                                      //baru next jadi null
    if((*Q).first == NULL)                                  //jika elemen pertama null artinya queue kosong
    {
        (*Q).first = baru;                                  //maka first menunjuk ke elemen baru
    }
    else                                                    //jika bukan null artinya ada elemennya
    {
        (*Q).last->next = baru;                             //last next menunjuk pada elemen  baru
    }
    (*Q).last = baru;                                       //last menunjuk ke baru
    baru = NULL;                                            //baru menjadi null
}

//PROSEDUR UNTUK MENAMBAHKAN ELEMEN SESUAI PRIORITAS
void addPrioritas(char nama[], int prioritas, int semester, queue *Q) 
{
    elemen *baru;                                                   //mmebuat pointer baru
    baru = (elemen*)malloc(sizeof(elemen));                         //alokais memori

    //memasukkan data elemen
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.prioritas = prioritas;
    baru->kontainer.semester = semester;

    baru->next = NULL;                                              //baru next menjadi null

    if((*Q).first == NULL)                                          //jika elemen pertama null maka queue kosong                     
    {
        (*Q).first = baru;                                          //first dan last menujuk ke baru
        (*Q).last = baru;
    }
    else                                                            //jika queue sudah ada isinya
    {
        if(prioritas == 1)                                          //jika prioritasnya 1 maka jadi elemen pertama
        {
            baru->next = (*Q).first;                                //baru next menunjuk pada first
            (*Q).first = baru;                                      //first menujuk pada elemen baru
        }
        else if(prioritas > countElement(*Q))                       //jika prioritasnya lebih besar dari jumlah elemen, maka menjadi elemen terakhir
        {       
            (*Q).last->next = baru;                                 //last next menunjuk pada baru
            (*Q).last = baru;                                       //last menunjuk pada baru
        }
        else    //j                                                 //jika prioritasnya ditengah, simpan sesuai posisi
        {
            elemen *bantu = (*Q).first;                             //buat pointer bantu yg menujuk first
            int i = 1;                                              //inisialiasi
            while(bantu != NULL)                                    //selama bantu bukan null
            {
                if(i == prioritas - 1)                              //jika i sekarang adalah elemen sebelum prioritas
                {
                    baru->next = bantu->next;                       //baru next menunjuk pada banru next
                    bantu->next = baru;                             //bantu next menunjuk pada baru
                }
                bantu = bantu->next;                                //bantu menjuk pada elemen yg ditunjuk bantu next
                i++;                                                //iterasi
            }
        }
    }
    baru = NULL;                                                    //pointer baru menjadi null karena sudah tidak terpakai
}

//PROSEDUR UNTUK MENGHAPUS ELEMN
void del(queue *Q1) 
{
    if((*Q1).first != NULL)                             //jika queue tidak kosong
    {
        elemen *hapus = (*Q1).first;                    //hapus menunjuk pada elemen pertanya
        if(countElement(*Q1) == 1)                      //jika elemennya hanya satu
        {
            (*Q1).first = NULL;                         //maka nullkan first dan lastnya
            (*Q1).last = NULL;
        } 
        else                                            //jika lebih dari satu elemen
        {
            (*Q1).first = (*Q1).first->next;            //first maju ke elemen setelahnya
            hapus->next = NULL;                         //nullkan elemen sebelumnya
        }
        free(hapus);                                    //hapus elemen tersebut
    }
}

//PROSEDUR UNTUK MENCETAK QUEUE SAAT INI
void printQueue(queue *Q, int n, int Queue)
{
    if(Queue != 0)                                                      //jika kode queue bykan 0, maka cetak yg sudah menerima beasiswa        
    {
        printf("sudah mendapat beasiswa:\n");
    } 
    else                                                                 //jika queue 0 cetak yg masih dalam antrian       
    {
        printf("\nbelum mendapat beasiswa:\n");
    }

    if((*Q).first != NULL)                                             //jika queue tidak kosong
    {
        elemen *bantu = (*Q).first;                                     //buat pointer banru yg menunjuk pada first
        int i = 0;                                                      //inisialiasi                       
        while(bantu != NULL && i < n)                                   //selama banru bukan null dan belum sampai elemen terakhir
        {
            printf("%s %d %d\n", bantu->kontainer.nama, bantu->kontainer.prioritas, bantu->kontainer.semester);    //cetak elemen ke layar
            bantu = bantu->next;                                        //maju ke elemen setelahnya
            del(Q);                                                     //hapus queue yang sudah dicetak
            i++;                                                        //iterasi
        }
    } 
    else                                                                //jika queue kosong
    {
        printf("queue kosong\n");                                       //cetak teks ke layar
    }
}