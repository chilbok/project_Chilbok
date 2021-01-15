#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int N;
int MAX = 0;
vector<vector<int>> mapV;

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		vector<int> tmpV;
		for (int j = 0; j < N; j++) {
			int tmpI;
			cin >> tmpI;
			tmpV.push_back(tmpI);
		}
		mapV.push_back(tmpV);
	}
	return;
}

vector<vector<int>> move(vector<vector<int>> vv, int d) {
	vector<vector<int>> result = vv;
	vector<pair<int,int>> check;
	check.push_back(make_pair(-1, -1));
	switch (d) {
	case 0://L
		for (int i = 0; i < N; i++) {
			//각각의 행에 대해 시행
			for (int j = 1; j < N; j++) {
				if (result[i][j] == 0) continue;
				int tmpNum = result[i][j];
				result[i][j] = 0;
				for (int k = j-1; k > -1; k--) {
					if (result[i][k] != 0) {
						if (result[i][k] == tmpNum && check[check.size()-1]!=make_pair(i,k)) {
							result[i][k] += tmpNum;
							check.push_back(make_pair(i, k));
							break;
						}
						else {
							result[i][k + 1] = tmpNum;
							break;
						}
					}
					if (k == 0) {
						result[i][k] = tmpNum;
						break;
					}
				}
			}
		}
		break;
	case 1://R
		for (int i = 0; i < N; i++) {
			//각각의 행에 대해 시행
			for (int j = N-2; j > -1; j--) {
				if (result[i][j] == 0) continue;
				int tmpNum = result[i][j];
				result[i][j] = 0;
				for (int k = j+1; k < N; k++) {
					if (result[i][k] != 0) {
						if (result[i][k] == tmpNum && check[check.size() - 1] != make_pair(i, k)) {
							result[i][k] += tmpNum;
							check.push_back(make_pair(i, k));
							break;
						}
						else {
							result[i][k - 1] = tmpNum;
							break;
						}
					}
					if (k == N-1){
						result[i][k] = tmpNum;
						break;
					}
				}
			}
		}
		break;
	case 2://U
		for (int j = 0; j < N; j++) {
			//각각의 행에 대해 시행
			for (int i = 1; i < N; i++) {
				if (result[i][j] == 0) continue;
				int tmpNum = result[i][j];
				result[i][j] = 0;
				for (int k = i-1; k > -1; k--) {
					if (result[k][j] != 0 ) {
						if (result[k][j] == tmpNum&& check[check.size() - 1] != make_pair(k, j)) {
							result[k][j] += tmpNum;
							check.push_back(make_pair(k, j));
							break;
						}
						else {
							result[k + 1][j] = tmpNum;
							break;
						}
					}
					if (k == 0) {
						result[k][j] = tmpNum;
						break;
					}
				}
			}
		}
		break;
	case 3://D
		for (int j = 0; j < N; j++) {
			//각각의 행에 대해 시행
			for (int i = N-2; i > -1; i--) {
				if (result[i][j] == 0) continue;
				int tmpNum = result[i][j];
				result[i][j] = 0;
				for (int k = i+1; k < N; k++) {
					if (result[k][j] != 0 ) {
						if (result[k][j] == tmpNum&& check[check.size() - 1] != make_pair(k, j)) {
							result[k][j] += tmpNum;
							check.push_back(make_pair(k, j));
							break;
						}
						else {
							result[k - 1][j] = tmpNum;
							break;
						}
					}
					if (k == N - 1) {
						result[k][j] = tmpNum;
						break;
					}
				}
			}
		}
		break;
	}
	return result;
}

void printV(vector<vector<int>> v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	return;
}

void findMax(vector<vector<int>> v) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v[i][j] > MAX) MAX = v[i][j];
		}
	}
}

void DFS(vector<vector<int>> v, int cnt) {
	if (cnt > 6) return;
	findMax(v);
	for (int i = 0; i < 4; i++) {
		DFS(move(v, i), cnt + 1);
	}
	return;
}

void run() {
	init();
	findMax(mapV);
	vector<vector<int>>tmpV;
	/*
	cout << "---------------------------\n";
	tmpV = move(mapV, 0);
	printV(tmpV);
	cout << endl;
	cout << "---------------------------\n";
	tmpV = move(mapV, 1);
	printV(tmpV);
	cout << endl;
	cout << "---------------------------\n";
	tmpV = move(mapV, 2);
	printV(tmpV);
	cout << endl;
	cout << "---------------------------\n";
	tmpV = move(mapV, 3);
	printV(tmpV);
	cout << endl;
	*/
	DFS(mapV, 1);
	cout << MAX << endl;

	//printV(move(move(mapV, 0),2));
	return;
}

int main() {
	run();
	return 0;
}