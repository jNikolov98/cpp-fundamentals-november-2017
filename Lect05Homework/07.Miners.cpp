/*
	You are given a sequence of strings, each on a new line. Every odd line on the console is representing a resource
	(e.g. Gold, Silver, Copper, and so on), and every even – quantity. Your task is to collect the resources and print them
	each on a new line.
	Print the resources and their quantities in format:
	{resource} –&gt; {quantity}
	The quantities inputs will be in the range [1 … 2 000]
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
	string resource;
	int quantity;
	unordered_map<string, int> resources;
	cin >> resource;
	while (resource != "stop")
	{
		cin >> quantity;
		resources[resource] += quantity;
		cin >> resource;
	}
	for (auto i = resources.begin(); i != resources.end(); i++)
	{
		cout << i->first << "->" << i->second << endl;
	}
	system("pause");
	return 0;
}