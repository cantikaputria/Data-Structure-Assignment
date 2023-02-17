#include "header.h"

int main()
{
    list L;
    createList(&L);

    int i;
    char nama[50];
    char level[10];
    char asal[50];

    //INPUT 1
    scanf("%s %s %s", &nama, &level, &asal);
    addFirst(nama, level, asal, &L);

    scanf("%s %s %s", &nama, &level, &asal);
    addFirst(nama, level, asal, &L);

    scanf("%s %s %s", &nama, &level, &asal);
    addAfter(L.first, nama, level, asal, &L);

    printElement(L);

    //INPUT 2

    delLast(&L);

    scanf("%s %s %s", &nama, &level, &asal);
    addAfter(L.data[L.first].next, nama, level, asal, &L);

    scanf("%s %s %s", &nama, &level, &asal);
    addLast(nama, level, asal, &L);
    printElement(L);

    //INPUT 3
    delAfter(L.data[L.first].next, &L);
    delFirst(&L);
    delLast(&L);
    printElement(L);

    //last
    delLast(&L);
    printElement(L);

    return 0;
}