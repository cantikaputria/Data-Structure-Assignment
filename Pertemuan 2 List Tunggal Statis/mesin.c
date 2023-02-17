#include "header.h"

//MEMBUAT LIST
void createList(list *L)                         //parameter list bernama L yaitu list yang kita punya(dideklarasikan di main)
{
    //first di nullkan
    (*L).first = -1;
    int i;

    //looping sebanyak alokasi jumlah data
    for(i = 0; i < 10; i++)
    {
        //set elemen sebagai tanda elemen belum digunakan / terpakai
        (*L).data[i].next = -2;
    }
}

//COUNT ELEMEN
int countElement(list L)
{
    //variabel penyimpan hasil hitung jumlah berapa elemen yg ada
    int hasil = 0;

    //syaratnya : jika first bukan null (tidak kosong = ada isinya)
    if(L.first != -1)
    {
        //pointer pennyimpan nilai yang ditunjuk pointer punya elemen
        int hitung;

        //nilai hitung = nilai pointer first
        hitung = L.first;

        //syarat : ketika nilai hitung bukan null (berhenti jika null alias sampe elemen terakhir)
        while(hitung != -1)
        {
            //penghitungan nilai hasil
            hasil = hasil + 1;

            //hitung sekarang adalah pointer next dari hitung sebelumnya
            //hitung yg tadi, nextnya
            hitung = L.data[hitung].next;
        }
    }

    //else berhenti jika null alias elemen kosong, maka hasil count = 0
    return hasil;
}

//EMPTY ELEMENT
//berfungsi menghasilkan index dari elemen yang masih kosong
int emptyElement(list L)
{
    //kondisi misal seluruh data penuh dan sudah terisi, maka hasil = null, dan elemen tidak ada yang kosong
    ///variabel pendanda di indeks berapa yang empty
    int hasil = -1;

    //kondisi mengecek sesuai jumlah data elemen
    if(countElement(L) < 10)
    {
        int ketemu = 0;                            //penghitung, ada berapa si jumlah elemen kosongnya
        int i = 0;                       

        //syarat : jika belum ketemu dan pencarian diabats sesuai jumlah elemen
        while((ketemu == 0) && (i < 10))
        {   
            //cari, jika data ke index dan nextnya adalah -2, maka data tersebut empty
            if(L.data[i].next == -2)
            {   
                //tandai hasil dengan di index berapa yg kosongnya
                hasil = i;
                ketemu = 1;
            }
            else
            {   
                //jika tidak ketemu, maju terus
                i = i + 1;
            }
        }
    }
    return hasil;
}

//ADD FIRST
void addFirst(char nim[], char nama[], char nilai[], list *L)    //parameternya adalah isi kontainer dan list yg akan ditambahkan
{
    //syarat : dengan batas jumlah elemen data
    if(countElement(*L) < 10)
    {
        //buat pointer baru di elemen yg masih kosong
        //baru adalah elemen kosong yg ditemukan pertama kali
        int baru = emptyElement(*L);

        //mengisi elemen kontainer
        strcpy((*L).data[baru].kontainer.nim, nim);
        strcpy((*L).data[baru].kontainer.nama, nama);
        strcpy((*L).data[baru].kontainer.nilai, nilai);

        //jika listnya kosong atau null
        if((*L).first == -1)
        {
            //maka deklasarikan baru next = null karena akan jadi paling belakang (elemen awal dan akhir)
            (*L).data[baru].next = -1;
        }
        //jika listnya tidak kosong
        else
        {
            //baru next kenalan sama elemen yang ditunjuk firts
            (*L).data[baru].next = (*L).first;
        }
        //pointer firts, pindah jadi nunjuk ke elemen baru
        (*L).first = baru;
    }
    else   //jika lebih dari itu maka elemen penuh
    {
        printf("sudah tidak dapat ditambah\n");
    }
}

