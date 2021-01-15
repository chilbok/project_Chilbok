#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maximum = -1000000001;
int minimum = 1000000001;

vector<int> numV;
int operArr[4] = { 0,0,0,0 };
vector<int> operV; // 0 : +, 1 : -, 2 : *, 3 : /
vector<int> checkOper;

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int min(int a, int b) {
	if (a < b) return a;
	else return b;
}

void initV() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		numV.push_back(tmp);
	}
	for (int i = 0; i < 4; i++) {
		int tmp;
		cin >> tmp;
		operArr[i] = tmp;
	}
	return;
}

void dfs(int pl, int mi, int mu, int de, int num, int cnt) {
	if (cnt >= numV.size()) {
		maximum = max(maximum, num);
		minimum = min(minimum, num);
		return;
	}
	for (int i = 0; i < 4; i++) {
		switch (i) {
		case 0:
			if (pl <= 0) continue;
			dfs(pl - 1, mi, mu, de, num + numV[cnt], cnt + 1);
			break;
		case 1:
			if (mi <= 0) continue;
			dfs(pl, mi - 1, mu, de, num - numV[cnt], cnt + 1);
			break;
		case 2:
			if (mu <= 0) continue;
			dfs(pl, mi, mu - 1, de, num * numV[cnt], cnt + 1);
			break;
		case 3:
			if (de <= 0) continue;
			dfs(pl, mi, mu, de - 1, num / numV[cnt], cnt + 1);
			break;
		}
	}
}

void run() {
	initV();
	dfs(operArr[0], operArr[1], operArr[2], operArr[3], numV[0], 1);
	cout << maximum << endl << minimum << endl;
	return;
}

int main() {
	run();
	return 0;
}