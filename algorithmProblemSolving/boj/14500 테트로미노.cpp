#include<iostream>
#include<algorithm>

#define N 500
#define M 500
using namespace std;

int n, m;
int map[N][M];
int SUM = 0;
int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };

int max(int a, int b) {
	if (a >= b) return a;
	else return b;
}

void initMap() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int num;
			cin >> num;
			map[i][j] = num;
		}
	}
}

void dfs(pair<int, int> first, pair<int, int>second, int cnt, int sum) {
	if (cnt == 4) {
		SUM = max(SUM, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int new_i = first.first + di[i];
		int new_j = first.second + dj[i];
		if (new_i < 0 || new_i >= n || new_j < 0 || new_j >= m) continue;
		if (make_pair(new_i, new_j) == second) continue;
		dfs({ new_i,new_j }, first, cnt + 1, sum + map[new_i][new_j]);
	}
}

void checkShape(int ii, int jj) {
	int sum = 0;
	if (ii >= 0 && ii + 1 < n && jj >= 0 && jj + 2 < m) {
		sum = map[ii][jj] + map[ii][jj + 1] + map[ii][jj + 2] + map[ii + 1][jj + 1];
		SUM = max(SUM, sum);
	}

	// 2. ㅏ
	if (ii >= 0 && ii + 2 < n && jj >= 0 && jj + 1 < m) {
		sum = map[ii][jj] + map[ii + 1][jj] + map[ii + 2][jj] + map[ii + 1][jj + 1];
		SUM = max(SUM, sum);
	}

	// 3. ㅗ
	if (ii - 1 >= 0 && ii < n && jj >= 0 && jj + 2 < m) {
		sum = map[ii][jj] + map[ii][jj + 1] + map[ii][jj + 2] + map[ii - 1][jj + 1];
		SUM = max(SUM, sum);
	}

	// 4. ㅓ
	if (ii - 1 >= 0 && ii + 1 < n && jj >= 0 && jj + 1 < m) {
		sum = map[ii][jj] + map[ii][jj + 1] + map[ii - 1][jj + 1] + map[ii + 1][jj + 1];
		SUM = max(SUM, sum);
	}
}

void findMax() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dfs({ i,j }, { -1,-1 }, 0, 0);
			checkShape(i, j);
		}
	}
}

int main() {
	initMap();
	findMax();
	cout << SUM << endl;
	return 0;
}