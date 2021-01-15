#include <iostream>
#include <vector>
#include<cstdio>
#define Max 1000000

using namespace std;

bool primes[Max];

void byeGoldbach() {
	cout << "Goldbach's conjecture is wrong" << endl;
}

void initPrimes() {
	primes[0] = true;
	primes[1] = true;
	for (int i = 2; i < Max; i++) {
		primes[i] = false;
	}
}

void findPrime() {
	for (int i = 2; i*i < Max; i++) {
		if (!primes[i]) {
			for (int j = (i * i) % Max; j < Max; j += i) {
				primes[j] = true;
			}
		}
	}
}

void goldBach(int n) {
	for (int i = 2; i < Max;i++) {
		if (!primes[i]) {
			int j = n - i;
			if (!primes[j]) {
				printf("%d = %d + %d\n", n, i, j);
				//cout << n << " = " << i << " + " << j << endl;
				return;
			}
		}
	}
	byeGoldbach();
}

int main() {
	initPrimes();
	findPrime();
	for (int i = 0; i < 100000; i++) {
		int n;
		scanf("%d", &n);
		if (n == 0) return 0;
		goldBach(n);
	}
	return 0;
}