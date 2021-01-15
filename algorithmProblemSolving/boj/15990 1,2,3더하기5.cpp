#include<iostream>
#define MOD 1000000009
using namespace std;

int T;
unsigned long long nums[100001][4] = { 0, };

void init() {
	cin >> T;
	nums[1][0] = 1;
	nums[1][1] = 1;
	
	nums[2][0] = 1;
	nums[2][2] = 1;

	nums[3][0] = 3;
	nums[3][1] = 1;
	nums[3][2] = 1;
	nums[3][3] = 1;
	return;
}


unsigned long long dp(int x) {
	if (x <= 0) return 0;

	if (nums[x][0] != 0) {
		return nums[x][0];
	}
	for (int j = 4; j <= x; j++) {
		if (nums[j][0] != 0) continue;
		for (int i = 3; i >= 1; i--) {
			for (int k = 1; k <= 3; k++) {
				if (k == i) continue;
				nums[j][i] = (nums[j][i] + nums[j - i][k])%MOD;
			}
		}
		nums[j][0] = (nums[j][1] + nums[j][2] + nums[j][3]) % MOD;
		
	}
	return nums[x][0];
	return -1;
}

void run() {
	init();
	
	for (int i = 0; i < T; i++) {
		int tmp;
		cin >> tmp;
		cout << dp(tmp) << endl;
	}
	return;
}

int main() {
	run();
	return 0;
}