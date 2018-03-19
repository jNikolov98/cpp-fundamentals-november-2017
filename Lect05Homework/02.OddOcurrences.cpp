/*
    Write a program that extracts from a given sequence of words all elements that appear in it an odd number of times
    (case-insensitive).
         Words are given in a single line, space separated.
         Print the result elements in lowercase, in their order of appearance.
*/

#include <iostream>
#include <sstream>
#include <ctype.h>
#include <map>
#include <queue>;

using namespace std;

int main()
{
    string line;
    getline(cin, line);
    int i = 0;
    while(line[i])
    {
        line[i] = tolower(line[i]);
        i++;
    }
    stringstream stream;
    stream << line;
    string word;
    map<string, int> ocurrances;
    queue<string> order;
    while(stream >> word)
    {
        if(!ocurrances[word]++)
        {
            order.push(word);
        }
    }
    while(!order.empty())
    {
        string word = order.front();
        order.pop();
        if(! (ocurrances[word] % 2))
        {
            continue;
        }
        cout << word;
        if(!order.empty())
        {
            cout << ", ";
        }
    }

    return 0;
}
