/*
    Write a program that enters the coefficients a, b and c of a quadratic equation a*x2 + b*x + c = 0 and
    calculates and prints its real roots. Note that quadratic equations may have 0, 1 or 2 real roots. You can check your
    program against this: https://www.mathsisfun.com/quadratic-equation- solver.html
    The numbers a, b, and c will be entered on a single line from the console, separated by spaces.
    If the quadratic equation has no real roots (e.g. if the Discriminant is less than 0), print &quot;no roots&quot;, if it has one real
    root print it, if it has two roots, print them on a single line, separated by a single space
*/

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
    double a, b, c;
    double d;
    cin >> a >> b >> c;
    d = b * b - 4 * a * c;
    if (d < 0) {
        cout << "no roots" << endl;
    } else if (d == 0) {
        cout << -b / (2 * a) << endl;
    } else {
        cout << (-b + sqrt(d)) / (2 * a) << ' ' << (-b - sqrt(d)) / (2 * a) << endl;
    }
    return 0;
} 

