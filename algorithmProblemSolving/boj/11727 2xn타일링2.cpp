#include<iostream>

using namespace std;

int x;
int dp[1001] = { 0, };
void init() {
	cin >> x;
	dp[1] = 1;
	dp[2] = 3;
	dp[3] = 5;
	return;
}

void run() {
	init();
	if (x < 4) {
		cout << dp[x] << endl;
	}
	else {
		for (int i = 4; i <= x; i++) {
			dp[i] = (dp[i - 1] + dp[i - 2]*2) % 10007;
		}
		cout << dp[x] << endl;
	}
	return;
}

int main() {
	run();
	return 0;
}