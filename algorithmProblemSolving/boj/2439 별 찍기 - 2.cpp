#include<iostream>
using namespace std;
int main() {
	int a;
	cin >> a;
	for (int i = 1; i < a+1; i++) {
		for (int k = a-i; k > 0; k--) {
			cout << " ";
		}
		for (int j = 1; j < i + 1; j++) {
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}