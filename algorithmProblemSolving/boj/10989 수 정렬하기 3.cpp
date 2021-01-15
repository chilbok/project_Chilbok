#include<cstdio>
#include<iostream>
using namespace std;
int main() {
	cin.tie(NULL);
	int N, tmp;
	scanf("%d", &N);
	int counting[10000] = { 0 };
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		counting[tmp-1]++;
	}
	for (int i = 0; i < 10000; i++) {
		tmp = counting[i];
			for (int j = 0; j < tmp; j++) {
				printf("%d\n", i + 1);
			}
	}
	return 0;
}