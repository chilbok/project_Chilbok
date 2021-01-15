#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
int main() {
	int devil = 666;
	int N, count = 0, iter = 0, title, digit, check = 0, tmp, wow = 6;
	cin >> N;
	while (count != N) {
		
		check = 0;
		if ((iter % 10) != 6) {
			title = iter * 1000 + devil;
			count++;
			iter++;
			}
		else if ((iter % 10) == 6) {
			tmp = iter;
			digit = (int)log10(iter) + 1;
			for (int i = 0; i < digit; i++) {
				if ((tmp % 10)==6) {
					tmp = tmp / 10;
					check++;
				}
				else break;
			}// 6이 몇번 반복되는지 판별
			for (int i = 0; i < pow(10, check); i++) {
				count++;
				if (count == N) {
					title = iter * 1000 + devil;
					for (int j = 0; j < check-1; j++) {
						wow = wow * 10 + 6;
					}
					title = title - wow + i;
					break;
				}
			}
			iter++;
			
		}
		
	}
	cout << title << endl << endl;
	return 0;
}