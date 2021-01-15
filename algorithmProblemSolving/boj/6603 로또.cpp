#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

vector<vector<int>> numV;

void initNumV() {
	while (true) {
		int N;
		cin >> N;
		if (N == 0) break;
		vector<int> tmpV;
		for (int i = 0; i < N; i++) {
			int n;
			cin >> n;
			tmpV.push_back(n);
		}
		numV.push_back(tmpV);
	}
}

void printV(vector<int> a, vector<int> b) {
	for (int i = 0; i < a.size(); i++) {
		if (b[i] == 1) {
			printf("%d ", a[i]);
		}
	}
	printf("\n");
}

void findCombination(vector<int> a) {
	vector<int> tmpV(a.size(), 0);
	for (int i = 0; i < 6; i++) {
		tmpV[i] = 1;
	}
	do {
		printV(a, tmpV);
	} while (prev_permutation(tmpV.begin(), tmpV.end()));
}

void run() {
	initNumV();
	for (int i = 0; i < numV.size(); i++) {
		findCombination(numV[i]);
		cout << endl;
	}
	return;
}

int main() {
	run();
	return 0;
}