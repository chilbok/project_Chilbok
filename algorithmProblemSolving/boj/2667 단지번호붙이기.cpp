#pragma warning (disable:4996)
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#define MAX_VAL 25

using namespace std;

int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };
vector<vector<bool>> map(MAX_VAL, vector<bool>(MAX_VAL, false));
vector<vector<bool>> visit(MAX_VAL, vector<bool>(MAX_VAL, false));
vector<vector<int>> cnt(MAX_VAL, vector<int>(MAX_VAL, 0));
int N;

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string tmpStr;
		cin >> tmpStr;
		for (int j = 0; j < N; j++) {
			map[i][j] = tmpStr.at(j)-'0';
		}
	}
	return;
}

void dfs(pair<int,int> index, pair<int,int> start) {
	//cout << index.first << ", " << index.second << endl;
	cnt[start.first][start.second]++;
	visit[index.first][index.second] = true;
	for (int i = 0; i < 4; i++) {
		int ni = index.first + di[i];
		int nj = index.second + dj[i];
		if (ni < 0 || nj < 0 || ni >= N || nj >= N) continue;
		if (map[ni][nj]&&!visit[ni][nj]) {
			dfs(make_pair(ni, nj), start);
		}
	}
	return;
}

void print() {
	vector<int> answer;
	for (int i = 0; i < N;i++) {
		for (int j = 0; j < N; j++) {
			if (cnt[i][j] > 0)
				answer.push_back(cnt[i][j]);
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << endl;
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << '\n';
	}
}

void run() {
	init();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j]&&map[i][j]) {
				//cout <<"start ("<< i << ", " << j<<")" << endl;
				dfs({ i,j }, { i,j });
			}
		}
	}
	print();
	return;
}

int main() {
	run();
	return 0;
}