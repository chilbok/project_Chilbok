#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>

using namespace std;

vector<int> numV;

void initNumV() {
	numV.clear();
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		numV.push_back(i+1);
	}
	return;
}

void findNext() {
	vector<int> tmpV = numV;
	do {
		for (int i = 0; i < tmpV.size(); i++) {
			printf("%d ", tmpV[i]);
		}
		printf("\n");
	} while (next_permutation(tmpV.begin(), tmpV.end()));
	return;
}

void run() {
	initNumV();
	findNext();
	return;
}

int main() {
	run();
	return 0;
}