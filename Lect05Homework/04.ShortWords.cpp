/*
    Read a text, extract its words (separated by spaces) find all short words (less than 5 characters) and print them
    alphabetically, in lowercase, separate by a single comma and a single space
     Use case-insensitive matching.
     Remove duplicated words.
*/

#include <iostream>
#include <sstream>
#include <set>

using namespace std;

int main()
{
    string line, word;
    stringstream stream;
    set<string> words;
    getline(cin, line);
    int i = 0;
    while(line[i])
    {
        line[i] = tolower(line[i]);
        i++;
    }
    stream << line;
    while(stream >> word)
    {
        if(word.size() < 5)
        {
            words.insert(word);
        }
    }
    auto j = words.begin();
    while(true)
    {
            cout << *j;
        j++;
        if(j != words.end())
        {
            cout << ", ";
        }
        if(j == words.end())
        {
            break;
        }
    }
    return 0;
}


