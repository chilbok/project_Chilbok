#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int W[10][10];
bool check[10];
int N;
int cost = 100000000;

int min(int a, int b) {
	if (a < b) return a;
	else return b;
}

void initCheck() {
	for (int i = 0; i < 10; i++) {
		check[i] = false;
	}
	return;
}

void initArr() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			W[i][j] = tmp;
		}
	}
	for (int i = 0; i < N; i++) {
		check[i] = false;
	}
}

void dfs(int start, int next, int cnt, int cost) {
	if (cnt == N && next == start) {
		::cost = min(::cost, cost);
		return;
	}
	for (int i = 0; i < N; i++) {
		if (W[next][i] == 0) continue;
		
		if (!check[next] && W[next][i] > 0) {
			check[next] = true;
			if (cost + W[next][i] <= ::cost) {
				dfs(start, i, cnt + 1, cost + W[next][i]);
			}
			check[next] = false;
		}
	}
	return;
}


void run() {
	initArr();
	for (int i = 0; i < N; i++) {
		//check[i] = true;
		dfs(i, i, 0, 0);
		initCheck();
	}
	cout << cost << endl;
	return;
}

int main() {
	run();
	return 0;
}