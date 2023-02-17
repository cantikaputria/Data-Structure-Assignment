#include "header.h"

void createEmpty(queue *Q){
    (*Q).first = NULL;
    (*Q).last = NULL;
}

int isEmpty(queue Q){
    int hasil = 0;
    if(Q.first == NULL){
        hasil = 1;
    }
    return hasil;
}

int countElement(queue Q){
    int hasil = 0;
    if(Q.first != NULL){
        /* queue tidak kosong */
        elemen* bantu;
        /* inisialisasi */
        bantu = Q.first;

        while(bantu != NULL){
            /* proses */
            hasil= hasil + 1;

            /* iterasi */
            bantu = bantu->next;
        }
    }
    return hasil;
}

void add(char nama[], char rating[], queue *Q )
{
    elemen* baru;
    baru = (elemen *) malloc (sizeof (elemen));
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.rating, rating);
   
    baru->next = NULL;
    if((*Q).first == NULL)
    {
        (*Q).first = baru;
    } else{
        (*Q).last->next = baru;
    }
    (*Q).last = baru;
    baru = NULL;
}

void addPriority(char nama[], char rating[], int priority, queue *Q)
{
    elemen* baru;
    baru = (elemen *) malloc (sizeof (elemen));
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.rating, rating);
   
    baru->next = NULL;
    
        if (priority == 1)
        {
            baru->next =  (*Q).first;
            (*Q).first = baru;
        }
        else if(priority == 2)
        {
            baru->next = (*Q).first->next;
            (*Q).first->next = baru;
        }
        else if(priority > countElement(*Q))
        {
            add(nama, rating, Q);
        }
}

void del(queue *QA, queue *QB) 
{
    if((*QA).first != NULL) 
    {
        elemen *hapus = (*QA).first;
        add(hapus->kontainer.nama, hapus->kontainer.rating, QB);
        if(countElement(*QA) == 1)
        {
            (*QA).first = NULL;
            (*QA).last = NULL;
        }
         else 
        {
            (*QA).first = (*QA).first->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void printQueue1(queue Q)
{
    if(Q.first != NULL){
        elemen* bantu = Q.first;
        int i = 1;

        printf("Queue 1\n");
        while(bantu != NULL)
        {
        
            printf("%s %s\n", bantu->kontainer.nama, bantu->kontainer.rating);
        
            /* iterasi */
            bantu = bantu->next;
            i = i + 1;
        }
    }
    else
    {
        /* proses jika queue kosong */
        printf("queue kosong\n");
    }
}

void printQueue2(queue Q){
    if(Q.first != NULL){
        elemen* bantu = Q.first;
        int i = 1;
       
         printf("Queue 2\n");
        while(bantu != NULL)
        {
           
            printf("%s %s\n", bantu->kontainer.nama, bantu->kontainer.rating);
        
            /* iterasi */
            bantu = bantu->next;
            i = i + 1;
        }
    } else
    {
        /* proses jika queue kosong */
        printf("queue kosong\n");
    }
}