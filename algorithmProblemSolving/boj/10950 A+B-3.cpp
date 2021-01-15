#include<iostream>
using namespace std;
int main() {
	int a, b, c;
	cin >> a;
	int *arr = new int[a];
	for (int i = 0; i < a; i++) {
		cin >> b >> c;
		arr[i] = b + c;
	}
	for (int i = 0; i < a ; i++) {
		cout << arr[i] << endl;
	}
	delete[] arr;
	return 0;
}