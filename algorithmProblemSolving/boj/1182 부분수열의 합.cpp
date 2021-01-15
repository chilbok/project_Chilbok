#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, S;
int count = 0;
vector<int> numV;

void init() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		numV.push_back(tmp);
	}
	return;
}

int sumV(vector<int> v, vector<int> check) {
	int res = 0;
	for (int i = 0; i < check.size(); i++) {
		if (!check[i]) { 
			res += v[i]; 
		}
	}
	return res;
}

void find() {
	vector<int> check(N, 1);
	for (int i = 1; i < N+1; i++) {
		vector<int> tmpCheck = check;
		for (int j = 0; j < i; j++) {
			tmpCheck[j] = 0;
		}
		do {
			int sum = sumV(numV, tmpCheck);
			if (sum == S) ::count++;
		} while (next_permutation(tmpCheck.begin(), tmpCheck.end()));
	}
}


void run() {
	init();
	find();
	cout << ::count << endl;
	return;
}

int main() {
	run();
	return 0;
}