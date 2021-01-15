#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
vector<vector<int>> status(100, vector<int>(100, 0));

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			status[i][j] = tmp;
		}
	}
	return;
}

int calculStat(vector<int> v) {
	int result = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if (i == j) continue;
			result += status[v[i]][v[j]];
		}
	}
	return result;
}

void run() {
	init();
	int min = 100000;
	vector<int> player(N, 1);
	for (int i = 0; i < N / 2; i++) {
		player[i] = 0;
	}
	do {
		int tmpMin;
		vector<int> team1, team2;
		for (int i = 0; i < player.size(); i++) {
			if (player[i] == 0) {
				team1.push_back(i);
			}
			else {
				team2.push_back(i);
			}
		}
		tmpMin = abs(calculStat(team1) - calculStat(team2));
		if (tmpMin < min) {
			min = tmpMin;
		}
	} while (next_permutation(player.begin(), player.end()));
	cout << min << endl;
	return;
}

int main() {
	run();
	return 0;
}