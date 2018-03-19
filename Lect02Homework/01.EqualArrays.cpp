/*
    Write a program that reads two integer arrays from the console and compares them element by element. For better
    code reusability, you could do the comparison in a
    bool areEqual(int arr1[], int length1, int arr2[], int length2)
    function, which returns true if they are equal and false if not.
    Each array will be defined by two lines on the console – the first containing a number representing the length of the
    array, and the second containing the numbers in the array, separated by spaces.
    Print equal if the arrays match, and not equal if the arrays don’t match.
*/

#include <iostream>

using namespace std;

bool areEqual(int arr1[], int size1, int arr2[], int size2);
void arrFill(int arr[], int arrSize);

int main()
{
    int size1, size2;
    cin >> size1;
    int arr1[size1];
    arrFill(arr1, size1);
    cin >> size2;
    int arr2[size2];
    arrFill(arr2, size2);
    bool res = areEqual(arr1, size1, arr2, size2);
    cout << ((res == true) ? "equal" : "not equal");
    return 0;
}

void arrFill(int arr[], int arrSize)
{
    for(int i = 0; i < arrSize; i++)
    {
        cin >> arr[i];
    }
}

bool areEqual(int arr1[], int size1, int arr2[], int size2)
{
    if (size1 != size2) {
        return false;
    }
    for(int i =0; i < size1; i++)
    {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}
