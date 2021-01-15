#include<iostream>
#define MOD 10007
#define ll long long

using namespace std;

ll nums[1001][11] = { 0, };
int N;

void init() {
	cin >> N;
	for (int i = 0; i < 10; i++) {
		nums[1][i] = 1;
	}
	nums[1][10] = 10;
	return;
}

ll dp(int x) {
	if (x == 1) return nums[1][10];

	for (int i = 2; i <= x; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				nums[i][j] = (nums[i][j] + nums[i - 1][k]) % MOD;
			}
			nums[i][10] = (nums[i][10] + nums[i][j]) % MOD;
		}
	}
	return nums[x][10];
}

void run() {
	init();
	cout << dp(N) << endl;
	return;
}

int main() {
	run();
	return 0;
}