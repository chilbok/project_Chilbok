#include <iostream>
#include <vector>
using namespace std;

int N;
int max_size = 0;
int num[1001], dp[1001];
void init() {
	cin >> N;
	for (int i = N-1; i >= 0; i--) {
		cin >> num[i];
	}
	//dp[0] = num[0];
	return;
}

void DP() {
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (num[j] < num[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (max_size < dp[i]) {
			max_size = dp[i];
		}
	}
}

void run() {
	init();
	DP();
	cout << max_size << endl;
	return;
}

int main() {
	run();
	return 0;
}