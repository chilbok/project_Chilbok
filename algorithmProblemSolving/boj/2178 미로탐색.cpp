#pragma warning (disable:4996)
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <utility>
#define MAX_VALUE 100

using namespace std;

vector<vector<bool>> map(MAX_VALUE, vector<bool>(MAX_VALUE, false));
vector<vector<bool>> visit(MAX_VALUE, vector<bool>(MAX_VALUE, false));
vector<vector<int>> countV(MAX_VALUE, vector<int>(MAX_VALUE, 0));

int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };
int N, M;
int CNT = 99999999;
int c = 0;

void init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < tmp.length(); j++) {
			map[i][j] = tmp.at(j) - '0';
		}
		cin.ignore();
	}
	return;
}

void bfs(pair<int, int> index) {
	queue<pair<int, int>> q;
	q.push(index);
	visit[index.first][index.second] = true;
	while (!q.empty()) {
		pair<int, int> tmp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ni = tmp.first + di[i];
			int nj = tmp.second + dj[i];
			if (ni < 0 || nj < 0 || ni >= N || nj >= M)continue;
			if (visit[ni][nj] || !map[ni][nj]) continue;
			countV[ni][nj] = countV[tmp.first][tmp.second] + 1;
			q.push(make_pair(ni, nj));
			visit[ni][nj] = true;
		}
	}
}


void run() {
	init();
	bfs(make_pair(0, 0));
	printf("%d\n", countV[N-1][M-1]+1);
	return;
}

int main() {
	run();
	return 0;
}