/*
    Same as Problem 6, but your task here is to find the longest noise in a number (numbers will always be positive
    integers). There are several noises with equal length, print the one that is the first lexicographically. If there are no
    noises, print “no noise”. All symbols in the input will be either letters, digits, punctuation, or signs from of the
    standard ASCII table (no control symbols like newlines or tabs, delete, etc.)
*/

#include <iostream>
#include <sstream>
#include <string>

#include "help.h"

using namespace std;

string getNoise(string);

int main()
{
    string line;
    getline(cin, line);
    istringstream stream(line);
    string longestNoise = "";
    while(stream.good()) {
        stream >> line;
        string noise = getNoise(line);
        if(longestNoise.size() < noise.size()) longestNoise = noise;
        if(longestNoise.size() == noise.size()) longestNoise = min(longestNoise, noise);
    }
    cout << longestNoise << endl;
    return 0;
}

string getNoise(string str)
{
    for(int i = 0; i < str.size(); i++) {
        if(str[i] >= '0' && str[i] <= '9') {
            str.erase(i--, 1);
        }
    }
    return str;
}


