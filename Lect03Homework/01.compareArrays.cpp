/*
    Write a program that reads two integer arrays from the console and compares them element by element. For better
    code reusability, you could do the comparison in a function, which returns true if they are equal and false if not.
    Each array will be defined by a single line on the console, containing the numbers in the array, separated by spaces.
    Print equal if the arrays match, and not equal if the arrays don’t match.
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> v;

v jugArray()
{
    string line;
    v vect;
    getline(cin, line);
    istringstream s(line);
    int num;
    while(s >> num)
    {
        vect.push_back(num);
    }
    return vect;
}

bool areEqual(v vect1, v vect2)
{
    if(vect1.size() != vect1.size())
    {
        return false;
    }
    for(int i = 0; i < vect1.size(); i++)
    {
        if(vect1[i] != vect2[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    auto vect1 = jugArray();
    auto vect2 = jugArray();
    if(areEqual(vect1, vect2))
    {
        cout << "equal";
    } else
    {
        cout << "not equal";
    }
    cout << endl;

    return 0;
}
