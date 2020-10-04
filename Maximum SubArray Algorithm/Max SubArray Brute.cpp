#include<iostream>
#include <cstdlib>
#include<ctime>
#include<chrono>
#include<fstream>
#include<iomanip>
using namespace std;

	//struct for storing lowest, highest and their differnece 
	struct subArrayStruct
	{
		int low;
		int high;
		int totalSum;
	};
	//function that generates random numbers for array
	void randArray(int* arr, int size)
	{
		int variable;
		for (int i = 0; i < size; i++)
		{
			variable = rand() % 1000000;
			if ((variable % 2) != 0)
			{
				variable *= -1;
			}
			arr[i] = variable;
		}
	}

	void fileOutput(int* arr, int size)
	{
		ofstream outFile;
		outFile.open("ArrayForBruteForce.csv");
		for (int i = 0; i < size; i++)
		{
			outFile << arr[i] << endl;
		}
		outFile.close();
	}
	//Desired function to find the differnece of lowest and highest value
	subArrayStruct maxSubArrayBruteForce(int* arr, int size)
	{
		int low = -1;
		int high = -1;
		int max = 0;
		subArrayStruct obj;
		for (int i = 0; i < size; i++)
		{
			int sum = 0;
			for (int j = i; j < size; j++)
			{
				sum = sum + arr[j];
				if (sum >= max)
				{
					max = sum;
					high = j;
					low = i;
				}
			}
		}
		obj.high = high;
		obj.low = low;
		obj.totalSum = max;
		return  obj;
	}


	int main()
	{
		srand(time(0));
		subArrayStruct obj;
		int size;
		cout << "Enter the size plz" << endl;
		cin >> size;
		int *arr = new int[size];
		//created a random array
		randArray(arr, size);
		fileOutput(arr, size);

		//code used for measuring time
		auto start = chrono::high_resolution_clock::now();
		//calling the main function
		obj = maxSubArrayBruteForce(arr, size);
		//code used for measuring time
		auto end = chrono::high_resolution_clock::now();
		double time_taken = chrono::duration_cast <chrono::nanoseconds>(end - start).count();
		time_taken *= 1e-9;

		cout << "The low index is  " << obj.low << endl;
		cout << "The high index is  " << obj.high << endl;
		cout << "The total sum is  " << obj.totalSum << endl;

		//rest of the code for time measurement

		cout << "Time taken by program is : " << fixed << time_taken << setprecision(9);
		cout << " sec" << endl;
	};