#include <iostream>
#include <vector>
using namespace std;

int N;
int max_size = 0;
int max_index = 0;
int num[1001], dp[1001], indexArr[1001];
vector<int> result;
void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	return;
}

void DP() {
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		indexArr[i] = -1;
		for (int j = 0; j < i; j++) {
			if (num[j] < num[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				indexArr[i] = j;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (max_size < dp[i]) {
			max_size = dp[i];
			max_index = i;
		}
	}
}

void findVector() {
	int idx = max_index;
	while (idx >= 0) {
		result.push_back(num[idx]);
		idx = indexArr[idx];
	}
}

void run() {
	init();
	DP();
	cout << max_size << endl;
	findVector();
	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i] << " ";
	}
	cout << endl;
	return;
}

int main() {
	run();
	return 0;
}