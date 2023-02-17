#include "header.h"

int main()
{
    list L;
    createList(&L);
    
    int i, n;
    
    scanf("%d", &n);

    sederhana input;
    for (i = 0; i < n; i++)
    {
        scanf("%s", input.string);
        addFirst(input, &L);
        
    }
    
    printElement(L);

    return 0;
}