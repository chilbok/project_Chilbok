#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> strV;
vector<bool> checkV(26, false);
vector<int> charV(26, -1);
vector<int> charVBackup(26, -1);

int N;
int check = 0;

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string tmpStr;
		cin >> tmpStr;
		strV.push_back(tmpStr);
	}
	for (int i = 0; i < strV.size(); i++) {
		for (int j = 0; j < strV[i].size(); j++) {
			checkV[strV[i].at(j) - 'A'] = true;
		}
	}
	int tmp = 0;
	for (int i = 0; i < checkV.size(); i++) {
		if (checkV[i] == true) tmp++;
	}
	check = tmp;
	return;
}

int makeInt(string s) {
	int result = 0;
	for (int i = 0; i < s.length(); i++) {
		result = result * 10;
		result += charV[s.at(i)-'A'];
	}
	return result;
}

void run() {
	int max = 0;
	init();
	vector<int> nums;
	for (int i = 0; i < check; i++) {
		nums.push_back(9 - i);
	}
	do {
		int tmpMax = 0;
		charV = charVBackup;
		vector<int> tmpNumV = nums;
		for (int i = 0; i < 26; i++) {
			if (checkV[i] == true) {
				charV[i] = tmpNumV[tmpNumV.size() - 1];
				tmpNumV.pop_back();
			}
		}
		for (int i = 0; i < strV.size(); i++) {
			tmpMax += makeInt(strV[i]);
		}
		if (tmpMax > max) {
			max = tmpMax;
		}
	} while (prev_permutation(nums.begin(),nums.end()));
	cout << max << endl;
	return;
}

int main() {
	run();
	return 0;
}