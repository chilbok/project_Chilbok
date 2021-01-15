#include <iostream>
#include <vector>
#include <utility>
#include <deque>

using namespace std;

int N, M, x, y, K;
vector<vector<int>> mapV;
vector<int> commands;
vector<int> diceNum(7, 0);
pair<int, int> curP;

void init() {
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++) {
		vector<int> tmpV;
		for (int j = 0; j < M; j++) {
			int tmpI;
			cin >> tmpI;
			tmpV.push_back(tmpI);
		}
		mapV.push_back(tmpV);
	}
	for (int i = 0; i < K; i++) {
		int tmpI;
		cin >> tmpI;
		commands.push_back(tmpI);
	}
	curP = make_pair(x, y);
	return;
}

void rollDice(int d) {
	int tmp = diceNum[1];
	int ni = curP.first;
	int nj = curP.second;
	switch (d) {
	case 1://R
		nj++;
		if (ni<0 || nj<0 || ni>N - 1 || nj>M - 1) return;
		diceNum[1] = diceNum[4];
		diceNum[4] = diceNum[6];
		diceNum[6] = diceNum[3];
		diceNum[3] = tmp;
		break;
	case 2://L
		nj--;
		if (ni<0 || nj<0 || ni>N - 1 || nj>M - 1) return;
		diceNum[1] = diceNum[3];
		diceNum[3] = diceNum[6];
		diceNum[6] = diceNum[4];
		diceNum[4] = tmp;
		break;
	case 3://U
		ni--;
		if (ni<0 || nj<0 || ni>N - 1 || nj>M - 1) return;
		diceNum[1] = diceNum[2];
		diceNum[2] = diceNum[6];
		diceNum[6] = diceNum[5];
		diceNum[5] = tmp;
		break;
	case 4://D
		ni++;
		if (ni<0 || nj<0 || ni>N - 1 || nj>M - 1) return;
		diceNum[1] = diceNum[5];
		diceNum[5] = diceNum[6];
		diceNum[6] = diceNum[2];
		diceNum[2] = tmp;
		break;
	}
	curP = make_pair(ni,nj);
	if (mapV[ni][nj] == 0) {
		mapV[ni][nj] = diceNum[6];
	}
	else {
		diceNum[6] = mapV[ni][nj];
		mapV[ni][nj] = 0;
	}
	cout << diceNum[1] << endl;
	return;
}

void run() {
	init();
	for (int i = 0; i < commands.size(); i++) {
		rollDice(commands[i]);
	}
	return;
}

int main() {
	run();
	return 0;
}