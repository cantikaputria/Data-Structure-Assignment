/* 
    Saya Cantika Putri Arbiliansyah dengan NIM [2103727] mengerjakan 
    UAS No 1 Struktur Data untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
*/

//LIBRARY
#include "header.h"

//PROSES
int main ()
{
    //MEMBUAT TREE
    tree T;

    //MEMBUAT STRUT
    input data;

    //INPUT DATA
    scanf("%d %d", &data.ortu, &data.pembagi);

    //MEMBUAT TREE
    makeTree(data, &T);

    int hasil;
    if ((data.ortu / data.pembagi ) % 2 == 0)       //JIKA GENAP
    {
        hasil = data.ortu / data.pembagi;
        addRight(data, T.root);
    }
    else if((data.ortu / data.pembagi ) % 2 != 0)   //JIKA GANJIL
    {
        hasil = data.ortu / data.pembagi;
        addLeft(data, T.root);
    }

    printTreeInOrder(T.root);
    return 0;
}