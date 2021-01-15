#include <iostream>
#include <vector>

using namespace std;

int N;
int max_sum = 0;
vector<int> numV;
vector<vector<int>> dp(2,vector<int>());

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
	dp[0].push_back(numV[0]);
	dp[1].push_back(numV[0]);
	return;
}

void DP() {
	for (int i = 1; i < N; i++) {
		dp[0].push_back(max(dp[0][i - 1] + numV[i], numV[i]));
		dp[1].push_back(max(dp[1][i - 1] + numV[i], dp[0][i-1]));
	}
	for (int i = 0; i < dp[0].size(); i++) {
		if (max_sum < dp[0][i]) {
			max_sum = dp[0][i];
		}
	}
	for (int i = 0; i < dp[1].size(); i++) {
		if (max_sum < dp[1][i]) {
			max_sum = dp[1][i];
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