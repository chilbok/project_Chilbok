#include<iostream>
#include<vector>
#include<iomanip>
#include<queue>
#include<algorithm>
#define max_n 21
#define max_val 999
using namespace std;

int map[max_n][max_n];
int distArr[max_n][max_n];
int n;
int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };
pair<int, int> minLoca = { -1,-1 };
int minDist = max_val;

typedef struct Fish {
	int i;
	int j;
	int size;
	int exp = 0;
	int cnt = 0;
	Fish() {}
	Fish(int i, int j, int size) :i(i), j(j), size(size) {

	}
	void printCnt() {
		cout << cnt << endl;
	}
	void sizeUp() {
		if (exp == size) {
			size++;
			exp = 0;
			return;
		}
		return;
	}
}F;

F shark;

void initDist() {
	for (int i = 0; i < max_n; i++) {
		for (int j = 0; j < max_n; j++) {
			distArr[i][j] = max_val;
		}
	}
}
void setMap() {
	cin >> ::n;
	int tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			if (tmp == 9) {
				Fish tmpF(i, j, 2);
				tmp = 0;
				shark = tmpF;
			}
			map[i][j] = tmp;
		}
	}
}
void printArr() {
	cout << "-------------  m a p  -------------" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << "------------- d i s t -------------" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (distArr[i][j] == max_val)
				cout << setw(3) << "-" << " ";
			else
				cout << setw(3) << distArr[i][j] << " ";
		}
		cout << endl;
	}
}
bool isIn(int ii, int jj) {
	if (ii < 0 || ii >= n || jj < 0 || jj >= n) return false;
	return true;
}
void bfs(int ii, int jj) {
	queue<Fish> q;
	distArr[ii][jj] = 0;
	q.push(shark);
	while (!q.empty()) {
		Fish cur = q.front();
		q.pop();
		int i = cur.i;
		int j = cur.j;
		for (int k = 0; k < 4; k++) {
			int ni = i + di[k];
			int nj = j + dj[k];
			if (!isIn(ni, nj)) continue;
			if (distArr[ni][nj] != max_val || map[ni][nj] > shark.size) continue;
			distArr[ni][nj] = distArr[i][j] + 1;
			if (map[ni][nj] != 0 && map[ni][nj] < shark.size) {
				if (minDist > distArr[ni][nj]) {
					minLoca = { ni,nj };
					minDist = distArr[ni][nj];
				}
				else if (minDist == distArr[ni][nj]) {
					if (minLoca.first > ni) {
						minLoca = { ni,nj };
						minDist = distArr[ni][nj];
					}
					else if(minLoca.first==ni){
						if (minLoca.second > nj) {
							minLoca = { ni,nj };
							minDist = distArr[ni][nj];
						}
					}
				}
			}
			q.push(Fish(ni, nj, 0));
		}
	}
}
void eatThemAll(int i, int j, int dst) {
	map[i][j] = 0;
	shark.exp++;
	shark.sizeUp();
	shark.i = i;
	shark.j = j;
	shark.cnt += dst;
}
void run() {
	setMap();
	while (true) {
		initDist();
		bfs(shark.i, shark.j);
		if (minLoca.first != -1 && minLoca.second != -1) {
			eatThemAll(minLoca.first, minLoca.second, minDist);
			minLoca = { -1,-1 };
			minDist = max_val;
		}
		else {
			break;
		}
	}
}
int main() {
	run();
	shark.printCnt();
}