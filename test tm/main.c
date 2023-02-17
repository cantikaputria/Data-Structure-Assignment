#include "header.h"

int main() 
{
    tree T;
    mahasiswa data;

    //step 1
    scanf("%s %d", data.nama, &data.nilai);
    makeTree(data, &T);

    scanf("%s %d", data.nama, &data.nilai);
    addChild(data, T.root);

    scanf("%s %d", data.nama, &data.nilai);
    addChild(data, T.root);

    scanf("%s %d", data.nama, &data.nilai);
    addChild(data, T.root);

    scanf("%s %d", data.nama, &data.nilai);
    addChild(data, T.root->child);

    scanf("%s %d", data.nama, &data.nilai);
    addChild(data, T.root->child);

    printf("Step 1:\n");
    printf("================\n");
    first = 1;
    printTreePreOrder(T.root);
    printf("\n");

    first = 1;
    printTreePostOrder(T.root);
    printf("\n");

    delChild(T.root->child->child->sibling->kontainer, T.root->child);
    
    first = 1;
    printTreePreOrder(T.root);
    printf("\n");
    
    first = 1;
    printTreePostOrder(T.root);
    printf("\n");

    scanf("%s %d", data.nama, &data.nilai);
    addChild(data, T.root->child->sibling);

    scanf("%s %d", data.nama, &data.nilai);
    addChild(data, T.root->child->sibling);

    scanf("%s %d", data.nama, &data.nilai);
    addChild(data, T.root->child->sibling->sibling);
    first = 1;
    printTreePreOrder(T.root);

    //step 2
    tree T2;
    copyTree(T.root, &T2.root);

    printf("\nStep 2:\n");
    printf("================\n");
    if(isEqual(T.root, T2.root) == 1)
    {
        printf("Sama\n");
    } 
    else 
    {
        printf("Tidak Sama\n");
    }

    //step 3
    printf("Step 3:\n");
    printf("================\n");

    char cari[50];
    scanf("%s", cari);

    simpul *cari1 = findSimpul(cari, T.root->child->child);

    if(cari1 != NULL)
    {
        printf("%s ditemukan\n", cari);
    }
    else
    {
        printf("%s tidak ditemukan\n", cari);
    }

    simpul *cari2 = findSimpul(cari, T.root->child->sibling);

    if(cari2 != NULL)
    {
        printf("%s ditemukan\n", cari);
    }
    else
    {
        printf("%s tidak ditemukan\n", cari);
    }

    simpul *cari3 = findSimpul(cari, T.root);

    if(cari3 != NULL)
    {
        printf("%s ditemukan\n", cari);
    }
    else
    {
        printf("%s tidak ditemukan\n", cari);
    }

    return 0;
}