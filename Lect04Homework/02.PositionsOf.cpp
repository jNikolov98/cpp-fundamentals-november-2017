/*
    Write a program that reads a matrix of integers from the console, then a number, and prints all the positions at
    which that number appears in the matrix.
    The matrix definition on the console will contain a line with two positive integer numbers R and C – the number of
    rows and columns in the matrix – followed by R lines, each containing C numbers (separated by spaces),
    representing each row of the matrix.
    The number you will need to find the positions of will be entered on a single line, after the matrix.
    You should print each position on a single line – first print the row, then the column at which the number appears.
    If the number does not appear in the matrix, print not found
*/

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<vector<int>> fillMatrix();

int main()
{
    int r, c, needle;
    bool found = false;
    cin >> r >> c;
    int m[r][c];
    for(int cr = 0; cr < r; cr++) {
        for(int cc = 0; cc < c; cc++) {
            cin >> m[cr][cc];
        }
    }
    cin >> needle;
    for(int cr = 0; cr < r; cr++) {
        for(int cc = 0; cc < c; cc++) {
            if(m[cr][cc] == needle) {
                cout << cr << ' ' << cc << endl;
                found = true;
            }
        }
    }
    if(!found) cout << "no matches";
    return 0;
}
