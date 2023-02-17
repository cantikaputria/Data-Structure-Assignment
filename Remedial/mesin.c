/* 
    Saya Cantika Putri Arbiliansyah dengan nama [2103727] mengerjakan 
    Remedial Struktur Data untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

//LIBRARY
#include "header.h"

//PROSEDUR MEMBUAT LIST
void createList(list *L)
{
    (*L).first = NULL;                  //inisialisasi l.first sebagai elemen kosog
}

//FUNGSI MENGHITUNG JUMLAH ELEMEN BARIS
int countElementB(list L)
{
    int hasil = 0;                              //inisialisasi hasil masih kosong
    if(L.first !=NULL)                          //jika list tidak kosong
    {
        eBaris* bantu;                          //buat pointer pembantu bertipe baris
        bantu = L.first;                        //inisialisasi bantu mulai dari l.first

        while(bantu != NULL)                    //selama bantu tidak null, telusuri hingga akhir
        {
            hasil = hasil + 1;                  //maka hasil saat ini adalah hasil sebelumnya ditambah satu
            bantu = bantu->next;                //iterasi bantunya terus maju
        }
    }
    return hasil;                               //mengembalikan nilai hasil
}

//FUNGSI MENGHITUNG JUMLAH ELEMEN KOLOM
int countElementK(eBaris L)
{
    int hasil = 0;                              //inisialisasi hasil masih kosong
    if(L.col != NULL)                           //jika list tidak kosong
    {
        eKolom* bantu;                          //buat pointer pembantu bertipw kolom
        bantu = L.col;                          //insialisasi bantu mulai dari l.kolom

        while(bantu != NULL)                    //selama bantu tidak null, telusuri hingga akhir
        {
            hasil = hasil + 1;                  //hasil saat ini adalah hasil sebelumnya ditambah satu
            bantu = bantu->next_kol;            //iterasi bantu maju terus hingga akhir kolom
        }
    }
    return hasil;                               //mengembalikan nilai hasil
}

//PROSEDUR MENAMBAH ELEMEN DIAWAL PADA BARIS
void addFirstB(char peserta[], list *L)
{
    eBaris* baru;                                       //membuat pointer bantu
    baru = (eBaris *) malloc (sizeof (eBaris));         //alokasi memori               //menyimpan inputan data
    strcpy(baru->kontainer.peserta, peserta);                 //menyimpan inputan data
    
    baru->col = NULL;                                   //membuat kolom kosong

    if((*L).first == NULL)                              //jika listnya masih kosong
    {
        baru->next = NULL;                              //baru next menjaid null
    }
    else                                                //jika bukan list kosong
    {
        baru->next = (*L).first;                        //baru next menunjuk ke l first
    }

    (*L).first = baru;                                  //l first menunjuk ke elemen yg ditunjuk pointer baru
    baru = NULL;                                        //pointer baru menjadi null
}

//PROSEDUR MENAMBAH ELEMEN DIAWAL PADA KOLOM
void addFirstK(char bahan[], int berat, eBaris *L)
{
    eKolom* baru;                                       //membuat pointer bantu
    baru = (eKolom *) malloc (sizeof (eKolom));         //alokasi memori         //menyimpan inputan data
    strcpy(baru->kontainer_kol.bahan, bahan);
    baru->kontainer_kol.berat = berat;

    if((*L).col == NULL)                                //jika listnya masih kosong
    {
        baru->next_kol = NULL;                          //baru next kolom menjaid null
    }
    else                                                //jika bukan list kosong
    {
        baru->next_kol = (*L).col;                      //baru next menunjuk ke l first
    }

    (*L).col = baru;                                    //l col menunjuk ke elemen yg ditunjuk pointer baru
    baru = NULL;                                        //baru dinullkan
}

//PROSEDUR MENAMBAH ELEMEN DITENGAH PADA BARIS
void addAfterB(eBaris* prev, char peserta[])
{
    eBaris* baru;                                       //membuat pointer bantu
    baru = (eBaris *) malloc (sizeof (eBaris));         //alokasi memori               //menyimpan inputan data
    strcpy(baru->kontainer.peserta, peserta);                 //menyimpan inputan data
    baru->col = NULL;                                   //baru col menjadi null

    if(prev->next == NULL)                              //jika prev next bukan null
    {
        baru->next = NULL;                              //baru next menjadi null
    }
    else                                                //jika prev nextnya null
    {
        baru->next = prev->next;                        //baru next menunjuk ke prev next
    }

    prev->next = baru;                                  //prev next menunjuk ke baru
    baru = NULL;                                        //baru menjadi null
}       

//PROSEDUR MENAMBAH ELEMEN DITENGAH PADA KOLOM
void addAfterK(eKolom* prev, char bahan[], int berat, char jenis[])
{
    eKolom* baru;                                       //membuat pointer bantu 
    baru = (eKolom *) malloc (sizeof (eKolom));         //alokasi memori         //menyimpan inputan data
    strcpy(baru->kontainer_kol.bahan, bahan);
    baru->kontainer_kol.berat = berat;

    if(prev->next_kol == NULL)                          //jika bukan null
    {
        baru->next_kol = NULL;                          //maka baru next menjadi null
    }                           
    else                                                //jika null
    {
        baru->next_kol = prev->next_kol;                //maka baru next menunjuk ke prev next
    }

    prev->next_kol = baru;                              //prev next menunjuk ke baru
    baru = NULL;                                        //baru menjadi null
}

//PROSEDUR MENAMBAH ELEMEN DIAKHIR PADA KOLOM
void addLastB(char peserta[], list *L)
{
    if((*L).first == NULL)                                        //jika listnya kosong
    {
        addFirstB(peserta, L);                                  //lakukan addfirst
    }
    else                                                            //jika listnya tidak kosong
    {
        /*mencari elemen terakhir list*/
        eBaris *last = (*L).first;                              //inisialisasi
        while(last->next != NULL)                               //selama tidak bertemu null
        {
            /*iterasi*/
            last = last->next;
        }
        addAfterB(last, peserta);                             //lakukan addafter
    }
}

