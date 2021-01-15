#include<iostream>
#define MOD 1000000000
#define ll long long

using namespace std;

ll nums[101][11] = { 0, };
int N;

void init() {
	cin >> N;
	for (int i = 0; i < 10; i++) {
		nums[1][i] = 1;
	}
	nums[1][10] = 9;
	return;
} 

ll dp(int x) {
	if (x == 1) return nums[1][10];

	for (int i = 2; i <= x; i++) {
		nums[i][0] = nums[i - 1][1] % MOD;
		for (int j = 1; j < 9; j++) {
			nums[i][j] = (nums[i - 1][j - 1] + nums[i - 1][j + 1]) % MOD;
		}
		nums[i][9] = nums[i - 1][8] % MOD;
		for (int j = 1; j < 10; j++) {
			nums[i][10] = (nums[i][10] + nums[i][j]) % MOD;
		}
	}
	return nums[x][10];
}

void run() {
	init();
	cout << dp(N) << endl;
}

int main() {
	run();
	return 0;
}