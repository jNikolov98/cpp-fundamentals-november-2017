/*
    Write a program which reads a sequence of non-negative integer numbers (in the decimal numeral system),
    separated by spaces, and finds the maximum number. The numbers in the input may have “noise” – symbols before,
    after, or between the digits of the number, which are not decimal digits (you need to ignore these when reading the
    numbers). All symbols in the input will be either letters, digits, punctuation, or signs from of the standard ASCII table
    (no control symbols like newlines or tabs, delete, etc.)
*/

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int clearNoise(string);

int main()
{
    string line;
    getline(cin, line);
    istringstream stream(line);
    int maxNum = 0;
    while(stream.good()) {
        stream >> line;
        int num = clearNoise(line);
        maxNum = max(num, maxNum);
    }
    cout << maxNum << endl;
    return 0;
}

int clearNoise(string str)
{
    for(int i = 0; i < str.size(); i++) {
        if(str[i] < '0' || str[i] > '9') {
            str.erase(i--, 1);
        }
    }
    istringstream stream(str);
    int num;
    stream >> num;
    return num;
}


