#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int M, N, x, y;

void init() {
	cin >> M >> N >> x >> y;
	return;
}

int gcd(int a, int b) {
	while (b != 0) {
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b) {
	return a*b / gcd(a, b);
}

void run() {
	init();
	int g = gcd(N, M);
	int l = lcm(N, M);
	for (int i = x; i < l + 1; i=i+M) {
		if ((i - x) % M == 0 && (i - y) % N == 0){
			cout << i << endl;
			return;
		}
	}
	cout << -1 << endl;
	return;
}

int main() {
	int runCnt;
	cin >> runCnt;
	for (int i = 0; i < runCnt; i++) {
		run();
	}
	return 0;
}