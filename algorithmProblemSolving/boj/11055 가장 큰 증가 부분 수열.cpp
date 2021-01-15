#include <iostream>
#include <vector>
using namespace std;

int N;
int max_sum = 0;
int num[1001], dp[1001];
void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	dp[0] = num[0];
	max_sum = dp[0];
	return;
}

void DP() {
	for (int i = 1; i < N; i++) {
		dp[i] = num[i];
		for (int j = 0; j < i; j++) {
			if (num[j] < num[i] && dp[i] <= dp[j] + num[i]) {
				dp[i] = dp[j] + num[i];
			}
		}
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