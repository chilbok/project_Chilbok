#include <iostream>

using namespace std;

int N;
unsigned int wine[10001] = { 0, };
unsigned int drink[10001] = { 0, };

void init() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		wine[i] = tmp;
	}
	drink[1] = wine[1];
	drink[2] = wine[1] + wine[2];
	return;
}

unsigned int max(unsigned int a, unsigned int b, unsigned int c) {
	if (a > b) {
		if (a > c) {
			return a;
		}
		else {
			return c;
		}
	}
	else {
		if (b > c) {
			return b;
		}
		else {
			return c;
		}
	}
}

void dp() {
	for (int i = 3; i <= N; i++) {
		drink[i] = max(drink[i - 1], wine[i] + drink[i - 2], wine[i] + wine[i - 1] + drink[i - 3]);
	}
}

void run() {
	init();
	dp();
	cout << drink[N] << endl;
	return;
}

int main() {
	run();
	return 0;
}