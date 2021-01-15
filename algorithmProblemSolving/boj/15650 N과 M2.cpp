#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>

using namespace std;

vector<int> numV;
vector<int> check;
int N, M;

void init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		numV.push_back(i+1);
		if (i < M) check.push_back(0);
		else check.push_back(1);
	}
	return;
}


void printV() {
	do {
		for (int i = 0; i < N; i++) {
			if (!check[i]) {
				printf("%d ", numV[i]);
			}
		}
		printf("\n");
	} while (next_permutation(check.begin(), check.end()));
	return;
}

void run() {
	init();
	printV();
	return;
}

int main() {
	run();
}