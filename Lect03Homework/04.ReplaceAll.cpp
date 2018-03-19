/*
    Write a program which is given a line of text, another line with a &quot;find&quot; string and another line with a &quot;replace&quot;
    string. Any part of text which matches the &quot;find&quot; string should be replaced with the &quot;replace&quot; string. Print the
    resulting text on the console.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string searchStr, replaceStr, text;
    getline(cin, text);
    cin >> searchStr >> replaceStr;
    int startFrom = 0;
    while(startFrom < text.size()) {
        startFrom = text.find(searchStr, startFrom);
        text.replace(startFrom, searchStr.size(), replaceStr);
        startFrom += replaceStr.size();
    }
    cout << text << endl;
    return 0;
}
