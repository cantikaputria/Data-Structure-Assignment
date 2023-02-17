#include "header.h"

int main()
{
    list L;
    createList(&L);

    char nama[50];
    char tgl[50];
    char jumlah[50];

    //input 1
    scanf("%s %s %s", &nama, &tgl, &jumlah);
    addFirst(nama, tgl, jumlah, &L);

    scanf("%s %s %s", &nama, &tgl, &jumlah);
    addLast(nama, tgl, jumlah, &L);

    scanf("%s %s %s", &nama, &tgl, &jumlah);
    addAfter(L.first, nama, tgl, jumlah, &L);

    printf("Data Kebun Binatang\n");
    printf("===================\n");
    printElement(L);
    
    //pisah
    delAfter(L.data[L.first].next, &L);

    scanf("%s %s %s", &nama, &tgl, &jumlah);
    addAfter(L.first, nama, tgl, jumlah, &L);

    scanf("%s %s %s", &nama, &tgl, &jumlah);
    addAfter(L.data[L.tail].prev, nama, tgl, jumlah, &L);

    delFirst(&L);
    
    printf("===================\n");
    printElement(L);

    //input 2
   
    scanf("%s %s %s", &nama, &tgl, &jumlah);
    addFirst(nama, tgl, jumlah, &L);

    scanf("%s %s %s", &nama, &tgl, &jumlah);
    addAfter(L.data[L.first].next, nama, tgl, jumlah, &L);

    delLast(&L);

    printf("===================\n");
    printRev(L);

    //last
    delAll(&L);

    printf("===================\n");
    printElement(L);
    
 return 0;
}