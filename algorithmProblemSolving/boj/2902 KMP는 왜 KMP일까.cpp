#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int main() {
	char* KMP = new char[101];
	cin >> KMP;
	int size = strlen(KMP);
	vector<char> v;
	v.push_back(KMP[0]);
	for (int i = 1; i < size; i++) {
		if (KMP[i] == 45) v.push_back(KMP[i+1]);
	}
	int v_size = v.size();
	for (int i = 0; i < v_size; i++) {
		cout << v.at(i);
	}
	return 0;
}