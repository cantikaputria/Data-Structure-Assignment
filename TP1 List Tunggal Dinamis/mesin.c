/* 
    Saya Cantika Putri Arbiliansyah dengan NIM [2103727] mengerjakan 
    Tugas Praktikum 1 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan 
    kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

//PROSEDUR UNTUK MEMBUAT LIST
void createList(list *L)
{   
    (*L).first = NULL;                                                              //membuat pointer first yang nilainya null
}

//FUNGSI UNTUK MENGHITUNG JUMLAH ELEMEN
int countElement(list L)
{   
    int hasil = 0;                                                                  //membuat kotak hasil

    if(L.first !=NULL)                                                              //jika listnya tidak kosong atau bukan list terakhir, maka....
    {
        elemen* tunjuk;                                                             //membuat pointer penunjuk

        tunjuk = L.first;                                                           //mulai pengecelan dari elemen pertama

        while(tunjuk != NULL)                                                       //selama tunjukknya masiha ada elemennya, maka...
        {
            hasil = hasil + 1;                                                      //lakukan sampai elemen terakhir
            
            tunjuk = tunjuk->next;                                                  //tunjuk yg sekarang, tunjuk tadi nextnya
        }
    }
    return hasil;                                                                   //memgembalikan nilai hasil perhitungan
}

//PROSEDUR UNTUK MENAMBAH ELEMEN DI AWAL
void addFirst(char judul[], char artis[], int urutan, list *L)
{   
    elemen* baru;                                           //membuat pointer baru

    baru = (elemen*)malloc(sizeof(elemen));                 //elemen agar tipenya sama, alokasi memori sebesar data yg dibutuhkan elemen
                                                            //pointer baru akan mengacu secara casting (dipaksa) sebagai pointer
    strcpy(baru->kontainer.judul, judul);                   //menyimpan inputan judul lagu
    strcpy(baru->kontainer.artis, artis);                   //menyimpan inputan artis
    baru->kontainer.urutan = urutan;                        //menyimpan imputan urutan lagu

    if((*L).first == NULL)                                  //jika firstnya null, maka list kosong
    {
        baru->next = NULL;                                  //di null kan karena kosong
    }
    else                                                    //jika bukan null maka
    {
        baru->next = (*L).first;                            //pointer baru next menunjuk ke first
    }

    (*L).first = baru;                                      //pointer first menunjuk ke elemen baru
    baru = NULL;                                            //pointer baru akan menjadi null
}

//PROSEDUR UNTUK MENAMBAH ELEMEN DI TENGAH
void addAfter(elemen* prev, char judul[], char artis[], int urutan, list *L)
{
    elemen *baru;                                           //memnbuat pointer baru
    baru = (elemen*) malloc (sizeof (elemen));              //elemen agar tipenya sama, alokasi memori sebesar data yg dibutuhkan elemen

    strcpy(baru->kontainer.judul, judul);                   //menyimpan inputan judul lagu
    strcpy(baru->kontainer.artis, artis);                   //menyimpan inputan artis
    baru->kontainer.urutan = urutan;                        //menyimpan imputan urutan lagu

    if(prev->next == NULL)                                  //jika menambah elemen di akhir
    {
        baru->next = NULL;                                  //di null kan karena akan menjadi elemen terajhir
    }
    else                                                    //jika menambah di elemen tertentu
    {   
        baru->next = prev->next;                            //baru next akan menunjuk prev next
    }

    prev->next = baru;                                      //prev next akan menunjuk elemen baru
    baru = NULL;                                            //pointer baru akan menjadi null
}

//PROSEDUR UNTUK MENAMBAH ELEMEN DI AKHIR
void addLast(char judul[], char artis[], int urutan, list *L)
{
    if((*L).first == NULL)                                  //jika listnya adalah list kosong
    {
        addFirst(judul, artis, urutan, L);                  //gunakan addfirst
    }
    else                                                    //jika list tidak kosong
    {
        elemen* prev = (*L).first;                          //mulai pencarian elemen tertentu dari first
        while(prev->next != NULL)                           //lakukan hingga prev next bukan elemen terakhir
        {
            prev = prev->next;                              //maju terus
        }

        addAfter(prev, judul, artis, urutan, L);            //gunakan addafter
    }
}

//PROSEDUR UNTUK MENGHAPUS ELEMEN DI AWAL
void delFirst(list *L)
{   
    if((*L).first != NULL)                              //jika bukan list kosong
    {
        elemen* hapus = (*L).first;                     //buat pointer hapus dan mulai dari first

        if(countElement(*L) == 1)                       //jika jumlah elemen hanya satu
        {
            (*L).first = NULL;                          //maka elemen pertama bernilai null
        }
        else                                            //jika elemennya banyak
        {
            (*L).first = (*L).first->next;              //maka first menunjuk pada nextnya
            hapus->next = NULL;                         //sudah tidak terpakai, di nullkan
        }
        free(hapus);                                    //menghapus elemen
    }
}

//PROSEDUR UNTUK MENGHAPUS ELEMEN DI TENGAH
void delAfter(elemen* prev, list *L)
{   
    elemen* hapus = prev->next;                         //buat pointer hapus dan mulai dari prev next

    if(hapus != NULL)                                   //jika bukan list kosong
    {   
        if(hapus->next == NULL)                         //jika elemen terakhir
        {
            prev->next = NULL;                          //prev next menjadi null
        }
        else                                            //jika bukan elemen terakhir
        {
            prev->next = hapus->next;                   //prev next akan menunjuk hapus next
            hapus->next = NULL;                         //hapus next akan menjadi null
        }
        free(hapus);                                    //meghapus elemen yang ditunjuk
    }
}

//PROSEDUR UNTUK MENGHAPUS ELEMEN DI AKHIR
void delLast(list *L)
{
    if((*L).first != NULL)                              //jika list tidak kosong
    {
        if(countElement(*L) == 1)                       //jika hanya satu elemen                   
        {
            delFirst(L);                                //maka gunakan delfirst
        }
        else                                            //jika lbeih banyak elemen
        {
            elemen* last = (*L).first;                  //cari elemen terakhir list
            elemen* prev;                               //buat elemen prev

            while(last->next != NULL)                   //lanjut hingga elemen terakhir bernilai null
            {
                prev = last;                            //prev menunjuk ke last
                last = last->next;                      //last menjuntuk ke setelahnya
            }
            delAfter(prev, L);                          //gunakan delafter
        }
    }
}

//PROSEDUR UNTUK MENAMPILKAN SELURUH ELEMEN LIST
void printElement(list L)
{
    if(L.first != NULL)                                 //jika bukan list kosong
    {
        elemen* tunjuk = L.first;                       //membuat pointer penunjuk dan mulai dari elemen pertama
        int i = 1;                                      //inisialisasi

        while(tunjuk != NULL)                           //jika tunjuk tidak bernilai null
        {
            printf("%s - %s\n", tunjuk->kontainer.judul, tunjuk->kontainer.artis);          //menampilkan elemen ke layar
            tunjuk = tunjuk->next;                      //tunjuk pindah ke elemen selanjutnya
            i = i + 1;                                  //maju terus hingga elemen terakhir
        }
    }
    else                                                //jika null maka list kosong
    {
        printf("List Kosong.\n");                       //menampilkan teks ke layar
    }
}

//PROSEDUR MENGHAPUS SELURUH ELEMEN LIST
void delAll(list *L)
{   
    if(countElement(*L) != 0)                               //jika bukan list kosong
    {
        int i;                                              //inisialisasi
        for(i = countElement(*L); i>= 1; i--)               //sampai seluruh elemen
        {
            delLast(L);                                     //pemanggilan prosedur untuk menghapus seluruh elemen list
        }
    }
}

//PROSEDUR UNTUK SSORTING LIST
void sortList(list *L, char sort[], char ccc[])
{
    if(countElement(*L) > 1)                                                               //urutkan jika jumlah elemennya lebih dari satu
    {
        elemen* i = L->first, *j;                                                          //membuat pointer i dan j untuk membantu pengecekan dan penukaran elemen

        for(i = L->first; i->next != NULL; i = i->next)                                    //dilakukan terus hingga pointer i menunjuk elemen terakhir dari elemen pertama
        {
            for(j = i->next; j != NULL; j = j->next)                                       //dilakukan terus hingga pointer j menunjuk elemen terakhir dari elemen setelah i
            {
                if(strcmp(sort, "judul") == 0)                                             //jika sorting berdasarkan judul lagu
                {
                    if(strcmp(ccc, "asc") == 0)                                            //jika pengurutannya secara ascending
                    {   
                        if((strcmp(i->kontainer.judul, j->kontainer.judul) == 1))          //bandingkan dan cari yang terkecil
                        {
                            swap(i, j);                                                    //tukar elemen
                        }
                    } 
                    else                                                                   //jika pengurutannya secara descending
                    {  
                        if((strcmp(i->kontainer.judul, j->kontainer.judul) == -1))         //bandingkan dam cari yang terbesar
                        {
                            swap(i, j);                                                    //tukar elemen
                        }
                    }
                } 
                else                                                                       //jika sorting berdasarkan urutan
                {   
                    if(strcmp(ccc, "asc") == 0)                                            //jika pengurutannya secara ascending
                    {
                        if(i->kontainer.urutan > j->kontainer.urutan)                      //jika urutan i > j
                        {
                            swap(i, j);                                                    //tukar elemen
                        }
                    } 
                    else                                                                   //jika pengurutannya secara ascending
                    {
                        if(i->kontainer.urutan < j->kontainer.urutan)                      //jika urutan i < j
                        {
                            swap(i, j);                                                    //tukar elemen
                        }
                    }
                }
            }
        }
    }
}

//PROSEDUR UNTUK MENUKAR ELEMEN
void swap(elemen *a, elemen *b) 
{   
    lagu temp = a->kontainer;                                         //menyimpan elemen yg ditunjuk pointer a sementara di temp
    a->kontainer = b->kontainer;                                      //menyimpan elemen yg ditunjuk poingter b di elemen yang ditunjuk pointer a
    b->kontainer = temp;                                              //menyimpan elemen yg disimpan temp di elemen yg ditunjuk pointer b
}