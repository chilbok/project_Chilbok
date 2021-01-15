#include <iostream>

using namespace std;

int N;
long nums[91] = { 0, };

void init() {
	cin >> N;
	nums[1] = 1;
	nums[2] = 1;
	nums[3] = 2;
	return;
}

long dp(int x) {
	if (nums[x] != 0) return nums[x];
	nums[x] = dp(x - 1) + dp(x - 2);
	return nums[x];
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