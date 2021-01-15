#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N;
bool clearFlag = false;
vector<vector<char>> optionV;
vector<int> findV(21, 1);
vector<bool> visitV(21, false);
vector<int> result;

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		findV[i] = 0;
	}
	vector<char> tmpCharV(N,'.');
	for (int i = 0; i < N; i++) {
		optionV.push_back(tmpCharV);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i > j) continue;
			char tmp;
			cin >> tmp;
			optionV[i][j] = tmp;
		}
	}
	return;
}

int vSum(vector<int> v, int s, int e) {
	int result = 0;
	for (int i = s; i <= e; i++) {
		result += v[i];
	}
	return result;
}



bool checkOption(vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		if (vSum(v, i, v.size() - 1) > 0 && optionV[i][v.size() - 1] != '+') {
			return false;
		}
		else if (vSum(v, i, v.size() - 1) == 0 && optionV[i][v.size() - 1] != '0') {
			return false;
		}
		else if (vSum(v, i, v.size() - 1) < 0 && optionV[i][v.size() - 1] != '-') {
			return false;
		}
	}
	return true;
}

void DFS(vector<int> v) {
	if (clearFlag) return;
	v.push_back(100);
	int n = v.size() - 1;
	if (optionV[n][n] == '+') {
		for (int i = 10; i > 0; i--) {
			if (clearFlag) return;
			v[n] = i;
			if (checkOption(v)) {
				if (v.size() == N) {
					result = v;
					clearFlag = true;
					return;
				}
				DFS(v);
			}
		}
	}else if (optionV[n][n] == '0') {
		if (clearFlag) return;
		v[n] = 0;
		if (checkOption(v)) {
			if (v.size() == N) {
				result = v;
				clearFlag = true;
				return;
			}
			DFS(v);
		}
	}else if (optionV[n][n] == '-') {
		for (int i = -1; i > -11; i--) {
			if (clearFlag) return;
			v[n] = i;
			if (checkOption(v)) {
				if (v.size() == N) {
					result = v;
					clearFlag = true;
					return;
				}
				DFS(v);
			}
		}
	}
	return;
}

void BFS() {
	queue<int> q;

}

void run() {
	init();
	vector<int> tmp;
	vector<int> v;
	DFS(v);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	return;
}

int main() {
	run();
	return 0;
}