#include <iostream>
using namespace std;
#define MAX 50

int map[MAX][MAX];
int visited[MAX][MAX];
int w, h;

//방향
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void dfs(int x, int y);

int main() {

	while (1) {
		cin >> w >> h;
		int cnt = 0;
		if (w == 0 && h == 0) break;

		//visited 초기화
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) visited[i][j] = 0;
		}
		//map 초기화
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) cin >> map[i][j];
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] && !visited[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}

		cout << cnt<<'\n';

	}
	


	return 0;
}

void dfs(int x, int y) {
	if (visited[x][y] || !map[x][y]) return;//바다이거나 이미 방문한 곳이면 탐색할 필요 없음
	visited[x][y] = 1;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
			dfs(nx, ny);
		}
	}
}