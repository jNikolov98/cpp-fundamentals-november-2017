/*
    Write a program which finds the two closest (by value) integer numbers in an array and prints the absolute
    difference between them.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int vSize, minDif;
    vector<int> nums;
    cin >> vSize;
    for(int i = 0; i < vSize; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    minDif = abs(nums[0] - nums[1]);
    for(int i = 1; i < nums.size() - 1; i++)
    {
        if(abs(nums[i] - nums[i + 1]) < minDif)
        {
            minDif = abs(nums[i] - nums[i+1]);
        }
    }
    cout << minDif;
    return 0;
}
