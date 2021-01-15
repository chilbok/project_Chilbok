#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> mapV;
vector<vector<int>> backUp;
vector<vector<pair<int, int>>> points(3,vector<pair<int,int>>());
int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };
int MAX = 0;

void init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		vector<int> tmpV;
		for (int j = 0; j < M; j++) {
			int tmpI;
			cin >> tmpI;
			points[tmpI].push_back(make_pair(i, j));
			tmpV.push_back(tmpI);
		}
		mapV.push_back(tmpV);
	}
	backUp = mapV;
	return;
}

void wuhan(pair<int,int> v) {
	mapV[v.first][v.second] = 2;
	for (int i = 0; i < 4; i++) {
		int ni = v.first + di[i];
		int nj = v.second + dj[i];
		if (ni<0 || nj<0 || ni>N - 1 || nj>M - 1 || mapV[ni][nj] == 2 || mapV[ni][nj] == 1) continue;
		wuhan(make_pair(ni, nj));
	}
	return;
} //어쩌면 BFS가 더 빠르지 않을까..?

void findSafe(vector<vector<int>> v) {
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (v[i][j] == 0) cnt++;
		}
	}
	if (cnt > MAX) MAX = cnt;
	return;
}

void run() {
	init();

	vector<int> comb(points[0].size(), 0);
	for (int i = 0; i < 3; i++) {
		comb[i] = 1;
	}
	do {
		mapV = backUp;
		vector<pair<int, int>> makeWall;
		for (int i = 0; i < comb.size(); i++) {
			if (comb[i] == 1) {
				mapV[points[0][i].first][points[0][i].second] = 1;
			}
		}
		for (int i = 0; i < points[2].size(); i++) {
			wuhan(points[2][i]);
		}
		findSafe(mapV);
	} while (prev_permutation(comb.begin(), comb.end()));
	cout << MAX << endl;
	return;
}

int main() {
	run();
	return 0;
}