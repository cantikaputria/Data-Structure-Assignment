#include "header.h"

int main()
{
    list L;
    createList(&L);

    char label[50];
    char kode[50];
    char barang[50];

    int n, i, j;

    scanf("%d", &n);

    eBaris *baris;
    int k;
    for (k = 0; k < n; k++)
    {
        scanf("%s %s", label, kode);
        addLastB(label, kode, &L);

        baris = get(kode, L);


            scanf("%s", barang);
            addFirstK(barang, baris);

            scanf("%s", barang);
            addLastK(barang, baris);

            scanf("%s", barang);
            addAfterK(baris->col->next_kol, barang);

            scanf("%s", barang);
            addFirstK(barang, baris);

    }

    delAfterK(L.first->next->col->next_kol);
    delFirstB(&L);
    delFirstK(L.first);
    printElement(L);
    delAllB(&L);
    printElement(L);

    return 0;
}