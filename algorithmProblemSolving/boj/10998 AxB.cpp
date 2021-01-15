#include <iostream>

using namespace std;

int A, B;

void init() {
	cin >> A >> B;
	return;
}

void run() {
	init();
	cout << A * B << endl;
	return;
}

int main() {
	run();
	return 0;
}