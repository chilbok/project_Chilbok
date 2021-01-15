#include<iostream>
#include<vector>
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
	vector<int> answer;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int a, b;
		cin >> a >> b;
		answer.push_back(lcm(a, b));
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
	answer.clear();
	return 0;
}