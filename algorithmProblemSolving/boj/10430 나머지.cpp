#include <iostream>

using namespace std;

int A, B, C;

void init() {
	cin >> A >> B >> C;
	return;
}

void run() {
	init();
	cout << (A + B) % C << endl;
	cout << ((A % C) + (B % C)) % C << endl;
	cout << (A * B) % C << endl;
	cout << ((A % C) * (B % C)) % C << endl;
	return;
}

int main() {
	run();
	return 0;
}