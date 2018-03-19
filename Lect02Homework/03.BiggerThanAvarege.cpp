/*
    Write a program that read an array of integer numbers from the console and prints all numbers which are larger
    than or equal to the mathematical average of the numbers in the array. The output should be printed on a single
    line, separating the output number by spaces. The output numbers should be in the same order as they were in the
    input.
    The input array will be entered on two lines – the first line will contain an integer representing the number of
    elements, the second will contain the elements separated by spaces.
*/

#include <iostream>

using namespace std;

int main()
{
    int arrSize, sum = 0, avarage;
    cin >> arrSize;
    int arr[arrSize];
    for(int i = 0; i < arrSize; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    avarage = sum / arrSize;
    for(int num : arr)
    {
        if(num >= avarage)
        {
            cout << num << ' ';
        }
    }
    cout << endl;
}
