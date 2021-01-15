#pragma warning (disable:4996)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAX_N 1001

using namespace std;

int N, M;

bool relation[MAX_N][MAX_N] = { false, };
bool visit[MAX_N] = { false, };
vector<vector<int>> cnt(MAX_N);

void init() {
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int u, v;
		scanf("%d", &u);
		scanf("%d", &v);
		relation[u][v] = true;
		relation[v][u] = true;
	}
	return;
}

void dfs(int index, int start) {
	cnt[start].push_back(index);
	visit[index] = true;
	for (int i = 1; i < N+1; i++) {
		if (!visit[i] && relation[index][i]) dfs(i, start);
	}
}

int countCC() {
	int res = 0;
	for (int i = 0; i < cnt.size(); i++) {
		if (cnt[i].size() > 0) res++;
	}
	return res;
}

void run() {
	init();
	for (int i = 1; i < N+1; i++) {
		if (!visit[i]) dfs(i, i);
	}
	cout << countCC() << endl;
	return;
}

int main() {
	run();
	return 0;
}