#include <iostream>
using namespace std;

int main() {
	int a, b, c, temp = 0;

	cin >> a >> b >> c;
	if ((a - b)*(b - c)*(c - a) == 0) {
		if (a == b) cout << a;
		else if (b == c) cout << b;
		else if (a == c) cout << c;
	}
	else {
		if (a > b) {
			swap(a, b);
		}
		if (b > c) {
			swap(c, b);
		}
		if (a > b) {
			swap(a, b);
		}
		cout << b;
	}
	return 0;
}
void swap(int& a, int& b) {
	int tmp = 0;
	if (a > b) {
		tmp = a;
		a = b;
		b = tmp;
	}
}