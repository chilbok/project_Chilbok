#include<iostream>
#include<vector>

using namespace std;

int N;
int max_size = 0;
int num[1001] = { 0, };
int cost[1001] = { 0, };

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	return;
}

void dp(int index) {
	int min = 0;
	for (int i = 0; i < index; i++) {
		if (num[index] > num[i]) {
			if (min < cost[i]) {
				min = cost[i];
			}
		}
	}
	cost[index] = min + 1;
	if (max_size < cost[index]) {
		max_size = cost[index];
	}
}

void run() {
	init();
	for (int i = 0; i < N; i++) {
		dp(i);
	}
	cout << max_size << endl;
	return;
}

int main() {
	run();
	return 0;
}