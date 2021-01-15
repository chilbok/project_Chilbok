#include<iostream>
#include<vector>

using namespace std;

#define E_div 15
#define S_div 28
#define M_div 19

int E, S, M;

void initESM() {
	int e, s, m;
	cin >> e >> s >> m;
	E = e;
	S = s;
	M = m;
}

int findMin(int e, int s, int m) {
	int answer = s;
	int e_=e, s_=s, m_=m;
	if (e == 15) {
		e_ = 0;
	}
	if (s == 28) {
		s_ = 0;
	}
	if (m == 19) {
		m_ = 0;
	}
	while (true) {
		if (answer % E_div == e_ && answer % M_div == m_)
			break;
		answer += S_div;
	}

	return answer;
}

int main() {
	initESM();
	cout << findMin(E, S, M);
	return 0;
}