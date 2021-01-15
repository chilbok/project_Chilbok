#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>

using namespace std;

int N, M;
vector<int> numV;
vector<int> check;

void init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		numV.push_back(tmp);
		if (i < M) check.push_back(0);
		else check.push_back(1);
	}
	sort(numV.begin(), numV.end());
	return;
}

void printNum() {
	do {
		for (int i = 0; i < N; i++) {
			if (!check[i]) {
				printf("%d ", numV[i]);
			}
		}
		printf("\n");
	} while (next_permutation(check.begin(), check.end()));
}

void run() {
	init();
	printNum();
	return;
}

int main() {
	run();
	return 0;
}