#include <vector>
#include <iostream>
#include <deque>
using namespace std;

typedef struct Camera {
	int i, j;
	int camType;
	int dir;
	Camera() {};
	Camera(int ii, int jj, int cT) {
		i = ii;
		j = jj;
		camType = cT;
	}
}C;

int N, M;
vector<vector<int>> mapV;
vector<C> camV;
int MAX = 0;

void init() {
	cin >> N >> M;
	mapV.assign(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mapV[i][j];
			if (mapV[i][j] >= 1 && mapV[i][j] <= 5) {
				camV.push_back(Camera(i, j, mapV[i][j]));
				mapV[i][j] = 0;
			}
		}
	}
	return;
}

vector<vector<int>> watch(vector<vector<int>> v, C c, int dd) {
	vector<vector<int>> result = v;
	deque<bool> way(4,false); //URDL
	switch (c.camType) {
	case 1:
		way[1] = true;
		break;
	case 2:
		way[1] = true;
		way[3] = true;
		break;
	case 3:
		way[0] = true;
		way[1] = true;
		break;
	case 4:
		way[0] = true;
		way[1] = true;
		way[3] = true;
		break;
	case 5:
		way[0] = true;
		way[1] = true;
		way[2] = true;
		way[3] = true;
		break;
	}
	//아 돌리고 돌리고오오
	for (int i = 0; i < dd; i++) {
		way.push_back(way.front());
		way.pop_front();
	} 
	if (way[0]) {
		//위쪽 방향
		for (int i = c.i; i > -1; i--) {
			if (result[i][c.j] == 6) break;
			result[i][c.j] = -1;
		}
	}
	if (way[1]) {
		//오른쪽 방향
		for (int j = c.j; j < M; j++) {
			if (result[c.i][j] == 6) break;
			result[c.i][j] = -1;
		}
	}
	if (way[2]) {
		//아래쪽 방향
		for (int i = c.i; i < N; i++) {
			if (result[i][c.j] == 6) break;
			result[i][c.j] = -1;
		}
	}
	if (way[3]) {
		//왼쪽 방향
		for (int j = c.j; j > -1; j--) {
			if (result[c.i][j] == 6) break;
			result[c.i][j] = -1;
		}
	}
	return result;
}

int findSafeP(vector<vector<int>> v) {
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] == -1|| v[i][j] == 6) result ++;
		}
	}
	return result;
}

void DFS(vector<vector<int>> v, int idx) {
	if (idx == camV.size()) {
		int tmp = findSafeP(v);
		if (MAX < tmp) MAX = tmp;
		return;
	}
	for (int i = 0; i < 4; i++) {
		DFS(watch(v, camV[idx], i), idx+1);
	}
	return;
}

void run() {
	init();
	DFS(mapV, 0);
	cout << M*N-MAX << endl;
	return;
}

int main() {
	run();
	return 0;
}