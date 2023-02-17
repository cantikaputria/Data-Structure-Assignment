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

void addFirst(char food[], int price, list *L)
{   
    //bikin pointer
    elemen* baru;

    //pointer baru akan mengacu secara casting (dipaksa) sebagai pointer 
    //elemen agar tipenya sama, alokasi memori sebesar data yg dibutuhkan elemen
    baru = (elemen*) malloc (sizeof (elemen));
    
    strcpy(baru->kontainer.food, food);
    baru->kontainer.price = price;

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

void addAfter(elemen* prev, char food[], int price, list *L)
{
    elemen *baru;
    baru = (elemen*) malloc (sizeof (elemen));

    strcpy(baru->kontainer.food, food);
    baru->kontainer.price = price;

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

void addLast(char food[], int price, list *L)
{
    if((*L).first == NULL)
    {
        /*jika list adalah list kosong*/
        addFirst(food, price, L);
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

        addAfter(prev, food, price, L);
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
            printf("%s - %d\n", tunjuk->kontainer.food, tunjuk->kontainer.price);
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

void tuker(list *L1, list *L2, char tuker1[50], char tuker2[50])
{
    elemen* tanda1 = (*L1).first;
    elemen* tanda2 = (*L2).first;
    elemen* prev1 = NULL;
    elemen* prev2 = NULL;

    if((strcmp(tanda1->kontainer.food, tuker1) != 0) && (strcmp(tanda1->kontainer.food, tuker2) != 0))
    {

        printf("cek1\n");
        while((strcmp(tanda1->kontainer.food, tuker1) == 0) && (strcmp(tanda1->kontainer.food, tuker2)) == 0)
        {
            tanda1 = tanda1->next;
        }

        prev1 = tanda1;
        tanda1 = tanda1->next;
    }
    
    if( (strcmp(tanda2->kontainer.food, tuker1) != 0) && strcmp(tanda2->kontainer.food, tuker2) != 0)
    {
        while((strcmp(tanda2->kontainer.food, tuker1) == 0) && (strcmp(tanda2->kontainer.food, tuker2)) == 0)
        {
            tanda2 = tanda2->next;
        }

        prev2 = tanda2;
        tanda2 = tanda2->next;
    }

    if(prev1 == NULL && prev2 == NULL)
    {
        (*L1).first = tanda1->next;
        (*L2).first = tanda2->next;

        tanda1->next = (*L2).first;
        tanda2->next = (*L1).first;

        (*L1).first = tanda2;
        (*L2).first = tanda1;
    }
    else if(prev1 == NULL)
    {
        (*L1).first = tanda1->next;
        prev2->next = tanda2->next;

        tanda2->next = (*L1).first;
        (*L1).first = tanda2;

        tanda1->next = prev2->next;
        prev2->next = tanda1;

    }
}