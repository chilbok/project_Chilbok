#include <iostream>
#include <vector>

using namespace std;

int R, C;
int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };
int MAX = 0;
vector<vector<char>> mapV;
vector<bool> alphaV(26, false);

void init() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		vector<char> tmpV;
		for (int j = 0; j < C; j++) {
			char tmp;
			cin >> tmp;
			tmpV.push_back(tmp);
		}
		mapV.push_back(tmpV);
	}
	alphaV[mapV[0][0] - 'A'] = true;
	return;
}

void DFS(int ii, int jj, int cnt) {
	if (ii == R - 1 && jj == C - 1) {
		if (MAX < cnt) MAX = cnt;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ni = ii + di[i];
		int nj = jj + dj[i];
		if (ni < 0 || nj < 0 || ni >= R || nj >= C) continue;
		if (alphaV[mapV[ni][nj] - 'A'] == false) {
			alphaV[mapV[ni][nj] - 'A'] = true;
			DFS(ni, nj, cnt + 1);
			alphaV[mapV[ni][nj] - 'A'] = false;
		}
	}
	if (MAX < cnt) MAX = cnt;
}

void run() {
	init();
	DFS(0, 0, 1);
	cout << MAX << endl;
	return;
}

int main() {
	run();
	return 0;
}