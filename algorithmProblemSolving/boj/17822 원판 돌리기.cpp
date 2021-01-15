#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, t;
bool visit[51][51];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void initV() {
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			visit[i][j] = false;
		}
	}
}

pair<int,int> sumPan(vector<vector<int>> v) {
	pair<int, int> p;
	int sum = 0;
	int nums = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (v[i][j] == 0) continue;
			sum += v[i][j];
			nums++;
		}
	}
	p = { sum,nums };
	return p;
}

void calPan(vector<vector<int>>& v) {
	int sum;
	float avg;
	pair<int, int> p = sumPan(v);
	sum = p.first;
	avg = (float)sum / p.second;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (v[i][j] == 0) continue;
			if (v[i][j] > avg) {
				v[i][j]--;
			}
			else if (v[i][j] < avg) {
				v[i][j]++;
			}
		}
	}

}

void move(vector<int>& v, int d) {
	if (d == 0) { //시계방향
		int tmp = v[v.size() - 1];
		for (int i = v.size() - 1; i > 0; i--) {
			v[i] = v[i - 1];
		}
		v[0] = tmp;
	}
	else { //반시계방향
		int tmp = v[0];
		for (int i = 0; i < v.size() - 1; i++) {
			v[i] = v[i + 1];
		}
		v[v.size() - 1] = tmp;
	}
}

void check(vector<vector<int>> &v) {
	initV();
	vector<pair<int, int>> target;
	int val;
	bool change = false;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (v[i][j] == 0) continue;
			val = v[i][j];
			for (int k = 0; k < 4; k++) {
				int xx = j + dx[k];
				int yy = i + dy[k];

				if (yy < 0) {
					continue;
				}
				if (yy > v.size() - 1) {
					continue;
				}
				if (xx < 0) {
					xx = v[i].size() - 1;
				}
				if (xx > v[i].size()-1) {
					xx = 0;
				}
				if (!visit[yy][xx] && v[yy][xx] == val) {
					//visit[yy][xx] = true;
					target.push_back({ i,j });
					change = true;
				}
			}
		}
	}
	if (change) {
		for (int i = 0; i < target.size(); i++) {
			v[target[i].first][target[i].second] = 0;
			
		}
		target.clear();
	}
	else {
		calPan(v);
		target.clear();
	}
}

int main() {
	vector<int> tmp;
	vector<vector<int>> v;
	int a, b, c; //a배수 원판을 b방향으로 c칸
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int aa;
			cin >> aa;
			tmp.push_back(aa);
		}
		v.push_back(tmp);
		tmp.clear();
	}
	for (int i = 0; i < t; i++) {
		cin >> a >> b >> c;
		for (int i = 0; i < v.size(); i++) {
			if ((i + 1) % a == 0) {
				for (int j = 0; j < c; j++) {
					move(v[i], b);
				}
			}
		}
		check(v);
	}cout << sumPan(v).first << endl;
	return 0;
}