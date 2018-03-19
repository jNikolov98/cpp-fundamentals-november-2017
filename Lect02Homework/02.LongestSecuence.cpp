/*
    Write a program that finds the longest sequence of equal elements in an integer array and then prints that sequence
    on the console (integers separated by space on a single line). If there is more than one such sequence, print the last
    one. The input array will be entered on two lines – the first line will contain an integer representing the number of
    elements, the second will contain the elements separated by spaces
*/

#include <iostream>

using namespace std;

int main()
{
    int arrSize;
    int maxSteakNum, curSteakTimes = 0, maxSteakTimes = 0;
    cin >> arrSize;
    int arr[arrSize];
    for(int i = 0; i < arrSize; i++) {
        cin >> arr[i];
    }
    for(int i = 1; i < arrSize; i++)
    {
        if(arr[i-1] == arr[i]) {
            curSteakTimes++;
        } else {
            if (curSteakTimes > maxSteakTimes) {
                maxSteakTimes = curSteakTimes;
                maxSteakNum = arr[i - 1];
            }
            curSteakTimes = 0;
        }
    }
    if (maxSteakTimes == 0) {
        maxSteakNum = arr[arrSize - 1];
    }
    for (int i = 0; i <= maxSteakTimes; i++) {
        cout << maxSteakNum << ' ';
    }
    cout << endl;

    return 0;
}
