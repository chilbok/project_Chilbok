#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int N;
int cnt = 0;
vector<vector<int>> v;

void init() {
	cin >> N;
	v.assign(N, vector<int>(N));
	return;
}

bool checkOption(vector<int> v) {
	int n = v.size() - 1;
	for (int i = 0; i < n; i++) {
		if (v[i] == v[n]) {
			return false;
		}
		else if (abs(i - n) == abs(v[i] - v[n])) {
			return false;
		}
	}
	return true;
}

void DFS(vector<int> v, vector<bool>visit, int cur) {
	if (v.size() == N) {
		cnt++;
		return;
	}
	v.push_back(-1);
	int n = v.size() - 1;
	for (int i = 0; i < N; i++) {
		if (cur == i || cur + 1 == i || cur - 1 == i) continue;
		if (visit[i]) continue;
		v[n] = i;
		if (checkOption(v)) {
			visit[i] = true;
			DFS(v,visit,i);
			visit[i] = false;
		}
	}
	return;
}

void run() {
	init();
	vector<bool> visit(N, false);
	DFS({},visit,-2);
	cout << cnt <<endl;
	return;
}

int main() {
	run();
	return 0;
}