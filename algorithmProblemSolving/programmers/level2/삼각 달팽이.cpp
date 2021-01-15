#include <string>
#include <vector>
#include <utility>

using namespace std;

int di[3] = { 1,0,-1 };
int dj[3] = { 0,1,-1 };

vector<int> makeAnswer(vector<vector<int>> v) {
	vector<int> result;
	for (int i = 0; i<v.size(); i++) {
		for (int j = 0; j<v[i].size(); j++) {
			result.push_back(v[i][j]);
		}
	}
	return result;
}

vector<int> solution(int n) {
	vector<int> answer;
	vector<vector<int>> vv(n);
	int tot = n*(n + 1) / 2;
	int idx = 0;
	pair<int, int> curP = make_pair(0, 0);
	for (int i = 0; i<n; i++) {
		vv[i].assign(i + 1, 0);
	}
	for (int i = 0; i < tot; i++) {
		vv[curP.first][curP.second] = i+1;
		int ni = curP.first + di[idx];
		int nj = curP.second + dj[idx];
		if (vv[ni][nj] != 0 || ni >= n || nj >= vv[ni].size() || ni < 0 || nj < 0) {
			idx = (idx + 1) % 3;
			curP = make_pair(curP.first + di[idx], curP.second + dj[idx]);
		}
		else {
			curP = make_pair(ni, nj);
		}
	}
	answer = makeAnswer(vv);
	return answer;
}