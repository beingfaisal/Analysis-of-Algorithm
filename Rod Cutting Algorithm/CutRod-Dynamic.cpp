#include <iostream>
#include<stdlib.h>
using namespace std;

//Global variable to save the calls
int countCallDynamic = 0;

//Function just to calculate the maximum value
int max(int a, int b)
{
	if (a > b) return a;
	else return b;
}

//The function in Dynamic Approach that runs recursively
int cutRodAUX(int* arr, int* temp, int size)
{
	countCallDynamic++;
	if (temp[size - 1] >= 0) return temp[size - 1];
	int max_revenue;
	if (size <= 0)  max_revenue = 0;
	else
	{
		max_revenue = -1;
		for (int i = 0; i < size; i++)
		{
			max_revenue = max(max_revenue, (arr[i] + cutRodAUX(arr, temp, size - i - 1)));
		}
	}
	temp[size - 1] = max_revenue;
	return max_revenue;
}

/*The Starting Function in Dynamic Approach that
passes an array to store value in recursive function*/
int cutRodAI(int* arr, int size)
{
	int* arrTemp = new int[size];
	for (int i = 0; i < size; i++) arrTemp[i] = -1;
	return cutRodAUX(arr, arrTemp, size);
}



int main()
{
	//this array stores the revenue for certain lenght
	int arr[10] = { 1,5,8,9,10,17,17,20,24,30 };
	int size;
	cout << "Please Enter the value " << endl;
	cin >> size;
	//call to the function
	int revenueDynamic = cutRodAI(arr, size);
	cout << "The Max Revenue from Dynamic Function is  " << revenueDynamic << endl;
	cout << "The Dynamic Function ran " << countCallDynamic << " times" << endl;

}