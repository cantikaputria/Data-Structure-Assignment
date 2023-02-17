#include "header.h"

int main()
{
    list L;
    createList(&L);
    printElement(L);

    printf("=================\n");

    if(L.first != 0)
    {
        int depan = L.first;
        int belakang = L.tail;
        int i;

        char nim[10];
        char nama[50];
        char nilai[2];

        for ( i = 0; i < countElement(L) / 2; i++)
        {
            strcpy(nim, L.data[depan].kontainer.nim);
            strcpy(L.data[depan].kontainer.nim, L.data[belakang].kontainer.nim);
            strcpy(L.data[belakang].kontainer.nim, nim);
        }

        depan = L.data[depan].next;
        belakang = L.data[belakang].prev;
        
    }
    addFirst("1", "Orang_1", "A", &L);
    addAfter(L.first, "2", "Orang_2", "A", &L);
    addLast("3", "Orang_3", "A", &L);

    
    printElement(L);
    
    
    printf("=================\n");
    delLast(&L);
    delAfter(L.first, &L);
    delFirst(&L);
    printElement(L);
    printf("=================\n");

 return 0;
}