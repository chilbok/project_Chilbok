#include <iostream>
#include <vector>

using namespace std;

int N, B, C;
vector<int> A;
long TOTAL = 0;

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmpI;
		cin >> tmpI;
		A.push_back(tmpI);
	}
	cin >> B >> C;
	return;
}

void run() {
	init();
	for (int i = 0; i < N; i++) {
		A[i] -= B;
		if (A[i] < 0) A[i] = 0;
		if (A[i] == 0) continue;
		int tmpI = A[i] / C;
		TOTAL += tmpI;
		if (A[i] != tmpI*C) TOTAL += 1;
	}
	TOTAL += N;
	cout << TOTAL << endl;
	return;
}

int main() {
	run();
	return 0;
}