//PROSEDUR MENAMBAH ELEMEN DIAKHIR PADA BARIS
void addLastK(char bahan[], int berat, eBaris *L)
{
    if((*L).col == NULL)                                        //jika listnya kosong
    {
        addFirstK(bahan, berat, L);        //lakukan addfirst
    }
    else                                                        //jikalistnya tidak kosong, cari hingga elemen terakhir
    {
        eKolom *last = (*L).col;                                //pointer baru inisalisasi

        while(last->next_kol != NULL)                           //selamat pointer nextnya tidak null
        {
            /*iterasi*/
            last = last->next_kol;
        }
        addAfterK(last, bahan, berat);     //lakukan addafter
    }
}

//PROSEDUR MENGHAPUS ELEMEN DIAWAL PADA KOLOM
void delFirstK(eBaris *L)
{
    if((*L).col != NULL)
    {
        /*jika list bukan list kosong*/
        eKolom* hapus = (*L).col;
        
        if(countElementK(*L) == 1)
        {
            (*L).col = NULL;
        }
        else
        {
            (*L).col = (*L).col->next_kol;
            hapus->next_kol = NULL;
        }
        free(hapus);
    }
}

//PROSEDUR MENGHAPUS ELEMEN DITENGAH PADA KOLOM
void delAfterK(eKolom* prev)
{
    eKolom* hapus = prev->next_kol;

    if(hapus != NULL)
    {
        if(hapus->next_kol == NULL)
        {
            prev->next_kol = NULL;
        }
        else
        {
            prev->next_kol = hapus->next_kol;
            hapus->next_kol = NULL;
        }
        free(hapus);
    }
}

//PROSEDUR MENGHAPUS ELEMEN AKHIR PADA BARIS
void delLastK(eBaris *L)
{
    if((*L).col != NULL)
    {
        /*jika list tidak kosong*/
        if(countElementK(*L) == 1)
        {
            /*list terdiri dari satu
            elemen*/
            delFirstK(L);
        }
        else
        {
            /*mencari elemen terakhir list*/
            eKolom *last = (*L).col;
            eKolom *before_last;

            while(last->next_kol != NULL)
            {
            /*iterasi*/
                before_last = last;
                last = last->next_kol;
            }
            delAfterK(before_last);
        }
    }
}

