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

vector<int> initNumV(int n) {
	vector<int> answer;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		answer.push_back(num);
	}
	return answer;
}

long long sumOfGcd(vector<int> v) {
	long long answer = 0;
	for (int i = 0; i < v.size()-1; i++) {
		for (int j = i + 1; j < v.size(); j++) {
			answer += gcd(v[i], v[j]);
		}
	}
	return answer;
}

void printV(vector<long long> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}

int main() {
	vector<long long> answer;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		vector<int> numV = initNumV(n);
		answer.push_back(sumOfGcd(numV));
		numV.clear();
	}
	printV(answer);
	return 0;
}