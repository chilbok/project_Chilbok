#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
int main() {
	int N, digit, tmp;
	cin >> N;
	digit = (int)log10(N)+1;
	int digit_Num[10] = { 0 };
	for (int i = 0; i < digit; i++) {
		tmp = N % 10;
		N = N / 10;
		digit_Num[tmp]++;
	}
	for (int i = 9; i > -1; i--) {
		for (int j = 0; j < digit_Num[i]; j++) {#pragma warning (disable:4996)
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
#define MAX_VAL 100001

using namespace std;

vector<bool> visit(MAX_VAL, false);
vector<int> d(MAX_VAL, 0);

int N, K;

void init() {
	cin >> N >> K;
	return;
}

int movePosition(int a, int index) {
	switch (a) {
	case 0:
		return index - 1;
		break;
	case 1:
		return index + 1;
		break;
	case 2:
		return index * 2;
		break;
	default:
		return -1;
		break;
	}
	return -1;
}

void bfs(int index) {
	queue<int> q;
	q.push(index);
	visit[index] = true;
	while (!q.empty()) {
		if (visit[K]) return;
		int tmp = q.front();
		q.pop();
		for (int i = 0; i < 3; i++) {
			int np = movePosition(i, tmp);
			if (np < 0 || np >= MAX_VAL) continue;
			if (visit[np]) continue;
			d[np] = d[tmp] + 1;
			q.push(np);
			visit[np] = true;
		}
	}
	
}

void run() {
	init();
	bfs(N);
	cout << d[K] << endl;
	return;
}

int main() {
	run();
	return 0;
}
			cout << i;
		}
	}
	cout << "\n";
	return 0;
}