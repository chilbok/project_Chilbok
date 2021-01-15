#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> numV;

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int gap(int a, int b) {
	if (a - b < 0) return(a - b) * -1;
	return a - b;
}

int sumOfGap(vector<int> v) {
	int res = 0;
	for (int i = 0; i < v.size()-1; i++) {
		res += gap(v[i], v[i + 1]);
	}
	return res;
}

void initNumV() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		numV.push_back(tmp);
	}
	return;
}

int findMaxGap() {
	vector<int> tmpV = numV;
	sort(tmpV.begin(), tmpV.end());
	int res = -1;
	do {
		res = max(res, sumOfGap(tmpV));
	} while (next_permutation(tmpV.begin(), tmpV.end()));
	return res;
}

void run() {
	initNumV();
	cout << findMaxGap() << endl;
	return;
}

int main() {
	run();
	return 0;
}