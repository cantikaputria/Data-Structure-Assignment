/* 
    Saya Cantika Putri Arbiliansyah dengan harga [2103727] mengerjakan 
    Tugas Praktikum 3 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

//LIBRARY
#include "header.h"

//PROSEDUR UNTUK MEMBUAT STACK KOSONG
void createEmpty(stack *S)
{
 (*S).top = NULL;                                   //karena kosong top di set null
}

//FUNGSI UNTUK MENGECEK STACK KOSONG
int isEmpty(stack S)
{
    int hasil = 0;                                  //inisialisasi
    if(S.top == NULL)                               //jika elemen teratas null maka hasil = 1
    {                                               //jika nilainya 0, maka stack tidak kosong, jika bernilai 1, maka stack kosong
        hasil = 1;                                  
    }
    return hasil;                                   //mengembalikan nilai hasil
}

//FUNGSI UNTUK MENGHITUNG ELEMEN STACK
int countElement(stack S)
{
    int hasil = 0;                              //inisialisasi
    if(S.top != NULL)
    {
        elemen* bantu;                          //membuat pointer bantu sebagai penunjuk
        bantu = S.top;                          //pointer bantu menunjuk pada elemen top
        while(bantu != NULL)                    //ketika bantu bukan null
        {
            hasil= hasil + 1;                   //hasil sama dengan hasil saat ini ditambah hasil setelahnya
            bantu = bantu->next;                //maju hingga elemen terakhir dan bertemu null
        }
    }
    return hasil;                               //mengembalikan nilai hasil
}

//PROSEDUR UNTUK MEMASUKKAN DATA KE ELEMEN STACK
void push(int harga, char nama[], int kalori, stack *S )
{
    elemen* baru;                                               //membuat pointer baru sebagai penunjuk
    baru = (elemen *) malloc (sizeof (elemen));                 //meminta memori sebesar elemen
    baru->kontainer.harga = harga;                              //memasukkan data harga makanan
    strcpy(baru->kontainer.nama, nama);                         //memasukkan data nama makanan
    baru->kontainer.kalori = kalori;                            //memasukkan data kalori makanan

    if((*S).top == NULL)                                        //jika stacknya kosong
    {
        baru->next = NULL;                                      //elemen selanjutnya null
    }
    else                                                        //jika tidak kosong
    {
        baru->next = (*S).top;                                  //elemen kedua adalah stack sebelumnya
    }
    (*S).top = baru;                                            //top pindah ke baru
    baru = NULL;                                                //nilai baru menjadi null
}

//PROSEDUR UNTUK MENGHAPUS ELEMEN DARI STACK
void pop(stack *S)
{
    if((*S).top != NULL)                                //jika stacknya tidak kosong
    {
        elemen *hapus = (*S).top;                       //membuat pointer hapus yg menunjuk top
        if(countElement(*S) == 1)                       //jika stack hanya 1 eleme
        {
            (*S).top = NULL;                            //isi stack kosong
        }
        else                                            //jika elemen lebih dari satu
        {
            (*S).top = (*S).top->next;                  //pindahkan top elemen ke stack kedua
        }
        hapus->next = NULL;                             //nullkan hapus next
        free(hapus);                                    //hapus elemen
    }
    else                                                //jika stack kosong
    {
        printf("stack kosong");                         //tampilkan output stack kosong
    }
}

//PROSEDUR UNTUK MENAMPILKAN STACK MAKANAN PEDAS
void printStack1(stack S)
{
    if(S.top != NULL)                                           //jika stack tidak kosong
    {
        printf("Wishlist Makanan Pedas:\n");                    //tampilkan teks ke layar
        printf("===================\n");                        //tampilkan pembatas
        
        elemen* bantu = S.top;                                  //buat elemen pembantu yang menunjuk top
        int i = 1;                                              //inisialisasi

        while(bantu != NULL)                                    //selama bantu bukan null
        {
            printf("%d. %s\n", i, bantu->kontainer.nama);       //print data nama makanan dan nomornya
            /* iterasi */
            bantu = bantu->next;                                //maju hingga pointer terakhir
            i = i + 1;                                          //iterasi jumlah makanan
        }
    }
    else                                                        //jika tidak maka stack kosong
    {
        /* proses jika stack kosong */      
        printf("Wishlist Makanan Pedas:\n");                    //tampilkan output ke layar
        printf("===================\n");
        printf("LEMAH!\n");
    }
}

//PROSEDUR UNTUK MENAMPILKAN STACK MAKANAN MANIS
void printStack2(stack S)
{
    if(S.top != NULL)                                           //jika stack tidak kosong
    {
        printf("\nWishlist Makanan Manis:\n");                  //tampilkan teks ke layar
        printf("===================\n");                        //tampilkan pembatas

        elemen* bantu = S.top;                                  //buat elemen pembantu yang menunjuk top
        int i = 1;                                              //inisialisasi                      

        while(bantu != NULL)                                    //selama bantu bukan null
        {
            printf("%d. %s\n", i, bantu->kontainer.nama);       //print data nama makanan dan nomornya
            /* iterasi */
            bantu = bantu->next;                                //maju hingga pointer terakhir
            i = i + 1;                                          //iterasi jumlah makanan
        }
    }
    else
    {
        /* proses jika stack kosong */
        printf("\nWishlist Makanan Manis:\n");                  //jika tidak maka stack kosong
        printf("===================\n");                        //tampilkan output ke layar
        printf("NDAK SEHAT!\n");
    }
}

//FUNGSI UNTUK MENGHITUNG ASCII
int countAscii(char str[]) 
{
    int count = 0;                                              //inisialisasi              
    
    for (int i = 0; i < strlen(str); i++)                       //cari panjangnya, hitung sampe huruf terakhir
    {
        count += str[i];                                        //nilai count adalah nilai saat ini ditambah nilai selanjutnya
    }
    return count;                                               //mengembalikan nilai count
}

//PROSEDUR UNTUK MENGECEK JENIS MAKANAN
void pushCek(stack *SX, stack *SY, stack *SZ)
{
    if((*SX).top != NULL)                                                       //jika stacknya tidak kosomg
    {
        elemen* pindah = (*SX).top;                                             // membuat pointer pindah 
        while(pindah != NULL)                                                   //selama pindah bukan null
        {
            if(countAscii(pindah->kontainer.nama) % 2 == 0)                     //jika jumlah ascinya genap
            {
                push(pindah->kontainer.harga, pindah->kontainer.nama, pindah->kontainer.kalori, SY);        //masukkan pada stack makanan pedas
            }
            else                                                                //jika jumlah ascinya ganjil
            {
                push(pindah->kontainer.harga, pindah->kontainer.nama, pindah->kontainer.kalori, SZ);        //masukkan pada stack makanan manis
            }
            pindah = pindah->next;                                              //maju terus keelemen selnajutnya                       
        }
    }
    else                                                                        //jika stack kosong                             
    {
        printf("- Stack Kosong\n");                                             //maka tampilkan teks ke layar                      
    }
}