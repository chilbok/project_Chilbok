#include <iostream>
#include <string>
using namespace std;

int main() {
	string str = "";
	string subStr = "";
	int size = 0, iter = 0;
	getline(cin, str);
	size = str.length();
	for (int i = 0; i < (size / 10); i++) {
		subStr = str.substr(iter, 10);
		iter += 10;
		cout << subStr << endl;
	}
	subStr = str.substr(iter, size - iter);
	cout << subStr;
	str.clear();
	subStr.clear();
	return 0;
}