/*
    You are given a list of words in one line. Randomize their order and print each word at a separate line.
    Also, to implement this task you should write a class that is initialized with a list (or array or vector) of words
    and which has a getRandomized() method which returns the words randomized. Each call to getRandomized()
    should return a different ordering of the words.
*/

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <sstream>

using namespace std;

class WordsRandomizer {
private:
    vector<string> words;
public:
    WordsRandomizer(vector<string> words) :
        words(words)
    {}

    string randomize() {
        ostringstream stream;
        auto words = this->words;
        while(!words.empty()){
            auto index = rand() % words.size();
            stream << words[index] << " ";
            words.erase(words.begin() + index);

        }
        return stream.str();
    }
};

int main()
{
    string line;
    getline(cin, line);
    istringstream stream(line);
    vector<string> words;
    while(stream >> line) {
        words.push_back(line);
    }
    WordsRandomizer randomizer(words);
    for(int i = 0; i < 100; i++) {
        cout << randomizer.randomize();
        cout << endl << endl;
    }
}
