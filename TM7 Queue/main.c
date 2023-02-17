#include "header.h"

int main ()
{
    queue Q1, Q2;
    createEmpty(&Q1);
    createEmpty(&Q2);

    char nama[50], rating[50];

    //1
    scanf("%s %s", nama, rating);
    add(nama, rating, &Q1);

    scanf("%s %s", nama, rating);
    add(nama, rating, &Q1);

    scanf("%s %s", nama, rating);
    addPriority(nama, rating, 2, &Q1);

    printf("******************\n");
    printQueue1(Q1);

    //2
    del(&Q1, &Q2); //nanti masukin ke q2

    printf("******************\n");
    printQueue1(Q1);
    printf("******************\n");
    printQueue2(Q2);

    //3
    scanf("%s %s", nama, rating);
    addPriority(nama, rating, 1, &Q1);

    scanf("%s %s", nama, rating);
    addPriority(nama, rating, 99, &Q1);

    printf("******************\n");
    printQueue1(Q1);
    del(&Q1, &Q2); //nanti masukin ke q2
    del(&Q1, &Q2); //nanti masukin ke q2

    //4
    scanf("%s %s", nama, rating);
    add(nama, rating, &Q1);

    printf("******************\n");
    printQueue1(Q1);
     printf("******************\n");
    printQueue2(Q2);
    printf("******************\n");

    return 0;
}