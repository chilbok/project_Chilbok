#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int N, M;
int currBtn = 100;
vector<bool> errBtn(10,true);

void init() {
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int tmp;
		cin >> tmp;
		errBtn[tmp] = false;
	}
	return;
}

bool isOk(int ch) {
	string chStr = to_string(ch);
	for (int i = 0; i < chStr.length(); i++) {
		if (!errBtn[chStr.at(i) - 48]) {
			return false;
		}
	}
	return true;
}

int findCh(bool flag) {
	int result = 1000007;
	if (flag) {
		//up
		for (int i = N+1; i < 1000007; i++) {
			if (isOk(i)) {
				return i;
			}
		}
	}
	else {
		//down
		for (int i = N-1; i > -1; i--) {
			if (isOk(i)) {
				return i;
			}
		}
	}
	return result;
}

void run() {
	init();
	//초기화 완료
	int pmBtn = abs(N - currBtn);
	int move = 1000007;
	if (M == 10) {
		cout << pmBtn << endl;
		return;
	}
	if (isOk(N)) {
		move = to_string(N).length();
	}
	else {
		int up = findCh(true);
		int down = findCh(false);
		int chUp = abs(up-N) + to_string(up).length();
		int chDown = abs(down - N) + to_string(down).length();
		if (chUp < 0) {
			chUp = 1000007;
		}
		if (chDown < 0) {
			chDown = 1000007;
		}
		if (chUp < chDown) {
			move = chUp;
		}
		else {
			move = chDown;
		}
		//cout << "------------------\n";
		//cout << up << "     " << down << endl;
	}
	//cout << pmBtn << "  " << move << endl;
	//cout << "------------------\n";

	if (pmBtn < move) {
		cout << pmBtn << endl;
	}
	else {
		cout << move << endl;
	}
	return;
}

int main() {
	run();
	return 0;
}