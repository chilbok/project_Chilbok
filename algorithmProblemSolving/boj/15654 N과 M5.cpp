#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>

using namespace std;

vector<string> numV;
vector<int> num;
int N, M;

void init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		numV.push_back(to_string(i+1));
	}
	num.push_back(0);
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		num.push_back(tmp);
	}
	sort(num.begin(), num.end());
	return;
}

bool find(string str, string n) {
	for (int i = 0; i < str.length(); i++) {
		if (str.at(i) == n.at(0)) return true;
	}
	return false;
}

void printNum(string str) {
	for (int i = 0; i < str.length(); i++) {
		int index = str.at(i) - '0';
		printf("%d ", num[index]);
	}
	printf("\n");
}

void dfs(int index, int cnt, string str) {
	if (cnt >= M) {
		printNum(str);
		return;
	}
	for (int i = 0; i < N; i++) {
		if (index == i) continue;
		if (find(str,numV[i])) continue;
		dfs(i, cnt + 1, str + numV[i]);
	}
}

void run() {
	init();
	for (int i = 0; i < N; i++) {
		dfs(i, 1, numV[i]);
	}
	return;
}

int main() {
	run();
}
