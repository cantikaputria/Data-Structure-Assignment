/* 
    Saya Cantika Putri Arbiliansyah dengan nim [2103727] mengerjakan 
    Tugas Masa Depan Struktur Data untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

//LIBRARY
#include "header.h"

//PROSES
int main()
{
    //DEKLARASI VARIABEL
    tree T;                                                                                                    //deklarasi tree
    mie parent, child;                                                                                         //struct penampung child dan parent
    char str[201], str2[201];                                                                                  //variabel penampung inputan sementara dari user
    int n, i, j = 0;                                                                                           //inisialisasi variabel
    simpul *find;                                                                                              //pointer untuk pencarian
    int batasJual;                                                                                             //variabel penampung batas jual dari user
    int tempPanjang[100];                                                                                      //variabel penampung sementara panjang string

    //INPUTAN USER
    scanf("%d", &n);                                                                                           //meminta inputan jumlah child dari user

    //PROSES
    for (i = 0; i < n; i++)                                                                                    //perulangan sejumlah n
    {
        //INPUTAN USER
        scanf("%s", str);                                                                                      //meminta inputan string dari user 
        
        //PEMANGGILAN PROSEDUR
        pisah(child, str, child.nama, parent.nama, child.nilaiJual, child.jmlhKom, &jumlahKom2);               //memisahkan string sesuai jenis variabelnya
        child.simpan = jumlahKom2;                                                                             //isi simpan dengan jumlah komponen mie
        
        //INPUTAN USER
        for (j = 0; j < jumlahKom2; j++)                                                                       //perulangan sejumlah komponen mie yang diinput user
        {
            scanf("%s", &str2);                                                                                //meminta inputan isi komponen mie dari user
            strcpy(child.komponen[j], str2);                                                                   //memasukkan inputan ke dalam struct child
        }
        
        //MEMBUAT TREE
        if(strcmp(parent.nama, "null") == 0)                                                                   //jika tidak mempunyai parent
        {
            makeTree(child, &T);                                                                               //maka itu adalah kepala tree dan buatlah treenya
        }
        else                                                                                                   //jika mempunyai parent
        {
            find = findSimpul(parent.nama, T.root);                                                            //cari parentnya
            addChild(child, find);                                                                             //tambahkan child sesuai parentnya
        }
    }

    //INPUTAN USER
    scanf("%d", &batasJual);                                                                                   //meminta inputan batas penjualan dari user

    //MENCARI STRING TERPANJANG
    maxPanjang[0] = strlen(T.root->kontainer.nama) + 4 + strlen(T.root->kontainer.nilaiJual);                  //mengisi indeks ke 0 dengan menghitung panjang string ditambah 4 karakter
    for(i = 0; i < child.simpan; i++)                                                                          //perulangan sejumlah komponen mie
    {
        tempPanjang[0] = strlen(T.root->kontainer.komponen[i]) + 4;                                            //menghitung panjang string komponen
        if (tempPanjang[0] > maxPanjang[0])                                                                    //jika string komponen lebih panjang dari sting atasnya
        {
            maxPanjang[0] = tempPanjang[0];                                                                    //maka nilai maxpanjang diganti dengan panjang string komponen
        }                                                                                                      //jika tidak maka maxpanjangnya tetap seperti tadi
    }
    i = 0;                                                                                                     //inisialisasi
    cariMaxLen(T.root, 0, maxPanjang);                                                                         //panggil prosedur untuk mencari panjang maxsimal string indek selanjutnya

    //OUTPUT PERTAMA
    printTreePreOrder(T.root, &i, maxPanjang);                                                                 //menampilkan isi tree secara pre order
    printf("\n");

    //HAPUS CHILD
    hapus_jual(T.root, batasJual);                                                                             //menghapus child yg nilai jualnya dibawah batas jual

    //OUTPUT KEDUA
    i = 0;                                                                                                      //inisialisasi
    printTreePreOrder(T.root, &i, maxPanjang);                                                                 //menampilkan isi tree secara pre order

    //KEMBALI KE 0
    return 0;                                                                                                  //mengembalikan nilai ke 0
}