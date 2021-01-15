#include <iostream>
using namespace std;
int main() {
	int N = 0;
	float max = 0, sum = 0;
	float avg;
	cin >> N;
	if (N < 0) return 0;
	else {
		float* score = new float[N];
		cin >> score[0];
		max = score[0];
		sum = score[0];
		for (int i = 1; i < N; i++) {
			cin >> score[i];
			if (max < score[i]) max = score[i];
			sum += score[i];
		}
		avg = (sum / max * 100) / N;
		cout << avg;
		delete[] score;
		score = NULL;
	}
	return 0;
}