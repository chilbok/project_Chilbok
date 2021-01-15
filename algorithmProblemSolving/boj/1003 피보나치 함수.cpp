#include<iostream>
using namespace std;
struct fib {
	int count_0 = 0;
	int count_1 = 0;
	long long int num;
}typedef fib;
long long int dat[41] = { 0 };
long long int fibo(int x);
fib fi[41];


int main() {
	int case_;
	int N;

	cin >> case_;
	int* in = new int[case_];
	for (int i = 0; i < case_; i++) {
		cin >> N;
		in[i] = N;
		fibo(N);
	}
	for (int i = 0; i < case_; i++) {
		cout << fi[in[i]].count_0 << " " << fi[in[i]].count_1 << endl;
	}
	return 0;
}
long long int fibo(int x) {
	if (x == 0) {
		fi[0].count_0 = 1;
		fi[0].count_1 = 0;
		fi[0].num = 0;
		return 0;
	}
	else if (x == 1) {
		fi[1].count_0 = 0;
		fi[1].count_1 = 1;
		fi[1].num = 1;
		return 1;
	}
	if (fi[x].num != 0) {
		return fi[x].num;
	}
	else {
		fi[x].num = fibo(x - 1) + fibo(x - 2);
		fi[x].count_0 = fi[x - 1].count_0 + fi[x - 2].count_0;
		fi[x].count_1 = fi[x - 1].count_1 + fi[x - 2].count_1;
		return fi[x].num;
	}
}