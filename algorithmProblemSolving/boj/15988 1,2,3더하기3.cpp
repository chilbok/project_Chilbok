#include <iostream>
#define MOD 1000000009

using namespace std;

int T;
long long dp[1000001] = { 0, };

void init() {
	cin >> T;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	return;
}

long long solution(int n) {
	int result = 0;
	if (n < 1) return 0;

	if (dp[n] != 0) {
		return dp[n];
	}
	else {
		dp[n] = (solution(n - 1) + solution(n - 2) + solution(n - 3))%MOD;
		return dp[n];
	}

	return result;
}

void run() {
	init();
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		cout << solution(n) << endl;
	}
	return;
}

int main() {
	run();
	return 0;
}