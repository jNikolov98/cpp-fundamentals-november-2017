/*
    Write a program which reads a single line from the console, containing brackets for a mathematical expression (only
    the brackets will appear in the input), and determines whether the brackets in the expression are correct. There are
    3 types of brackets – {}, [] and (). {} can contain {}, [] and () brackets. Square brackets [] can contain [] and
    () brackets. Curved () brackets can contain only () brackets. Said simply, each type of brackets can contain the
    same type of brackets inside, or a “lower” type of brackets (() is lower than [] which is lower than {}). If a bracket
    of one type is opened, it needs to be closed before a bracket of another type is closed.
*/

#include <iostream>
#include <queue>
#include <map>

struct range {
    int from;
    int to;

    renge(int from, int to)
    {
        this->from = from;
        this->to = to;
    }
};

bool checkIfIsHigherClass(char);

using namespace std;

int main()
{
    string line;
    queue<range> q;
    map<char, char> openingBrackets {
        { '{', '}' },
        { '[', ']' },
        { '(', ')' }
    };
    map<char, char> closingBrackets {
        { '}', '{' },
        { ']', '[' },
        { ')', '(' }
    };
    getline(cin, line);
    q.push({0, line.size() - 1});
    while(!q.empty()) {
        range current = q.front();
        q.pop();
        range newRange;
        if(!openingBrackets[line[current.from]]) {
            cout << "invalid" << endl;
            break;
        }
        if(!closingBrackets[line[current.to]]) {
            cout << "invalid" << endl;
            break;
        }
        char open = 0, close = 0;
        int betweenOpenClose = 0;
        for(int i = current.from; i <= current.to; i++) {
            if(open == 0) {
                if(!openingBrackets[line[i]]) {
                    cout << "invalid" << endl;
                    break;
                }
                open = line[i];
                newRange.from = i + 1;
                continue;
            }
            if(open != 0 && close == 0) {
                if(line[i] == closingBrackets[open] && betweenOpenClose == 0) {
                    close = line[i];
                } else {
                    if(checkIfIsHigherClass(line[i])) {
                        cout << "invalid" << endl;
                        break;
                    }
                    if(openingBrackets[line[i]]) {
                        betweenOpenClose++;
                    }
                    if(closingBrackets[line[i]]) {
                        betweenOpenClose--;
                    }
                    if(betweenOpenClose < 0) {
                        cout << "invalid" << endl;
                        break;
                    }
                }
            }
            if (close == 0) {
                open = 0;
                close = 0;
                newRange.to = i - 1;
                if(newRange.from != newRange.to) {
                    q.push(newRange);
                }
                range newRange;
            }
        }
    }
    cout << "valid" << endl;
    return 0;

}

bool checkIfIsHigherClass(char c)
{

}
