#include "header.h"

int main()
{
    list L;
    createList(&L);
    printElement(L);
    printf("=================\n");
    
    printElement(L);
    printf("=================\n");

    addFirst("1", "Orang_1", "A", &L);
    addAfter(L.first, "2", "Orang_2", "A", &L);
    addLast("3", "Orang_3", "A", &L);

    delLast(&L);
    delAfter(L.first, &L);
    delFirst(&L);
    printElement(L);

    printf("=================\n");

    return 0;
}


// addFirst("1", "Orang_1", "A", &L);
//     addFirst("2", "Cacan", "A", &L);
//     addAfter(2, "3", "jncdjcdjdj", "B", &L);
//     addLast("4", "Orang_3", "A", &L);