/*
    Write a program that reads a line from the console containing a mathematical expression. Write a bool function
    that checks whether the brackets in the expression () are placed correctly (assume everything else is correct, i.e.
    you don’t need to check for correct signs, correct variables/numbers, etc.) and returns true if they are correct and
    false if they are not correct. Print correct or incorrect accordingly on the console
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;
    getline(cin, line);
    int openBrackets = 0, closedBrackets = 0;
    for(int i = 0; i < line.size(); i++)
    {
        if(line[i] == '(')
        {
            openBrackets++;
        }
        if(line[i] == ')')
        {
            closedBrackets++;
        }
    }
    if(closedBrackets == openBrackets)
    {
        cout << "correct";
    } else
    {
        cout << "not correct";
    }
    cout << endl;
    return 0;
}
