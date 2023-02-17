#include "header.h"

void createEmpty(stack *S)
{
 (*S).top = NULL;
}

int isEmpty(stack S)
{
    int hasil = 0;
    if(S.top == NULL)
    {
        hasil = 1;
    }
    return hasil;
}

int countElement(stack S)
{
    int hasil = 0;
    if(S.top != NULL)
    {
        /* stack tidak kosong */
        elemen* bantu;
        /* inisialisasi */
        bantu = S.top;
        while(bantu != NULL)
        {
            /* proses */
            hasil= hasil + 1;
            /* iterasi */
            bantu = bantu->next;
        }
    }
    return hasil;
}

void push(char nama[], char harga[], stack *S )
{
    elemen* baru;
    baru = (elemen *) malloc (sizeof (elemen));
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.harga, harga);

    if((*S).top == NULL)
    {
        //jika stack kosong
        baru->next = NULL;
    }
    else
    {
        //jika stack tidak kosong
        baru->next = (*S).top;
    }
    (*S).top = baru;
    baru = NULL;
}

void pop(stack *S)
{
    if((*S).top != NULL)
    {
        /*jika stack bukan list kosong*/
        elemen *hapus = (*S).top;
        if(countElement(*S) == 1){
        (*S).top = NULL;
        }
        else{
        (*S).top = (*S).top->next;
        }
        hapus->next = NULL;
        free(hapus);
    }
    else
    {
        printf("stack kosong");
    }
}

void printStack1(stack S)
{
    if(S.top != NULL)
    {
        printf("S1:\n");
        elemen* bantu = S.top;
        int i = 1;

        while(bantu != NULL)
        {
            printf("%d. %s\n", i, bantu->kontainer.nama);
            /* iterasi */
            bantu = bantu->next;
            i = i + 1;
        }
    }
    else
    {
            /* proses jika stack kosong */
            printf("S1:\n");
            printf("- Stack Kosong\n");
    }
}

void printStack2(stack S)
{
    if(S.top != NULL)
    {
        printf("S2:\n");
        elemen* bantu = S.top;
        int i = 1;

        while(bantu != NULL)
        {
            printf("%d. %s\n", i, bantu->kontainer.nama);
            /* iterasi */
            bantu = bantu->next;
            i = i + 1;
        }
    }
    else
    {
            /* proses jika stack kosong */
            printf("S2:\n");
            printf("- Stack Kosong\n");
    }
}

void popTuker(stack *SX, stack *SY)
{
    
    if((*SX).top != NULL)
    {
        /*jika stack bukan list kosong*/
        elemen *hapus = (*SX).top;
        push(hapus->kontainer.nama, hapus->kontainer.harga, SY);

        if(countElement(*SX) == 1)
        {
            (*SX).top = NULL;
        }
        else
        {
            (*SX).top = (*SX).top->next;
        }
        hapus->next = NULL;
        free(hapus);
    }
    else
    {
        printf("stack kosong");
    }
}