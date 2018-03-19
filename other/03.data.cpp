#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;


int main()
{
	map<string, vector<map<string, string>>> db;
	string index;
	cin >> index;
	cin.ignore();
	string entry;
	getline(cin, entry);
	while (entry != "[queries]") {
		istringstream stream(entry);
		string key, value;
		map<string, string> temEntry;
		string indexKey;
		while (stream >> key) {
			if (key == index) {
				stream >> indexKey;
			}
			else {
				stream >> value;
				temEntry[key] = value;
			}
		}
		if (!indexKey.empty()) {
			db[indexKey].push_back(temEntry);
		}
		getline(cin, entry);
	}
	string query;
	getline(cin, query);
	while (query != "end") {
		string qKey, qVal;
		istringstream stream(query);
		stream >> qKey >> qVal;
		auto matchedIndex = db[qKey];
		if (matchedIndex.empty()) {
			cout << "[not found]" << endl;
		}
		else {
			vector<string> printResult;
			for (int i = 0; i < matchedIndex.size(); i++) {
				if (!(matchedIndex[i][qVal].empty())) {
					printResult.push_back(matchedIndex[i][qVal]);
				}
			}
			for (int i = 0; i < printResult.size(); i++) {
				cout << printResult[i];
				if (i + 1 < printResult.size()) {
					cout << " ";
				}
			}
			cout << endl;
		}

		getline(cin, query);
	}
	system("pause");
	return 0;
}