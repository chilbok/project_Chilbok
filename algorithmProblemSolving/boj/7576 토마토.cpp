#pragma warning (disable:4996)
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <queue>
#include <utility>
#define MAX_VALUE 1000

int N, M;

using namespace std;

vector<vector<int>> box(MAX_VALUE, vector<int>(MAX_VALUE,0));
vector<vector<int>> countV(MAX_VALUE, vector<int>(MAX_VALUE, 99999999));
queue<pair<int, int>> q;

int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };

bool init() {
	bool check = true;
	scanf("%d", &M);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int tmp;
			scanf("%d", &tmp);
			if (tmp == 0) {
				check = false;
			}
			else if (tmp == 1) {
				countV[i][j] = 0;
				q.push(make_pair(i, j));
			}
			box[i][j] = tmp;
		}
	}
	if (check)
		printf("0");
	return check;
}

void bfs() {
	while (!q.empty()) {
		pair<int, int> tmp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ni = tmp.first + di[i];
			int nj = tmp.second + dj[i];
			if (ni < 0 || nj < 0 || ni >= N || nj >= M) continue;
			if (box[ni][nj] == 0 && countV[ni][nj] == 99999999) {
				countV[ni][nj] = countV[tmp.first][tmp.second] + 1;
				q.push(make_pair(ni, nj));
			}
		}
	}
}

void printResult() {
	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 0 && countV[i][j] == 99999999) {
				printf("-1\n");
				return;
			}
			else if(countV[i][j]!= 99999999){
				if (countV[i][j] > max) {
					max = countV[i][j];
				}
			}

		}
	}
	printf("%d\n", max);
	return;
}

void run() {
	if (!init()) {
		bfs();
		printResult();
	}
	return;
}

int main() {
	run();
	return 0;
}