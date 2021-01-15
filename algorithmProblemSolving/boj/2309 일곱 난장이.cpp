#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> miniMan(9);
int sumOfMan = 0;

void initMiniMan() {
	for (int i = 0; i < 9; i++) {
		int n;
		cin >> n;
		sumOfMan += n;
		miniMan[i] = n;
	}
}

void findSevenMan() {
	for (int i = 0; i < 8; i++) {
		for (int j = i+1; j < 9; j++) {
			if (miniMan[i] + miniMan[j] == (sumOfMan - 100)) {
				miniMan[i] = 0;
				miniMan[j] = 0;
				sort(miniMan.begin(), miniMan.end());
				return;
			}
		}
	}
}

void printV() {
	for (int i = 2; i < 9; i++) {
		cout << miniMan[i] << endl;
	}
}

void run() {
	initMiniMan();
	findSevenMan();
	printV();
}

int main() {
	run();
	return 0;
}
