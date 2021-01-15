#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

bool S[21] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int M, x;
	cin >> M;
	for (int i = 0; i < M; i++) {
		string strInput;
		cin >> strInput;
		if (strInput == "all") {
			memset(S, true, sizeof(S));
		}
		else if (strInput == "empty") {
			memset(S, false, sizeof(S));
		}
		else if (strInput == "add") {
			cin >> x;
			S[x] = true;
		}
		else if (strInput == "remove") {
			cin >> x;
			S[x] = false;
		}
		else if (strInput == "check") {
			cin >> x;
			if (S[x]) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else {
			cin >> x;
			if (S[x]) S[x] = false;
			else S[x] = true;
		}
	}
	return 0;
}