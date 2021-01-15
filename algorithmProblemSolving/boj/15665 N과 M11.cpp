#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> arr;
vector<int> v;

void init() {
	cin >> n >> m;

	arr.resize(n);

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());
	return;
}

void DFS(int x)
{
	int use[10010];
	memset(use, 0, sizeof(use));

	v.push_back(arr[x]);
	if (v.size() == m) {
		for (int i = 0; i < v.size(); ++i) {
			printf("%d ", v[i]);
		}
		printf("\n");
		v.pop_back();
		return;
	}

	for (int i = 0; i < arr.size(); ++i) {
		if (!use[arr[i]]) {
			use[arr[i]] = 1;
			DFS(i);
		}
	}
	v.pop_back();
}

void run() {
	init();
	for (int i = 0; i < arr.size(); ++i) {
		if (i != 0 && arr[i] == arr[i - 1]) {
			continue;
		}
		DFS(i);
	}
	return;
}

int main() {
	run();
	return 0;
}