#include <vector>
#include <deque>
#include <iostream>
#include <utility>
using namespace std;
int K;
vector<deque<int>> cV(6, deque<int>(8, -1));
vector<pair<int, int>> commands;


void init() {
	for (int i = 1; i < 5; i++) {
		for (int j = 0; j < 8; j++) {
			char tmpC;
			cin >> tmpC;
			cV[i][j] = tmpC - '0';
		}
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		commands.push_back(make_pair(x, y));
	}
	return;
}

void spinC(int idx, int d) {
	if (d == 1) {
		//시계방향
		cV[idx].push_front(cV[idx].back());
		cV[idx].pop_back();
	}
	else {
		//반시계방향
		cV[idx].push_back(cV[idx].front());
		cV[idx].pop_front();
	}
	return;
}

void spinAll(int idx, int d) {
	vector<int> isSpin(5, 0);
	isSpin[idx] = d;
	for (int i = idx-1; i >= 1; i--) {
		//본인 기준 왼쪽
		if (isSpin[i + 1] == 0) continue;
		if (cV[i][2] != cV[i + 1][6]) isSpin[i] = isSpin[i + 1] * -1;
	}
	for (int i = idx+1; i <= 4; i++) {
		//본인 기준 오른 쪽
		if (isSpin[i - 1] == 0) continue;
		if (cV[i][6] != cV[i - 1][2]) isSpin[i] = isSpin[i - 1] * -1;
	}
	for (int i = 1; i < 5; i++) {
		if (isSpin[i] == 0) continue;
		spinC(i, isSpin[i]);
	}
}

int calculScore() {
	int result = 0;
	if (cV[1].front() == 1) result += 1;
	if (cV[2].front() == 1) result += 2;
	if (cV[3].front() == 1) result += 4;
	if (cV[4].front() == 1) result += 8;
	return result;
}

void run() {
	init();
	for (int i = 0; i < commands.size(); i++) {
		spinAll(commands[i].first, commands[i].second);
	}
	cout << calculScore() << endl;
	return;
}

int main() {
	run();
	return 0;
}