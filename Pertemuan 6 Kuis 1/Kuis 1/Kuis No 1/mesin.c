//LIBRARY
#include "header.h"

//PROSEDUR UNTUK MEMBUAT LIST
void createList(list *L)
{
    (*L).first = NULL;
}

//FUNGSI UNTUK MENGHITUNG JUMLAH ELEMEN
int countElement(list L)
{   
    //bikin kotak hasil
    int hasil = 0;

    //kalo listnya ga kosong atau bukan list terakhir
    if(L.first !=NULL)
    {
        /*list tidak kosong*/

        //pointer
        elemen* tunjuk;

        /*inisialisasi*/
        tunjuk = L.first;

        //selama tunjukknya masiha ada elemennya
        while(tunjuk != NULL)
        {
            /*proses*/
            hasil = hasil + 1;

            /*iterasi*/
            //tunjuk yg sekarang, tunjuk tadi nextnya
            tunjuk = tunjuk->next;
        }
    }
    return hasil;
}

//FUNGSI MENGHITUNG ELEMEN KOSONG
int emptyElement(list L)
{
 int hasil = -1;
 if(countElement(L) < 10)
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
void addFirst(char jenis[], char nama[], int harga, list *L)
{   
    //bikin pointer
    elemen* baru;

    //pointer baru akan mengacu secara casting (dipaksa) sebagai pointer 
    //elemen agar tipenya sama, alokasi memori sebesar data yg dibutuhkan elemen
    baru = (elemen*) malloc (sizeof (elemen));
    
    strcpy(baru->kontainer.jenis, jenis);
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.harga = harga;

    //kalo firstnya null list kosong
    if((*L).first == NULL)
    {
        baru->next = NULL;
    }

    //kalo bukan null
    //pake tanda panah karena langsung pake memori (pointer)
    else
    {
        baru->next = (*L).first;
    }

    (*L).first = baru;
    baru = NULL;
}

//PROSEDUR UNTUK MENAMBAH ELEMEN DI TENGAH
void addAfter(elemen* prev, char jenis[], char nama[], int harga, list *L)
{
    elemen *baru;
    baru = (elemen*) malloc (sizeof (elemen));

    strcpy(baru->kontainer.jenis, jenis);
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.harga = harga;

    //diakhir
    if(prev->next == NULL)
    {
        baru->next = NULL;
    }
    else
    {   //ditengah
        baru->next = prev->next;
    }

    prev->next = baru;
    baru = NULL;
}

//PROSEDUR UNTUK MENAMBAH ELEMEN DI AKHIR
void addLast(char jenis[], char nama[], int harga, list *L)
{
    if((*L).first == NULL)
    {
        /*jika list adalah list kosong*/
        addFirst(jenis, nama, harga, L);
    }
    else
    {
        /*jika list tidak kosong
        /*mencari elemen terakhir list*/
        elemen* prev = (*L).first;
        while(prev->next != NULL)
        {
            /*iterasi*/
            prev = prev->next;
        }

        addAfter(prev, jenis, nama, harga, L);
    }
}

//PROSEDUR UNTUK MENAMPILKAN SELURUH ELEMEN LIST
void printElement(list L)
{
    if(L.first != NULL)
    {
        /*jika list tidak kosong*/
        /*inisialisasi*/
        elemen* tunjuk = L.first;
        int i = 1;
        while(tunjuk != NULL)
        {
           
            printf("%s %s %d\n", tunjuk->kontainer.jenis, tunjuk->kontainer.nama, tunjuk->kontainer.harga);
            /*iterasi*/
            tunjuk = tunjuk->next;
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
void tuker(list *L1, list *L2, char perusahaan[], char jenis_swap[])
{
    elemen* tanda1 = (*L1).first;
    elemen* tanda2 = (*L2).first;
    elemen* prev1 = NULL;
    elemen* prev2 = NULL;

    if((strcmp(perusahaan, "pertama") == 0))
    {
        if((strcmp(jenis_swap, "minuman") == 0))
        {
           
        }
        else if((strcmp(jenis_swap, "snack") == 0))
        {
           
        }
    }

    else if((strcmp(perusahaan, "kedua") == 0))
    {
        if((strcmp(jenis_swap, "minuman") == 0))
        {
           
        }
        else if((strcmp(jenis_swap, "snack") == 0))
        {
           
        }
    }
}