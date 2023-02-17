#include "header.h"

void createList(list *L)
{
    (*L).first = NULL;
    (*L).tail = NULL;
}

int countElement(list L)
{
    int hasil = 0;

    if(L.first !=NULL)
    {
        /*list tidak kosong*/
        elemen* bantu;
        /*inisialisasi*/
        bantu = L.first;

        while(bantu != NULL)
        {
            /*proses*/
            hasil = hasil + 1;
            /*iterasi*/
            bantu = bantu->next;
        }
    }
    return hasil;
}

void addFirst(char nama[], int tanggal, int kode, list *L)
{
    elemen* baru;
    baru = (elemen*) malloc (sizeof (elemen));
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.tanggal = tanggal;
    baru->kontainer.kode = kode;

    if((*L).first == NULL)
    {
        baru->prev = NULL;
        baru->next = NULL;
        (*L).tail = baru;
    }
    else
    {
        baru->next = (*L).first;
        baru->prev = NULL;
        (*L).first->prev = baru;
    }
    (*L).first = baru;
    baru = NULL;
}

void addAfter(elemen* before, char nama[], int tanggal, int kode, list *L)
{
    if(before != NULL)
    {
        elemen* baru;
        baru = (elemen*) malloc (sizeof (elemen));
        strcpy(baru->kontainer.nama, nama);
        baru->kontainer.tanggal = tanggal;
        baru->kontainer.kode = kode;

        if(before->next == NULL)
        {
            baru->next = NULL;
            (*L).tail = baru;
        }
        else
        {
            baru->next = before->next;
            baru->next->prev = baru;
        }
        baru->prev = before;
        before->next = baru;
        baru = NULL;
    }
}

void addBefore(elemen *after, char nama[], int tanggal, int kode, list *L)
{
    if(after != NULL)
    {
        elemen *baru;
        baru = (elemen*)malloc(sizeof(elemen));
        strcpy(baru->kontainer.nama, nama);
        baru->kontainer.tanggal = tanggal;
        baru->kontainer.kode = kode;

        if(after->prev == NULL)
        {
            baru->prev = NULL;
            (*L).first = baru;
        }
        else
        {
            baru->prev = after->prev;
            after->prev->next = baru;
        }
        baru->next = after;
        after->prev = baru;
        baru = NULL;
    }
}

void addLast(char nama[], int tanggal, int kode, list *L)
{
    if((*L).first == NULL)
    {
        /*jika list adalah list kosong*/
        addFirst(nama, tanggal, kode, L);
    }
    else
    {
        /*jika list tidak kosong*/
        addAfter((*L).tail, nama, tanggal, kode, L);
    }
}

