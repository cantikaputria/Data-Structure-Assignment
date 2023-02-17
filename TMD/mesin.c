/* 
    Saya Cantika Putri Arbiliansyah dengan nim [2103727] mengerjakan 
    Tugas Masa Depan Struktur Data untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

//LIBRARY
#include "header.h"

//VARIABEL GLOBAl                                               
int jumlahKom2;                                                 //variabel penampung jumlah komponen mie (integer)
int maxPanjang[100];                                            //variabel penampung panjang string

//PROSEDUR UNTUK MEMBUAT TREE
void makeTree(mie c, tree *T)
{
    simpul *node;                                               //membuat pointer node
    node = (simpul *) malloc (sizeof(simpul));                  //alokasi memori
    node->kontainer = c;                                        //mengisi data
    node->kontainer.nilaiJual2 = atoi(c.nilaiJual);             //mengubah tipe nilai jual string menjadi integer
    node->kontainer.level = 0;                                  //inisalisasi level
    node->sibling = NULL;                                       //membuat pointer sibling
    node->child = NULL;                                         //membuat pointer child
    (*T).root = node;                                           //root diisi node
}

//PROSEDUR UNTUK MENAMBAHKAN CHILD PADA TREE
void addChild(mie c, simpul *root)
{ 
    if(root != NULL)                                                            //jika tree tidak kosong berarti dapat ditambahkan child
    {
        //MEMBUAT SIMPUL CHILD
        simpul *baru;                                                           //membuat pointer baru
        baru = (simpul*)malloc(sizeof(simpul));                                 //alokasi memori
        baru->kontainer = c;                                                    //mengisi data
        baru->kontainer.nilaiJual2 = atoi(c.nilaiJual);                         //mengubah string menjadi integer
        baru->kontainer.level = root->kontainer.level + 1;                      //perhitungan perubahan level
        
        for(int i = 0; i < jumlahKom2; i++)                                     //perulangan sebanyak jumlah komponen
        {
           strcpy(baru->kontainer.komponen[i], c.komponen[i]);                  //mengisi data komponen
        }
        baru->child = NULL;                                                     //pointer baru pada child menjadi null

        //JIKA ROOT BELUM MEMPUNYAI CHILD
        if(root->child == NULL)
        {
            baru->sibling = NULL;                                              //pointer baru pada sibling menjadi null                 
            root->child = baru;                                                //pointer root yg menunjuk pada child sekarang menunjuk baru
        }
        //JIKA ROOT MEMPUNYAI CHILD
        else
        {
            //JIKA CHILD TIDAK MEMILIKI SIBLING
            if(root->child->sibling == NULL)
            {
                baru->sibling = root->child;                                   //simpul baru menjadi anak kedua
                root->child->sibling = baru;                                   //root child menunjuk pointer baru
            }
            //JIKA CHILD MEMILIKI SIBLING
            else
            {
                simpul *last = root->child;                                    //membuat pointer last yang berada di root child untuk mencari anak terakhir
                
                while(last->sibling != root->child)                            //mencari simpul anak terakhir karena akan dikaitkan dengan simpul baru sebagai simpul anak terakhir yanbaru, simpul anak terakhir adalah yang memiliki sibling simpul anak pertama 
                {
                    last = last->sibling;                                      //selama belum sampai di anak terakhir, penunjuk last akan berjalan ke simpul anak berikutnya
                }
                baru->sibling = root->child;                                   //baru pada sibling menunjuk root child
                last->sibling = baru;                                          //last pada sibling pindah menunjuk ke baru
            }
        }
    }
}

//PROSEDUR UNTUK MENGHAPUS CHILD PADA TREE
void delAll(simpul *root)
{
    if(root != NULL)                                                //jika tree tidak kosong
    {
        //JIKA ROOT MEMPUNYAI ANAK
        if(root->child != NULL)
        {
            //JIKA MEMILIKI SATU ANAK DAN TIDAK PUNYA SIBLING
            if(root->child->sibling == NULL)
            {
                delAll(root->child);                                           //rekursif dengan mulai hapus dari anak dari rootnya saat ini                                           
            }
            //JIKA MEMILIKI BANYAK ANAK / MEMPUNYAI SIBLING
            else
            {
                simpul *bantu;                                                 //membuat pointer baru
                simpul *proses;                                                //membuat pointer proses
                bantu = root->child;                                           //pointer baru menujuk pada anak dari root
               
                while(bantu->sibling != root->child)                           //selama saudaranya bukan anak langsung dari root
                {
                    proses = bantu;                                            //pointer proses menunjuk yg sama dengan pointer bantu
                    bantu = bantu->sibling;                                    //pointer bantu maju menunjuk ke siblingnya
                    delAll(proses);                                           //rekursif dengan menghapus dari anak yang ditunjuk proses
                }
            }
            free(root);
            root->child= NULL;                                                       //menghapus root saat ini
        }
        //JIKA ROOT TIDAK MEMPUNYAI ANAK
        else
        {
            free(root);                                                       //menghapus root saat ini
        }
    }
}

//PROSEDUR UNTUK MENGHAPUS KESELURUHAN TREE
void delChild(mie c, simpul *root)
{
    if(root != NULL)                                                            //jika pohon tidak kosong
    {
        simpul *hapus = root->child;                                            //buat pointer penanda untuk menghapus di anak dari root
        if(hapus != NULL)                                                       //jika anak dari rootnya ada
        {
            //JIKA HANYA MEMPUNYAI SATU ANAK
            if(hapus->sibling == NULL)
            {
                if(strcmp(root->child->kontainer.nama, c.nama) == 0)            //jika nama yang ditunjuk sesuai dengan yang akan dihapus
                {
                    delAll(root->child);                                       //hapus anaknya
                    root->child = NULL;                                         //nullkan root childnya
                }
            } 
            //JIKA MEMILIKI LEBIH DARI SATU ANAK
            else
            {
                simpul *prev = NULL;                                            //membuat pointer prev
                int ketemu = 0;                                                 //inisialisasi pointer penanda

                while((hapus->sibling != root->child) && (ketemu == 0))           //selama sibling dari pointer yg ditunjuk hapus bukan rootchild, dan belum ketemu
                {
                    if(strcmp(hapus->kontainer.nama, c.nama) == 0)              //jika sesuai yang dicari
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
                if((ketemu == 0)&&(strcmp(hapus->kontainer.nama, c.nama) == 0)) //jika sesuai dengan yang dicari
                {
                    ketemu = 1;                                                 //maka tandai 1
                }

                if(ketemu == 1)                                                 //jika sudah ketemu
                {
                    simpul *last = root->child;                                 //buat pointer last yanag menunjuk pada anak dari root
                    //mencari anak terakhir untuk membantu proses atau pemeriksaan jika yangdihapus nantinya anak terakhir
                    //selama saudaranya last bukan root child
                    while(last->sibling != root->child)
                    {
                        last = last->sibling;                                  //maka pointer last maju ke siblingnya
                    }

                    //JIKA YANG DIHAPUS ANAK PERTAMA
                    if(prev == NULL)
                    {
                        //JIKA HANYA ADA DUA ANAK
                        if((hapus->sibling == last) && (last->sibling == root->child))
                        {
                            root->child = last;                                 //root child menjadi last
                            last->sibling = NULL;                               //last sibling menjadi null
                        }
                        //JIKA MEMILIKI SIMPUL ANAKA LEBIH DARI DUA
                        else
                        {
                            root->child = hapus->sibling;                       //root child menjadi hapus sibling
                            last->sibling = root->child;                        //last sibling menjadi root child
                        }
                    }

                    //JIKA YANG DIHAPUS BUKAN ANAK PERTAMA
                    else
                    {
                        //JIKA HANYA ADA DUA ANAK DAN YANG DIHAPUS ANAK KEDUA
                        if((prev == root->child) && (hapus->sibling == root->child))
                        {
                            root->child->sibling = NULL;                          //root child sibling menjadi null
                        }
                        //JIKA YANG DIHAPUS ANAK PERTAMA DAN MEMILIKI LEBIH DARI DUA SIMPUL
                        else
                        {
                            prev->sibling = hapus->sibling;                    //prev sibling menjadi hapus sibling
                            hapus->sibling = NULL;                             //hapus sibling menjadi null
                        }
                    }
                    delAll(hapus);                                              //hapus simpulnya
                }
            }
        }
    }
}

//FUNGSI UNTUK MENCARI SIMPUL TREE
simpul* findSimpul(char cari[], simpul *root)
{
    simpul *hasil = NULL;                                                         //membuat pointer hasill
    if(root != NULL)                                                              //selama bukan pohon kosong
    {
        if(strcmp(root->kontainer.nama, cari) == 0)                              //jika yang dicari adalah root dan sesuai
        {
            hasil = root;                                                         //hasil = tandai rootnya
        }
        else                                                                      //jika tidak sesuai
        {
            simpul *bantu = root->child;                                          //buat pointer bantu yang menunjuk pada anak root
            if(bantu != NULL)                                                     //jika bantu bukan null
            {
                //JIKA MEMILIKI SATU SIMPUL ANAK
                if(bantu->sibling == NULL)
                {
                    if(strcmp(bantu->kontainer.nama, cari) == 0)                  //jika yang ditunjuk sesuai dengan yang dicari
                    {
                        hasil = bantu;                                            //hasil adalah yang ditunjuk pointer bantu
                    }
                    else                                                          //jika tidak sesuai
                    {
                        hasil = findSimpul(cari, bantu);                          //cari lagi dengan root saat ini yang ditunjuk pointer bantu
                    }
                }

                //JIKA MEMILIKI BANYAK SIMPUL ANAK
                else
                {
                    int ketemu = 0;                                               //inisialisasi penanda
                    while((bantu->sibling != root->child) &&(ketemu == 0))        //selama siblingnya bukan root child dan belum ketemu
                    {
                        if(strcmp(bantu->kontainer.nama, cari) == 0)              //jika yang dicari sudah sesuai
                        {
                            hasil = bantu;                                        //pointer hasil menunju ke bantu
                            ketemu = 1;                                           //tandai ketemu menjadi 1
                        }
                        else                                                      //jika tidak sesuai
                        {
                            hasil = findSimpul(cari, bantu);                     //cari lagi dengan root saat ini yang ditunjuk pointer bantu
                            if(hasil != NULL)                                    //jika hasilnya bukan null
                            {
                                ketemu = 1;                                      //maka ketemu tandai dengan 1
                            }
                            bantu = bantu->sibling;                              //maju terus ke siblingnya
                        }
                    }

                    //memproses simpul anak terakhir karena belum terproses dalam pengulangan
                    if(ketemu == 0)                                              //jika masih belum ketemu
                    {
                        if(strcmp(bantu->kontainer.nama, cari) == 0)            //jika yang dicari sudah sesuai
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

//PROSEDUR UNTUK MENAMPILKAN TREE SECARA PRE ORDER
void printTreePreOrder(simpul *root, int *panjangStr, int temp[])
{ 
    int i;                                                                          //inisialisasi
    
    if(root != NULL)                                                                //jika bukan pohon yang kosong
    {  
        for (int i = 0; i < *panjangStr; i++)                                       //perulangan sebanyak panjang string
        {
            printf(" ");                                                            //tampilkan spasi
        }
        
        printf("|%s - %s\n", root->kontainer.nama, root->kontainer.nilaiJual);      //tampilkan nama mie dan nilai jual ke layar
       
        for (int i = 0; i < root->kontainer.simpan; i++)                            //perulangan sejumlah komponen mie
        {
            for (int j = 0; j < *panjangStr; j++)                                   //perulangan sebanyak panjang string
            {
                printf(" ");                                                        //tampilkan spasi
            }
            printf(" - %s\n", root->kontainer.komponen[i]);                         //tampilkan isi komponen mie
        }

        simpul *bantu = root->child;                                                //buat pointer bantu yang menunjuk pada anak root
        if(bantu != NULL)                                                           //jika bantu bukan null
        {
            //JIKA HANYA MEMILIKI SATU SIMPUL ANAK
            if(bantu->sibling == NULL)
            {
                printf("\n");                                                       //tampilkan new line
                *panjangStr += temp[root->kontainer.level];                         //string terpanjang saat ini adalah string terpanjang ditambah temp indeks ke level
                printTreePreOrder(bantu, panjangStr, temp);                         //rekursif dan panggil kembali prosedur print dengan root yg ditunjuk pointer bantu
                *panjangStr -= temp[root->kontainer.level];                         //mereset kembali nilai panjang string
            }

            //JIKA MEMILIKI BANYAK SIMPUL ANAK
            else
            {
                while(bantu->sibling != root->child)                                //selama sibling anak yang ditunjuk pointer bantu bukan merupakan anak yg berhubungan langsung dengan root
                {
                    printf("\n");                                                   //tampilkan new line ke layar
                    *panjangStr += temp[root->kontainer.level];                     //string terpanjang saat ini adalah string terpanjang ditambah temp indeks ke level
                    printTreePreOrder(bantu, panjangStr, temp);                     //rekursif dan panggil kembali prosedur print dengan root yg ditunjuk pointer bantu
                    *panjangStr -= temp[root->kontainer.level];                     //mereset kembali nilai panjang string

                    bantu = bantu->sibling;                                         //maju ke siblingnya
                }

                    printf("\n");                                                   //tampilkan new line ke layar
                    *panjangStr += temp[root->kontainer.level];                     //string terpanjang saat ini adalah string terpanjang ditambah temp indeks ke level
                    printTreePreOrder(bantu, panjangStr, temp);                     //rekursif dan panggil kembali prosedur print dengan root yg ditunjuk pointer bantu
                    *panjangStr -= temp[root->kontainer.level];                     //mereset kembali nilai panjang string
            }
        }
    }
}

//PROSEDUR UNTUK MEMISAHKAN INPUTAN
void pisah(mie c, char str[], char temp1[], char temp2[], char temp3[], char temp4[], int *jumlah)
{
    int tanda = 0;
    int j = 0, k = 0, l = 0, m = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        if(str[i] == '#')
        {
            tanda++;
        }
        else if(tanda == 0)
        {
            temp1[j] = str[i];
            j++;
        }
        else if(tanda == 1)
        {
            temp2[k] = str[i];
            k++;
        }
        else if(tanda == 2)
        {
            temp3[l] = str[i];
            l++;
        }
        else if(tanda == 3)
        {
            temp4[m] = str[i];
            m++;
        }
    }
    
    temp1[j] = '\0';
    temp2[k] = '\0';       
    temp3[l] = '\0';
    temp4[m] = '\0';
    *jumlah = temp4[0] - 48;
}

//PROSEDUR UNTUK MENCARI STRING TERPANJANG
void cariMaxLen(simpul *root, int level, int temp[])
{
    if (root != NULL)
    {
       if(level == root->kontainer.level)
       {
            if(temp[root->kontainer.level] < strlen(root->kontainer.nama) + 4 + strlen(root->kontainer.nilaiJual))
            {
                temp[root->kontainer.level] = strlen(root->kontainer.nama) + 4 + strlen(root->kontainer.nilaiJual);
            }

            for (int i = 0; i < root->kontainer.simpan; i++)
            {
                if(temp[root->kontainer.level] < strlen(root->kontainer.komponen[i]) + 4)
                {
                    temp[root->kontainer.level] = strlen(root->kontainer.komponen[i]) + 4;
                }
            }
       }

        simpul *bantu = root->child;
        if(bantu != NULL)
        {
            level++;
            if(bantu->sibling == NULL)
            {
                cariMaxLen(bantu, level, temp);
            }
            else
            {
                while(bantu->sibling != root->child)
                {
                   cariMaxLen(bantu, level, temp);
                   bantu = bantu->sibling;
                }
            }
            cariMaxLen(bantu, level, temp);
        }
    }
} 