#include <iostream>
using namespace std;
int check(int N);
int main() {
	int N, x = 0, y = 0;
	//x = 5g, y = 3g
	cin >> N;
	check(N);
	return 0;
}
int check(int N) {
	int count = N / 5;
	int tmp = N;
	for (int i = count; i > -1; i--) {
		tmp = tmp - i * 5;
		if (tmp % 3 == 0) {
			cout << i + tmp / 3;
			return 0;
		}
		tmp = N;
	}
	cout << -1;
	return 0;
}