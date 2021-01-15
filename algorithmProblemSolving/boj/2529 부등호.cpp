#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<char> sign;
vector<string> resultV;

int K;

string makeString(vector<int> v) {
	string result = "";
	for (int i = 0; i < v.size(); i++) {
		result = result + to_string(v[i]);
	}
	return result;
}

int makeInt(vector<int> v) {
	int result = 0;
	for (int i = 0; i < v.size(); i++) {
		result = result * 10;
		result = result + v[i];
	}
	return result;
}

bool check(vector<int> v) {
	bool result = true;
	for (int i = 0; i < sign.size(); i++) {
		if (sign[i] == '<') {
			if (v[i] >= v[i + 1]) {
				return false;
			}
		}
		else if (sign[i] == '>') {
			if (v[i] <= v[i + 1]) {
				return false;
			}
		}
	}
	return result;
}

void init() {
	cin >> K;
	for (int i = 0; i < K; i++) {
		char inputChar;
		cin >> inputChar;
		sign.push_back(inputChar);
	}
	return;
}

void run() {
	init();
	vector<int> numV;
	vector<int> findV;
	vector<int> selectNumV;
	for (int i = 0; i < 10; i++) {
		numV.push_back(i);
		findV.push_back(1);
	}
	for (int i = 0; i < K+1; i++) {
		findV[i] = 0;
	}
	do {
		selectNumV.clear();
		for (int i = 0; i < findV.size(); i++) {
			if (findV[i] == 0) {
				selectNumV.push_back(numV[i]);
			}
		}
		do {
			if (check(selectNumV)) {
				resultV.push_back(makeString(selectNumV));
			}
		} while (next_permutation(selectNumV.begin(),selectNumV.end()));
	} while (next_permutation(findV.begin(), findV.end()));
	sort(resultV.begin(), resultV.end());
	cout << resultV[resultV.size() - 1] << endl << resultV[0] << endl ;
	return;
}

int main() {
	run();
	return 0;
}