#include <iostream>
using namespace std;

int main() {
	int count, answer = 0;
	cin >> count;
	char* num = new char[count];
	cin.clear();
	cin.ignore();
	cin.getline(num, count+1);
	for (int i = 0; i < count; i++) {
		answer = answer + num[i] - 48;
	}
	cout << answer << endl;
	delete[] num;
	num = NULL;
	return 0;
}