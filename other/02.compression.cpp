#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	string text;
	ostringstream stream;
	getline(cin, text);
	int currentCount = 1;
	char lastChar = text[0];
	for (int i = 1; i < text.size(); i++) {
		if (text[i] == lastChar) {
			currentCount++;
		}
		else {
			if (currentCount == 1) {
				stream << lastChar;
			}
			else if (currentCount == 2) {
				stream << lastChar << lastChar;
			}
			else {
				stream << currentCount << lastChar;
			}
			lastChar = text[i];
			currentCount = 1;
		}
	}
	if (currentCount == 1) {
		stream << lastChar;
	}
	else if (currentCount == 2) {
		stream << lastChar << lastChar;
	}
	else {
		stream << currentCount << lastChar;
	}
	cout << stream.str() << endl;
	system("pause");
	return 0;
}