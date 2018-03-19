/*
    Write a program that calculates the greatest common divisor (GCD) of given two numbers. Hint: you can use the
    Euclidean algorithm.
    The two integer numbers will be entered on a single line from the console, separated by a single space.
    Find and print their GCD.
*/

#include <iostream>

using namespace std;

int main()
{
    int a, b, temp;
    cin >> a >> b;
    while(true) {
        if (b > a) {
            temp = b;
            b = a;
            a = temp;
        }
        if (b == 0) {
            temp = a;
            break;
        }
        temp = a % b;
        a = temp;
    }
    cout << temp << endl;
    return 0;
}
