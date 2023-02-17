/* 
    Saya Cantika Putri Arbiliansyah dengan NIM [2103727] mengerjakan 
    UAS No 1 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

//LIBRARY
#include "header.h"

//PROSEDUR UNTUK MEMBUAT TEE
void makeTree(input c, tree *T)
{
    simpul *baru;                                           //pointer penanda "baru"
    baru = (simpul *) malloc (sizeof(simpul));              //alokasi memori
    baru->kontainer = c;                                    //pointer baru kontainernya adalah c
    baru->right = NULL;                                     //pointer baru sebelah kanan nya null
    baru->left = NULL;                                      //begitu pula dengan yang sebelah kiri
    (*T).root = baru;                                       //tree diisi dengan baru
    baru = NULL;                                            //baru kembali menjadi null
}

//PROSEDUR UNTUK MENAMBAH CHILD DI SEBELAH KANAN
void addRight(input c, simpul *root)
{
    if(root->right == NULL)                                 //jika sebelah kanan tree kosong
    {
        simpul *baru;                                       //buat pointer baru
        baru = (simpul *) malloc (sizeof (simpul));         //alokasi memorinya
        baru->kontainer = c;                      // memasukkan isi simpul
        baru->right = NULL;                                 //pointer baru sebelah kanan nya null
        baru->left = NULL;                                  //begitu pula dengan yang sebelah kiri
        root->right = baru;                                 //sebelah kanan tree diisi dengan simpul baru
    }
    else                                                    //jika sebelah kanan tree tidak kosong
    {
        printf("sub pohon kanan telah terisi \n");          //tampilkan teks ke layar
    }
}

//PROSEDUR UNTUK MENAMBAH CHILD DI SEBELAH KIRI
void addLeft(input c, simpul *root)
{
    if(root->left == NULL)                                  //jika sebelah kiri tree kosong
    {
        simpul *baru;                                       //buat pointer baru
        baru = (simpul *) malloc (sizeof (simpul));         //alokasi memorinya
        baru->kontainer = c;                       // memasukkan isi simpul
        baru->right = NULL;                                 //pointer baru sebelah kanan nya null
        baru->left = NULL;                                  //begitu pula dengan yang sebelah kiri
        root->left = baru;                                  //sebelah kiri tree diisi dnegan simpul baru
    }
    else                                                    //jika sebelah kiri tree tidak kosong
    {
        printf("sub pohon kanan telah terisi \n");          //tampilkan teks ke layar
    }
}

//PROSEDUR UNTUK MENGHAPUS SELURUH SIMPUL
void delAll(simpul *root)
{
    if(root != NULL)                            //jika tree telah terisi
    {
        delAll(root->left);                     //rekursif dengan menghapus simpul sebelah kiri bawah terlebih dahulu
        delAll(root->right);                    //setelah selesai, rekursif dengan menghapus simpul kanan bawah
        free(root);                             //membebaskan memori
    }
}

//PROSEDUR UNTUK MENGHAPUS SIMPUL DI SEBELAH KANAN
void delRight(simpul *root)
{
    if(root != NULL)                                //jika tree telah terisi
    {
        if(root->right != NULL)                     //jika sebelah kanan simopul mempunyai child
        {
            delAll(root->right);                    //hapus simpul dan childnya
            root->right = NULL;                     //nullkan
        }
    }
}

//PROSEDUR UNTUK MENGHAPUS SIMPUL DI SEBELAH KIRI
void delLeft(simpul *root)
{
    if(root != NULL)                                //jika tree telah terisi
    {
        if(root->left != NULL)                      //jika sebelah kiri simpul mempunyai child
        {
            delAll(root->left);                     //hapus simpul dan childnya
            root->left = NULL;                      //nullkan
        }   
    }
}

//PROSEDUR UNTUK MENAMPILKAN TREE SECARA IN ORDER
void printTreeInOrder(simpul *root)
{
    if(root != NULL)                                    //jika tree tidak kosong
    {
        printTreeInOrder(root->left);                   //rekursif dan menampilkan dari sebelah kiri
        // if(first != 1)
        // {
        //     printf(" - ");    
        // }
        // first = 0;
        printf("%d %d", root->kontainer.ortu, root->kontainer.hasil);                   //tampilkan output node saat ini              
        printTreeInOrder(root->right);                  //jika telah selesai rekursif, menampilkan sebelah kanan
    }
}

// void addData(input c, int hasil, simpul *root)
// {
//     // printf("test");
//     if ((c.ortu / c.pembagi ) % 2 == 0)
//     {
//         printf("test");
//         c.hasil = c.ortu / c.pembagi;
//         addRight(hasil, root);
//         addData(c, hasil, root->right);
//     }
//     else if((c.ortu / c.pembagi ) % 2 != 0)
//     {
//         c.hasil = c.ortu / c.pembagi;
//         addLeft(hasil, root);
//         addData(c, hasil, root->left);
//     }
// }