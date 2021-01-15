#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int N;
vector<int> cntV;


void init() {
	cin >> N;
	for (int i = 0; i < 8; i++) {
		cntV.push_back(pow(10, i) * 9 * (i + 1));
	}
	cntV.push_back(9);
	return;
}

void run() {
	init();
	int result = 0;
	int logCnt = log10(N);
	for (int i = 0; i < logCnt; i++) {
		result += cntV[i];
	}
	result = result + (N - pow(10, logCnt) + 1) * (logCnt + 1);
	cout << result << endl;
	return;
}

int main() {
	run();
	return 0;
}