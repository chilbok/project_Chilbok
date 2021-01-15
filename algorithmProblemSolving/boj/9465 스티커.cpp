#include <iostream>
#include <queue>
#include<utility>

using namespace std;

int N, T;
int stickers[2][100001] = { 0, };
int cost[2][100001] = { 0, };

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

void init() {
	cin >> N;
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp;
			cin >> tmp;
			stickers[i][j] = tmp;
		}
	}
	cost[0][1] = stickers[0][1];
	cost[1][1] = stickers[1][1];
	return;
}

void dp() {
	for (int j = 2; j <= N; j++) {
		for (int i = 0; i < 2; i++) {
			cost[i][j] = stickers[i][j] + max(cost[(i + 1) % 2][j - 1], cost[(i + 1) % 2][j - 2]);
		}
	}
	return;
}

void run() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		init();
		dp();
		cout << max(cost[0][N], cost[1][N]) << endl;
	}
	return;
}

int main() {
	run();
	return 0;
}