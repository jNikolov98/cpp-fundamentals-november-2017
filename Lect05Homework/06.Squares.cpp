/*
	Read a list of integers and extract all square numbers from it and print them in descending order. A square number
	is an integer which is the square of any integer. For example, 1, 4, 9, 16 are square numbers.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <set>

using namespace std;

int main()
{
	string line;
	getline(cin, line);
	istringstream stream(line);
	int num;
	multiset<int> result;
	while (stream >> num)
	{
		int res = sqrt(num);
		if (res * res == num)
		{
			result.insert(num);
		}
	}
	for (auto i = result.rbegin(); i != result.rend(); i++)
	{
		cout << (*i) << " ";
	}
	cout << endl;
	system("pause");
}