#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using namespace std;

class Message {
public:
	string text;
private:
	bool reported = false;
	bool complete = false;
	int priority = -1;
public:
	Message(string text) : text(text) {
		bool comp = true;
		for (int i = 0; i < text.size(); i++) {
			if (text[i] == '?') {
				comp = false;
				break;
			}
		}
		if (comp) {
			this->complete = true;
			this->setPriority();
		}
	}
	Message() {}

	void appNewData(string newData) {
		for (int i = 0; i < this->text.size(); i++) {
			if (this->text[i] == '?') {
				this->text[i] = newData[i];
			}
		}
		for (int i = 0; i < this->text.size(); i++) {
			if (this->text[i] == '?') {
				return;
			}
		}
		this->setPriority();
		this->complete = true;
	}

	string report() {
		this->reported = true;
		return this->text;
	}

	bool isReported() {
		return this->reported;
	}

	bool isComplete() {
		return this->complete;
	}

	bool isEmpty() {
		return this->text.empty();
	}

	int getPriority() {
		return this->priority;
	}

private:
	void setPriority() {
		stringstream stream;
		for (int i = 0; i < this->text.size(); i++) {
			if (this->text[i] >= '0' && this->text[i] <= '9') {
				stream << this->text[i];
				this->text.erase(i, 1);
				i--;
			}
		}
		stream >> this->priority;
	}
};

int main()
{
	map<double, Message> messageBag;
	string line;
	getline(cin, line);
	while (line != "end") {
		if (line != "report") {
			istringstream stream(line);
			double freq;
			string messageEntry;
			stream >> freq >> messageEntry;
			if (messageBag[freq].isEmpty()) {
				messageBag[freq] = Message(messageEntry);
			}
			else {
				messageBag[freq].appNewData(messageEntry);
			}
		}
		else {
			double maxPFreq;
			int maxP = 0;
			for (auto i = messageBag.begin(); i != messageBag.end(); i++) {
				if (i->second.isComplete() && !(i->second.isReported()) && i->second.getPriority() > maxP) {
					maxP = i->second.getPriority();
					maxPFreq = i->first;
				}
			}
			if (maxP == 0) {
				cout << "[no new messages]" << endl;
			}
			else {
				cout << messageBag[maxPFreq].report() << endl;
			}
		}
		getline(cin, line);
	}
	system("pause");
	return 0;
}