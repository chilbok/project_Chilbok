#include<vector>
#include<iostream>
#include<utility>

using namespace std;

int N, M;
pair<int, int> red, blue, goal;
vector<vector<char>> mapV;
bool gameOver = false;
bool gameClear = false;
int MIN = 11;

void init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		vector<char> tmpV;
		for (int j = 0; j < M; j++) {
			char tmpC;
			cin >> tmpC;
			if (tmpC == 'R') {
				tmpC = '.';
				red = make_pair(i, j);
			}
			else if (tmpC == 'B') {
				tmpC = '.';
				blue = make_pair(i, j);
			}
			else if (tmpC == 'O') {
				tmpC = '.';
				goal = make_pair(i, j);
			}
			tmpV.push_back(tmpC);
		}
		mapV.push_back(tmpV);
	}
	return;
}

pair<pair<int, int>,bool> moveBall(pair<int, int> p1, pair<int,int> p2, int d) {
	pair<int, int> point = p1;
	//p1 : 움직일 공, p2 : 비교대상
	switch (d) {
	case 0: //L
		for (int i = point.second; i > -1; i--) {
			pair<int, int> tmpPair = make_pair(point.first, i);
			if (goal == tmpPair) {
				return make_pair(make_pair(-1, -1), true);
			}
			else if (tmpPair == p2 || mapV[tmpPair.first][tmpPair.second]=='#') {
				return make_pair(make_pair(point.first, i + 1), false);
			}
		}
		break;
	case 1: //R
		for (int i = point.second; i < M; i++) {
			pair<int, int> tmpPair = make_pair(point.first, i);
			if (goal == tmpPair) {
				return make_pair(make_pair(-1, -1), true);
			}
			else if (tmpPair == p2 || mapV[tmpPair.first][tmpPair.second] == '#') {
				return make_pair(make_pair(point.first, i - 1), false);
			}
		}
		break;
	case 2: //U
		for (int i = point.first; i > -1; i--) {
			pair<int, int> tmpPair = make_pair(i,point.second);
			if (goal == tmpPair) {
				return make_pair(make_pair(-1, -1), true);
			}
			else if (tmpPair == p2 || mapV[tmpPair.first][tmpPair.second] == '#') {
				return make_pair(make_pair(i + 1, tmpPair.second), false);
			}
		}
		break;
	case 3: //D
		for (int i = point.first; i < M; i++) {
			pair<int, int> tmpPair = make_pair(i, point.second);
			if (goal == tmpPair) {
				return make_pair(make_pair(-1, -1), true);
			}
			else if (tmpPair == p2 || mapV[tmpPair.first][tmpPair.second] == '#') {
				return make_pair(make_pair(i - 1, tmpPair.second), false);
			}
		}
		break;
	}
}

void DFS(pair<int, int> r, pair<int, int> b, int cnt) {
	if (gameOver == true) {
		gameOver = false;
		gameClear = false;
		return;
	}
	if (gameClear == true && gameOver == false) {
		if (cnt < MIN) MIN = cnt;
		gameOver = false;
		gameClear = false;
		return;
	}
	if (cnt > 10) {
		return;
	}
	pair<pair<int, int>,bool> tmpR, tmpB;
	//L
	if (r.second < b.second) {
		tmpR = moveBall(r, b, 0);
		tmpB = moveBall(b, tmpR.first, 0);
		if (tmpR.second) gameClear = true;
		if (tmpB.second) gameOver = true;
		if (tmpR.first != r || tmpB.first != b) {
			DFS(tmpR.first, tmpB.first, cnt + 1);
		}
	}
	else {
		tmpB = moveBall(b, r, 0);
		tmpR = moveBall(r, tmpB.first, 0);
		if (tmpR.second) gameClear = true;
		if (tmpB.second) gameOver = true;
		if (tmpR.first != r || tmpB.first != b) {
			DFS(tmpR.first, tmpB.first, cnt + 1);
		}
	}
	//R
	if (r.second > b.second) {
		tmpR = moveBall(r, b, 1);
		tmpB = moveBall(b, tmpR.first, 1);
		if (tmpR.second) gameClear = true;
		if (tmpB.second) gameOver = true; 
		if (tmpR.first != r || tmpB.first != b) {
			DFS(tmpR.first, tmpB.first, cnt + 1);
		}
	}
	else {
		tmpB = moveBall(b, r, 1);
		tmpR = moveBall(r, tmpB.first, 1);
		if (tmpR.second) gameClear = true;
		if (tmpB.second) gameOver = true;
		if (tmpR.first != r || tmpB.first != b) {
			DFS(tmpR.first, tmpB.first, cnt + 1);
		}
	}
	//U
	if (r.first < b.first) {
		tmpR = moveBall(r, b, 2);
		tmpB = moveBall(b, tmpR.first, 2);
		if (tmpR.second) gameClear = true;
		if (tmpB.second) gameOver = true;
		if (tmpR.first != r || tmpB.first != b) {
			DFS(tmpR.first, tmpB.first, cnt + 1);
		}
	}
	else {
		tmpB = moveBall(b, r, 2);
		tmpR = moveBall(r, tmpB.first, 2);
		if (tmpR.second) gameClear = true;
		if (tmpB.second) gameOver = true;
		if (tmpR.first != r || tmpB.first != b) {
			DFS(tmpR.first, tmpB.first, cnt + 1);
		}
	}
	//D
	if (r.first > b.first) {
		tmpR = moveBall(r, b, 3);
		tmpB = moveBall(b, tmpR.first, 3);
		if (tmpR.second) gameClear = true;
		if (tmpB.second) gameOver = true;
		if (tmpR.first != r || tmpB.first != b) {
			DFS(tmpR.first, tmpB.first, cnt + 1);
		}
	}
	else {
		tmpB = moveBall(b, r, 3);
		tmpR = moveBall(r, tmpB.first, 3);
		if (tmpR.second) gameClear = true;
		if (tmpB.second) gameOver = true;
		if (tmpR.first != r || tmpB.first != b) {
			DFS(tmpR.first, tmpB.first, cnt + 1);
		}
	}
	return;

}

void run() {
	init();
	DFS(red, blue, 0);
	if (MIN == 11) MIN = -1;
	cout << MIN << endl;
	return;
}

int main() {
	run();
	return 0;
}