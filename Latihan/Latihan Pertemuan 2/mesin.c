#include "header.h"

void addFirst(float x, list *L)
{
    if(countElement(*L) < 10)
    {
        int baru = emptyElement(*L);
        
        (*L).data[baru].kontainer.x = x;

        if((*L).first == -1)
        {
            /*jika list kosong*/
            (*L).data[baru].next = -1;
        }
        else
        {
            /*jika list tidak kosong*/
            (*L).data[baru].next = (*L).first;
        }
        (*L).first = baru;
    }
    else
    {
        /*proses jika array penuh*/
        printf("sudah tidak dapat ditambah\n");
    }
}

void printElement(list L)
{
    if(L.first != -1)
    {
        /*inisialisasi*/
        int tunjuk = L.first;
        int i = 1;

        while(tunjuk != -1)
        {
            /*proses*/
            printf("%0.2f\n", L.data[tunjuk].kontainer.x);
           
            /*iterasi*/
            tunjuk = L.data[tunjuk].next;
            i = i + 1;
        }
    }
    else
    {
        /*proses jika list kosong*/
        printf("list kosong\n");
    }
}

void createList(list *L)
{
    (*L).first = -1;
    int i;

    for(i = 0; i < 10; i++)
    {
        /*proses menginisialisasi isi array*/
        (*L).data[i].next = -2;
    }
}

int countElement(list L)
{
    int hasil = 0;
    if(L.first != -1)
    {
        /*list tidak kosong*/
        int hitung;

        /*inisialisasi*/
        hitung = L.first;

        while(hitung != -1)
        {
            /*proses*/
            hasil = hasil + 1;

            /*iterasi*/
            hitung = L.data[hitung].next;
        }
    }
    return hasil;
}

//EMPTY ELEMENT
int emptyElement(list L)
{
    int hasil = -1;

    if(countElement(L) < 10)
    {
        int ketemu = 0;
        int i = 0;
        while((ketemu == 0) && (i < 10))
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