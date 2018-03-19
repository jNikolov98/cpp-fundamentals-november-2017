/*
    Write a program which changes each word in a text to start with a capital letter (don’t bother with the exact title-
    case rules about not capitalizing things like in, from, etc.). Assume the first letter of a word is an English alphabetical
    symbol preceded by a non-alphabetical symbol (so in “we will-- rock you”, “we”, “will”, “rock” and “you” are all
    considered words which need to be capitalized).
*/

#include <iostream>

using namespace std;

bool isLetter(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

char toUpper(char c) {
    if(c >= 'a') return c += 'A' - 'a';
    return c;
}

int main() {
    string line;
    getline(cin, line);
    for(int i = 0; i < line.size(); i++) {
        if(i > 0 && !isLetter(line[i - 1])) line[i] = toUpper(line[i]);
    }
    cout << line;
    return 0;
}
