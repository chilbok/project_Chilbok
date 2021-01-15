#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
int main() {
	int N, digit, tmp;
	cin >> N;
	digit = (int)log10(N)+1;
	int digit_Num[10] = { 0 };
	for (int i = 0; i < digit; i++) {
		tmp = N % 10;
		N = N / 10;
		digit_Num[tmp]++;
	}
	for (int i = 9; i > -1; i--) {
		for (int j = 0; j < digit_Num[i]; j++) {
			cout << i;
		}
	}
	cout << "\n";
	return 0;
}