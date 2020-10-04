#include <iostream>
using namespace std;

int* greedyActivitySelector(int* start, int end[],int lengthOfActivities)
{
    int n = lengthOfActivities;
    int* activityArr = new int[n]();
    int k = 0;
    activityArr[0] = 0;
    int activityIndex = 1;
    for (int i = 1; i < n; i++)
    {
        if (start[i] >= end[k])
        {
            activityArr[activityIndex] = i;
            activityIndex += 1;
            k = i;
        }
    }
    return activityArr;

}

int main()
{
    int startingClass[5] = { 800,810,850,1000,1100 };
    int endingClass[5] = { 845,1100,900,1100,1200 };
    int lenArr = sizeof(startingClass) / sizeof(startingClass[0]);
    int* arr = new int[lenArr];
    arr = greedyActivitySelector(startingClass, endingClass,lenArr);
    for (int i = 0; i < 4; i++)
    {

        cout << startingClass[arr[i]] << " -- " << endingClass[arr[i]] << endl;
    }
}

