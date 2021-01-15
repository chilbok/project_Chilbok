#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>

using namespace std;

vector<string> numV;
int N, M;

void init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		numV.push_back(to_string(i + 1));
	}
	return;
}


void printNum(string str) {
	for (int i = 0; i < str.length(); i++) {
		printf("%c ", str.at(i));
	}
	printf("\n");
}

void dfs(int index, int cnt, string str) {
	if (cnt >= M) {
		printNum(str);
		return;
	}
	for (int i = index; i < N; i++) {
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