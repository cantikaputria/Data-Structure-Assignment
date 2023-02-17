#include "header.h"

int main ()
{
    stack S1, S2;
    char nama[50], harga[50];

    createEmpty(&S1);
    createEmpty(&S2);

    printStack1(S1);
    printStack2(S2);
    printf("==================\n");

    //pertama
    scanf("%s %s", nama, harga);
    push(nama, harga, &S1);

    scanf("%s %s", nama, harga);
    push(nama, harga, &S2);

    scanf("%s %s", nama, harga);
    push(nama, harga, &S2);

    printStack1(S1);
    printStack2(S2);
    printf("==================\n");

    //kedua
    pop(&S1);
    popTuker(&S2, &S1);

    scanf("%s %s", nama, harga);
    push(nama, harga, &S1);

    scanf("%s %s", nama, harga);
    push(nama, harga, &S2);

    scanf("%s %s", nama, harga);
    push(nama, harga, &S1);

    pop(&S2);
    popTuker(&S1, &S2);

    printStack1(S1);
    printStack2(S2);
    printf("==================\n");

    return 0;
}
