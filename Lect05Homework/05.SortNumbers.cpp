/*
    Read a list of decimal numbers and sort them in increasing order. Print the output as shown in the examples below.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
    vector<double> nums;
    string line;
    stringstream stream;
    getline(cin, line);
    double num;
    stream << line;
    while(stream >> num)
    {
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
        if(i + 1 != nums.size())
        {
            cout << " <= ";
        }
    }
    return 0;
}
