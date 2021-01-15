#include<iostream>
#include<cmath>
#include<math.h>
using namespace std;
int main() {
	cin.tie(NULL);
	int N, tmp, max, min;
	double sum = 0;
	cin >> N;
	int mid, mid_index = (N + 1) / 2;
	int counting[8001] = { 0 };
	string s = "";
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		sum += tmp;
		counting[tmp + 4000]++;
	}
	// 카운팅 배열 초기화 counting[n] -> n-4000의 개수
	sum = sum / N;
	cout << round(sum) << endl;
	//산술평균
	tmp = 0;
	for (int i = 0; i < 8001; i++) {
		tmp += counting[i];
		if (tmp >= mid_index) {
			mid = i - 4000;
			break;
		}
	}
	cout << mid << endl;
	//중앙값
	tmp = 0;
	int tmp_index = 0;
	int count = 0;
	for (int i = 0; i < 8001; i++) {
		if (tmp <= counting[i]) {
			tmp = counting[i];
			tmp_index = i;
		}
	}
	int wow;
	for (int i = 0; i <tmp_index+1; i++) {
		if (counting[i] == counting[tmp_index]) {
			wow = i;
			count++;
			if (count > 1) break;
		}
	}
	cout << wow - 4000 << "\n";
	for (int i = 0; i < 8001; i++) {
		if (counting[i] != 0) {
			min = i - 4000;
			break;
		}
	}
	//최솟값
	for (int i = 8000; i > -1; i--) {
		if (counting[i] != 0) {
			max = i - 4000;
			break;
		}
	}
	//최댓값
	cout << max - min << endl;
	//범위
	return 0;
}