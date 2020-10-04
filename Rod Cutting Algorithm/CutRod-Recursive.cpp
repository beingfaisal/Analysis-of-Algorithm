#include <iostream>
#include<stdlib.h>
using namespace std;

//Global variables to save the calls
int countCallRecursive = 0;
int countCallDynamic = 0;
//function to calaculate the maximum one
int max(int a, int b)
{
	if (a > b) return a;
	else return b;
}
//Recursive Function to calculate the max revenue
int cut_rod(int* arr, int size)
{
	countCallRecursive++;
	if (size <= 0)
	{
		return 0;
	}
	int max_revenue = 0;
	for (int i = 0; i < size; i++)
	{
		max_revenue = max(max_revenue, (arr[i] + cut_rod(arr, size - i - 1)));
	}

	return max_revenue;
}

int main()
{
	int arr[10] = { 1,5,8,9,10,17,17,20,24,30 };
	int size;
	cout << "Please Enter the value " << endl;
	cin >> size;
	int revenue = cut_rod(arr, size);
	cout << "The Max Revenue from Recursive Function is  " << revenue << endl;
	cout << "The Recursive Function Ran  " << countCallRecursive << " times" << endl;


}