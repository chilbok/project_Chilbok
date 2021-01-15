#include <iostream>
#include <utility>
#include <vector>
#include <deque>
using namespace std;

int N, K, L;
vector<int> commands(10001, 0);
deque<pair<int, int>> snake;
vector<vector<int>> mapV;
int d = 2; // <<0 : L, 1 : U, 2 : R, 3 : D>>
int di[4] = { 0,-1,0,1 };
int dj[4] = { -1,0,1,0 };

void init() {
	cin >> N >> K;
	vector<vector<int>> tmpV(N, vector<int>(N, 0));
	mapV = tmpV;
	for (int i = 0; i < K; i++) {
		int ii, jj;
		cin >> ii >> jj;
		mapV[ii-1][jj-1] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int ii;
		char c;
		cin >> ii >> c;
		if (c == 'L') {
			commands[ii] = 3;
		}
		else if (c == 'D') {
			commands[ii] = 1;
		}
	}
	mapV[0][0] = 2;
	snake.push_back(make_pair(0, 0));
	return;
}

bool moveSnake(int d) {
	int ni = snake.front().first + di[d];
	int nj = snake.front().second + dj[d];
	pair<int, int> nP = make_pair(ni, nj);
	if ((ni < 0 || nj < 0 || ni > N-1 || nj > N-1) || mapV[ni][nj]==2) {
		return true;
	}
	else {
		if (mapV[ni][nj] == 0) {
			//사과를 못 먹으면
			mapV[snake.back().first][snake.back().second] = 0;
			snake.pop_back();
		}
		mapV[ni][nj] = 2;
		snake.push_front(nP);
		return false;
	}
}

void printM() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << mapV[i][j] << " ";
		}
		cout << endl;
	}
}

void run() {
	init();
	//printM();
	for (int i = 1; i < commands.size(); i++) {
		bool isEnd = moveSnake(d);
		if (isEnd) {
			cout << i << endl;
			return;
		}
		d = (d + commands[i]) % 4;
	}
	return;
}

int main() {
	run();
	return 0;
}