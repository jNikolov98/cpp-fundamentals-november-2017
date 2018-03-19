/*
    Write a program that reads the integer number N and prints how many trailing zeros are present at the end of the
    number N! (N factorial). Make sure your program works for N up to 50 000. Hint: you don’t need to calculate the
    actual factorial to count the number of trailing zeroes.
*/

#include <iostream>

using namespace std;

int main()
{
    int n, zeros = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        if (i % 5 == 0) {
            int temp = i;
            while(temp % 5 == 0) {
                zeros++;
                temp /= 5;
            }
        }
    }
    cout << zeros << endl;
    return 0;
}

