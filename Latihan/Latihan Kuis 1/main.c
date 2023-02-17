#include "header.h"

int main ()
{
    list L1;
    createList(&L1);

    list L2;
    createList(&L2);

    char food[50];
    int price, i;


    int n;
    scanf("%d", &n);

    for ( i = 0; i < n; i++)
    {
        scanf("%s %d", &food, &price);
        addLast(food, price, &L1);
    }

    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        scanf("%s %d", &food, &price);
        addLast(food, price, &L2);
    }

    char tuker1[50], tuker2[50];

    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        scanf("%s %s", &tuker1, &tuker2);
        tuker(&L1, &L2, tuker1, tuker2);
    }


    printElement(L1);
    printf("++++++++++++++++++INI BATAS+++++++++++++++++++\n");
    printElement(L2);






    return 0;
}