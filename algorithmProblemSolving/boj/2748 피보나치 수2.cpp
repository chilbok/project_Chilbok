#include<iostream>
using namespace std;
long long int dat[91] = { 0 };
long long int fibo(int x);
int main() {
    long long int N;
	cin >> N;
	cout<<fibo(N)<<endl;
	return 0;
}
long long int fibo(int x) {
	if(x==0){
        return 0;
    }
    else if (x < 2) {
		return 1;
	}
	if (dat[x] != 0) {
		return dat[x];
	}
	else {
		dat[x] = fibo(x - 1) + fibo(x - 2);
		return dat[x];
	}
}