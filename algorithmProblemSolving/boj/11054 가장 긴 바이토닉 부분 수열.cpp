#include <iostream>
#include <vector>
using namespace std;

int N;
int max_size = 0;
int num[1001], dp[1001], dp2[1001];
vector<int> num2;
void init() {
	cin >> N;
	for (int i = N - 1; i >= 0; i--) {
		cin >> num[i];
		num2.push_back(num[i]);
	}
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
		dp2[i] = 1;
		for (int j = 0; j < i; j++) {
			if (num2[j] < num2[i] && dp2[i] < dp2[j] + 1) {
				dp2[i] = dp2[j] + 1;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (max_size < dp[i] + dp2[N - i - 1]-1) {
			max_size = dp[i] + dp2[N - i - 1]-1;
		}
	}
}

void run() {
	init();
	DP();
	cout << max_size << endl;
	/*for (int i = 0; i < N; i++) {
		cout << dp[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << dp2[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << dp[i] + dp2[N - i - 1] << " ";
	}
	*/
	return;
}

int main() {
	run();
	return 0;
}