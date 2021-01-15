#include<iostream>
using namespace std;

unsigned long long int length[101] = { 0 };
unsigned long long int padoban(int x);
int main() {
	int T, N;
	cin >> T;
	unsigned long long int* cases = new unsigned long long int[T];
	for (int i = 0; i < T; i++) {
		cin >> N;
		cases[i] = padoban(N);
	}
	for (int i = 0; i < T; i++) {
		cout << cases[i] << endl;
	}
    return 0;
}
unsigned long long int padoban(int x) {
	if (x <= 3) return 1;
    else if (x == 4 || x == 5) return 2;
	else if (length[x] != 0) return length[x];
	else {
		length[x] = padoban(x - 1) + padoban(x - 5);
		return length[x];
	}
}