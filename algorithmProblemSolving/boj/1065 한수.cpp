#include<iostream>
#include<math.h>
using namespace std;
int main() {
	int N = 0, count, q=0;
	cin >> N;
	for (int i = 3; i > -1; i--) {
		q = N/pow(10, i);
		if (q>0) {
			count = i;
			break;
		}
	}//자리수를 구해줌
	q = 0;
	switch (count) {
	case 0:
	case 1:
		cout << N;
		break;
	case 2:
	case 3:
		for (int i = 100; i < N + 1; i++) {
			if ((i / 100 + (i / 10) % 10 + i % 10) == 3 * ((i / 10) % 10)) {
				q++;
			}
		}
		cout << q + 99;
		break;
	}
	return 0;
}