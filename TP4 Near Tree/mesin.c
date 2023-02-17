/* 
    Saya Cantika Putri Arbiliansyah dengan nama [2103727] mengerjakan 
    Tugas Praktikum 4 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

//LIBRARY
#include "header.h"

//PROSEDUR UNTUK MEMBUAT TREE
void makeTree(char nama[], tree *T)
{
    simpul *node;                                                   //membuat pointer node
    node = (simpul *) malloc (sizeof(simpul));                      //alokasi memori
    strcpy(node->nama, nama);                                       //mengisi data
    node->sibling = NULL;                                           //membuat pointer sibling
    node->child = NULL;                                             //membuat pointer child
    (*T).root = node;                                               //root diisi node
}

//PROSEDUR MENAMBAHKAN CHILD
void addChild(char nama[], simpul *root)
{ 
    if(root != NULL)                                                                //jika tree tidak kosong
    {
        //membuat simpul anak
        simpul *baru;                                                               //membuat pointer baru
        baru = (simpul*)malloc(sizeof(simpul));                                     //alokasi memori
        strcpy(baru->nama, nama);                                                   //mengisi data
        baru->child = NULL;                                                         //baru child menjadi null

        //jika root belum mempunyai child
        if(root->child == NULL)
        {
            baru->sibling = NULL;                                                   //baru sibling menjadi null
            root->child = baru;                                                     //root child menjadi baru 
        }
        //jika root mempunyau child
        else        
        {
            //jika child tidak memiliki sibling
            if(root->child->sibling == NULL)                                        
            {
                baru->sibling = root->child;                                        //simpul baru menjadi anak kedua
                root->child->sibling = baru;                                        //root child menjadi baru
            }
            //jika child memiliki sibling
            else
            {
                simpul *last = root->child;                                        //membuat pointer last yang berada di root child untuk mencari anak terakhir

                //mencari simpul anak terakhir karena akan dikaitkan dengan simpul baru sebagai simpul anak terakhir yanbaru, simpul anak terakhir adalah yang memiliki sibling simpul anak pertama 
                while(last->sibling != root->child)                                //selama belum sampai di anak terakhir, penunjuk last akan berjalan ke simpul anak berikutnya
                {
                    last = last->sibling;                                          //penunjuk last maju ke siblingnya
                }
                baru->sibling = root->child;                                       //baru siblingnya menjadi root child
                last->sibling = baru;                                              //last sibling menjadi baru
            }
        }
    }
}

//PROSEDUR MENGHAPUS ELEMEN
void delAll(simpul *root)
{
    if(root != NULL)                                                            //jika tree tidak kosong
    {
        //jika root mempunyai anak
        if(root->child != NULL)
        {
            //jika hanya memiliki satu simpul anak / tidak mempunyai sibling
            if(root->child->sibling == NULL)
            {
                delAll(root->child);                                           //rekursif dengan mulai hapus dari anak dari rootnya saat ini
                free(root);                                                    //menghapus root saat ini
            }
            //jika memiliki banyak anak / mempunyai sibling
            else
            {
                simpul *bantu;                                                 //membuat pointer bantu
                simpul *proses;                                                //membuat pointer pross
                bantu = root->child;                                           //pointer baru menujuk pada anak dari root
                while(bantu->sibling != root->child)                           //selama saudaranya bukan anak langsung dari root
                {
                    proses = bantu;                                            //pointer proses menunjuk yg sama dengan pointer bantu
                    bantu = bantu->sibling;                                    //pointer bantu maju menunjuk ke siblingnya
                    delAll(proses);                                            //rekursif dengan menghapus dari anak yang ditunjuk proses
                }
            }
            free(root);                                                        //menghapus root saat ini
        }
        //jika root tidak mempuyai anak
        else
        {
            free(root);                                                        //menghapus root saat ini                       
        }
    }
}

//PROSEDUR MENGHAPUS CHILD
void delChild(char nama[], simpul *root)
{
    if(root != NULL)                                                            //jika pohon tidak kosong
    {
        simpul *hapus = root->child;                                            //buat pointer penanda untuk menghapus di anak dari root
        if(hapus != NULL)                                                       //jika anak dari rootnya ada
        {
            //jika hanya mempuyai satu anak
            if(hapus->sibling == NULL)
            {
                if(strcmp(root->child->nama, nama) == 0)                        //jika nama yang ditunjuk sesuai dengan yang akan dihaoys
                {
                    delAll(root->child);                                        //hapus anaknya
                    root->child = NULL;                                         //nullkan root childnya
                }
                else                                                            //jika tidak sesuai
                {
                    printf("tidak ada simpul anak dengan kontainer karakter masukan\n");    //tanpilkan tek ske layar
                }
            } 
            //jika memiliki lebih dari satu anak
            else
            {
                simpul *prev = NULL;                                            //membuat pointer prev
                int ketemu = 0;                                                 //inisialisasi pointer penanda

                //selama sibling dari pointer yg ditunjuk hapus bukan rootchild, dan belum ketemy
                while((hapus->sibling != root->child)&&(ketemu == 0))
                {
                    if(strcmp(hapus->nama, nama) == 0)                          //jika sesuai dengan yang dicari
                    {
                        ketemu = 1;                                             //maka tandai 1
                    }
                    else                                                        //jika tidak sesuai
                    {
                        prev = hapus;                                           //pointer prev menunjuk pada hapus
                        hapus = hapus->sibling;                                 //pointer hapus maju ke siblingnya
                    }
                }

                //memproses simpul anak terakhir karena belum terproses dalam pengulangan
                if((ketemu == 0)&&(strcmp(hapus->nama, nama) == 0))            //jika sesuai dengan yang dicari
                {
                    ketemu = 1;                                                //maka tandai 1
                }
                
                if(ketemu == 1)                                                //jika sudah ketemu
                {
                    simpul *last = root->child;                                //buat pointer last yanag menunjuk pada anak dari root
                    //mencari anak terakhir untuk membantu proses atau pemeriksaan jika yangdihapus nantinya anak terakhir
                    //selama saudaranya last bukan root child
                    while(last->sibling != root->child)
                    {
                        last = last->sibling;                                  //maka pointer last maju ke siblingnya
                    }

                    //jika simpul yang dihapus anak pertama
                    if(prev == NULL)
                    {
                        //jika hanya ada dua anak
                        if((hapus->sibling == last)&&(last->sibling == root->child))
                        {
                            root->child = last;                                 //root child menjadi last
                            last->sibling = NULL;                               //last sibling menjadi null
                        }
                        //jika memiliki simpul anak lebih dari dua
                        else
                        {
                            root->child = hapus->sibling;                       //root child menjadi hapus sibling
                            last->sibling = root->child;                        //last sibling menjadi root child
                        }
                    }
                    //jika simpul yang dihapus bukan anak pertama
                    else
                    {
                        //jika hanya ada dua anak dan yang dihapus adalah anak kedua
                        if((prev == root->child) &&(last == hapus))
                        {
                            root->child->sibling = NULL;                       //root child sibling menjadi null
                        }
                        else
                        {
                            //jika yang dihapus simpul anak pertama dan simpul root memiliki simpul anak lebih dari dua simpul
                            prev->sibling = hapus->sibling;                    //prev sibling menjadi hapus sibling
                            hapus->sibling = NULL;                             //hapus sibling menjadi null
                        }
                    }
                    delAll(hapus);                                             //hapus simpulnya
                }
                //jika bukan keduanya
                else
                {
                    printf("tidak ada simpul anak dengan kontainer karakter masukan\n");    //tampilkan teks ke layar
                }
            }
        }
    }
}

//FUNGSI UNTUK MENCARI SIMPUL
simpul* findSimpul(char cari[], simpul *root)
{
    simpul *hasil = NULL;                                                         //membuat pointer hasill
    if(root != NULL)                                                              //selama bukan pohon kosong
    {
        if(strcmp(root->nama, cari) == 0)                                         //jika yang dicari adalah root dan sesuai
        {
            hasil = root;                                                         //hasil = tandai rootnya
        }
        else                                                                      //jika tidak sesuai
        {
            simpul *bantu = root->child;                                          //buat pointer bantu yang menunjuk pada anak root
            if(bantu != NULL)                                                     //jika bantu bukan null
            {
                //jika memiliki satu simpul anak
                if(bantu->sibling == NULL)
                {
                    if(strcmp(bantu->nama, cari) == 0)                            //jika yang ditunjuk sesuai dengan yang dicari
                    {
                        hasil = bantu;                                            //hasil adalah yang ditunjuk pointer bantu
                    }
                    else                                                          //jika tidak sesuai
                    {
                        hasil = findSimpul(cari, bantu);                          //cari lagi dengan root saat ini yang ditunjuk pointer bantu
                    }
                }
                //jika memiliki banyak simpul anak
                else
                {
                    int ketemu = 0;                                              //inisialisasi penanda
                    //selama siblingnya bukan root child dan belum ketemu
                    while((bantu->sibling != root->child) &&(ketemu == 0))
                    {
                        if(strcmp(bantu->nama, cari) == 0)                      //jika yang dicari sudah sesuai
                        {
                            hasil = bantu;                                      //pointer hasil menunju ke bantu
                            ketemu = 1;                                         //tandai ketemu menjadi 1
                        }
                        else                                                    //jika tidak sesuai
                        {
                            hasil = findSimpul(cari, bantu);                    //cari lagi dengan root saat ini yang ditunjuk pointer bantu
                            if(hasil != NULL)                                   //jika hasilnya bukan null
                            {
                                ketemu = 1;                                     //maka ketemu tandai dengan 1
                            }
                            bantu = bantu->sibling;                             //maju terus ke siblingnya
                        }
                    }
                    //memproses simpul anak terakhir karena belum terproses dalam pengulangan
                    //jika masih belum ketemu
                    if(ketemu == 0)
                    {
                        if(strcmp(bantu->nama, cari) == 0)                      //jika yang dicari sudah sesuai
                        {
                            hasil = bantu;                                      //hasilnya adalah yang ditunjuk pointer bantu
                        }
                        else                                                    //jika belum sesuai
                        {
                            hasil = findSimpul(cari, bantu);                    //cari terus hasilnya
                        }
                    }
                }
            }
        }
    }
    return hasil;                                                               //mengembalikan nilai hasil
}

//PROSEDUR MENAMPILKAN TREE SECARA PROSEDUR
void printTreePreOrder(simpul *root, int level)
{ 
    //jika bukan pohon yang kosong
    if(root != NULL)
    {   
        for(int i = 0; i < level; i++)                                      //selama i lebih kecil dari level
        {
            printf("->");                                                   //tampilkan panah
        }

        printf("%s\n", root->nama);                                         //tampilkan nama keluarga ke layar

        simpul *bantu = root->child;                                        //buat simpul bantu yang menunjuk pada anak dari root
        if(bantu != NULL)                                                   //selama anak dari rootnya ada
        {
            level++;                                                        //iterasi level terus bertambah
            //jika hanya memiliki satu simpul anak / tidak memiliki sodara
            if(bantu->sibling == NULL)                                      
            {
                printTreePreOrder(bantu, level);                            //rekursif dan panggil kembali prosedur print dengan root yg ditunjuk pointer bantu
            }
            //jika memiliki banyak anak / saudara
            else
            {   
                while(bantu->sibling != root->child)                        //selama sibling anak yang ditunjuk pointer bantu bukan merupakan anak yg berhubungan langsung dengan root
                {
                    printTreePreOrder(bantu, level);                        //rekursif dan panggil kembali prosedur print dengan root yg ditunjuk pointer bantu
                    bantu = bantu->sibling;                                 //pointer bantu maju ke siblingnya
                }
                printTreePreOrder(bantu, level);                            //memproses anak terakhir karena belum terproses dalam perlulangan, diproses secara rekursif dan panggil kembali prosedur print dengan root yg ditunjuk pointer bantu
            }
        }
    }
}