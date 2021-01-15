#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
int main() {
	int size_ = 0;
	char tmp;
	char* word = new char[501];
	vector<string> charVec;
	while(true) {
		cin.getline(word,501);
		if (word[0] == 'E'&&word[1] == 'N'&&word[2] == 'D'&&word[3] == NULL) break;
		size_ = strlen(word);
		for (int i = 0; i < size_/2; i++) {
			tmp = word[i];
			word[i] = word[size_ - i - 1];
			word[size_ - 1 - i] = tmp;
		}
		charVec.push_back(word);
	}
	int size = charVec.size();
	for (int i = 0; i < size; i++) {
		cout << charVec.at(i) << endl;
	}
	delete[] word;
	word = NULL;
	return 0;
}