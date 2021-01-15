#include<iostream>
#include<vector>
using namespace std;

bool isPrime(int n) {
	if (n == 1) return false;
	bool answer = true;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) return false;
	}
	return answer;
}
/*
int countPrime(vector<int>v) {
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (isPrime(v[i])) cnt++;
	}
	cout << cnt;
}
*/
int main() {
	int N;
	int answer = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		if (isPrime(n)) answer++;
	}
	cout << answer;
	return 0;
}