//ADDAFTER
void addAfter(int prev, char nim[], char nama[], char nilai[], list *L)
{   
    //jika elemen yg terisi kurang dari 10 maka
    if(countElement(*L) < 10)
    {   
        //buat pointer baru di elemen yg masih kosong
        //baru adalah elemen kosong yg ditemukan pertama kali
        int baru = emptyElement(*L);

        //mengisi elemen kontainer
        strcpy((*L).data[baru].kontainer.nim, nim);
        strcpy((*L).data[baru].kontainer.nama, nama);
        strcpy((*L).data[baru].kontainer.nilai, nilai);

        //jika di elemen terakhir
        if((*L).data[prev].next == -1)
        {
            //maka deklasarikan baru next = null karena akan jadi paling belakang
            (*L).data[baru].next = -1;
        }
        //elemen tengah
        else
        {   
            // int i = 0;
            //while prev next = indeks data yang dicaro
            // while((prev == 0) && (i < 10))
            // {   
            //     //cari, jika data ke index dan nextnya adalah -2, maka data tersebut empty
            //     if((*L).data[i].next == yg dicari)
            //     {   
            //         //tandai hasil dengan di index berapa yg kosongnya
            //         prev = i;
            //     }
            //     else
            //     {   
            //         //jika tidak ketemu, maju terus
            //         i = i + 1;
            //     }
            // }
            
            (*L).data[baru].next = (*L).data[prev].next;
        }
        (*L).data[prev].next = baru;
    }
    else
    {
        /*proses jika array penuh*/
        printf("sudah tidak dapat ditambah\n");
    }
}

//ADDLAST
void addLast(char nim[], char nama[], char nilai[], list *L)
{
    if((*L).first == -1)
    {
        /*proses jika list masih kosong*/
        addFirst(nim, nama, nilai, L);
    } 
    else
    {
        /*proses jika list telah berisi elemen*/
        if(countElement(*L) < 10)
        {
            /*proses jika array belum penuh*/
            /*proses mencari elemen terakhir*/
            /*inisialisasi*/
            int prev = (*L).first;

            while((*L).data[prev].next != -1)
            {
                /*iterasi*/
                prev = (*L).data[prev].next;
            }
            addAfter(prev, nim, nama, nilai, L);
        }
        else
        {
            /*proses jika array penuh*/
            printf("sudah tidak dapat ditambah\n");
        }
    }
}

//DELFIRST
void delFirst(list *L)
{
    //jika listnya tidak kosong
    if((*L).first != -1)
    {
        int hapus = (*L).first;
        //satu elemen
        if(countElement(*L) == 1)
        {
            (*L).first = -1;
        }
        //banyak elemen
        else
        {
            (*L).first = (*L).data[hapus].next;
        }
        /*elemen awal sebelumnya dikosongkan*/
        (*L).data[hapus].next = -2;
    }
    else
    {
        /*proses jika list kosong*/
        printf("list kosong\n");
    }
}

//DELAFTER
void delAfter(int prev, list *L)
{
    int hapus = (*L).data[prev].next;
    if(hapus != -1)
    {
        //dibelakang
        if((*L).data[hapus].next == -1)
        {
            (*L).data[prev].next = -1;
        }
        //ditengah
        else
        {
            (*L).data[prev].next = (*L).data[hapus].next;
        }
        /*pengosongan elemen*/
        (*L).data[hapus].next = -2;
    }
}

//DELLAST
void delLast(list *L)
{
    if((*L).first != -1)
    {
        if(countElement(*L) == 1)
        {
            /*proses jika list hanya berisi satu elemen*/
            delFirst(L);
        }
        else
        {
            int hapus = (*L).first;
            int prev;

            while((*L).data[hapus].next != -1)
            {
                /*iterasi*/
                prev = hapus;
                hapus = (*L).data[hapus].next;
            }
            /*elemen sebelum elemen terakhir menjadi elemen terakhir*/
            delAfter(prev, L);
        }
    }
    else
    {
        /*proses jika list kosong*/
        printf("list kosong\n");
    }
}

//PRINT ELEMEN
void printElement(list L)
{
    if(L.first != -1)
    {
        /*inisialisasi*/
        int tunjuk = L.first;
        int i = 1;

        while(tunjuk != -1)
        {
            /*proses*/
            printf("elemen ke : %d\n", i);
            printf("nim : %s\n", L.data[tunjuk].kontainer.nim);
            printf("nama : %s\n", L.data[tunjuk].kontainer.nama);
            printf("nilai : %s\n", L.data[tunjuk].kontainer.nilai);
            printf("next : %d\n", L.data[tunjuk].next);
            printf("------------\n");
            /*iterasi*/
            tunjuk = L.data[tunjuk].next;
            i = i + 1;
        }
    }
    else
    {
        /*proses jika list kosong*/
        printf("list kosong\n");
    }
}

//DELALL
void delAll(list *L)
{
    int i;
    for(i=countElement(*L); i>=1; i--)
    {
        /*proses menghapus elemen list*/
        delLast(L);
    }
}