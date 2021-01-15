#pragma warning (disable:4996)
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
#define MAX_VALUE 1001

using namespace std;

typedef struct emo {
	int disp;
	int clip;
	int time;
}e;

vector<vector<bool>> visit(MAX_VALUE, vector<bool>(MAX_VALUE,false));
int S;

void init() {
	cin >> S;
	return;
}

int bfs(e index) {
	queue<e> q;
	q.push(index);
	visit[index.disp][index.clip];
	while (!q.empty()) {
		e tmp = q.front();
		q.pop();
		if (tmp.disp == S) return tmp.time;
		if (0 < tmp.disp && tmp.disp < MAX_VALUE) {
			if (!visit[tmp.disp][tmp.disp]) {
				visit[tmp.disp][tmp.disp] = true;
				q.push({ tmp.disp,tmp.disp,tmp.time + 1 });
			}
			if (tmp.clip > 0 && tmp.disp + tmp.clip < MAX_VALUE) {
				if (!visit[tmp.disp + tmp.clip][tmp.clip]) {
					visit[tmp.disp + tmp.clip][tmp.clip] = true;
					q.push({ tmp.disp + tmp.clip, tmp.clip, tmp.time + 1 });
				}
			}
			if (!visit[tmp.disp - 1][tmp.clip]) {
				visit[tmp.disp - 1][tmp.clip] = true;
				q.push({ tmp.disp - 1,tmp.clip,tmp.time + 1 });
			}
		}
	}
}

void run() {
	init();
	cout << bfs({ 1,0,0 }) << endl;
	return;
}

int main() {
	run();
	return 0;
}