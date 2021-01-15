#pragma warning (disable:4996)
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
#define MAX_VALUE 100001

using namespace std;

vector<int> d(MAX_VALUE, 0);
vector<bool> visit(MAX_VALUE, false);
int N, K;


void init() {
	cin >> N >> K;
	return;
}

void bfs(int index) {
	queue<int> q;
	q.push(index);
	visit[index] = true;
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		int ni = tmp * 2;
		if (ni >= 0 && ni < MAX_VALUE) {
			if (!visit[ni]) {
				d[ni] = d[tmp];
				visit[ni] = true;
				q.push(ni);
			}
		}
		ni = tmp - 1;
		if (visit[K]) return;
		if (ni >= 0 && ni < MAX_VALUE) {
			if (!visit[ni]) {
				d[ni] = d[tmp] + 1;
				visit[ni] = true;
				q.push(ni);
			}
		}
		ni = tmp + 1;
		if (ni >= 0 && ni < MAX_VALUE) {
			if (!visit[ni]) {
				d[ni] = d[tmp] + 1;
				visit[ni] = true;
				q.push(ni);
			}
		}
		
	}
}

void run() {
	init();
	bfs(N);
	cout << d[K] << endl;
	return;
}

int main() {
	run();
	return 0;
}