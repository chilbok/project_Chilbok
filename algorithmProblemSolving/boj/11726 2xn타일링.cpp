#include<iostream>

using namespace std;

int x;
int dp[1001] = { 0, };
void init() {
	cin >> x;
	dp[1] = 1;
	dp[2] = 2;
	return;
}

void run() {
	init();
	if (x < 3) {
		cout << dp[x] << endl;
	}
	else {
		for (int i = 3; i <= x; i++) {
			dp[i] = (dp[i - 1] + dp[i - 2])%10007;
		}
		cout << dp[x] << endl;
	}
	return;
}

int main() {
	run();
	return 0;
}