void delFirst(list *L)
{
    if((*L).first != NULL)
    {
        /*jika list bukan list kosong*/
        elemen* hapus = (*L).first;
        
        if(countElement(*L) == 1)
        {
            (*L).first = NULL;
            (*L).tail = NULL;
        }
        else
        {
            (*L).first = (*L).first->next;
            (*L).first->prev = NULL;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void delAfter(elemen* before, list *L)
{
    if(before != NULL)
    {
        elemen* hapus = before->next;
        if(hapus != NULL)
        {
            if(hapus->next == NULL)
            {
                before->next = NULL;
                (*L).tail = before;
            }
            else
            {
                before->next = hapus->next;
                hapus->next->prev = before;
                hapus->next = NULL;
            }
            hapus->prev = NULL;
            free(hapus);
        }
    }
}

void delLast(list *L)
{
    if((*L).first != NULL)
    {
        /*jika list tidak kosong*/
        if(countElement(*L) == 1)
        {
            /*list terdiri dari satu elemen*/
            delFirst(L);
        }
        else
        {
            /*jika banyak elemen*/
            delAfter((*L).tail->prev, L);
        }
    }
}

int delEl(elemen *before, list *L, int simpan[])
{
    int i = 0;
   
    while(before->next != NULL)
    {

        if(before->kontainer.tanggal % 5 == 0)
        {
            simpan[i] = before->kontainer.kode;
            before = before->next;
            i++;
            delFirst(L);
        }
        else if(before->next->kontainer.tanggal % 5 == 0)
        {
            simpan[i] = before->next->kontainer.kode;
            i++;
            delAfter(before, L);
        }

        else
        {
            before = before->next;
        }
    }
    
    return i;
}

void printElement(list L)
{
    if(L.first != NULL)
    {
        /*jika list tidak kosong*/
        /*inisialisasi*/
        elemen* bantu = L.first;
        int i = 1;

        while(bantu != NULL)
        {
            
            printf("%s %d %d\n", bantu->kontainer.nama, bantu->kontainer.tanggal, bantu->kontainer.kode);
            bantu = bantu->next;
            i = i + 1;
        }
    }
    else
    {
        /*proses jika list kosong*/
        printf("List Kosong\n");
    }
}

void printRev(list L)
{
    if(L.tail != NULL)
    {
        elemen* bantu = L.tail;

        while(bantu != NULL)
        {
            printf("%s %d %d\n", bantu->kontainer.nama, bantu->kontainer.tanggal, bantu->kontainer.kode);

            bantu = bantu->prev;
        }
    }
    else
    {
        printf("Listnya kosong nih..\n");
    }
}

void delAll(list *L)
{
    if(countElement(*L) != 0)
    {
        int i;
        for(i=countElement(*L);i>=1;i--)
        {
            /*proses menghapus elemen list*/
            delLast(L);
        }
    }
}

void sort(list *L)
//function to sort the linked list data
{
	elemen *next,					//we're gonna need 4 pointer... smh :" idk how to explain this function
			 *sorted = NULL,
			 *current = L->first,
			 *temp;

	while(current != NULL)			//as long as current pointer is not null
	{
		next = current->next;		//next pointer will point the current next pointer
									//there will be 2 conditions if the input is asc or desc code
        if((sorted == NULL) || (sorted->kontainer.tanggal >= current->kontainer.tanggal))	//if the sorted pointer is null
        {																			//or, the sorted->tanggal is greater than the current->tanggal
            
            current->next = sorted;													//current next pointer will point the sorted pointer							
            sorted = current;														//and the sorted pointer will point the current pointer
        }
        else
        {																		//if not
            temp = sorted;															//the temp pointer will point the sorted pointer

            while((temp->next != NULL) && (temp->next->kontainer.tanggal < current->kontainer.tanggal))
                                                                                    //then, while the temp->next is not null
                                                                                    //and the temp->next->rate is smaller than the current->rate
            {
                temp = temp->next;													//temp pointer will point the temp->next pointer
            }

            current->next = temp->next;												//then, the current->next will point the temp->next pointer
            temp->next = current;													//and the temp->next pointer will point the current pointer
        }
        current = next;																//and the current pointer will point the next pointer
	}

	L->first = sorted;																//finally, the sorted pointer will be the new head of the linked list

}

void sortPrev(list *L)
{
    elemen *tunjuk;
    elemen *prev;

    tunjuk = L->first;
    
    while (tunjuk->next != NULL)
    {
        prev = tunjuk;
        tunjuk = tunjuk->next;
        tunjuk->prev = prev;
    }

    L->tail = tunjuk;
     
    L->first->prev = NULL;
};

void sortlagi(int simpan[], int kiri, int kanan)
{
    int i = kiri;                                                               //i ditandai sebagai kiri
    int j = kanan;                                                              //j ditandai sebagai kana                                                         //variabel penampung str saat penukaram
    int temp;  

    int hitung = simpan[(kanan + kiri) / 2];

    do                                                                          //lakukan
    {
        while(((simpan[i] < hitung) && (i <= j)))       //ketika durasi indeks i lebih besar dari durasi tengah
        {
            i++;
        }
        while(((simpan[i] > hitung) && (i <= j)))      //ketika durasi indeks j lebih besar dari durasi tengah
        {
            j--;
        }

        if (i < j)                                                              //jika nilai i lebih kecil dari j
        {
            //LAKUKAN PROSES PENUKARAM (kurang lebih sama seperti diatas)
          
            temp = simpan[i];
            simpan[i] = simpan[j];
            simpan[j] = temp;

            //iterasi
            i++;
            j--;
        }

    } while (i < j);                                                                   //ketika nilai i kurang dari j maka berhenti

    //REKURSIF
    if((kiri < j) && (j < kanan))                                                      //jika kiri lebih kecil dari j dan nilai j lebih dari kanan
    {
        sortlagi(simpan, kiri, j);                                                     //rekursif untuk kiri
    }

    if((i < kanan) && (i > kiri))                                                      //jika i lebih kecil dari kanan dan lebih besar dari kiri
    {
        sortlagi(simpan, i, kanan);                                                    //rekursif untuk kanan
    }
}


void sortt(int jumlah, int simpan[])
{
    int temp, i, j, minIndex;

    for(i=0; i<(jumlah-1); i++)
    {
        minIndex = i;

        for(j=i+1; j<jumlah; j++)
        {
            if(simpan[minIndex] > simpan[j])
            {
                minIndex = j;
            }
        }
        temp = simpan[i];
        simpan[i] = simpan[minIndex];
        simpan[minIndex] = temp;
    }
}
