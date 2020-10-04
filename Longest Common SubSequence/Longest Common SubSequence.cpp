#include <iostream>
#include<string>
using namespace std;

struct input
{
    int rows, cols = 0;
    char** arrB;
    int** arrC;
    input(int a, int b)
    {
        rows = a;
        cols = b;
        arrB = new char* [a];
        for (int i = 0; i < a; i++)
        {
            arrB[i] = new char[b];
        }
        arrC = new int* [a+1];
        for (int i = 0; i <= a; i++)
        {
            arrC[i] = new int[b+1];
        }
    }

};
input LCS(string a, string b)
{
    const int lengthOfA = a.length();
    const int lengthOfB = b.length();

    input newArray(lengthOfA, lengthOfB);
    for (int i = 0; i <= lengthOfA; i++)
    {
        newArray.arrC[i][0] = 0;
    }
    for (int i = 0; i <= lengthOfB; i++)
    {
        newArray.arrC[0][i] = 0;
    }
    for (int i = 1; i <= lengthOfA; i++)
    {
        for (int j = 1; j <= lengthOfB; j++)
        {
            if (a[i-1] == b[j-1])
            {
                newArray.arrC[i][j] = newArray.arrC[i - 1][j - 1] + 1;

                newArray.arrB[i-1][j-1] = 't';
            }
            else if (newArray.arrC[i - 1][j] >= newArray.arrC[i][j - 1])
            {
                newArray.arrC[i][j] = newArray.arrC[i - 1][j];
                newArray.arrB[i-1][j-1] = 'u';
            }
            else
            {
                newArray.arrC[i][j] = newArray.arrC[i][j - 1];
                newArray.arrB[i-1][j-1] = 'l';
            }
        }
    }
    return newArray;
}
void printLCS(char **arr, string X, int row, int col)
{
    if (row < 0 || col < 0)
    {
        return;
    }
    if (arr[row][col] == 't')
    {
        printLCS(arr, X, row - 1, col - 1);
        cout << X[row];
    }
    else if (arr[row][col] == 'u')
    {
        printLCS(arr, X, row - 1, col);
    }
    else {
        printLCS(arr, X, row, col-1);
    }
}


int main()
{
    string a = "ACBDEF";
    string b = "BACEDF";
    input outArray = LCS(a, b);
    printLCS(outArray.arrB, a, a.length()-1, b.length()-1);
    
    //Deallocating memory
    
    for (int i = 0; i < a.length(); i++)
    {
        delete[] outArray.arrB[i];
    }
    delete[] outArray.arrB;

    for (int j = 0; j <= a.length(); j++)
    {
        delete[] outArray.arrC[j];
    }
    delete[] outArray.arrC;
}