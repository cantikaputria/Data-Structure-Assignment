/* 
    Saya Cantika Putri Arbiliansyah dengan NIM [2103727] mengerjakan 
    UAS No 2 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

//LIBRARY
#include "header.h"

//PROSEDUR UNTUK MEMBUAT GRAPH
void createEmpty(graph *G)
{
    (*G).first = NULL;                          //null kan node pertama untuk membuat graph kosong
}

//PROSEDUR UNTUK MEMBUAT SIMPUL
void addSimpul(input c, graph *G)
{
    simpul *baru;                                               //pointer penanda baru
    baru = (simpul *) malloc (sizeof(simpul));                  //alokasi memori
    baru->kontainer = c;                                        //mengisi data
    baru->next = NULL;                                          //baru next menjadi null
    baru->arc = NULL;                                           //baru arc juga menjadi null

    if((*G).first == NULL)                                      //jika graf kosong
    {
        (*G).first = baru;                                      //node pertama adalah simpul baru
    }
    else                                                        //jika tidak kosong, menambahkan simpul baru di akhir graph
    {
        simpul *last = (*G).first;                              //poinyer last menujuk pada first
        while(last->next != NULL)                               //selama bukan simpul terakhir
        {
            last = last->next;                                  //last maju ke simpul selanjutya
        }
        last->next = baru;                                      //last next diisi simpul baru
    }
}

//PROSEDUR UNTUK MENAMBAHKAN JALUR
void addJalur(simpul *awal, simpul *tujuan, int beban)
{
    jalur *baru;                                                //pointer jalur baru
    baru = (jalur *) malloc (sizeof (jalur));                   //alokasi memori
    baru->kontainer_jalur = beban;                              //mengisi data dengan beban
    baru->next_jalur = NULL;                                    //nullkan next jalur simpul baru
    baru->tujuan = tujuan;                                      //jalur baru menuju pada ismpul tujuan

    if(awal->arc == NULL)                                       //jika list jalur kosong
    {
        awal->arc = baru;                                       //jalur awal diiisi jalur baru
    }
    else                                                        //jika jalur tidak kosong, menambahkan jalur baru pada akhir list jalur
    {
        jalur *last = awal->arc;                                //jalur last menunjuk pada jalur awal
        while(last->next_jalur != NULL)                         //selama bukan jalur terakhir
        {
            last = last->next_jalur;                            //pointer last maju terus 
        }
        last->next_jalur = baru;                                //jalur terakhir diisi jalur baru
    }
}

//FUNGSI UNTUK MENCARI SIMPUL
simpul* findSimpul(input c, graph G)
{
    simpul *hasil = NULL;                               //membuat pointer hasil
    simpul *bantu = G.first;                            //membuat pointer bantu yg menunjuk pada simpul pertama
    int ketemu = 0;                                     //penanda

    while((bantu != NULL) &&(ketemu == 0))              //selama bantu bernilai dan ketemu masih nol
    {
        if(bantu->kontainer.c == c.c)                       //jika pointer yg ditandai sesuai yg dicari
        {
            hasil = bantu;                              //tandai hasilnya
            ketemu = 1;                                 //tandai satu
        }
        else                                            //jika belum sesuai
        {
            bantu = bantu->next;                        //maju terus ke simpul selanjutnya
        }
    }

    return hasil;                                       //mengembalikan nilai hasil
}

//PROSEDUR UNTUK MENAMPILKAN GRAPH
void printGraph(graph G)
{
    int coba = 0;
    simpul *bantu = G.first;                                        //pointer penanda menunjuk pada simpul pertama

    printf("jumlah jalur: %d\n", coba);              //tampilkan teks ke layar
    printf("terdiri dari\n");
    printf("- %d jalur langsung\n", coba);
    printf("- %d jalur tidak langsung\n", coba);

    if(bantu != NULL)                                               //jika bantu bukan null
    {
        while(bantu != NULL)                                        //selama bantu bukan null
        {
            jalur *bantu_jalur = bantu->arc;                        //pointer penanda jalur

            while(bantu_jalur != NULL)                              //selama bantu jalur bukan null
            {
                bantu_jalur = bantu_jalur->next_jalur;              //bantu jalur maju ke setelahnya
            }
            bantu = bantu->next;                                    //bantu juga maju ke setelahnya
        }
    }
    else                                                            //jika= null maka graph kosong
    {
        printf("graf kosong\n");                                    //tampilkan teks ke layar
    }
}

//PROSEDUR UNTUK MENCARI JUMLAH JALUR (tidak jalan jadi saya komen)
// simpul* findJalur(input awal, input akhir, graph G, char temp[], int i)
// {
//     simpul *bantu = findSimpul(awal, G);
//     jalur *bantu_jalur = bantu->arc;
//     simpul *hasil = NULL; 
//     simpul *last = findSimpul(akhir, G);

//     int ketemu = 0;
//     while((bantu != NULL) &&(ketemu == 0))              //selama bantu bernilai dan ketemu masih nol
//     {
//         if(bantu->kontainer.c == akhir.c)                       //jika pointer yg ditandai sesuai yg dicari
//         {
//             hasil = bantu;                              //tandai hasilnya
//             ketemu = 1;                                 //tandai satu
//         }
//         else                                            //jika belum sesuai
//         {
//             bantu = bantu->next;                        //maju terus ke simpul selanjutnya
//         }
//         findJalur(bantu->kontainer, akhir, G, temp, i);
//     }

//     printf("%d", hasil)
//     return hasil;
// }