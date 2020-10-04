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
	outFile.open("ArrayForHybrid.csv");
	for (int i = 0; i < size; i++)
	{
		outFile << arr[i] << endl;
	}
	outFile.close();
}
subArrayStruct crossSum(int* arr, int start, int mid, int end);
subArrayStruct maxSubArrayBruteForce(int* arr, int start, int end)
{
	int size = (end - start) + 1;
	subArrayStruct obj;
	if (size > 1)
	{
		int low = -1;
		int high = -1;
		int max = 0;
		for (int i = 0; i < size; i++)
		{
			int sum = 0;
			for (int j = i; j < size; j++)
			{
				sum = sum + arr[j];
				if (sum > max)
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
	else
	{
		obj.high = start;
		obj.low = end;
		obj.totalSum = arr[start];
		return obj;
	}

}
//function to find the subarray of maximum sum
subArrayStruct maxSubArrayhybrid(int* arr, int start, int end)
{
	subArrayStruct result;
	if (((end - start) + 1) > 147)
	{
		int mid;
		mid = floor((start + end) / 2);
		subArrayStruct obj1 = maxSubArrayhybrid(arr, start, mid);
		subArrayStruct obj2 = maxSubArrayhybrid(arr, mid + 1, end);
		subArrayStruct obj3 = crossSum(arr, start, mid, end);
		if ((obj1.totalSum >= obj2.totalSum) && (obj1.totalSum >= obj3.totalSum))
		{
			return obj1;
		}
		else if ((obj2.totalSum >= obj1.totalSum) && (obj2.totalSum >= obj3.totalSum))
		{
			return obj2;
		}
		else if ((obj3.totalSum >= obj1.totalSum) && (obj3.totalSum >= obj2.totalSum))
		{
			return obj3;
		}
	}
	else
	{
		result = maxSubArrayBruteForce(arr, start, end);
		return result;
	}



}
subArrayStruct crossSum(int* arr, int start, int mid, int end)
{
	subArrayStruct obj;
	int leftMax = 0;
	int rightmax = 0;
	int leftSum = 0;
	int rightSum = 0;
	int s = 0;
	int e = 0;
	for (int i = mid; i >= start; i--)
	{
		leftSum = leftSum + arr[i];
		if (leftSum > leftMax)
		{
			leftMax = leftSum;
			s = i;
		}
	}
	for (int i = (mid + 1); i <= end; i++)
	{
		rightSum = rightSum + arr[i];
		if (rightSum > rightmax)
		{
			rightmax = rightSum;
			e = i;
		}
	}
	obj.low = s;
	obj.high = e;
	obj.totalSum = (rightmax + leftMax);
	return obj;
}



int main()
{
	srand(time(0));
	subArrayStruct obj;
	int size;
	cout << "Enter the value plz" << endl;
	cin >> size;
	int* arr = new int[size];

	//created a random array
	randArray(arr, size);
	fileOutput(arr, size);

	//code used for measuring time
	auto start = chrono::high_resolution_clock::now();
	//calling the main function
	obj = maxSubArrayhybrid(arr, 0, size - 1);
	//code used for measuring time
	auto end = chrono::high_resolution_clock::now();
	cout << "The low index is  " << obj.low << endl;
	cout << "The high index is  " << obj.high << endl;
	cout << "The total sum is  " << obj.totalSum << endl;
	//rest of the code for time measurement
	double time_taken = chrono::duration_cast <chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	cout << "Time taken by program is : " << fixed << time_taken << setprecision(9);
	cout << " sec" << endl;
}