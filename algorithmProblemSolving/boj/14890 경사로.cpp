#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, L;
vector<vector<int>> mapV;
vector<vector<int>> backUp;
vector<vector<bool>> isAdd;
int CNT = 0;

void init() {
	cin >> N >> L;
	mapV.assign(N, vector<int>(N, 0));
	backUp.assign(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mapV[i][j];
			backUp[j][i] = mapV[i][j];
		}
	}
	return;
}

void check() {
	isAdd.assign(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++) {
		int curN = mapV[i][0];
		int len = 1;
		int startIdx = 0;
		for (int j = 1; j < N; j++) {
			if (mapV[i][j] == curN) {
				len++;
			}
			else if(mapV[i][j]>curN){
				//이어진 칸의 마지막 인덱스는 j-1
				if (abs(curN - mapV[i][j]) > 1||len<L) {
					//칸의 차이가 1보다 크다면
					CNT++;
					break;
				}
				else {
					int tmpCNT = 0;
					for (int k = startIdx; k < j; k++) {
						if (isAdd[i][k] == false) tmpCNT++;
					}
					if (tmpCNT < L) {
						CNT++;
						break;
					}
					for (int k = 0; k < L; k++) {
						isAdd[i][j - 1 - k] = true;
					}
					len = 1;
					startIdx = j;
					curN = mapV[i][j];
				}
			}
			else if (mapV[i][j] < curN) {
				if (abs(curN - mapV[i][j]) > 1||j+L-1>=N) {
					//칸의 차이가 1보다 크다면 || 경사로를 놓으면 맵을 벗어나는 경우
					CNT++;
					break;
				}
				else {
					int tmpNum = mapV[i][j];
					int tmpCntNext = 0;
					for (int k = j; k < N; k++) {
						if (mapV[i][k] != tmpNum) break;
						tmpCntNext++;
					}
					if (tmpCntNext < L) {
						CNT++;
						break;
					}
					else {
						for (int k = 0; k < L; k++) {
							isAdd[i][j + k] = true;
						}
						len = 1;
						startIdx = j;
						curN = mapV[i][j];
					}
				}
			}
		}
	}
	return;
}


void run() {
	init();
	check();
	mapV = backUp;
	check();
	cout << 2 * N - CNT << endl;
	return;
}

int main() {
	run();
	return 0;
}