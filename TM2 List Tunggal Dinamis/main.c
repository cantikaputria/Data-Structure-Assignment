#include "header.h"

int main()
{
    list L;
    createList(&L);

    char nama[50];
    char jk[10];
    char asal[50];

    //input 1
    scanf("%s %s %s", &nama, &jk, &asal);
    addLast(nama, jk, asal, &L);

    scanf("%s %s %s", &nama, &jk, &asal);
    addFirst(nama, jk, asal, &L);

    scanf("%s %s %s", &nama, &jk, &asal);
    addAfter(L.first->next, nama, jk, asal, &L);
    
    printf("--------------------\n");
    printElement(L);
 
    delAfter(L.first->next, &L);
    delFirst(&L);
    printElement(L);

    //input 2
   
    scanf("%s %s %s", &nama, &jk, &asal);
 
    addLast(nama, jk, asal, &L);

    scanf("%s %s %s", &nama, &jk, &asal);
    addFirst(nama, jk, asal, &L);

    delLast(&L);

    printElement(L);

    //last
    delAll(&L);
    printElement(L);

    scanf("%s %s %s", &nama, &jk, &asal);
    addLast(nama, jk, asal, &L);

    printElement(L);
    
 return 0;
}