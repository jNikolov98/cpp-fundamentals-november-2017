/*
    Read a list of real numbers and print largest 3 of them. If less than 3 numbers exit, print all of them.
*/

#include <iostream>
#include <set>
#include <sstream>

using namespace std;

int main()
{
    string line;
    getline(cin, line);
    stringstream stream;
    stream << line;
    double num;
    set<double> nums;
    while(stream >> num)
    {
        nums.insert(num);
    }
    int lastThrere = 0;
    auto i = nums.end();
    i--;
    while(true)
    {
        if(lastThrere < 3) cout << *i << " ";
        i--;
        lastThrere++;
        if(i == nums.begin()) break;
    }

    return 0;
}
