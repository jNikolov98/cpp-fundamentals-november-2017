/*
    Write a program that finds the most frequent number in a given sequence of numbers.
     Numbers will be in the range [0…9].
     In case of multiple numbers with the same maximal frequency, print all of them, ordered from smallest to
    largest, separated by spaces
*/

#include <iostream>

using namespace std;

int main()
{
    int arrSize, nums[10] {};
    cin >> arrSize;
    for(int i =0; i < arrSize; i++)
    {
        int num;
        cin >> num;
        nums[num]++;
    }
    int maxFreq = 0;
    for(int num : nums)
    {
        if(num > maxFreq)
        {
            maxFreq = num;
        }
    }
    for(int i = 0; i < 10; i++) {
        if(nums[i] == maxFreq)
        {
            cout << i << ' ';
        }
    }
    cout << endl;
    return 0;
}
