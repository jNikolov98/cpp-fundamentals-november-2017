/*
    Write a program that reads an integer number N, then reads a line of N integers, and prints the minimum and
    maximum of those integers.
*/

#include <iostream>

using namespace std;

int main()
{
    int n, minNum, maxNum, num;
    cin >> n;
    cin >> num;
    minNum = maxNum = num;
    for(int i = 2; i <= n; i++) {
        cin >> num;
        if(num > maxNum) maxNum = num;
        if(num < minNum) minNum = num;
    }

    cout << minNum << ' ' << maxNum << endl;
    return 0;
}

