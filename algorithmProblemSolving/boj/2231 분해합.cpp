#include<iostream>
#include<cstdlib>
#include<cmath>
#include<math.h>
using namespace std;
int maker(int n);
int main() {
	int N = 0;
	cin >> N;
	int digit = (int)log10(N) + 1;
	bool little = true;
	bool success = false;
	// digit = N의 자리수
	if ((int)log10(N - 9 * digit) + 1 == digit) {
		little = false;
	}
	//little -> false = 한 자리가 더 작은수 불가능
	//			true = 한 자리가 더 작은수 가능
	//cout << little << endl;
	if (little) {
		for (int i = N - digit * 9; i < N - 1; i++) {
			if (maker(i) == N) {
				cout << i << endl;
				success = true;
				break;
			}
		}
	}
	else {
		for (int i = N-digit*9; i < N - 1; i++) {
			if (maker(i) == N) {
				cout << i<<endl;
				success = true;
				break;
			}
		}
	}
	if (!success) cout << 0 << endl;
	return 0;
}
int maker(int n) {
	int digit = (int)log10(n) + 1;
	int result = n;
	int tmp = n;
	for (int i = 0; i < digit; i++) {
		result += tmp % 10;
		tmp = tmp / 10;
	}
	return result;
}