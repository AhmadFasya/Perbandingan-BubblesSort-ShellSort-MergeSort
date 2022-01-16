#include "sort.h"

void createRandomArray(int arrTampung[], int banyak){
    for (int i=0; i<banyak;i++){
        arrTampung[i] = rand()%10000+1;
    }
}

void cetakArray(int arrTampung[], int banyak){
    cout << "\n\nArray Anda adalah : " << endl;
    for (int i=0; i<banyak; i++){
        cout << arrTampung[i] << endl;
    }
}

void bubbleSort(int arrTampung[], int banyak){
    for (int i = banyak-1; i>=0; i--){
        for (int j=1; j<=i;j++){
            if (arrTampung[j-1] > arrTampung[j]){
                int temp = arrTampung[j-1];
                arrTampung[j-1] = arrTampung[j];
                arrTampung[j] = temp;
            }
        }
    }
}

void shellSort(int arrTampung[], int banyak){
	for (int gap = banyak / 2; gap > 0; gap /= 2) {	// Decreasing gap with every iteration
		for (int i = gap; i < banyak; i++) {
			int temp = i;
			while (temp - gap >= 0 && arrTampung[temp - gap] > arrTampung[temp]) {	// Comparing values "gap" distance apart
				swap(arrTampung[temp - gap], arrTampung[temp]);
				temp -= gap;
			}
		}
	}
}

void Merge(int *a, int low, int high, int mid){
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;

	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}



	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}


void mergeSort(int *a, int low, int high){
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		mergeSort(a, low, mid);
		mergeSort(a, mid+1, high);
		Merge(a, low, high, mid);
	}
}

void menuAwal(){
    cout << "=============== BUBBLE SORT, MERGE SORT, SHELL SORT ===============" << endl;
    cout << " Masukkan Banyak Indeks Array yang diinginkan (n) :  ";
}

void menuUtama(){
    cout << "   Kelompok 7 - Shell Sort dan Merge Sort" << endl;
    cout << " " << endl;
    cout << "===========BUBBLE SORT, MERGE SORT, SHELL SORT===========" << endl;
    cout << "|   Pilihan Menu yang tersedia :                        |" << endl;
    cout << "|   1. Tampilkan Array                                  |" << endl;
    cout << "|   2. Bubble Sort                                      |" << endl;
    cout << "|   3. Merge Sort                                       |" << endl;
    cout << "|   4. Shell Sort                                       |" << endl;
    cout << "|   5. Reset isi Array                                  |" << endl;
    cout << "|   0. Keluar dari program                              |" << endl;
    cout << "=========================================================" << endl;
    cout << "    Pilihan Anda : ";
}

void menuPilihan(int pilihan, int arrTampung[],int banyak){
    switch (pilihan){
        case 1:
            cetakArray(arrTampung,banyak);
            break;
        case 2:{
            auto t1 = GetTickCount();
            bubbleSort(arrTampung,banyak);
            auto t2=GetTickCount();
            cout << endl << "Waktu eksekusi Bubble Sort dengan "<<banyak <<" angka acak = " << (int)(t2 - t1) << " ms";
            cout<<endl;
            }break;
        case 3:{
            auto t3 = chrono::high_resolution_clock::now();
            mergeSort(arrTampung,0,banyak-1);
            auto t4 = chrono::high_resolution_clock::now();
            auto duration2 = chrono::duration_cast<chrono::milliseconds>(t4-t3).count();
            cout << "Waktu eksekusi Merge sort dengan " << banyak <<" angka acak = " << duration2 << " ms" << endl;
            cout<<endl;
            }break;
        case 4:{
            double t5 = GetTickCount();
            shellSort(arrTampung,banyak);
            double t6=GetTickCount();
            cout << endl << "Waktu eksekusi Shell Sort dengan "<<banyak <<" angka acak = " << (double)(t6 - t5) << " ms";
            cout<<endl;
            }break;
        case 5:
            createRandomArray(arrTampung,banyak);
            break;
        case 0:
            break;
        default:
            cout << "Masukkan angka yang valid" << endl;
            break;
    }
}
