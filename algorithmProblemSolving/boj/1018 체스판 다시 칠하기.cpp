#include<iostream>
#include<cstdlib>
using namespace std;
int main() {
	int M, N, count = 33;
	bool check = false;
	cin >> N >> M;
	char** chess = new char*[N];
	for (int i = 0; i < N; i++) {
		chess[i] = new char[M];
	}
	for (int i = 0; i < N; i++) {
		cin >> chess[i];
	}
	int iter = (N - 7)*(M - 7); //검색해야하는 8*8크기의 체스판 개수
	// W=1. B=-1
	int sumW = 0, sumB = 0;
	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) { //시작점 지정
			//chess[i][j]에서 시작 chess[i+7][j+7]까지 반복
			sumW = 0, sumB = 0; // 체스판의 합을 초기화
			for (int k = 0; k < 8; k++) {
				for (int l = 0; l < 8; l++) {
					check = !check;
					//cout << check << " ";
					if (check) { //check = true (W인지 검사)
						if (chess[i + k][j + l] == 'B') sumW += 1;//W스타트
						else if (chess[i + k][j + l] == 'W') sumB += 1; //B스타트
					}
					else if (!check) { //check = flase (B인지 검사)
						if (chess[i + k][j + l] == 'W') sumW += 1;//W스타트
						else if (chess[i + k][j + l] == 'B') sumB += 1; //B스타트

					}
				}
				check = !check;
				//cout << endl;
			}
			//chess판에서 바꿔야하는 경우의 수 확인 완료
			if (sumW < sumB) {
				if (count > sumW) count = sumW;
				}
			else {
				if (count > sumB) count = sumB;
				}
		}
	}
	
	cout  << count;
	return 0;
}