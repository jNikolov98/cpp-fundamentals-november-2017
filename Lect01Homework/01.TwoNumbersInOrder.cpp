// Write a program that reads two integers from the console and prints them in increasing order

#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if (a > b) cout << b << ' ' << a << endl;
    else cout << a << ' ' << b << endl;
    return 0;
}