//PROSEDUR MENGHAPUS ELEMEN KOLOM PADA BARIS
void delAllK(eBaris *L)
{
    if(countElementK(*L) != 0)
    {
        int i;
        for(i=countElementK(*L);i>=1;i--)
        {
            /*proses menghapus elemen list*/
            delLastK(L);
        }
    }
}

//PROSEDUR MENGHAPUS ELEMEN DIAWAL PADA BARIS
void delFirstB(list *L)
{
    if((*L).first != NULL){
    /*jika list bukan list kosong*/
    eBaris *hapus = (*L).first;

    if(hapus->col != NULL)
    {
        //menghapus semua elemen kolom
        delAllK(hapus);
    }
    if(countElementB(*L) == 1)
    {
        (*L).first = NULL;
    }
    else
    {
        (*L).first = (*L).first->next;
    }

        hapus->next = NULL;
        free(hapus);
    }
    else
    {
        printf("list kosong");
    }
}

//PROSEDUR MENGHAPUS ELEMEN TENGAH BARIS
void delAfterB(eBaris* prev)
{
    if(prev != NULL)
    {
        eBaris *hapus = prev->next;
        if(hapus != NULL)
        {
            if(hapus->col != NULL)
            {
            //menghapus semua elemen kolom jika ada
                delAllK(hapus);
            }
                if(hapus->next == NULL)
                {
                    prev->next = NULL;
                }
            else
            {
                 prev->next = hapus->next;
            }
            hapus->next = NULL;
            free(hapus);
        }
    }
}

//PROSEDUR ELEMEN TERAKHIR BARIS
void delLastB(list *L)
{
    if((*L).first != NULL)
    {
        /*jika list tidak kosong*/

        if(countElementB(*L) == 1)
        {
            /*list terdiri dari satu
            elemen*/
            delFirstB(L);
        }
        else
        {
            /*mencari elemen terakhir list*/
            eBaris *last = (*L).first;
            eBaris *before_last;
            while(last->next != NULL)
            {
                /*iterasi*/
                before_last = last;
            
                last = last->next;
            }
            delAfterB(before_last);
        }
    }
}

//PROSEDUR MENGHAPUS SELURUH ELEMEN BARIS
void delAllB(list *L)
{
    if(countElementB(*L) != 0)
    {
        int i;

        for(i=countElementB(*L);i>=1;i--)
        {
            /*proses menghapus elemen list*/
            delLastB(L);
        }
    }
}

//PROSEDUR MENAMPILKAN OUTPUT KE LAYAR
void printElement(list L)
{
    if(L.first != NULL)
    {
        /*inisialisasi*/
        eBaris* bantu = L.first;
        int i = 1;
        
        while(bantu != NULL)
        {
            /*proses*/
            printf("%s\n", bantu->kontainer.peserta);

            eKolom* eCol = bantu->col;
            while(eCol != NULL)
            {
                printf("- %s %s %d %d %s\n", eCol->kontainer_kol.bahan, eCol->kontainer_kol.berat);
                eCol = eCol->next_kol;
            }

            /*iterasi*/
            bantu = bantu->next;
            i = i + 1;
        }
    }
    else
    {
        /*proses jika list kosong*/
        printf("list kosong\n");
    }
}

//PROSEDUR MENDAPAT ALAMAT BARIS
eBaris* get(list L)
{
    eBaris* tunjuk = L.first;                               //buat pointer, disimoan di l.frist
    
    while (tunjuk != NULL)                                  //selama tunjuk bukan  null
    {
        if(strcmp(tunjuk->kontainer.kode, kode) == 0)       //jika kode yg dibandingkan sama
        {
            return tunjuk;                                  //kenbalikan nilai tunjuk
        }
        else                                                //jika tidak sama
        {
            tunjuk = tunjuk->next;                          //tunjuk maju terus
        }
    }
}

