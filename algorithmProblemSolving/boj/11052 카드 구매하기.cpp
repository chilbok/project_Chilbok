#include <iostream>

using namespace std;

int n;
int cost[1001] = { 0, };
int price[1001] = { 0, };

void init() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		cost[i] = tmp;
	}
	price[1] = cost[1];
	return;
}

int dp(int x) {
	if (x <= 0) return 0;
	if (price[x] != 0) {
		return price[x];
	}
	else {
		int tmp = 0;
		for (int i = 0; i < x; i++) {
			int sum = 0;
			sum = cost[x-i] + dp(i);
			if (sum > tmp) tmp = sum;
		}
		price[x] = tmp;
		return price[x];
	}
	return 0;
}

void run() {
	init();
	cout << dp(n) << endl;
	return;
}

int main() {
	run();
	return 0;
}