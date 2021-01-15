#include<iostream>
#include<vector>

using namespace std;
int answer[12];

void initAnswer() {
	answer[1] = 1;
	answer[2] = 2;
	answer[3] = 4;
	for (int i = 4; i < 12; i++) {
		answer[i] = -1;
	}
}

int find(int n) {
	if (answer[n] != -1) {
		return answer[n];
	}
	else {
		answer[n] = find(n - 1) + find(n - 2) + find(n - 3);
		return answer[n];
	}
}

void run() {
	vector<int> input;
	initAnswer();
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int tmp;
		cin >> tmp;
		input.push_back(tmp);
	}
	for (int i = 0; i < input.size(); i++) {
		cout << find(input[i]) << endl;
	}
}

int main() {
	run();
	return 0;
}