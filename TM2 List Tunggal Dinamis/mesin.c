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

void addFirst(char nama[], char jk[], char asal[], list *L)
{   
    //bikin pointer
    elemen* baru;

    //pointer baru akan mengacu secara casting (dipaksa) sebagai pointer 
    //elemen agar tipenya sama, alokasi memori sebesar data yg dibutuhkan elemen
    baru = (elemen*) malloc (sizeof (elemen));
    
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.jk, jk);
    strcpy(baru->kontainer.asal, asal);

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

void addAfter(elemen* prev, char nama[], char jk[], char asal[], list *L)
{
    elemen *baru;
    baru = (elemen*) malloc (sizeof (elemen));

    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.jk, jk);
    strcpy(baru->kontainer.asal, asal);

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

void addLast(char nama[], char jk[], char asal[], list *L)
{
    if((*L).first == NULL)
    {
        /*jika list adalah list kosong*/
        addFirst(nama, jk, asal, L);
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

        addAfter(prev, nama, jk, asal, L);
    }
}

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
            
            printf("%s - %s - %s\n", tunjuk->kontainer.nama, tunjuk->kontainer.jk, tunjuk->kontainer.asal);
          
            tunjuk = tunjuk->next;
            i = i + 1;
        }
        printf("--------------------\n");
    }
    else
    {
        
        /*proses jika list kosong*/
        printf("List Kosong.\n");
         printf("--------------------\n");
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