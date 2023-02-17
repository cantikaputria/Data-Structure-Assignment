#include "header.h"

int main()
{
    graph G;
    createEmpty(&G);

    addSimpul(1, &G);
    addSimpul(2, &G);
    addSimpul(3, &G);
    addSimpul(4, &G);
    addSimpul(5, &G);
    addSimpul(6, &G);
    addSimpul(7, &G);
    addSimpul(8, &G);

    simpul *begin;
    simpul *end;

    begin = findSimpul(1, G);

    begin = findSimpul(2, G);

    begin = findSimpul(3, G);
    end = findSimpul(8, G);
    if((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 3);
    }
    
    begin = findSimpul(3, G);
    end = findSimpul(1, G);
    if((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 4);
    }

    begin = findSimpul(3, G);
    end = findSimpul(7, G);
    if((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 4);
    }

    begin = findSimpul(4, G);
    end = findSimpul(2, G);
    if((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 5);
    }

    begin = findSimpul(5, G);
    end = findSimpul(6, G);
    if((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 6);
    }

    begin = findSimpul(6, G);
    end = findSimpul(3, G);
    if((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 7);
    }

    begin = findSimpul(7, G);
    end = findSimpul(4, G);
    if((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 8);
    }

    begin = findSimpul(8, G);
    end = findSimpul(1, G);
    if((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 9);
    }

    begin = findSimpul(8, G);
    end = findSimpul(6, G);
    if((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 0);
    }

    printGraph(G);

    int hapus;
    scanf("%d", &hapus);

    begin = findSimpul(hapus, G);
    if (begin != NULL)
    {
        delSimpul(hapus, &G);
    }
    printf("==============\n");
    printGraph(G);
    return 0;
}