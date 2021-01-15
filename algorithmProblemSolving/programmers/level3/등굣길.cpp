#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	vector<vector<int>> map;
	vector<int> tmp(m+1, 0);
	for (int i = 0; i<n+1; i++) {
		map.push_back(tmp);
	}
	tmp.clear();
	for (int i = 0; i<puddles.size(); i++) {
		int x = puddles[i][0];
		int y = puddles[i][1];
		map[y - 1][x - 1] = -1;
	}
	for (int i = 0; i<m; i++) {
		map[0][i] = 1;
	}
	for (int i = 0; i<n; i++) {
		map[i][0] = 1;
	}
	for (int i = 1; i<n; i++) {
		for (int j = 1; j<m; j++) {
			if (map[i][j] == -1) {
				continue;
			}
			else {
				int l = map[i][j - 1];
				int u = map[i - 1][j];
				if (l == -1) l = 0;
				if (u == -1) u = 0;
				map[i][j] = l + u;
			}
		}
	}
	answer = map[n - 1][m - 1];
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	answer = answer % 1000000007;
	return answer;
}