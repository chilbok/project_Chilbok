#include<iostream>
using namespace std;
int dat_[1000000] = { 0 };
int prob(int);
int main() {
	int N;
	cin >> N;
	cout << prob(N) << endl;
	return 0;
}
int prob(int x) {
	dat_[0] = 1;
	dat_[1] = 1;
	for (int i = 2; i < x+1; i++) {
		dat_[i] = (dat_[i - 1] + dat_[i - 2])%15746;
	}
	return dat_[x];
}