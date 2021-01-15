#include<iostream>
using namespace std;
int max(int, int);
int main() {
	int N, tmp, l, r;
	cin >> N;
	int** tri = new int*[N];
	for (int i = 0; i < N; i++) {
		tri[i] = new int[500];
	}
	for (int i = 0; i < N; i++) {
		tmp = i;
		for (int j = 0; j < tmp + 1; j++) {
			cin >> tri[i][j];
		}
	}
	for (int i = 1; i < N; i++) {
		tmp = i;
		for (int j = 0; j < tmp+1; j++) {
			if (j - 1 < 0) l = -1;
			else l = tri[i - 1][j - 1];
			if (j > i-1) r = -1;
			else r = tri[i - 1][j];
			tri[i][j] += max(l, r);
		}
	}

	int maxi = tri[N - 1][0];
	for (int i = 1; i < N; i++) {
		if (tri[N - 1][i] > maxi) maxi = tri[N - 1][i];
	}
	cout << maxi << endl;
	return 0;
}

int max(int x, int y)
{
	if (x > y) return x;
	else return y;
}
