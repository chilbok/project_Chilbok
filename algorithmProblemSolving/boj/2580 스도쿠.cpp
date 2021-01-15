#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> mapV;

vector<vector<bool>> garo(9, vector<bool>(10, false));
vector<vector<bool>> sero(9, vector<bool>(10, false));
vector<vector<bool>> nemo(9, vector<bool>(10, false));

void init() {
	for (int i = 0; i < 9; i++) {
		vector<int> tmp;
		for (int j = 0; j < 9; j++) {
			int num;
			cin >> num;
			tmp.push_back(num);
			if (num != 0) {
				garo[i][num] = true;
				sero[j][num] = true;
				nemo[(i / 3) * 3 + (j / 3)][num] = true;
			}
		}
		mapV.push_back(tmp);
	}
	return;
}

void printV(vector<vector<int>> v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}
void printV(vector<vector<bool>> v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}
void DFS(int cnt) {
	int ii = cnt / 9;
	int jj = cnt % 9;
	if (cnt == 81) {
		printV(mapV);
		exit(0);
		//return;
	}
	if (mapV[ii][jj] == 0) {
		for (int i = 1; i < 10; i++) {
			if ((garo[ii][i] == false)&&(sero[jj][i] == false)&& (nemo[(ii / 3) * 3 + (jj / 3)][i] == false)) {
				garo[ii][i] = true;
				sero[jj][i] = true;
				nemo[(ii / 3) * 3 + (jj / 3)][i] = true;
				mapV[ii][jj] = i;
				DFS(cnt + 1);
				garo[ii][i] = false;
				sero[jj][i] = false;
				nemo[(ii / 3) * 3 + (jj / 3)][i] = false;
				mapV[ii][jj] = 0;
			}
		}
	}
	else {
		DFS(cnt + 1);
	}
}

void run() {
	init();
	/*cout << "--------------------------------------------\n";
	printV(garo);
	cout << "--------------------------------------------\n";
	printV(sero);
	cout << "--------------------------------------------\n";
	printV(nemo);
	cout << "--------------------------------------------\n";
	*/
	DFS(0);
	return;
}

int main() {
	run();
	return 0;
}