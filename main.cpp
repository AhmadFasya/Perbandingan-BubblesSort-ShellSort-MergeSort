#include "sort.h"

int main()
{
    int banyak;
    menuAwal();
    cin >> banyak;
    int arrTampung[banyak];
    createRandomArray(arrTampung,banyak);
    system("PAUSE");
    system("CLS");

    int pilihan;
    do{
        menuUtama();
        cin >> pilihan;
        menuPilihan(pilihan,arrTampung,banyak);
        system("PAUSE");
        system("CLS");
    }while (pilihan!=0);

    system("PAUSE");
    return 0;
}
