#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> T(1,-1);
vector<int> P(1,-1);
int cost = 0;

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int t, p;
		cin >> t >> p;
		T.push_back(t);
		P.push_back(p);
	}
	return;
}

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

void dfs(int index, int sum) {
	for (int i = index + T[index]; i < T.size(); i++) {
		if (i + T[i] <= N+1) {
			dfs(i, sum + P[i]);
		}
	}
	::cost = max(::cost, sum);
	return;
}

void findMax() {
	for (int i = 1; i < T.size(); i++) {
		if(i+T[i]<=N+1)
			dfs(i, P[i]);
	}
}

void run() {
	init();
	findMax();
	cout << ::cost << endl;
	return;
}

int main() {
	run();
	return 0;
}