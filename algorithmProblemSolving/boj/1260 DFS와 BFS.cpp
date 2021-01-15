#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#pragma warning (disable:4996)

#define max 1000
using namespace std;

int N, M, V;

vector<vector<int>> relation;
bool visit[max+1] = { false, };

void init() {
	scanf("%d", &N);
	scanf("%d", &M);
	scanf("%d", &V);
	vector<vector<int>> tmpV(N+1, vector<int>(0));
	for (int i = 0; i < M; i++) {
		int tmp1, tmp2;
		scanf("%d", &tmp1);
		scanf("%d", &tmp2);
		tmpV[tmp1].push_back(tmp2);
		tmpV[tmp2].push_back(tmp1);
	}
	for (int i = 0; i < tmpV.size(); i++) {
		sort(tmpV[i].begin(), tmpV[i].end());
	}
	relation = tmpV;
	tmpV.clear();
	return;
}

void DFS(int index) {
	printf("%d ", index);
	visit[index] = true;
	for (int i = 0; i < relation[index].size(); i++) {
		int next = relation[index][i];
		if (!visit[next]) DFS(next);
	}
	return;
}

void BFS(int index) {
	queue<int> q;
	q.push(index);
	visit[index] = true;

	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		printf("%d ", tmp);
		for (int i = 0; i < relation[tmp].size(); i++) {

			int next = relation[tmp][i];
			if (!visit[next]) {
				q.push(next);
				visit[next] = true;
			}
		}
	}

	return;
}

void run() {
	init();
	DFS(V);
	printf("\n");
	memset(visit, false, sizeof(visit));
	BFS(V);
	printf("\n");
	return;
}

int main() {
	run();
	return 0;
}