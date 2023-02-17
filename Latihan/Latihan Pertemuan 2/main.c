#include "header.h"

int main()
{
    list L;
    createList(&L);
    
    int i, n;
    float temp;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%f", &temp);
        addFirst(temp, &L);
    }
    
    printElement(L);

    return 0;
}