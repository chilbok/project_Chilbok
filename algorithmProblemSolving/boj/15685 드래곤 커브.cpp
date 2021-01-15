#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
vector<vector<string>> dc;
bool map[102][102] = { false, };
string spit(char k) {
	switch (k) {
	case '0':
		return "1";
		break;
	case '1':
		return "2";
		break;
	case '2':
		return "3";
		break;
	case '3':
		return "0";
		break;
	}
	return "-1";
}

void setDc() {
	vector<string> tmp;
	tmp = { "0","1","2","3" };
	dc.push_back(tmp);
	tmp.clear();
	for (int i = 1; i < 11; i++) {
		//i = generation;
		vector<string> tmp_v = dc[i-1];
		for (int j = 0; j < tmp_v.size(); j++) {
			for (int k = tmp_v[j].length() - 1; k > -1; k--) {
				tmp_v[j] += spit(tmp_v[j].at(k));
			}
		}
		dc.push_back(tmp_v);
	}
}

void draw(int x, int y, int d, int g) {
	map[y][x] = true;
	int _x = x;
	int _y = y;
	for (int i = 0; i < dc[g][d].length(); i++) {
		char dd = dc[g][d].at(i);
		switch (dd) {
		case '0':
			_x = _x + dx[0];
			_y = _y + dy[0];
			map[_y][_x] = true;
			break;
		case '1':
			_x = _x + dx[1];
			_y = _y + dy[1];
			map[_y][_x] = true;
			break;
		case '2':
			_x = _x + dx[2];
			_y = _y + dy[2];
			map[_y][_x] = true;
			break;
		case '3':
			_x = _x + dx[3];
			_y = _y + dy[3];
			map[_y][_x] = true;
			break;
		}
	}
}

bool check(int i, int j) {
	if (!map[i][j]) return false;
	if (!map[i+1][j]) return false;
	if (!map[i][j+1]) return false;
	if (!map[i+1][j+1]) return false;
	return true;
}

int countB() {
	int result = 0;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (check(i,j)) {
				result++;
			}
		}
		
	}
	return result;
}

int main() {
	int n;
	int x, y, d, g;
	//n: 커브 개수
	// x ,y : 커브 시작 좌표 d : 방향 g : 세대
	setDc();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> d >> g;
		draw(x, y, d, g);
	}

	cout << countB() << endl;
	return 0;
}