//PROSEDUR MENDAPAT ALAMAT KOLOM
eKolom* get2(eBaris *L, char kode[])
{
    eKolom *last = (*L).col;
    while(last->next_kol != NULL && strcmp(last->next_kol->kontainer_kol.kodeD, kode) != 0) 
    {
        last = last->next_kol;
    }
    return last;
}

//PROSEDUR PROSES
void proses(eBaris *L, int berat, int tahun)
{
    int i = 0;
    char temp[50];
    eKolom* before;
    
    while (before != NULL)
    {
        before = L->col;
        if(strcmp(before->kontainer_kol.jenis, "sirup") == 0)
        {
            if (before->kontainer_kol.tahun == tahun)
            {
                if ((before->kontainer_kol.berat == berat) || (before->kontainer_kol.berat > berat))
                {
                    strcpy(before->kontainer_kol.bahan, temp);                          //simpan  kodenya pada array
                    before = before->next_kol;                                     //beforenya maju
                    i++;                                                       //iterasi
                    delFirstK(L);
                }
                else if ((before->next_kol->kontainer_kol.berat == berat) || (before->next_kol->kontainer_kol.berat > berat))
                {
                    strcpy(before->next_kol->kontainer_kol.bahan, temp);                          //simpan  kodenya pada array
                    i++;                                                       //iterasi
                    delAfterK(L->col->next_kol);
                }
                else
                {
                    before = before->next_kol;
                }
            }
            else if (before->next_kol->kontainer_kol.tahun == tahun)
            {
                if ((before->kontainer_kol.berat == berat) || (before->kontainer_kol.berat > berat))
                {
                    strcpy(before->kontainer_kol.bahan, temp);                          //simpan  kodenya pada array
                    before = before->next_kol;                                     //beforenya maju
                    i++;                                                       //iterasi
                    delFirstK(L);
                }
                else if ((before->next_kol->kontainer_kol.berat == berat) || (before->next_kol->kontainer_kol.berat > berat))
                {
                    strcpy(before->next_kol->kontainer_kol.bahan, temp);                          //simpan  kodenya pada array
                    i++;                                                       //iterasi
                    delAfterK(L->col->next_kol);
                }
                else
                {
                    before = before->next_kol;
                }
            }
            else
            {
                before = before->next_kol;
            }
        }
        else if(strcmp(before->next_kol->kontainer_kol.jenis, "sirup") == 0)
        {
            if (before->kontainer_kol.tahun == tahun)
            {
                if ((before->kontainer_kol.berat == berat) || (before->kontainer_kol.berat > berat))
                {
                    strcpy(before->kontainer_kol.bahan, temp);                          //simpan  kodenya pada array
                    before = before->next_kol;                                     //beforenya maju
                    i++;                                                       //iterasi
                    delFirstK(L);
                }
                else if ((before->next_kol->kontainer_kol.berat == berat) || (before->next_kol->kontainer_kol.berat > berat))
                {
                    strcpy(before->next_kol->kontainer_kol.bahan, temp);                          //simpan  kodenya pada array
                    i++;                                                       //iterasi
                    delAfterK(L->col->next_kol);
                }
                else
                {
                    before = before->next_kol;
                }
            }
            else if (before->next_kol->kontainer_kol.tahun == tahun)
            {
                if ((before->kontainer_kol.berat == berat) || (before->kontainer_kol.berat > berat))
                {
                    strcpy(before->kontainer_kol.bahan, temp);                          //simpan  kodenya pada array
                    before = before->next_kol;                                     //beforenya maju
                    i++;                                                       //iterasi
                    delFirstK(L);
                }
                else if ((before->next_kol->kontainer_kol.berat == berat) || (before->next_kol->kontainer_kol.berat > berat))
                {
                    strcpy(before->next_kol->kontainer_kol.bahan, temp);                          //simpan  kodenya pada array
                    i++;                                                       //iterasi
                    delAfterK(L->col->next_kol);
                }
                else
                {
                    before = before->next_kol;
                }
            }
            else
            {
                before = before->next_kol;
            }
        }
        else
        {
            before = before->next_kol;
        }
    }
}