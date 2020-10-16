#include <iostream>
#include <cstdlib>
#include<ctime>
#include<fstream>
#include<chrono>
#include<math.h>
#include<iomanip>
using namespace std;
//Comment

void randArray(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand();
    }
}

void mergeSort(int* arr, int start, int end)
{
    void merge(int* arr, int start, int mid, int end);
    if (start < end)
    {
        int mid = floor((start + end) / 2);
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void merge(int* arr, int start, int mid, int end)
{
    const int n1 = mid - start + 1;
    const int n2 = end - mid;

    int* leftArr = new int[n1 + 1];
    int* rightArr = new int[n2 + 1];
    int i, j, k;
    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = arr[start + i];
    }
    for (int i = 0; i < n2; i++)
    {
        rightArr[i] = arr[mid + 1 + i];
    }
    i = 0, j = 0;
    leftArr[n1] = 1000001;
    rightArr[n2] = 1000001;
    for (int k = start; k <= end; k++)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }

    }

    delete[] leftArr;
    delete[] rightArr;
}
void fileOutput(int* arr, int size)
{
    ofstream outFile;
    outFile.open("SortedMergeSort.csv");
    for (int i = 0; i < size; i++)
    {
        outFile << arr[i] << endl;

    }
    outFile.close();
}

int main()
{
    srand(time(NULL));
    cout << "Enter the size" << endl;
    int size;
    cin >> size;
    int* arr = new int[size];
    randArray(arr, size);
    auto start = chrono::high_resolution_clock::now();
    mergeSort(arr, 0, size - 1);
    auto end = chrono::high_resolution_clock::now();
    fileOutput(arr, size);
    double time_taken = chrono::duration_cast <chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(9);
    cout << " sec" << endl;
}