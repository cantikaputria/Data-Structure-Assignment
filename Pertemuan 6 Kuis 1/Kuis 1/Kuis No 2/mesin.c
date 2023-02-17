#include "header.h"

//PROSEDUR UNTUK MEMBUAT LIST
void createList(list *L)
{
    (*L).first = -1;                            //deklarasi first sama dengan null
    (*L).tail = -1;                             //deklarasi tail sama dengan null
    int i;                                      //inisialisasi

    for(i=0;i<10;i++)                           //looping sebanyak data
    {
        (*L).data[i].prev = -2;                 //pointer prev diisi
        (*L).data[i].next = -2;                 //pointer next diisi
    }
}

//FUNGSI UNTUK MENGHITUNG JUMLAH ELEMEN
int countElement(list L)
{
    int hasil = 0;                                  //membuat kotak hasil

    if(L.first != -1)                               //jika listnya tidak kosong atau bukan list terakhir, maka....
    {
        int bantu;                                  //membuat pointer penunjuk
        
        bantu = L.first;                            //mulai pengecelan dari elemen pertama

        while(bantu != -1)                          //selama tunjukknya masiha ada elemennya, maka...
        {
            hasil = hasil + 1;                      //lakukan sampai elemen terakhir
            bantu = L.data[bantu].next;             //tunjuk yg sekarang, tunjuk tadi nextnya
        }
    } 
    
    return hasil;                                   //mengembalikan haisl hitung
}

//FUNGSI MENGHITUNG ELEMEN KOSONG
int emptyElement(list L)
{
 int hasil = -1;                                //jika hasil null
 if(countElement(L) < 10)                       //dan count elemen kurang dari 10
    {
        int ketemu = 0;
        int i = 0;
        while((ketemu == 0)&&(i < 10))
        {
            if(L.data[i].next == -2)
            {
                hasil = i;
                ketemu = 1;
            }
            else
            {
                i = i + 1;
            }
        }
    } 
    return hasil;
}

//PROSEDUR UNTUK MENAMBAH ELEMEN DI AWAL
void addFirst(int id, char nama[], char bagian[], list *L)
{
    if(countElement(*L) < 10)
    {
        int baru = emptyElement(*L);
      
       (*L).data[baru].kontainer.id = id;
        strcpy((*L).data[baru].kontainer.nama, nama);
        strcpy((*L).data[baru].kontainer.bagian, bagian);
        
        if((*L).first == -1)
        {
            /*jika list kosong*/
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = -1;
            (*L).tail = baru;
        }
        else
        {
            /*jika list tidak
            kosong*/
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = (*L).first;
            (*L).data[(*L).first].prev = baru;
        }
            
        (*L).first = baru;
    }
            
    else
    {
        /*proses jika array penuh*/
        printf("sudah tidak dapat ditambah\n");
    }
}

//PROSEDUR UNTUK MENAMBAH ELEMEN DI TENGAH
void addAfter(int before, int id, char nama[], char bagian[], list *L)
{
    if(countElement(*L) < 10)
    {
        int baru = emptyElement(*L);
        (*L).data[baru].kontainer.id = id;
        strcpy((*L).data[baru].kontainer.nama, nama);
        strcpy((*L).data[baru].kontainer.bagian, bagian);

        if((*L).data[before].next != -1)
        {
            //jika baru bukan menjadi elemen terakhir
            (*L).data[baru].prev = before;
            (*L).data[baru].next = (*L).data[before].next;
            (*L).data[before].next = baru;
            (*L).data[(*L).data[baru].next].prev = baru;
        }
        else
        {
            //jika baru menjadi elementerakhir
            (*L).data[baru].prev = before;
            (*L).data[before].next = baru;
            (*L).data[baru].next = -1;
            (*L).tail = baru;
        }
    }
    else
    {
        /*proses jika array penuh*/
        printf("sudah tidak dapat ditambah\n");
    }
}

//PROSEDUR UNTUK MENAMBAH ELEMEN DI AKHIR
void addLast(int id, char nama[], char bagian[], list *L)
{
    if((*L).first == -1)
    {
        /*proses jika list masih kosong*/
        addFirst(id, nama, bagian, L);
    }
    else
    {
        /*proses jika list telah berisi elemen*/
        addAfter((*L).tail, id, nama, bagian, L);
    }
}

//PROSEDUR UNTUK MENAMPILKAN SELURUH ELEMEN LIST
void printElement(list L)
{
    if(L.first != -1)
    {
        /*inisialisasi*/
        int bantu = L.first;
        int i = 1;

        while(bantu != -1)
        {
            /*proses*/
            printf("%d %s %s\n", L.data[bantu].kontainer.id, L.data[bantu].kontainer.nama, L.data[bantu].kontainer.bagian);
            /*iterasi*/
            bantu = L.data[bantu].next;
            i = i + 1;
        }
    }
    else
    {
        /*proses jika list kosong*/
        printf("list kosong\n");

    }
}

//PROSEDUR UNTUK MENUKAR ELEMEN
void tukar(list *L1, list *L2)
{
    int depan1 = (*L1).first;
    int belakang1 = (*L1).tail;

    int depan2 = (*L1).first;
    int belakang2 = (*L1).tail;

    int id_temp;
    char nama_temp[50];
    char bagian_temp[100];

    int i;
    
    for ( i = 0; i < countElement(*L1); i++)
    {
       
        id_temp = (*L1).data[depan1].kontainer.id;
        (*L1).data[depan1].kontainer.id = (*L2).data[belakang2].kontainer.id;
        (*L2).data[belakang2].kontainer.id = id_temp;

        strcpy(nama_temp, (*L1).data[depan1].kontainer.nama);
        strcpy((*L1).data[depan1].kontainer.nama, (*L2).data[belakang2].kontainer.nama);
        strcpy((*L2).data[belakang2].kontainer.nama, nama_temp);

        strcpy(bagian_temp, (*L1).data[depan1].kontainer.bagian);
        strcpy((*L1).data[depan1].kontainer.bagian, (*L2).data[belakang2].kontainer.bagian);
        strcpy((*L2).data[belakang2].kontainer.bagian, bagian_temp);
    }

    depan1 = (*L1).data[depan1].next;
    belakang1 = (*L1).data[belakang1].prev;

    depan2 = (*L1).data[depan1].next;
    belakang2 = (*L1).data[belakang1].prev;
}