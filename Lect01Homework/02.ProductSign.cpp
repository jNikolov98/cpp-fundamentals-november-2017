/*
    Write a program that shows the sign (+ or -) of the product of three real numbers without calculating it.
    The program should read 3 real numbers from the console (on a single line, separated by spaces) and should print
    the sign of their product (i.e. the sign of the number resulting from the multiplication of the 3 numbers). If the
    product is 0, print +.
*/

#include <iostream>

using namespace std;

int main()
{
    double nums[3];
    int minusSigns = 0;
    cin >> nums[0] >> nums[1] >> nums[2];
    for(int i = 0; i < 3; i++)
        if(nums[i] < 0) minusSigns++;
    if(minusSigns % 2 == 0) cout << '+';
    else cout << '-';
    cout << endl;
    return 0;
}

