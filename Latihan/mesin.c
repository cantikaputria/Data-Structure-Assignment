#include "header.h"

void createList(list *L)
{
    (*L).first = NULL;
}

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

void addFirst(sederhana input, list *L)
{   
    //bikin pointer
    elemen* baru;

    //pointer baru akan mengacu secara casting (dipaksa) sebagai pointer 
    //elemen agar tipenya sama, alokasi memori sebesar data yg dibutuhkan elemen
    baru = (elemen*) malloc (sizeof (elemen));
    baru->kontainer = input;
    
   
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

// void addAfter(elemen* prev, char nim[], char nama[], char nilai[], list *L)
// {
//     elemen *baru;
//     baru = (elemen*) malloc (sizeof (elemen));

//     strcpy(baru->kontainer.nim, nim);
//     strcpy(baru->kontainer.nama, nama);
//     strcpy(baru->kontainer.nilai, nilai);

//     //diakhir
//     if(prev->next == NULL)
//     {
//         baru->next = NULL;
//     }
//     else
//     {   //ditengah
//         baru->next = prev->next;
//     }

//     prev->next = baru;
//     baru = NULL;
// }

// void addLast(char nim[], char nama[], char nilai[], list *L)
// {
//     if((*L).first == NULL)
//     {
//         /*jika list adalah list kosong*/
//         addFirst(nim, nama, nilai, L);
//     }
//     else
//     {
//         /*jika list tidak kosong
//         /*mencari elemen terakhir list*/
//         elemen* prev = (*L).first;
//         while(prev->next != NULL)
//         {
//             /*iterasi*/
//             prev = prev->next;
//         }

//         addAfter(prev, nim, nama, nilai, L);
//     }
// }

void delFirst(list *L)
{   
    //kalo ada elemennya
    if((*L).first != NULL)
    {
        /*jika list bukan list kosong*/
        //bikin pointer disimpen di first
        elemen* hapus = (*L).first;

        //kalo elemennya cuma satu
        if(countElement(*L) == 1)
        {
            (*L).first = NULL;
        }
        else //banyak elemen
        {
            (*L).first = (*L).first->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void delAfter(elemen* prev, list *L)
{   
    //bikin pointer yang nunjuk ke prev bext
    elemen* hapus = prev->next;

    if(hapus != NULL)
    {   
        //elemen terakhir
        if(hapus->next == NULL)
        {
            prev->next = NULL;
        }
        //elemen di tengah
        else
        {
            prev->next = hapus->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void delLast(list *L)
{
    if((*L).first != NULL)
    {
        /*jika list tidak kosong*/
        if(countElement(*L) == 1)
        {
            /*list terdiri dari satu elemen*/
            delFirst(L);
        }
        else
        {
            /*mencari elemen terakhir list*/
            elemen* last = (*L).first;
            elemen* prev;

            while(last->next != NULL)
            {
                /*iterasi*/
                prev = last;
                last = last->next;
            }
            delAfter(prev, L);
        }
    }
}

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
            /*proses*/

            printf("%s\n", tunjuk->kontainer.string);
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

void delAll(list *L)
{
    if(countElement(*L) != 0)
    {
        int i;
        for(i=countElement(*L);i>=1;i--)
        {
            /*proses menghapus elemen list*/
            delLast(L);
        }
    }
}