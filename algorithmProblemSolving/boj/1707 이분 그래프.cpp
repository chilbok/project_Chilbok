#pragma warning (disable:4996)
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAX_VAL 20001

using namespace std;
vector<vector<int>> relation(MAX_VAL, vector<int>());
vector<vector<int>> backUp(MAX_VAL, vector<int>());

int visit[MAX_VAL] = { 0, }; // 0: 방문x, 1: RED, 2: BLUE
bool isBG = true;
int N, M;


void init() {
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int u, v;
		scanf("%d", &u);
		scanf("%d", &v);
		relation[u].push_back(v);
		relation[v].push_back(u);
	}
	return;
}

void printAnswer(bool check) {
	if (check) printf("YES\n");
	else printf("NO\n");
}

void DFS(int index, bool check) {
	//check -> true : red, false : blue
	if (check) visit[index] = 1;
	else visit[index] = 2;
	for (int i = 0; i < relation[index].size(); i++) {
		int next = relation[index][i];
		if (visit[next] != 0) {
			if (visit[index] == visit[next]) {
				isBG = false;
				return;
			}
		}
		else {
			DFS(next, !check);
		}
	}
}

void run() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		isBG = true;
		memset(visit, 0, sizeof(visit));
		relation = backUp;
		init();
		for (int j = 1; j < N + 1; ++j) {
			if (visit[j] == 0) DFS(j,true);
		}
		printAnswer(isBG);
	}
	return;
}

int main() {
	run();
	return 0;
}