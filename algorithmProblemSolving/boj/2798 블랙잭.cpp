#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<time.h>

using  namespace std;

int main() {
	int N, M, tmp = 0, sum = 0;
	bool success = false;
	bool exist = false;
	cin >> N >> M;
	vector<int>card;
	vector<int>sumV;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		card.push_back(tmp);
	}
	//입력값 초기화
	
	//sort(card.begin(), card.end(), greater<int>());
	//입력받은 카드를 내림차순 정렬
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				sum = card[i] + card[j] + card[k];
				if (M == sum) {
					cout << sum << endl;
					i = N - 2;
					j = N - 1;
					success = true;
					break;
				}
				else if (M > sum) {
					exist = true;
					sumV.push_back(sum);
				}
			}
		}
	}
	if ((!success)&&exist) {
		sort(sumV.begin(), sumV.end(), greater<int>());
		cout << sumV[0] << endl;
	}
	return 0;
}