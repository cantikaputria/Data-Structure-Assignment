/* 
    Saya Cantika Putri Arbiliansyah dengan NIM [2103727] mengerjakan 
    Tugas Praktikum 2 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan 
    kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

//LIBRARY
#include "head.h"

//PROSEDUR UNTUK MEMBUAT LIST
void createList(list *L)
{
    (*L).first = NULL;                              //first di set null
    (*L).tail = NULL;                               //tail di set null dengan maksud membuat list kosong
}

//FUNGSI UNTUK MENGHITUNG JUMLAH ELEMEN DALAM LIST
int countElement(list L)
{
    int hasil = 0;                              //inisialisasi

    if(L.first !=NULL)                          //jika listnya tidak kosong kosong
    {
        elemen* bantu;                          //buat pointer bantu
        bantu = L.first;                        //inisialisasi

        while(bantu != NULL)                    //jika bantu bukan null
        {
            hasil = hasil + 1;                  //hasil adalah hasil tambah 1
            bantu = bantu->next;                //bantu majuu
        }
    }
    return hasil;                               //mengembalikan nilai hasil
}

//PROSEDUR UNTUK MENAMBAH ELEMEN DI AWAL
void addFirst(char nama[], int tanggal, int kode, list *L)
{
    elemen* baru;                                           //membuat pointer baru
    baru = (elemen*) malloc (sizeof (elemen));              //elemen agar tipenya sama, alokasi memori sebesar data yg dibutuhkan elemen

    strcpy(baru->kontainer.nama, nama);                     //menyimpan inputan nama barang
    baru->kontainer.tanggal = tanggal;                      //menyimpan inputan tanggal
    baru->kontainer.kode = kode;                            //menyimpan inputan kode barang

    if((*L).first == NULL)                                  //jika firstnya null, maka list kosong
    {
        baru->prev = NULL;                                  //baru prev di null kan
        baru->next = NULL;                                  //baru next di null kan
        (*L).tail = baru;                                   //tail nunjuk  ke baru
    }
    else                                                    //jika bukan null maka
    {
        baru->next = (*L).first;                            //baru next nunjuk ke first
        baru->prev = NULL;                                  //baru prevnya null
        (*L).first->prev = baru;                            //prev first sama dengan baru
    }
    (*L).first = baru;                                      //first nunjuk ke baru
    baru = NULL;                                            //pointer baru null
}

//PROSEDUR UNTUK MENAMBAH ELEMEN DI TENGAH ATAU SESUAI PERINTAH
void addAfter(elemen* before, char nama[], int tanggal, int kode, list *L)
{
    if(before != NULL)
    {
        elemen* baru;                                           //membuat pointer baru
        baru = (elemen*) malloc (sizeof (elemen));              //elemen agar tipenya sama, alokasi memori sebesar data yg dibutuhkan elemen

        strcpy(baru->kontainer.nama, nama);                     //menyimpan inputan nama barang
        baru->kontainer.tanggal = tanggal;                      //menyimpan inputan tanggal
        baru->kontainer.kode = kode;                            //menyimpan inputan kode barang

        if(before->next == NULL)                                //jika before nextnya null
        {
            baru->next = NULL;                                  //baru next set null
            (*L).tail = baru;                                   //tail nunjuk ke baru
        }
        else                                                    //jika bukan null
        {
            baru->next = before->next;                          //baru next adalah before next
            baru->next->prev = baru;                            //baru next prevnya sama dengan baru
        }
        baru->prev = before;                                    //baru prev sama dengan before 
        before->next = baru;                                    //before nextnya sama dengan baru
        baru = NULL;                                            //baru menjadi null
    }
}

//PROSEDUR UNTUK MENAMBAH ELEMEN DI AKHIR
void addLast(char nama[], int tanggal, int kode, list *L)
{
    if((*L).first == NULL)                                                        //jika list kosong
    {
        addFirst(nama, tanggal, kode, L);                                         //panggil prosedur addfirst
    }
    else                                                                          //jika tidak kosong
    {
        addAfter((*L).tail, nama, tanggal, kode, L);                              //panggil prosedur add after
    }
}

//PROSEDUR UNTUK MENGHAPUS ELEMEN DI AWAL
void delFirst(list *L)
{
    if((*L).first != NULL)                                                  //jika bukan list kosong
    {
        elemen* hapus = (*L).first;                                         //inisialisasi pointer hapus
        
        if(countElement(*L) == 1)                                           //jika hanya satu elemen
        {
            (*L).first = NULL;                                             //first di set null
            (*L).tail = NULL;                                              //tail di set null
        }
        else                                                                //jika lebih dari satu elemen
        {
            (*L).first = (*L).first->next;                                  //firstnya maju
            (*L).first->prev = NULL;                                        //first prev = null
            hapus->next = NULL;                                             //hapus next = null
        }
        free(hapus);                                                        //hapus elemen
    }
}

//PROSEDUR UNTUK MENGHAPUS ELEMEN DI TENGAH ATAU SESUAI PERINTAH
void delAfter(elemen* before, list *L)
{
    if(before != NULL)                              //jika beforenya bukan null
    {
        elemen* hapus = before->next;               //inisialisasi pointer hapus
        if(hapus != NULL)                           //jika hapusnya bukan null
        {
            if(hapus->next == NULL)                 //dan jika hapus nexnya null
            {
                before->next = NULL;                //maka before next = nul
                (*L).tail = before;                 //tail menunjuk ke elemen yg ditunjuk before
            }
            else                                    //jika bukan null
            {
                before->next = hapus->next;         //before nextnya = hapus next
                hapus->next->prev = before;         //hapus next prevnya adalah before
                hapus->next = NULL;                 //hapus next dinullkan
            }
            hapus->prev = NULL;                     //hapus prev di nullkan
            free(hapus);                            //menghapus elemen
        }
        else                                        //jika bukan null
        {
            hapus = before->prev;                   //hapus = before prevnya
            (*L).tail = hapus;                      //tail menunjuk ke hapus
            hapus->next = NULL;                     //hapus next dinullkan       
            free(before);                           //menghapus elemen
        }
    }
}

//PROSEDUR UNTUK MENAMPILKAN ISI ELEMEN KE LAYAR
void printRev(list *L)
{
    if((*L).tail != NULL)                                                   //jika bukan list kosong
    {
        elemen* bantu = (*L).tail;                                          //inisialisasi elemen di tail

        while(bantu != NULL)                                                //jika bantunya bukan null
        {
            printf("%d %s\n", bantu->kontainer.kode, bantu->kontainer.nama);    //print elemen

            bantu = bantu->prev;                                                //pointer bantu mundur ke belakang
        }
    }
    else                                                                    //jika listnya kosong
    {
        printf("Listnya kosong nihh..\n");                                  //menampilkan teks ke layar
    }
}

//PROSEDUR UNTUK SORTING LIST (NEXT)
void sort(list *L)
//function to sort the linked list data
{
	elemen *next,					//membuat pointer next
			 *sorted = NULL,        //membuat pointer penanda untuk sorting
			 *current = L->first,   //membuat pointer penanda posisi saat ini
			 *temp;                 //membuat pointer sementara

	while(current != NULL)			//selama currentnya bukan null
	{
		next = current->next;		//pointer next menunjk pada current next
        if((sorted == NULL) || (sorted->kontainer.tanggal >= current->kontainer.tanggal))	        //jika sortednya null atau tanggal yg dipegang lebih besar dari tanggal satunya
        {																		
            current->next = sorted;													                //maka current next menunjuk pada sorted						
            sorted = current;														                //dan sorted akan menunjuk pada current
        }
        else
        {																		                    //jika tidak maka
            temp = sorted;															                //pointer temp akan menunjuk soretd

            while((temp->next != NULL) && (temp->next->kontainer.tanggal < current->kontainer.tanggal))   //selama temp nextnya bukan nul dan tanggal temp next lebih kecil dari current
            {
                temp = temp->next;													                      //tempnya maju
            }

            current->next = temp->next;												                      //currnet next menunjuk pada temp next
            temp->next = current;													                      //temp next menunjuk pada current
        }
        current = next;																                     //current menunjuk pada nextnya
	}

	L->first = sorted;																                      //firstnya menunjuk pada elemen yg dipegang sorted

}

//PROSEDUR UNTUK SORTING LIST (PREV)
void sortPrev(list *L)
{
    elemen *tunjuk;                                           //membuat pointer tunjuk
    elemen *prev;                                             //membuat pointer prev

    tunjuk = L->first;                                        //inisialisasi
    
    while (tunjuk->next != NULL)                              //selama tunjuk nextnya bukan null
    {
        prev = tunjuk;                                       //prevnya = tunjuk
        tunjuk = tunjuk->next;                               //tunjuk maju
        tunjuk->prev = prev;                                 //tunjuk prev mundur
    }

    L->tail = tunjuk;                                       //tail nya menuju ke tunjuk bu
     
    L->first->prev = NULL;                                  //null
}

//FUNGSI UNTUK MENGHAPUS ELEMEN SESUAI PERINTAH
int delEl(list *L)
{
    int i = 0;                                                          //inisialisasi
    elemen *before = L->first;                                          //inisialiasasi pointer before di first
    
    int temp[50];                                                       //buat variabel penampung kode elemen yg dihpaus

    while(before->next != NULL)                                         //selama beofre next bukan null
    {
        if(before->kontainer.tanggal % 5 == 0)                          //jika elemen pertama tanggalnya merupakan kelipatan 5
        {
            temp[i] = before->kontainer.kode;                          //simpan  kodenya pada array
            before = before->next;                                     //beforenya maju
            i++;                                                       //iterasi
            delFirst(L);                                               //hapus elemen
        }
        else if(before->next->kontainer.tanggal % 5 == 0)              //jika elemen yg ditujuk before next tanggalnya merupakan kelipatan 5
        {
            temp[i] = before->next->kontainer.kode;                    //simpan kodenya pada array
            i++;                                                       //iterasi                  
            delAfter(before, L);                                       //hapus elemen
        }
        else                                                           //jika bukan kelipatan 5 
        {
            before = before->next;                                     //pointer before maju
        }
    }

    if(before->kontainer.tanggal % 5 == 0)                             //jika elemen terakhir merupakan kelipatan 5
    {
        temp[i] = before->kontainer.kode;                               //simpan  kodenya pada array
        before = before->next;                                         //before maju
        i++;                                                           //iterasi
        delFirst(L);                                                   //hapus elemen
    }
    
    sortt(i, temp);                                                    //sorting kode array yg dihapus tadi

    for(int j=0; j<i; j++)
    {
        printf("%d telah dihapus.\n", temp[j]);                        //menampilkan ke layar
    }

    return i;                                                            //mengembalikan nilai i
}

//PROSEDUR UNTUK SORTING ELEMEN YANG DIHAPUS
void sortt(int jumlah, int simpan[])
{
    //selection short
    int temp, i, j, minIndex;                           //inisialisasi

    for(i=0; i<(jumlah-1); i++)                       
    {
        minIndex = i;                                  //minIndex diisi dengan i                  

        for(j=i+1; j<jumlah; j++)
        {
            if(simpan[minIndex] > simpan[j])          //jika simpan indeks ke sekian lebih besar dari simpan indeks ke j
            {
                minIndex = j;                         //maka minIndex diisi dengan j
            }
        }

        //PENUKARAN
        temp = simpan[i];
        simpan[i] = simpan[minIndex];
        simpan[minIndex] = temp;
    }
}