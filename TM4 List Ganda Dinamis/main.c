#include "header.h"

int main()
{
    list L;
    createList(&L);

    char nama[50];
    char nim[50];
    char golDar[50];

    //input 1
    scanf("%s %s %s", &nama, &nim, &golDar);
    addLast(nama, nim, golDar, &L);

    scanf("%s %s %s", &nama, &nim, &golDar);
    addFirst(nama, nim, golDar, &L);

    scanf("%s %s %s", &nama, &nim, &golDar);
    addBefore(L.first->next, nama, nim, golDar, &L);
    
    printf("Data Golongan Darah\n");
    printf("===================\n");
    printElement(L);
 
    //input 2
    scanf("%s %s %s", &nama, &nim, &golDar);
    addAfter(L.first->next, nama, nim, golDar, &L);

    delAfter(L.first, &L);

    scanf("%s %s %s", &nama, &nim, &golDar);
    addAfter(L.first, nama, nim, golDar, &L);

    scanf("%s %s %s", &nama, &nim, &golDar);
    addBefore(L.tail, nama, nim, golDar, &L);

    delFirst(&L);

    printf("===================\n");
    printElement(L);
    // printf("aman?\n");

    delLast(&L);
    
    delAfter(L.first, &L);

    //input 3
    scanf("%s %s %s", &nama, &nim, &golDar);
    addLast(nama, nim, golDar, &L);

    printf("===================\n");
    printRev(L);
    // printf("aman?\n");

    //terakhir
    delAll(&L);

    printf("===================\n");
    printElement(L);
    //printf("aman?\n");
    
 return 0;
}