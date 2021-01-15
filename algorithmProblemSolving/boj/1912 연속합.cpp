#include <iostream>
#include <vector>

using namespace std;

int N;
int max_sum = 0;
vector<int> numV;
vector<int> dp;

int max(int a, int b, int c) {
	if (a > b&& a > c) {
		return a;
	}
	else if (b > a&& b > c) {
		return b;
	}
	else {
		return c;
	}
}

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		numV.push_back(tmp);
	}
	max_sum = numV[0];
	dp.push_back(numV[0]);
	return;
}

void DP() {
	for (int i = 1; i < N; i++) {
		dp.push_back(max(dp[i - 1] + numV[i], numV[i]));
	}
	for (int i = 0; i < dp.size(); i++) {
		if (max_sum < dp[i]) {
			max_sum = dp[i];
		}
	}
}

void run() {
	init();
	DP();
	cout << max_sum << endl;
	return;
}

int main() {
	run();
	return 0;
}