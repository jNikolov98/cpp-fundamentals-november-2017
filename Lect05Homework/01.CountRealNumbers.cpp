/*
    Read a list of real numbers and print them in ascending order along with their number of occurrences.
*/

#include <iostream>
#include <map>
#include <sstream>

using namespace std;

int main()
{
    stringstream stream;
    string line;
    getline(cin, line);
    stream << line;
    double num;
    map<double, int> nums;
    while(stream >> num)
    {
        nums[num]++;
    }
    for(auto i = nums.begin(); i != nums.end(); i++)
    {
        cout << i->first << "->" << i->second << endl;
    }
    return 0;
}
