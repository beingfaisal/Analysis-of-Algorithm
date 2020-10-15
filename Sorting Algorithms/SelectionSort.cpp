# include <iostream>
#include <cstdlib>
#include<ctime>
#include<fstream>
#include<iomanip>
#include<chrono>

using namespace std;

void swapping(int& a, int& b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void selectionSort(int* array, int size) {
    int i, j, imin;
    for (i = 0; i < size - 1; i++) {
        imin = i;   
        for (j = i + 1; j < size; j++)
            if (array[j] < array[imin])
                imin = j;
        
        swap(array[i], array[imin]);
    }
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{

    int size;
    cout << "Enter the number of elements: ";
    cin >> size;
    int* arr = new int [size];
    cout << "Enter elements:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << "Array before Sorting: ";
    printArr(arr, size);
    cout << endl;
    auto start = chrono::high_resolution_clock::now();
    selectionSort(arr, size);
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast <chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Array after Sorting: ";
    printArr(arr, size);
    cout << endl;
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(9);
    cout << " sec" << endl;
}

