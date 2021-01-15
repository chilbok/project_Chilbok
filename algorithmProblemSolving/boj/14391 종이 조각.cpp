#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int N, M;
int MAX = 0;
vector<vector<int>> mapV;

void init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		vector<int> tmpV;
		for (int j = 0; j < M; j++) {
			char tmp;
			cin >> tmp;
			tmpV.push_back(tmp-'0');
		}
		mapV.push_back(tmpV);
	}
	return;
}

void findAll() {
	for (int b = 0; b < (1 << (N * M)); b++) {
		//b -> 비트마스크
		//가로로 자를 친구들을 먼저 계산.
		int sum = 0;
		for (int i = 0; i < N; i++) {
			int tmpSum = 0;
			for (int j = 0; j < M; j++) {
				int idx = i * M + j;
				if ((b & (1 << idx)) == 0) {
					//idx번째 비트가 0 (가로)
					tmpSum = tmpSum * 10 + mapV[i][j];
				}
				else {
					//idx번째 비트가 1 (세로)
					sum += tmpSum;
					tmpSum = 0;
				}
			}
			sum += tmpSum;
		}
		//세로로 자를 친구들을 계산
		for (int j = 0; j < M; j++) {
			int tmpSum = 0;
			for (int i = 0; i < N; i++) {
				int idx = i * M + j;
				if ((b & (1 << idx)) != 0) {
					//idx번째 비트가 0 (가로)
					tmpSum = tmpSum * 10 + mapV[i][j];
				}
				else {
					//idx번째 비트가 1 (세로)
					sum += tmpSum;
					tmpSum = 0;
				}
			}
			sum += tmpSum;
		}
		if (MAX < sum) MAX = sum;
	}
}

void run() {
	init();
	findAll();
	cout << MAX << endl;
	return;
}

int main() {
	run();
	return 0;
}
