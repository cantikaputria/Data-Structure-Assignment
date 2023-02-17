#include "header.h"

int main()
{
    list L;
    createList(&L);
    
    int i, n;
    int temp;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        addFirst(temp, &L);
    }
    
    printElement(L);

    return 0;
}