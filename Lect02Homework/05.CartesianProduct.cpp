/*
    Write a program which reads an array from the console and prints the product of each of its elements with all
    elements. E.g. for the array {1, 7, 3}, the result would be {1 * 1, 1 * 7, 1 * 3, 7 * 1, 7 * 7, 7 * 3, 3 * 1, 3 * 7, 3 * 3},
    which gives us the array {1, 7, 3, 7, 49, 21, 3, 21, 9}, so for the input
    1 7 3
    the program should print
    1 7 3 7 49 21 3 21 9
*/

#include <iostream>

using namespace std;

int main()
{
    int arrSize;
    cin >> arrSize;
    int arr[arrSize];
    for(int i = 0; i < arrSize; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < arrSize; i++)
    {
        for(int j = 0; j < arrSize; j++)
        {
            cout << arr[i]*arr[j] << ' ';
        }
    }
    cout << endl;
    return 0;
}
