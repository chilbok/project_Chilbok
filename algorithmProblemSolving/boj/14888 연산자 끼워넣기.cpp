#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> numV;
vector<int> operV; // 0 : +, 1 : -, 2 : *, 3 : /

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int min(int a, int b) {
	if (a < b) return a;
	else return b;
}

void initV() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		numV.push_back(tmp);
	}
	for (int i = 0; i < 4; i++) {
		int tmp;
		cin >> tmp;
		for (int j = 0; j < tmp; j++) {
			operV.push_back(i);
		}
	}
	return;
}

int calcul(vector<int> num, vector<int> oper) {
	int res = num[0];
	for (int i = 0; i < oper.size(); i++) {
		switch (oper[i]) {
		case 0:
			res = res + num[i + 1];
			break;
		case 1:
			res = res - num[i + 1];
			break;
		case 2:
			res = res * num[i + 1];
			break;
		case 3:
			res = res / num[i + 1];
			break;
		}
	}
	return res;
}

pair<int,int> findMax() {
	int maximum = -1000000001;
	int minimum = 1000000001;
	do {
		int tmp = calcul(numV, operV);
		maximum = max(maximum, tmp);
		minimum = min(minimum, tmp);
	} while (next_permutation(operV.begin(), operV.end()));
	return make_pair(maximum, minimum);
}

void run() {
	initV();
	pair<int, int> result = findMax();
	cout << result.first << endl << result.second << endl;
	return;
}

int main() {
	run();
	return 0;
}