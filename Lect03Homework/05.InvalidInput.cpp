/*
    Write a program which reads a line containing integer numbers, separated by spaces, and prints their sum. In
    addition to the numbers, each line will contain one or more words (sequences of English letters) – print those words
    on a separate line, separated by spaces, after the sum, in the order they were in the input.
*/

#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

int main()
{
    string line, str;
    int sum = 0;
    queue<string> strings;
    getline(cin, line);
    istringstream stream(line);
    while(stream.good()) {
        int n;
        stream >> n;
        if (stream.fail()) {
            stream.clear();
            stream >> str;
            strings.push(str);
            continue;
        }
        sum += n;
    }
    cout << sum << endl;
    while(!strings.empty()) {
        cout << strings.front() << ' ';
        strings.pop();
    }
    cout << endl;

    return 0;
}
