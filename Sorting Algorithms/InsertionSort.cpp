#include <iostream>
#include <cstdlib>
#include<ctime>
#include<fstream>
#include<iomanip>
#include<chrono>
using namespace std;

void insertionSort(int* arr, int startIndex, int endIndex)
{
    int element, j;
    for (int i = startIndex; i < endIndex; i++)
    {
        element = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > element)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = element;
    }
}

void randArray(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand();
    }
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void fileOutput(int* arr, int size)
{
    ofstream outFile;
    outFile.open("SortedInsertionSort.csv");
    for (int i = 0; i < size; i++)
    {
        outFile << arr[i] << endl;
    }
    outFile.close();
}
int main()
{

    int size;
    cout << "Enter the number of elments you want\n";
    cin >> size;
    srand(time(0));
    int* arr = new int[size];
    randArray(arr, size);
    auto start = chrono::high_resolution_clock::now();
    insertionSort(arr, 0, size);
    auto end = chrono::high_resolution_clock::now();
    fileOutput(arr, size);
    double time_taken = chrono::duration_cast <chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(9);
    cout << " sec" << endl;
}



