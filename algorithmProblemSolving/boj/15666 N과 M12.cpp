#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<string>

using namespace std;

int N, M;
vector<int> numV;

void init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		numV.push_back(tmp);
	}
	sort(numV.begin(), numV.end());
	numV.erase(unique(numV.begin(), numV.end()), numV.end());
	return;
}

void DFS(int index, int cnt, string s) {
	if (cnt >= M) {
		printf("%s\n", s.c_str());
		return;
	}
	for (int i = index; i < numV.size(); i++) {
		DFS(i, cnt+1,s+" "+to_string(numV[i]));
	}
	return;
}

void run() {
	init();
	for (int i = 0; i < numV.size(); i++) {
		DFS(i, 1, to_string(numV[i]));
	}
	return;
}

int main() {
	run();
	return 0;
}