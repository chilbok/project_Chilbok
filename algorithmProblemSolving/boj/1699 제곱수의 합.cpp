#include <iostream>

using namespace std;
int N;
int minSize[100001] = { 0, };

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}

void init() {
	cin >> N;
	return;
}


int DP(int idx) {
	for (int i = 1; i <= idx; i++) {
		minSize[i] = i;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 2; j * j <= i; j++) {
			minSize[i] = min(minSize[i], minSize[i - j * j] + 1);
		}
	}
	return minSize[idx];
}

void run() {
	init();
	cout << DP(N) << endl;
	return;
}



int main() {
	run();
	return 0;
}