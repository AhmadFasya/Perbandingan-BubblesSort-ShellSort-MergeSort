#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <chrono>
#include <time.h>
#include <conio.h>
#include <windows.h>


using namespace std;

void createRandomArray(int arrTampung[], int banyak);
void cetakArray(int arrTampung[], int banyak);
void bubbleSort(int arrTampung[], int banyak);
void Merge(int *a, int low, int high, int mid);
void mergeSort(int *a, int low, int high);
void shellSort(int arrTampung[], int banyakn);

void menuAwal();
void menuUtama();
void menuPilihan(int pilihan, int arrTampung[],int banyak);


#endif // SORT_H_INCLUDED
