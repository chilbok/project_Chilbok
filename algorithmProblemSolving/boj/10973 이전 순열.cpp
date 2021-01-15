#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> numV;

void initNumV() {
	numV.clear();
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		numV.push_back(tmp);
	}
	return;
}

void findNext() {
	vector<int> tmpV = numV;
	bool check = false;
	do {
		if (check) {
			for (int i = 0; i < tmpV.size(); i++) {
				cout << tmpV[i] << " ";
			}
			cout << endl;
			return;
		}
		check = true;
	} while (prev_permutation(tmpV.begin(), tmpV.end()));
	cout << -1 << endl;
	return;
}

void run() {
	initNumV();
	findNext();
	return;
}

int main() {
	run();
	return 0;
}