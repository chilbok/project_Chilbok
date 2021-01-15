#include<iostream>
using namespace std;

int gcd(int a, int b) {
	//최대공약수
	int answer;
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	answer = a;
	return answer;
}

int lcm(int a, int b) {
	//최소공배수
	int answer;
	int g = gcd(a, b);
	answer = a * b / g;
	return answer;
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << endl << lcm(a, b);
	return 0;
}