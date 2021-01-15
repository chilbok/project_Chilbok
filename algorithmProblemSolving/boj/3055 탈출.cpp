#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <utility>
#define RIP "KAKTUS"
using namespace std;

int R, C;
int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };
char map[51][51];
int d_dochi[51][51] = { 0, };
int d_water[51][51] = { 0, };
queue<pair<int, int>> water;
pair<int, int> cave;
pair<int, int> dochi;

void init() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < C; j++) {
			char tmpChar = tmp.at(j);
			map[i][j] = tmpChar;

		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char tmpChar = map[i][j];
			if (tmpChar == 'D') {
				cave = make_pair(i, j);
				//map[i][j] = '.';
			}
			else if (tmpChar == '*') {
				water.push(make_pair(i, j));
				//map[i][j] = '.';
			}
			else if (tmpChar == 'S') {
				dochi = make_pair(i, j);
				//map[i][j] = '.';
			}
		}
	}
	return;
}

void BFS_water() {
	while (!water.empty()) {
		int cur_i = water.front().first;
		int cur_j = water.front().second;
		water.pop();
		for (int i = 0; i < 4; i++) {
			int ni = cur_i + di[i];
			int nj = cur_j + dj[i];
			if (ni < 0 || nj < 0 || ni >= R || nj >= C) continue;
			if (d_water[ni][nj] == 0 && map[ni][nj] == '.') {
				d_water[ni][nj] = d_water[cur_i][cur_j] + 1;
				water.push(make_pair(ni, nj));
			}
		}
	}
	return;
}

void BFS(pair<int, int> start) {
	queue<pair<int, int>> q;
	q.push(start);
	//d_dochi[start.first][start.second] = 0;
	while (!q.empty()) {
		int cur_i = q.front().first;
		int cur_j = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ni = cur_i + di[i];
			int nj = cur_j + dj[i];
			if (ni >= 0 && ni < R && nj >= 0 && nj < C) {
				if (d_dochi[ni][nj] == 0 && (map[ni][nj] == '.' || map[ni][nj] == 'D')) {
					if (d_water[ni][nj] == 0) {
						d_dochi[ni][nj] = d_dochi[cur_i][cur_j] + 1;
						q.push(make_pair(ni, nj));
					}
					else {
						if (d_water[ni][nj] > d_dochi[cur_i][cur_j] + 1) {
							d_dochi[ni][nj] = d_dochi[cur_i][cur_j] + 1;
							q.push(make_pair(ni, nj));
						}
					}
				}
			}
		}

	}
	//return -1;
}

void run() {
	init();
	BFS_water();
	BFS(dochi);
	if (d_dochi[cave.first][cave.second] == 0) {
		cout << "KAKTUS" << endl;
	}
	else {
		cout << d_dochi[cave.first][cave.second] << endl;
	}
	return;
}

int main() {
	run();
	return 0;
}