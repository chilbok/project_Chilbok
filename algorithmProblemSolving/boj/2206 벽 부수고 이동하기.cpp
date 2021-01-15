#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>

using namespace std;

int N;
int M;
int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };
vector<vector<int>> map(1001,vector<int>(1001, 0));
int d[1001][1001][2] = { 0, };

void init() {
	cin >> N >> M;
	string tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		for (int j = 0; j < tmp.length(); j++) {
			map[i][j] = tmp.at(j) - '0';
		}
	}
}

int BFS(pair<pair<int,int>,int> start) {
	queue<pair<pair<int, int>,int>>q;
	q.push(start);
	d[start.first.first][start.first.second][start.second] = 1;
	while (!q.empty()) {
		int cur_i = q.front().first.first;
		int cur_j = q.front().first.second;
		int crash = q.front().second;
		q.pop();
		if (cur_i == N - 1 && cur_j == M - 1) return d[cur_i][cur_j][crash];
		for (int i = 0; i < 4; i++) {
			int ni = cur_i + di[i];
			int nj = cur_j + dj[i];
			if (ni < 0 || nj < 0 || ni >= N || nj >= M) continue;
			if (d[ni][nj][crash]) continue;
			if (!map[ni][nj]) {
				d[ni][nj][crash] = d[cur_i][cur_j][crash] + 1;
				q.push(make_pair(make_pair(ni, nj), crash));
			}
			else if (map[ni][nj] && !crash) {
				d[ni][nj][1] = d[cur_i][cur_j][crash] + 1;
				q.push(make_pair(make_pair(ni, nj), 1));
			}
		}
	}
	return -1;
}

void run() {
	init();
	cout << BFS({ {0,0},0 }) << endl;
}

int main() {
	run();
	return 0;
}