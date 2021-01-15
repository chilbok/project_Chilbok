#include<iostream>
using namespace std;
int max(int, int);
struct jump {
	int j = 0;
	int jj = 0;
};
int main() {
	int N;
	cin >> N;
	jump* score = new jump[N+1];
	int* s = new int[N + 1];
	s[0] = 0;
	for (int i = 1; i < N+1; i++) {
		cin >> s[i];
	}
	score[1].j = s[1];
	score[2].j = s[1] + s[2];
	score[2].jj = s[2];
	for (int i = 3; i < N + 1; i++) {
		score[i].j = score[i - 1].jj + s[i];
		score[i].jj = max(score[i-2].j, score[i - 2].jj) + s[i];
	}
	cout << max(score[N].j, score[N].jj) << endl;
	return 0;
}

int max(int x, int y)
{
	if (x > y) return x;
	else return y;
}
