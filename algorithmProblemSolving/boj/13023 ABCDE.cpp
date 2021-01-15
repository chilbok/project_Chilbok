#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstring>
#pragma warning (disable:4996)

using namespace std;

int N, M;
bool cnt = false;
//vector<vector<bool>> relation(2000,vector<bool>(2000,false));
bool visit[2000] = { false, };
vector<vector<int>> relation(2000);


void init() {
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int tmp1, tmp2;
		scanf("%d", &tmp1);
		scanf("%d", &tmp2);
		relation[tmp1].push_back(tmp2);
		relation[tmp2].push_back(tmp1);
	}
	return;
}

void DFS(int index, int c) {
	if (c >= 5) {
		cnt = true;
		return;
	}
	visit[index] = true;
	for (int i = 0; i < relation[index].size(); i++) {
		if (visit[relation[index][i]]) continue;
		DFS(relation[index][i], c + 1);
		if (cnt) return;
	}
	visit[index] = false;
	return;
}

void run() {
	init();
	for (int i = 0; i < N; i++) {
		memset(visit, false,sizeof(visit));
		DFS(i, 1);
		if (cnt) break;
	}
	if(cnt)	printf("1\n");
	else printf("0\n");
	return;
}

int main() {
	run();
	return 0;
}