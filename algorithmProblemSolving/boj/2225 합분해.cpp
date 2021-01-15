#include <iostream>
#define MOD 1000000000

using namespace std;

int N, K;
int dp[201][201] = { 0, };

void init() {
	cin >> N >> K;
	for (int i = 0; i <= N; i++) {
		dp[0][i] = 0;
		dp[1][i] = 1;
	}
	return;
}

void run() {
	init();
	for (int i = 2; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD;
			}
		}
	}
	cout << dp[K][N] << endl;
	return;
}

int main() {
	run();
	return 0;
}