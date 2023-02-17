/* 
    Saya Cantika Putri Arbiliansyah dengan nim [2103727] mengerjakan 
    Tugas Kuis 2 No 1 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

//Prosedur Untuk Membuat Stack
void createEmpty(stack *S) 
{
    (*S).top = -1;                                  // inisialisasi stack kosong
}

//Fungsi Untuk Mengecek Apakah Stack Kosong 
int isEmpty(stack S) 
{
    int hasil = 0;                                              //inisialisasi
    if(S.top == -1)                                             //jika topnya null maka stack kosong
    {
        hasil = 1;                                              //tandai 1
    }
    return hasil;                                               //kembalikan nilai hasil
}

//Fungsi Untuk Mengecek Apakah Stack Penu
int isFull(stack S) 
{
    int hasil = 0;
    if(S.top == 49)                     // jika index top nya 49 maka stack sudah penuh
    {
        hasil = 1;
    }
    return hasil;
}

//Prosedur Untuk Menambah Elemen Stack
void push(char nama[], char counter[], char daerah[], stack *S) 
{
    if(isFull(*S) == 1)                                  //jika stack penuh
    {
        printf("Stack penuh\n");
    }
    else                                                //jika stack belum penuh
    {
        if(isEmpty(*S) == 1)                            //jika stack masih kosong
        {
            (*S).top = 0;                               //inisialisasi index

            //memasukkan data element
            strcpy((*S).data[0].nama, nama);
            strcpy((*S).data[0].counter, counter);
            strcpy((*S).data[0].daerah, daerah);
        }
        else                                             //jika stack sudah ada isinya
        {
            (*S).top = (*S).top + 1;                    //incremen index

            // memasukkan data elemen
            strcpy((*S).data[(*S).top].nama, nama);
            strcpy((*S).data[(*S).top].counter, counter);
            strcpy((*S).data[0].counter, daerah);
        }
    }
}

//Prosedur Untuk Menghapus Elemen Stack
void pop(stack *S) 
{
    if((*S).top == 0)                       //jika elemen hanya 1
    {
        (*S).top = -1;
    } 
    else                                   //jika elemen lebih dari 1
    {
        if((*S).top != -1)                 //jika elemen ada, decrement
        {
            (*S).top = (*S).top - 1;
        }
    }
}

//Fungsi Untuk Memindahkan Elemen Stack
void popPush(stack *S1, stack *S2) 
{
    if((*S1).top == 0)                                  //jika elemen hanya 1
    {
        if(strcmp((*S1).data[0].nama, "0") != 0) 
        {
            push((*S1).data[0].nama, (*S1).data[0].counter, (*S1).data[0].daerah, S2);
        }
        (*S1).top = -1;
    }
    else                                            //jika elemen lebih dari 1
    {
        if((*S1).top != -1)                          // jika elemen ada
        {
            if(strcmp((*S1).data[(*S1).top].nama, "0") != 0)
            {
                push((*S1).data[(*S1).top].nama, (*S1).data[(*S1).top].counter, (*S1).data[(*S1).top].daerah, S2);
            }
            (*S1).top = (*S1).top - 1;  
        }
    }
}

//Prosedur Untuk Mencetak Elemen Stack
void printStack(stack S, int flag) 
{
    if(S.top != -1)                          // jika stack tidak kosong
    {
        int i;
        for(i = S.top; i >= 0; i--) 
        {
            printf("- %s %s %s\n", S.data[i].nama, S.data[i].counter, S.data[i].daerah);  // cetak elemen dari yang teratas
        }
    }
    else // jika stack kosong
    {
        if(flag == 1)                                             // jika stack utama yang kosong
        {
            printf("kosong\n");
        }
    }
}

//Prosedur Mencari counter Dalam Stack Utama
int cariDaerah(stack *S1, stack *S2, char cari[][50], int n) 
{
    int minIdx = n;                                     // inisialisasi penanda index terkecil
    for (int i = 0; i < n; i++) 
    {
        for(int j = (*S1).top; j >= 0; j--)             // untuk setiap daerah yang dicari
        {
            if(strcmp((*S1).data[j].daerah, cari[i]) == 0)  // untuk setiap stack
            {
                popPush(S1, S2);
                minIdx = j < minIdx ? j : minIdx;
            }
        }
    }

    return minIdx;                                   // kembalikan index terkecil (pembatas pop)
}