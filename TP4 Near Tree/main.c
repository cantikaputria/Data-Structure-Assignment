/* 
    Saya Cantika Putri Arbiliansyah dengan nama [2103727] mengerjakan 
    Tugas Praktikum 4 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

//LIBRARY
#include "header.h"

int main() 
{
    //DEKLARASI VARIABLE
    tree T;                                                     //variabel untuk tree                     
    char query[50];                                             //variabel penampung inputan query dari user
    char str1[50], str2[50];                                    //variabel penampung inputan penanda child dan parentnya
    char temp[50];                                              //variabel penampung sementara untuk pemisah titik koma      
    int tanda = 0, i;                                           //variabel penanda jumlah output

    //PROSES
    do                                                          //lakukan
    {
        scanf("%s", &query);                                    //meminta inputan query dari user
        if(strcmp(query, "DONE;") != 0)                         //jika querynya bukan done, maka lakukan
        {
            if(strcmp(query, "MAKETREE") == 0)                  //jika querynya make tree, maka
            {
                scanf("%s", &str1);                             //meminta inputan child dari user
                i = 0;                                          //inisialisasi
                do                      
                {
                    temp[i] = str1[i];                          //masukkan huruf satu per satu ke variabel temp
                    i++;                                        //iterasi
                } while (str1[i] != ';');                       //berhenti ketika bertemu dengan tutup koma
                temp[i] = '\0';                                 //tutup string
                makeTree(temp, &T);                             //panggil variabel untuk membuat tree
            }
            else if(strcmp(query, "CHILD") == 0)                //jika querynya child
            {
                scanf("%s %s", &str1, &str2);                   //meminta inputan child dan parent dari user
                i = 0;                                          //inisialisasi
                do
                {
                    temp[i] = str2[i];                          //masukkan huruf parent satu per satu ke variabel temp
                    i++;                                        //iterasi
                } while (str2[i] != ';');                       //berhenti ketika bertemu dengan titik koma
                temp[i] = '\0';                                 //tutup string

                simpul *parent = findSimpul(temp, T.root);      //cari parent dengan memanggil fungsi find simpul
                addChild(str1, parent);                         //panggil prosedur untuk menambahkan child
            }
            else if(strcmp(query, "PREORDER;") == 0)            //jika querynya preorder
            {
                tanda++;                                        //tanda akan iterasi
                printf("Output %d:\n", tanda);                  //tampilkan output dengan diikuti angka sebanyak tanda
                printf("=========\n");                          //tampilkan batas ke layar
                printTreePreOrder(T.root, 0);                   //panggil prosedur untuk menampilkan tree secara preorder
            }
            else if(strcmp(query, "DELLCHILD") == 0)            //jika querynya delchild
            {
                scanf("%s %s", &str1, &str2);                   //meminta inputan child dan parent yg akan dihapus
                i = 0;                                          //inisialisasi
                do
                {
                    temp[i] = str2[i];                          //masukkan huruf parent satu per satu ke variabel temp
                    i++;                                        //iterasi
                } while (str2[i] != ';');                       //berhenti ketika bertemu dengan titik koma
                temp[i] = '\0';                                 //tutup string

                simpul *parent = findSimpul(temp, T.root);      //cari parent dengan memanggil fungsi find simpul
                delChild(str1, parent);                         //panggil prosedur untuk menghapus child
            }
        }
    } while (strcmp(query, "DONE;") != 0);                      //berhenti ketika querynya DONE     

    printf("=========\n");                                      //tampilkan batas ke layar
    
    return 0;                                                   //kembali ke 0
}