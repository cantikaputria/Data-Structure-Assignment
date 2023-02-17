/* 
    Saya Cantika Putri Arbiliansyah dengan nama [2103727] mengerjakan 
    Tugas Praktikum 5 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

//LIBRARY
#include "header.h"

//PROSEDUR UNTUK MEMBUAT GRAPH 
void createEmpty(graph *G)
{
    (*G).first = NULL;                                  //simpul pertama null
}

//PROSEDUR UNTUK MENAMBAHKAN SIMPUL
void addSimpul(input c, graph *G)
{
    simpul *baru;                                               //buat pointer baru
    baru = (simpul *) malloc (sizeof(simpul));                  //alokasi memori
    baru->kontainer = c;                                        //mengisi data
    baru->next = NULL;                                          //baru nextnya null
    baru->arc = NULL;                                           //baru jalurnya null

    if((*G).first == NULL)                                      //jika graf kosong
    {
        (*G).first = baru;                                      //maka simpul pertama adalah simpul baru
    }
    else                                                        //jika graf sudah mempunyai simpul, tambahkan baru pada akhir graph
    {
        simpul *last = (*G).first;                              //buat pointer last yg menunjuk simpul  first
        while(last->next != NULL)                               //selama setelah last bukan null
        {
            last = last->next;                                  //maju ke simpul setelahnya
        }   
        last->next = baru;                                      //simpul setelah last diisi simpul baru
    }
}

//PROSEDUR UNTUK MENAMBAHKAN JALUR
void addJalur(simpul *awal, simpul *tujuan, int beban)
{
    jalur *baru;                                                        //buat pointer baru
    baru = (jalur *) malloc (sizeof (jalur));                           //alokasi memori
    baru->bobot = beban;                                                //bobot baru diisi dengan beban
    baru->next_jalur = NULL;                                            //next jalur dari baru null
    baru->tujuan = tujuan;                                              //tujuan pointer baru pada simpul tujuan

    if(awal->arc == NULL)                                               //jika list jalur kosong
    {
        awal->arc = baru;                                               //awal jalur menunjuk pada simpul baru
    }
    else                                                                //menambahkan jalur baru pada akhir list jalur
    {
        jalur *last = awal->arc;                                        //membuat pointer penanda last

        while(last->next_jalur != NULL)                                 //selama last nextya belum null
        {
            last = last->next_jalur;                                    //maju terus
        }
        last->next_jalur = baru;                                        //last nextnya menunjuk pada baru
    }
}

//FUNGSI UNTUK MENVCARI SIMPUL
simpul* findSimpul(input c, graph G)
{
    simpul *hasil = NULL;                                   //membuat pointer hasil yang di set null
    simpul *bantu = G.first;                                //membuat pointer bantu di first simpul
    int ketemu = 0;                                         //inisialisasi variabel penanda

    while((bantu != NULL) &&(ketemu == 0))                  //selama bantu nya tidak null dan belum ketemu
    {
        if(bantu->kontainer.c == c.c)                       //jika yang ditunjuk bantu sesuai dengan yang dicari
        {
            hasil = bantu;                                  //tandai hasilnya
            ketemu = 1;                                     //ketemu menjadi 1
        }
        else                                                //jika belum sesuai
        {
            bantu = bantu->next;                            //bantu maju terus
        }
    }

    return hasil;                                           //mengembalikan nilai hasil
}

//PROSEDUR UNTUK MENCARI JALUR
void findJalur(input awal, input akhir, graph G, int totbot, char temp[], int i)
{
    simpul *bantu = findSimpul(awal, G);                    //membuat pointer bantu di simpul awal
   
    temp[i] = bantu->kontainer.c;                           //isi temp sementara dengan jalur yg dilalui
    i++;                                                    //iterasi

    if(bantu->kontainer.c == akhir.c)                       //jika yg ditunjuk bantu sesuai dengan pointer akhir (ibu)
    {
        for(int j = 0; j < i; j++)
        {
            printf("%c ", temp[j]);                         //tampilkan simpul yang dilalui
        }
        printf("%d\n", totbot);                             //tampilkan total bobot jalurnya
    } 
    
    //jika belum sesuai
    jalur *bantu_jalur = bantu->arc;                        //buat pointer bantu jalur
    while (bantu_jalur != NULL)                             //selama bantu jalur bukan null
    {
        totbot += bantu_jalur->bobot;                       //niai total bobotnya bertambah
        findJalur(bantu_jalur->tujuan->kontainer, akhir, G, totbot, temp, i);   //rekursif
        totbot -= bantu_jalur->bobot;
        bantu_jalur = bantu_jalur->next_jalur;              //maju ke jalur selanjutnya
    }
}   