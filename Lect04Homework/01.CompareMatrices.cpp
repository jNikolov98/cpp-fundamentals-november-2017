/*
    Write a program that reads two integer matrices (2D arrays) from the console and compares them element by
    element. For better code reusability, you could do the comparison in a function, which returns true if they are
    equal and false if not.
    Each matrix definition on the console will contain a line with a positive integer number R – the number of rows in
    the matrix – followed by R lines containing the numbers in the matrix, separated by spaces (each line will have an
    equal amount of numbers.
    The matrices will have at most 10 rows and at most 10 columns.
    Print equal if the matrices match, and not equal if they don’t match.
*/

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<vector<int>> fillMatrix();
bool areEqual(vector<vector<int>>, vector<vector<int>>);

int main()
{
    auto m1 = fillMatrix();
    auto m2 = fillMatrix();
    cout << (areEqual(m1, m2) ? "equal" : "not equal");
    return 0;
}

vector<vector<int>> fillMatrix()
{
    vector<vector<int>> matrix;
    int rows;
    cin >> rows;
    cin.ignore();
    for(int i = 0; i < rows; i++)
    {
        vector<int> row;
        string numbers;
        getline(cin, numbers);
        istringstream stream(numbers);
        int num;
        while(stream >> num) {
            row.push_back(num);
        }
        matrix.push_back(row);
    }
    return matrix;
}

bool areEqual(vector<vector<int>> m1, vector<vector<int>> m2)
{
    if(m1.size() != m2.size()) return false;
    for(vector<vector<int>>::size_type r = 0; r < m1.size(); r++)
    {
        if(m1[r].size() != m2[r].size()) return false;
        for(vector<int>::size_type c = 0; c < m1[r].size(); c++) {
            if(m1[r][c] != m2[r][c]) return false;
        }
    }
    return true;
}
